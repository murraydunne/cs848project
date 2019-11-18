use timely::*;
use timely::dataflow::operators::{Input, Inspect, Map};

fn main() {

    // construct and execute a timely dataflow
    timely::execute_from_args(std::env::args(), |worker| {

        // add an input and base computation off of it
        let mut input = worker.dataflow(|scope| {
            let (input, stream) = scope.new_input();
            stream.map(|x| x * 2)
                    .inspect(|x| println!("hello {:?}", x));
            input
        });

        // introduce input, advance computation
        for round in 0..10 {
            input.send(round);
            input.advance_to(round + 1);
            worker.step();
        }
    });
}