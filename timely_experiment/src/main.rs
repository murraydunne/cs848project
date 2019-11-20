use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;

use opencv::prelude::*;
use opencv::core;
use opencv::videoio;
use opencv::highgui;

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
                                    if datum.0 == index as u64 {
                                        session.give(datum);
                                    }
                                }
                            }
                        }
                    })
                    .unary(Pipeline, "Frame", |_, _| {
                        let mut vector : Vec<(u64, u64)> = Vec::new();
                        let mut cam = videoio::VideoCapture::new_from_file_with_backend("../video-data/policeChase.mp4",videoio::CAP_ANY).unwrap();
                        let mut frame = core::Mat::default().unwrap();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    cam.read(&mut frame);
                                    println!("Got frame {}, with width {} and height {}", datum.0, frame.size().unwrap().width, frame.size().unwrap().height);
                                    // let first = frame.at<double>(i,j);
                                    // const double* Mi = frame.ptr<double>(0);
                                    session.give(datum);
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
        for video_frame_index in 0..23 {
            for pipeline in 0..5 {
                input.send((video_frame_index, pipeline));
            }
            input.advance_to(video_frame_index + 1);
            worker.step();
        }
    }).ok();

}