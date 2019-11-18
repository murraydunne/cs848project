use timely::*;
use timely::dataflow::operators::*;
use timely::dataflow::operators::generic::*;
use timely::dataflow::channels::pact::Pipeline;

fn main() {

    // construct and execute a timely dataflow
    timely::execute_from_args(std::env::args(), |worker| {

        // add an input and base computation off of it
        let mut input = worker.dataflow(|scope| {
            let index = scope.index();
            let (input, stream) = scope.new_input();
            stream.unary(Pipeline, "DropNotNeeded", |capability, info| {
                        let mut vector = Vec::new();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    if datum == index as u64 {
                                        session.give(datum);
                                    }
                                }
                            }
                        }
                    })
                    .exchange(|x| *x % 5 as u64)
                    .map(|x| x * 2)
                    .inspect(move |x| println!("{:?} did {:?} - first", index, x / 2))
                    .exchange(|x| *x % 5 + 5 as u64)
                    .map(|x| x * 3)
                    .inspect(move |x| println!("{:?} did {:?} - second", index, x / 6));
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