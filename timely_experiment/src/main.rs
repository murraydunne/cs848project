use timely::*;
use timely::dataflow::operators::*;

fn main() {

    // construct and execute a timely dataflow
    timely::execute_from_args(std::env::args(), |worker| {

        // add an input and base computation off of it
        let mut input = worker.dataflow(|scope| {
            let index = scope.index();
            let (input, stream) = scope.new_input();
            stream.exchange(|x| *x % 5 as u64)
                    .map(|x| x * 2)
                    .inspect(move |x| println!("first worker {:?} done {:?}", index, x))
                    .exchange(|x| *x % 5 + 5 as u64)
                    .map(|x| x * 3)
                    .inspect(move |x| println!("second worker {:?} done {:?}", index, x));
            input
        });

        // introduce input, advance computation
        for round in 0..5 {
            input.send(round);
            input.advance_to(round + 1);
            worker.step();
        }
    });
}