//! Begins a trace of sage nodes that accumulate the

use timely::Data;
use timely::dataflow::channels::pact::Pipeline;
use timely::dataflow::{Stream, Scope};
use timely::dataflow::operators::generic::operator::Operator;

use crate::sarge_context::SargeContext;

/// Extension trait for filtering.
pub trait SargeOrigin <G: Scope, D: Data> {
    /// Returns a new instance of `self` with records transmitted appropriately for starting a Sarge pipeline.
    ///
    /// # Examples
    /// ```
    /// use timely::dataflow::operators::{ToStream, Inspect};
    /// use sarge::operators::SargeOrigin;
    ///
    /// timely::example(|scope| {
    ///     (0..10).to_stream(scope)
    ///            .sarge_origin()
    ///            .inspect(|x| println!("seen: {:?}", x));
    /// });
    /// ```
    fn sarge_origin(&self, replicas: u64, rtcs: u64) -> Stream<G, (SargeContext, D)>;
}

impl<G: Scope, D: Data> SargeOrigin<G, D> for Stream<G, D> {
    fn sarge_origin(&self, replicas: u64, rtcs: u64) -> Stream<G, (SargeContext, D)> {
        let mut vector = Vec::new();
        let index = self.scope().index() as u64; // index determines who we are in the pipeline

        self.unary(Pipeline, "SargeOrigin", move |_,_| move |input, output| {
            input.for_each(|time, data| {

                let mut session = output.session(&time);
                data.swap(&mut vector);

                for datum in vector.drain(..) {
                    for rtc in 0..rtcs {
                        session.give((SargeContext {
                            source_replica: rtc, 
                            dest_replica: rtc,
                            pipe_stage: 0, 
                            num_replicas: replicas, 
                            num_rtcs: rtcs, 
                            is_rtc: true,
                            is_march: false,
                            start_time: 0
                        }, datum.clone()))
                    }
                    for replica in 0..replicas {
                        session.give((SargeContext {
                            source_replica: replica, 
                            dest_replica: replica,
                            pipe_stage: 0, 
                            num_replicas: replicas, 
                            num_rtcs: rtcs, 
                            is_rtc: false,
                            is_march: false,
                            start_time: 0
                        }, datum.clone()))
                    }
                }
            });
        })
    }
}
