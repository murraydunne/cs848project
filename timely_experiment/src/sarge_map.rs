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
    fn sarge_map<D2: Data, L: FnMut(D)->D2+'static, L2: FnMut(D)->D2+'static>(&self, march_ns: u64, logic: L, no_op: L2) -> Stream<S, (SargeContext, D2)>;
}

impl<S: Scope, D: Data> SargeMap<S, D> for Stream<S, (SargeContext, D)> {
    fn sarge_map<D2: Data, L: FnMut(D)->D2+'static, L2: FnMut(D)->D2+'static>(&self, march_ns: u64, mut logic: L, mut no_op: L2) -> Stream<S, (SargeContext, D2)> {
        let mut vector = Vec::new();
        let index = self.scope().index() as u64; // index determines who we are in the pipeline

        self.unary(Pipeline, "Map", move |_,_| move |input, output| {
            input.for_each(|time, data| {
                let mut session = output.session(&time);
                data.swap(&mut vector);

                for datum in vector.drain(..) {
                    if datum.0.is_rtc {
                        thread::sleep(time::Duration::from_nanos(march_ns));

                        let res = no_op(datum.1);

                        let mut new_context = datum.0.clone();
                        new_context.start_time = SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_nanos();
                        let rtc_replica = new_context.dest_replica;
                        new_context.is_march = true;
                        
                        println!("node {} - sending marches for stage {} time {:?}", index, datum.0.pipe_stage, *time.time());

                        new_context.is_rtc = false;
                        for replica in 0..(datum.0.num_replicas) {
                            new_context.dest_replica = replica;
                            session.give((new_context, res.clone()));
                        }

                        new_context.is_rtc = true;
                        new_context.is_march = false;
                        new_context.dest_replica = rtc_replica;
                        session.give((new_context, res.clone()));

                    } else {
                        let mut new_context = datum.0.clone();
                        new_context.is_rtc = false;
                        new_context.start_time = SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_nanos();

                        let res = logic(datum.1);

                        for replica in 0..(datum.0.num_replicas) {
                            new_context.dest_replica = replica;
                            session.give((new_context, res.clone()));
                        }
                    }
                }
            });
        })
    }
}