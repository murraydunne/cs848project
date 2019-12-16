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
        let mut last_finished_march : G::Timestamp = Default::default();
        let mut output_set : Vec<(SargeContext, D)> = Vec::new();

        self.unary(
            ExchangePact::new(move |x: &(SargeContext, D)| {
                if x.0.is_rtc {
                    // nodes [0, rtcs) are the RTCS, was this one meant for us?
                    //println!("worker {} routing to {} stage {} (which should be itself for rtc)", index, x.0.dest_replica, x.0.pipe_stage);
                    x.0.dest_replica 
                } else {
                    // nodes rtcs + stage * replicas + replica is the address for a given replica at a stage
                    //println!("worker {} routing to dest replica {} stage {} (should be worker {})", index, x.0.dest_replica, x.0.pipe_stage,
                    //    x.0.num_rtcs + x.0.num_replicas * x.0.pipe_stage + x.0.dest_replica);
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

                    if datum_next_stage.0.pipe_stage == 0 {
                        // if it's pipeline stage zero there is no cross sends to happen yet
                        // so just forward
                        datum_next_stage.0.pipe_stage += 1;
                        session.give(datum_next_stage);
                        output_set.clear();

                    } else if datum_next_stage.0.is_rtc {
                        // we're still just on the RTC so forward as normal, no action needed
                        datum_next_stage.0.pipe_stage += 1;
                        session.give(datum_next_stage);
                        output_set.clear();

                    } else if *time.time() > last_finished_march {
                        // otherwise take actions only if we have not received the march yet
                        //println!("node {} - got src={} dest={} stage={} march={} time={:?} lfm={:?}",
                        //    index, datum_next_stage.0.source_replica, datum_next_stage.0.dest_replica,
                        //    datum_next_stage.0.pipe_stage, datum_next_stage.0.is_march, *time.time(), last_finished_march);

                        let our_replica = (index - datum_next_stage.0.num_rtcs) % datum_next_stage.0.num_replicas;

                        if datum_next_stage.0.is_march {
                            // we're not on an RTC and we got the march
                            last_finished_march = time.time().clone();

                            if !output_set.is_empty() {
                                // if we have some output, use the output selection strategy

                                // select according to selection strategy
                                let full_set: Vec<u64> = (0..datum_next_stage.0.num_replicas).collect();
                                let mut live_set : Vec<u64> = output_set.iter().map(|x| x.0.source_replica).collect();
                                live_set.sort();

                                let mut dead_set = full_set.clone();
                                dead_set.retain(|x| !live_set.contains(x));

                                let our_pos_in_dead_set = dead_set.iter().position(|x| *x == our_replica).unwrap();
                                output_set.sort_by(|x, y| x.0.source_replica.partial_cmp(&y.0.source_replica).unwrap());
                                let mut selected_output = output_set[our_pos_in_dead_set % output_set.len()].clone();

                                //println!("all={:?} dead={:?} live={:?} me={} ourpos={} selsrc={}", 
                                //    full_set, dead_set, live_set, our_replica, our_pos_in_dead_set, selected_output.0.source_replica);

                                println!("FAIL-OVER: TAKING OUTPUT FROM REPLICA {} AT TIME {:?}_{} ON REPLICA {} (NODE {})", 
                                    selected_output.0.source_replica, time.time(), datum_next_stage.0.pipe_stage, 
                                    selected_output.0.dest_replica, index);

                                selected_output.0.source_replica = selected_output.0.dest_replica;
                                selected_output.0.pipe_stage += 1;
                                session.give(selected_output);
                                output_set.clear();
                            } else {
                                println!("HARD-FAIL: VIOLATED MARCH AT TIME {:?}_{} ON REPLICA {} (NODE {})", 
                                    time.time(), datum_next_stage.0.pipe_stage, datum_next_stage.0.dest_replica, index);
                                output_set.clear();
                            }

                        } else if datum_next_stage.0.dest_replica == our_replica && datum_next_stage.0.source_replica == our_replica {
                            // we got the expected input before the march, use it and proceed
                            //println!("node {} - accepted input src={} dest={} stage={} march={} time={:?} lfm={:?}",
                            //    index, datum_next_stage.0.source_replica, datum_next_stage.0.dest_replica,
                            //    datum_next_stage.0.pipe_stage, datum_next_stage.0.is_march, *time.time(), last_finished_march);
                            last_finished_march = time.time().clone();

                            println!("node {} - stage={} source={} delta={} time={:?}", index, datum_next_stage.0.pipe_stage, datum_next_stage.0.source_replica,
                                SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_nanos() - datum_next_stage.0.start_time, *time.time());

                            datum_next_stage.0.pipe_stage += 1;
                            session.give(datum_next_stage);
                            output_set.clear();

                        } else if datum_next_stage.0.dest_replica == our_replica {
                            // we got an input from another stage, add it to the set

                            println!("node {} - stage={} source={} delta={} time={:?}", index, datum_next_stage.0.pipe_stage, datum_next_stage.0.source_replica,
                                SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_nanos() - datum_next_stage.0.start_time, *time.time());

                            output_set.push(datum_next_stage);
                        }
                        
                    }
                }
            });
        })
    }
}
