use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;
use std::{thread, time};

fn main() {

    // construct and execute a timely dataflow
    timely::execute_from_args(std::env::args(), |worker| {

        // add an input and base computation off of it
        let mut input = worker.dataflow(|scope| {
            let index = scope.index();
            let (input, stream) = scope.new_input();
            stream.unary(Pipeline, "DropNotNeeded", |_, _| {
                        let mut vector : Vec<(u64, u64)> = Vec::new();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    if datum.1 == index as u64 {
                                        session.give(datum);
                                    }
                                }
                            }
                        }
                    })
                    .exchange(|x: &(u64, u64)| (*x).1)
                    //.map(|x| x * 2)
                    .inspect(move |x: &(u64, u64)| println!("node {:?} pipeline {:?} frame {:?} - first", index, (*x).1, (*x).0))
                    .exchange(|x: &(u64, u64)| (*x).1 + 5)
                    //.map(|x| x * 3)
                    .inspect(move |x: &(u64, u64)| println!("node {:?} pipeline {:?} frame {:?} - second", index, (*x).1, (*x).0));
            input
        });

        // introduce input, advance computation
        let command_line_args: Vec<String> = std::env::args().collect();
        let index = command_line_args.iter().position(|r| r == "-p").unwrap();
        let pnum = command_line_args[index + 1].parse::<i32>().unwrap();


        if pnum == 0 {
            for video_frame_index in 0..23 {
                for pipeline in 0..5 {
                    input.send((video_frame_index, pipeline));
                }
                input.advance_to(video_frame_index + 1);
                for _ in 0..5 {
                    worker.step();
                }
                thread::sleep(time::Duration::from_millis(500));
            }
        } else {
            while worker.step() { }
        }

        
    }).ok();
}