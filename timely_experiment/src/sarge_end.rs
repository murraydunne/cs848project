//! Begins a trace of sage nodes that accumulate the

use std::default::Default;
use timely::ExchangeData;
use timely::dataflow::channels::pact::Pipeline;
use timely::dataflow::{Stream, Scope};
use timely::dataflow::operators::generic::operator::Operator;
use timely::dataflow::channels::pact::Exchange as ExchangePact;
use timely::progress::timestamp::{Timestamp};
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};
use std::{thread, time};

use crate::sarge_context::SargeContext;

/// Extension trait for filtering.
pub trait SargeEnd<G: Scope, D: ExchangeData+PartialEq> {
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
    fn sarge_end<L: FnMut(D)->()+'static>(&self, handle: L) -> Stream<G, SargeContext>;
}

impl<G: Scope, D: ExchangeData+PartialEq> SargeEnd<G,D> for Stream<G, (SargeContext, D)> {
    fn sarge_end<L: FnMut(D)->()+'static>(&self, mut handle: L) -> Stream<G, SargeContext> {
        let mut vector = Vec::new();
        let index = self.scope().index() as u64; // index determines who we are in the pipeline
        let mut last_finished_march : G::Timestamp = Default::default();
        let mut output_set : Vec<(SargeContext, D)> = Vec::new();

        self.unary(
            ExchangePact::new(move |x: &(SargeContext, D)| {
                if x.0.dest_replica < x.0.num_rtcs {
                    // nodes [0, rtcs) are the RTCS, was this one meant for us?
                    println!("node {} - routing to index {} (should be RTC) from {} for end (stage {})", 
                        index, x.0.dest_replica, x.0.source_replica, x.0.pipe_stage);
                    x.0.dest_replica 
                } else {
                    println!("node {} - rounting to 0 from {} (dest was {})", index, x.0.source_replica, x.0.dest_replica);
                    0
                }
            }), 
            "SargeExchange", 
            move |_,_| move |input, output| {
            input.for_each(|time, data| {
                let mut session = output.session(&time);

                data.swap(&mut vector);

                for datum in vector.drain(..) {
                    let mut datum_next_stage = datum.clone();

                    if *time.time() > last_finished_march {
                        // take actions only if we have not received the march yet
                        println!("node {} - got src={} dest={} stage={} march={} time={:?} lfm={:?}",
                            index, datum_next_stage.0.source_replica, datum_next_stage.0.dest_replica,
                            datum_next_stage.0.pipe_stage, datum_next_stage.0.is_march, *time.time(), last_finished_march);

                        if datum_next_stage.0.is_march {
                            // we're not on an RTC and we got the march
                            last_finished_march = time.time().clone();

                            if !output_set.is_empty() {
                                // if we have some output, vote
                                let result_set : Vec<D> = output_set.iter().map(|x| x.1.clone()).collect();
                                let mut current_choice : D = result_set[0].clone();
                                let mut class_size = 1;

                                for result in &result_set {
                                    let vote = result_set.iter().filter(|&n| result == n).count();
                                    if vote > class_size {
                                        current_choice = result.clone();
                                        class_size = vote;
                                    }
                                }

                                handle(current_choice);
                                output_set.clear();
                            } else {
                                println!("HARD-FAIL (VOTE): VIOLATED MARCH AT TIME {:?}_{} ON REPLICA {} (NODE {})", 
                                    time.time(), datum_next_stage.0.pipe_stage, datum_next_stage.0.dest_replica, index);
                                output_set.clear();
                            }

                        } else if datum_next_stage.0.dest_replica == index {
                            // we got an input, add it to the set
                            let mut live_set : Vec<u64> = output_set.iter().map(|x| x.0.source_replica).collect();

                            if !live_set.contains(&datum_next_stage.0.source_replica) {
                                println!("node {} - stage={} source={} time={}", index, datum_next_stage.0.pipe_stage, datum_next_stage.0.source_replica,
                                    SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_nanos() - datum_next_stage.0.start_time);
                                output_set.push(datum_next_stage);
                            }
                        }
                        
                    }
                }
            });
        })
    }
}
