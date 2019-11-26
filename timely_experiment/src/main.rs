use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;
use std::{thread, time};
use pyo3::{prelude::*, types::{PyModule, PyByteArray}};
use opencv::core;
use opencv::videoio;
use std::ptr;


#[macro_use]
extern crate lazy_static;


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
                                    if datum.1 == index as u64 || ((index == 15 || index == 16) && datum.1 == 0) {
                                        session.give((datum.0, index as u64));
                                    }
                                }
                            }
                        }
                    })

                    .exchange(move |x: &(u64, u64)| {
                        if index == 15 || index == 16 {
                            index as u64
                        } else {
                            (*x).1
                        }
                    })

                    .inspect(move |x: &(u64, u64)| println!("node {:?} pipeline {:?} frame {:?} - pre first", index, (*x).1, (*x).0))

                    .unary(Pipeline, "Frame", |_, _| {
                        let mut vector : Vec<(u64, u64)> = Vec::new();
                        let mut cam = videoio::VideoCapture::new_from_file_with_backend("video-data/policeChase.mp4",videoio::CAP_ANY).unwrap();
                        let mut frame : core::Mat = core::Mat::default().unwrap();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    if index == 15 || index == 16 {
                                        session.give((datum.0, datum.1, Vec::<u8>::new()));
                                    } else {
                                        cam.read(&mut frame);
                                        let framesize = frame.size().unwrap().width * frame.size().unwrap().height * 3;
                                        //println!("Got frame {}, with width {} and height {}", datum.0, frame.size().unwrap().width, frame.size().unwrap().height);
                                        // let first = frame.at<double>(i,j);
                                        unsafe { session.give((datum.0, datum.1, from_buf_raw(frame.ptr(0).unwrap(), framesize as usize))); }
                                    }
                                }
                            }
                        }
                    })
                    
                    .inspect(move |x: &(u64, u64, Vec<u8>)| println!("node {:?} pipeline {:?} frame {:?} - done first (size {:?})", index, (*x).1, (*x).0, (*x).2.len()))
                    
                    //.exchange(|x: &(u64, u64, Vec<u8>)| (*x).1 + 5)
                    .exchange(move |x: &(u64, u64, Vec<u8>)| {
                        if index == 15 || index == 16 {
                            index as u64
                        } else {
                            (*x).1 + 5
                        }
                    })

                    .map(move |x: (u64, u64, Vec<u8>)| {
                        if index == 15 || index == 16 {
                            (x.0, x.1, ":".to_owned())
                        } else {
                            (x.0, x.1, execute_python_module(x.0, index as u64, &(x.2)))
                        }
                    })
                    
                    .inspect(move |x: &(u64, u64, String)| println!("node {:?} pipeline {:?} frame {:?} - done second (result {:?})", index, (*x).1, (*x).0, (*x).2))

                    //.exchange(|x: &(u64, u64, String)| (*x).1 + 10)
                    .exchange(move |x: &(u64, u64, String)| {
                        if index == 15 || index == 16 {
                            index as u64
                        } else {
                            (*x).1 + 10
                        }
                    })

                    .map(|x: (u64, u64, String)| (x.0, x.1, x.2.split(":").next().unwrap().to_owned()))

                    .inspect(move |x: &(u64, u64, String)| println!("node {:?} pipeline {:?} frame {:?} - final (choice {:?})", index, (*x).1, (*x).0, (*x).2));
            input
        });

        // introduce input, advance computation
        let command_line_args: Vec<String> = std::env::args().collect();
        let index = command_line_args.iter().position(|r| r == "-p").unwrap();
        let pnum = command_line_args[index + 1].parse::<i32>().unwrap();


        if pnum < 5 || pnum == 15 || pnum == 16 {
            for video_frame_index in 0..23 {
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