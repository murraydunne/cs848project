use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;
use std::{thread, time};
use pyo3::{prelude::*, types::{PyModule, PyByteArray}};
use opencv::core;
use opencv::videoio;
use std::ptr;
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};

mod sarge_context;
mod sarge_origin;
mod sarge_exchange;

#[macro_use]
extern crate lazy_static;

#[macro_use]
extern crate abomonation;

fn execute_python_module(param: u64, worker: u64, frame: &Vec<u8>) -> String {

    lazy_static! {

    static ref GIL : pyo3::prelude::GILGuard = Python::acquire_gil();
    static ref PY : pyo3::python::Python<'static> = GIL.python();

    // https://www.learnopencv.com/keras-tutorial-using-pre-trained-imagenet-models/
    static ref PYMODULE : &'static pyo3::types::module::PyModule =   PyModule::from_code(*PY, "
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import keras
import numpy as np
from keras.applications.imagenet_utils import decode_predictions

vgg_model = keras.applications.vgg16.VGG16(weights='imagenet')
print(\"Creation context\")

def main(frame):
    image = np.frombuffer(frame, dtype=np.uint8)
    image = np.reshape(image, (640, 360, 3))
    image = image[208:432, 68:292, :]
    image_batch = np.expand_dims(image, axis=0)
    processed_image = keras.applications.vgg16.preprocess_input(image_batch.copy())
    predictions = vgg_model.predict(processed_image)
    netout = decode_predictions(predictions)
    result = ''
    for x in netout[0]:
        result += x[1] + ':' + str(x[2]) + ':'
    #labels = {x[1] : x[2] for x in netout[0]}
    #print(labels)
    return result
            ", "pymodule.py", "pymodule").map_err(|e| e.print(*PY)).unwrap();

    }

    //let buff = PyBuffer::new(*PY);
    let buff = PyByteArray::new(*PY, frame);

    let something = PYMODULE.call1("main", (buff,));

    let pyresult: String = (*something.map_err(|e| e.print(*PY)).unwrap()).extract().map_err(|e| e.print(*PY)).unwrap();

    //println!("Result: {:?}", pyresult);

    return pyresult;
}

// https://doc.rust-lang.org/std/ptr/fn.copy.html
fn from_buf_raw<T>(ptr: *const T, elts: usize) -> Vec<T> {
    let mut dst = Vec::with_capacity(elts);
    unsafe { 
        dst.set_len(elts); 
        ptr::copy(ptr, dst.as_mut_ptr(), elts);
    }
    dst
}

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
                                    if datum.1 == index as u64  {
                                        session.give((datum.0, index as u64));
                                    }
                                    if datum.1 == 0 && index == 0 {
                                        session.give((datum.0, 15 as u64));
                                        session.give((datum.0, 16 as u64));
                                    }
                                }
                            }
                        }
                    })

                    .exchange(move |x: &(u64, u64)| {
                        println!("node {:?} routing pipeline {:?} frame {:?}", index, (*x).1, (*x).0);
                        (*x).1
                    })

                    .inspect(move |x: &(u64, u64)| println!("node {:?} pipeline {:?} frame {:?} - pre first", index, (*x).1, (*x).0))

                    .map(move |x: (u64, u64)| (x.0, x.1, Instant::now()))

                    .unary(Pipeline, "Frame", |_, _| {
                        let mut vector : Vec<(u64, u64, Instant)> = Vec::new();
                        let mut cam = videoio::VideoCapture::new_from_file_with_backend("video-data/test-video.mp4",videoio::CAP_ANY).unwrap();
                        let mut frame : core::Mat = core::Mat::default().unwrap();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    if index == 15 || index == 16 {
                                        /*thread::sleep(time::Duration::from_millis(1180)); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                        for pipeline in 0..5 {
                                            session.give((datum.0, pipeline, Vec::<u8>::new(), datum.2));
                                        }*/
                                        session.give((datum.0, index as u64, Vec::<u8>::new(), datum.2));
                                    } else {
                                        //thread::sleep(time::Duration::from_millis(2000)); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                        cam.read(&mut frame);
                                        let framesize = frame.size().unwrap().width * frame.size().unwrap().height * 3;
                                        //println!("Got frame {}, with width {} and height {}", datum.0, frame.size().unwrap().width, frame.size().unwrap().height);
                                        // let first = frame.at<double>(i,j);
                                        let buff : Vec::<u8> = unsafe { from_buf_raw(frame.ptr(0).unwrap(), framesize as usize).to_owned() };

                                        for pipeline in 0..5 {
                                            session.give((datum.0, pipeline, buff.to_owned(), datum.2));
                                        }
                                    }
                                }
                            }
                        }
                    })

                    .map(move |x: (u64, u64, Vec<u8>, Instant)| {
                        if x.1 == index as u64 {
                            println!("Time to load frame {:?} was {:?} at node {:?}", x.0, x.3.elapsed().as_nanos(), index);
                        }
                        (x.0, x.1, x.2)
                    })
                    
                    .inspect(move |x: &(u64, u64, Vec<u8>)| {
                        if (*x).1 == index as u64 {
                            println!("node {:?} pipeline {:?} frame {:?} - done first (size {:?})", index, (*x).1, (*x).0, (*x).2.len());
                        }
                    })
                    
                    .exchange(move |x: &(u64, u64, Vec<u8>)| {
                        if (index == 15 || index == 16) && (*x).1 == index as u64 {
                            (*x).1
                        } else {
                            (*x).1 + 5
                        }
                    })

                    .unary(Pipeline, "WaitForGo1", |_, _| {
                        let mut vector : Vec<(u64, u64, Vec<u8>)> = Vec::new();
                        let mut keep : Vec<(u64, u64, Vec<u8>)> = Vec::new();
                        let mut last_sent_frame_number : u64 = 0;

                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);

                                for datum in vector.drain(..) {
                                    println!("node {:?} - SEEN pipeline {:?} frame {:?} vec len {:?} last frame {:?} keep len {:?}", 
                                            index, datum.1, datum.0, datum.2.len(), last_sent_frame_number, keep.len());

                                    if index == 15 || index == 16 {
                                        if datum.1 == index as u64 {
                                            session.give((datum.0, datum.1, datum.2));
                                            println!("node {:?} keeping pipeline {:?} frame {:?} because master", index, datum.1, datum.0);
                                        }
                                        keep.clear(); // doesn't matter, will never actually put anything in keep for 15/16
                                    } else if datum.1 + 5 == index as u64 && datum.2.len() > 0 && datum.0 > last_sent_frame_number {
                                        session.give((datum.0, datum.1, datum.2));
                                        last_sent_frame_number = datum.0;
                                        keep.clear();
                                        println!("node {:?} sending expected input - pipeline {:?} frame {:?}", index, datum.1, datum.0);
                                    } else if datum.2.len() == 0 && datum.0 > last_sent_frame_number {
                                        if keep.len() == 0 {
                                            println!("node {:?} marker occured before ANY inputs, failure case pipeline {:?} frame {:?}", index, datum.1, datum.0);
                                            last_sent_frame_number = datum.0;
                                        } else {
                                            session.give(keep[0].clone());
                                            last_sent_frame_number = datum.0;
                                            keep.clear();
                                            println!("node {:?} sending other input (got marker) - pipeline {:?} frame {:?}", index, datum.1, datum.0);
                                        }
                                    } else if datum.0 > last_sent_frame_number {
                                        keep.push(datum)
                                    }
                                }
                            }
                        }
                    })

                    .map(move |x: (u64, u64, Vec<u8>)| (x.0, x.1, x.2, Instant::now()))

                    .unary(Pipeline, "ML", |_, _| {
                        let mut vector : Vec<(u64, u64, Vec<u8>, Instant)> = Vec::new();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for x in vector.drain(..) {
                                    if index == 15 || index == 16 {
                                        thread::sleep(time::Duration::from_millis(1600)); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                        for pipeline in 0..5 {
                                            session.give((x.0, pipeline, index as u64, ":".to_owned(), x.3));
                                        }
                                        session.give((x.0, x.1, index as u64, ":".to_owned(), x.3));
                                    } else {
                                        let res : String = execute_python_module(x.0, index as u64, &(x.2));
                                        for pipeline in 0..5 {
                                            session.give((x.0, pipeline, x.1, res.to_owned(), x.3))
                                        }
                                    }
                                }
                            }
                        }
                    })

                    .map(move |x: (u64, u64, u64, String, Instant)| {
                        if x.1 + 5 == index as u64 || (index == 15 && x.1 == 15) || (index == 16 && x.1 == 16) {
                            println!("Time to run ML on frame {:?} was {:?} pipeline {:?} at node {:?}", x.0, x.4.elapsed().as_nanos(), x.1, index);
                        }
                        (x.0, x.1, x.2, x.3)
                    })

                    .inspect(move |x: &(u64, u64, u64, String)| {
                        if x.1 + 5 == index as u64 || (index == 15 && x.1 == 15) || (index == 16 && x.1 == 16) {
                            println!("node {:?} pipeline {:?} frame {:?} - done second (result {:?})", index, (*x).1, (*x).0, (*x).3);
                        }
                    })

                    .exchange(move |x: &(u64, u64, u64, String)| {
                        if (index == 15 || index == 16) && (*x).1 == index as u64 {
                            index as u64
                        } else {
                            (*x).1 + 10
                        }
                    })

                    .unary(Pipeline, "WaitForGo2", |_, _| {
                        let mut vector : Vec<(u64, u64, u64, String)> = Vec::new();
                        let mut keep : Vec<(u64, u64, u64, String)> = Vec::new();
                        let mut last_sent_frame_number : u64 = 0;

                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);

                                for datum in vector.drain(..) {
                                    println!("node {:?} - SEEN2 pipeline {:?} frame {:?} str {:?} last frame {:?} keep len {:?} time {:?}", 
                                            index, datum.1, datum.0, datum.3, last_sent_frame_number, keep.len(), SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_millis());

                                    if index == 15 || index == 16 {
                                        if datum.1 == index as u64 {
                                            session.give((datum.0, datum.1, datum.3));
                                            println!("node {:?} @ keeping pipeline {:?} frame {:?} because master", index, datum.1, datum.0);
                                        }
                                        keep.clear(); // doesn't matter, will never actually put anything in keep for 15/16
                                    } else if datum.2 + 10 == index as u64 && datum.3 != ":" && datum.0 > last_sent_frame_number {
                                        println!("node {:?} @ sending expected input - pipeline {:?} frame {:?} data {:?}", index, datum.1, datum.0, datum.2);
                                        session.give((datum.0, datum.1, datum.3));
                                        last_sent_frame_number = datum.0;
                                        keep.clear();
                                    } else if datum.3 == ":" && datum.0 > last_sent_frame_number {
                                        if keep.len() == 0 {
                                            println!("node {:?} @ marker occured before ANY inputs, failure case pipeline {:?} frame {:?}", index, datum.1, datum.0);
                                            last_sent_frame_number = datum.0;
                                        } else {
                                            session.give((keep[0].0, keep[0].1, keep[0].3.to_owned()));
                                            last_sent_frame_number = datum.0;
                                            keep.clear();
                                            println!("node {:?} @ sending other input (got marker) - pipeline {:?} frame {:?}", index, datum.1, datum.0);
                                        }
                                    } else if datum.0 > last_sent_frame_number {
                                        keep.push(datum)
                                    }
                                }
                            }
                        }
                    })

                    .map(move |x: (u64, u64, String)| (x.0, x.1, x.2, Instant::now()))

                    .map(|x: (u64, u64, String, Instant)| (x.0, x.1, x.2.split(":").next().unwrap().to_owned(), x.3))

                    .map(move |x: (u64, u64, String, Instant)| {
                        println!("Time to decide object on frame {:?} was {:?} at node {:?}", x.0, x.3.elapsed().as_nanos(), index);
                        (x.0, x.1, x.2)
                    })

                    .inspect(move |x: &(u64, u64, String)| println!("node {:?} pipeline {:?} frame {:?} - final (choice {:?})", index, (*x).1, (*x).0, (*x).2));
            input
        });

        // introduce input, advance computation
        let command_line_args: Vec<String> = std::env::args().collect();
        let index = command_line_args.iter().position(|r| r == "-p").unwrap();
        let pnum = command_line_args[index + 1].parse::<i32>().unwrap();


        if pnum < 5 {
            for video_frame_index in 1..5000 {
                for pipeline in 0..5 {
                    input.send((video_frame_index, pipeline));
                }
                input.advance_to(video_frame_index + 1);
                for _ in 0..5 {
                    worker.step();
                }
                thread::sleep(time::Duration::from_millis(5000));
            }
        } else {
            while worker.step() {
                thread::sleep(time::Duration::from_millis(1));
            }
        }

        
    }).ok();

}
