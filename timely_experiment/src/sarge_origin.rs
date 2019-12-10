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

        self.unary(Pipeline, "SargeOrigin", move |_,_| move |input, output| {
            input.for_each(|time, data| {

                let mut session = output.session(&time);
                data.swap(&mut vector);

                for datum in vector.drain(..) {
                    for rep in 0..replicas {
                        session.give((SargeContext {node: rep, stage: 0, replicas: replicas, rtcs: rtcs, is_rtc: false}, datum.clone()))
                    }
                    for rep in 0..rtcs {
                        session.give((SargeContext {node: rep, stage: 0, replicas: replicas, rtcs: rtcs, is_rtc: true}, datum.clone()))
                    }
                }
            });
        })
    }
}
