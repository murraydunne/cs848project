//! Extension methods for `Stream` based on record-by-record transformation.

use timely::Data;
use timely::dataflow::{Stream, Scope};
use timely::dataflow::channels::pact::Pipeline;
use timely::dataflow::operators::generic::operator::Operator;
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};
use std::{thread, time};

use crate::sarge_context::SargeContext;

/// Extension trait for `Stream`.
pub trait SargeMap<S: Scope, D: Data> {
    /// Consumes each element of the stream and yields a new element.
    ///
    /// # Examples
    /// ```
    /// use timely::dataflow::operators::{ToStream, Map, Inspect};
    ///
    /// timely::example(|scope| {
    ///     (0..10).to_stream(scope)
    ///            .map(|x| x + 1)
    ///            .inspect(|x| println!("seen: {:?}", x));
    /// });
    /// ```
    fn sarge_map<D2: Data, L: FnMut(D)->D2+'static>(&self, march_ms: u64, logic: L) -> Stream<S, (SargeContext, D2)>;
}

impl<S: Scope, D: Data> SargeMap<S, D> for Stream<S, (SargeContext, D)> {
    fn sarge_map<D2: Data, L: FnMut(D)->D2+'static>(&self, march_ms: u64, mut logic: L) -> Stream<S, (SargeContext, D2)> {
        let mut vector = Vec::new();
        self.unary(Pipeline, "Map", move |_,_| move |input, output| {
            input.for_each(|time, data| {
                let mut session = output.session(&time);
                data.swap(&mut vector);

                for datum in vector.drain(..) {
                    if datum.0.is_rtc {
                        thread::sleep(time::Duration::from_millis(march_ms));
                        session.give((datum.0, logic(datum.1)));
                    } else {
                        session.give((datum.0, logic(datum.1)));
                    }
                }
            });
        })
    }
}