extern crate timely;
#[macro_use]
extern crate abomonation;
extern crate rand;

use timely::dataflow::InputHandle;
use timely::dataflow::operators::{Input, Exchange, Inspect, Probe};
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};
use std::{thread, time};
use rand::Rng;

mod sarge_context;
mod sarge_origin;
mod sarge_exchange;
mod sarge_map;
mod sarge_end;

use crate::sarge_origin::SargeOrigin;
use crate::sarge_exchange::SargeExchange;
use crate::sarge_map::SargeMap;
use crate::sarge_end::SargeEnd;

fn main() {

    // initializes and runs a timely dataflow.
    timely::execute_from_args(std::env::args(), |worker| {

        let index = worker.index();
        let mut input = InputHandle::new();

        // create a new input, exchange data, and inspect its output
        let probe = worker.dataflow(|scope|
            scope.input_from(&mut input)
                 .sarge_origin(5, 3) // start sergeant pipeline with 5 replicas and 3 RTCs, 
                 // since we have 2 stages (2x sarge_exchange) we need (5 x 2 + 3) = 13 replicas
                 .sarge_exchange()
                 .sarge_map(40000000, move |x| {
                     println!("worker {}:\tstage 1:\tdata {}", index, x);
                     x
                 }, |x| x)
                 .sarge_exchange()
                 .sarge_map(40000000, move |x| {
                     //let mut rng = rand::thread_rng();
                     //thread::sleep(time::Duration::from_millis(rng.gen_range(0, 100)));
                     println!("worker {}:\tstage 2:\tdata {}", index, x);
                     x
                 }, |x| x)
                 .sarge_exchange()
                 .sarge_map(40000000, move |x| {
                     println!("worker {}:\tstage 3:\tdata {}", index, x);
                     x
                 }, |x| x)
                 .sarge_end(move |x| {
                     println!("worker {}:\tselected {}", index, x);
                 })
                 .probe()
        );

        // introduce data and watch!
        input.advance_to(1);
        for round in 1..11 {
            if index == 0 {
                input.send(round);
            }
            input.advance_to(round + 1);
            while probe.less_than(input.time()) {
                worker.step();
            }
        }
    }).unwrap();
}