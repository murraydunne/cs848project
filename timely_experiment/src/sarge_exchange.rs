//! Begins a trace of sage nodes that accumulate the

use timely::ExchangeData;
use timely::dataflow::channels::pact::Pipeline;
use timely::dataflow::{Stream, Scope};
use timely::dataflow::operators::generic::operator::Operator;
use timely::dataflow::channels::pact::Exchange as ExchangePact;

use crate::sarge_context::SargeContext;

/// Extension trait for filtering.
pub trait SargeExchange<G: Scope, D: ExchangeData> {
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
    fn sarge_exchange(&self) -> Stream<G, (SargeContext, D)>;
}

impl<G: Scope, D: ExchangeData> SargeExchange<G,D> for Stream<G, (SargeContext, D)> {
    fn sarge_exchange(&self) -> Stream<G, (SargeContext, D)> {
        let mut vector = Vec::new();
        let index = self.scope().index() as u64; // index determines who we are in the pipeline

        self.unary(
            ExchangePact::new(move |x: &(SargeContext, D)| {
                if x.0.is_rtc {
                    // nodes [0, rtcs) are the RTCS, was this one meant for us?
                    x.0.dest_replica 
                } else {
                    // nodes rtcs + stage * replicas + replica is the address for a given replica at a stage
                    x.0.num_rtcs + x.0.num_replicas * x.0.pipe_stage + x.0.dest_replica
                }
            }), 
            "SargeExchange", 
            move |_,_| move |input, output| {
            input.for_each(|time, data| {

                let mut session = output.session(&time);
                data.swap(&mut vector);

                for datum in vector.drain(..) {
                    let mut datum_next_stage = datum.clone();
                    datum_next_stage.0.pipe_stage += 1;
                    session.give(datum_next_stage);
                }
            });
        })
    }
}
