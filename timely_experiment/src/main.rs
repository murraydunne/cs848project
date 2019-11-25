use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;
use std::{thread, time};
use pyo3::{prelude::*, types::{IntoPyDict, PyModule, PyByteArray}};
use std::boxed::Box;

#[macro_use]
extern crate lazy_static;


fn execute_python_module(param: u64, worker: u64, frame: &Vec<u8>) -> f64 {
    println!("{:?} - Hello from the function!", worker);

    /*
    lazy_static! {
        static ref HASHMAP: HashMap<u32, &'static str> = {
            let mut m = HashMap::new();
            m.insert(0, "foo");
            m.insert(1, "bar");
            m.insert(2, "baz");
            m
        };
        static ref COUNT = HASHMAP.len();
    }*/

    lazy_static! {

    static ref GIL : pyo3::prelude::GILGuard = Python::acquire_gil();
    static ref PY : pyo3::python::Python<'static> = GIL.python();

    // https://www.learnopencv.com/keras-tutorial-using-pre-trained-imagenet-models/
    static ref PYMODULE : &'static pyo3::types::module::PyModule =   PyModule::from_code(*PY, "
import keras
import numpy as np
from keras.applications.imagenet_utils import decode_predictions

vgg_model = keras.applications.vgg16.VGG16(weights='imagenet')
print(\"Creation context\")

def main(frame):
    print('0')
    image = np.frombuffer(frame, dtype=np.uint8)
    print('0.5')
    image = np.reshape(image, (640, 360, 3))
    print('1')
    image = image[208:432, 68:292, :]
    print('1.5', image.shape)
    image_batch = np.expand_dims(image, axis=0)
    print('2')
    processed_image = keras.applications.vgg16.preprocess_input(image_batch.copy())
    print('3')
 
    predictions = vgg_model.predict(processed_image)
    print('4')
    label = decode_predictions(predictions)
    print('5')
    print(label)
    print('6')
    return len(frame)
            ", "pymodule.py", "pymodule").map_err(|e| e.print(*PY)).unwrap();

    }
    

    println!("{:?} - We have a python.", worker);
    

    println!("{:?} - We have a module.", worker);

    //let buff = PyBuffer::new(*PY);
    let buff = PyByteArray::new(*PY, frame);

    let something = PYMODULE.call1("main", (buff,));

    println!("{:?} - We called it!", worker);

    let pyresult: f64 = (*something.map_err(|e| e.print(*PY)).unwrap()).extract().map_err(|e| e.print(*PY)).unwrap();
    return pyresult;
}

use opencv::prelude::*;
use opencv::core;
use opencv::videoio;
use opencv::highgui;
use std::ptr;

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

    /*lazy_static! {
        static ref gil : pyo3::prelude::GILGuard = Python::acquire_gil();
    }*/

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
                    .unary(Pipeline, "Frame", |_, _| {
                        let mut vector : Vec<(u64, u64)> = Vec::new();
                        let mut cam = videoio::VideoCapture::new_from_file_with_backend("video-data/policeChase.mp4",videoio::CAP_ANY).unwrap();
                        let mut frame : core::Mat = core::Mat::default().unwrap();
                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    cam.read(&mut frame);
                                    let framesize = frame.size().unwrap().width * frame.size().unwrap().height * 3;
                                    println!("Got frame {}, with width {} and height {}", datum.0, frame.size().unwrap().width, frame.size().unwrap().height);
                                    // let first = frame.at<double>(i,j);
                                    unsafe { session.give((datum.0, datum.1, from_buf_raw(frame.ptr(0).unwrap(), framesize as usize))); }
                                }
                            }
                        }
                    })
                    .exchange(|x: &(u64, u64, Vec<u8>)| (*x).1)
                    //.map(|x| x * 2)
                    .inspect(move |x: &(u64, u64, Vec<u8>)| println!("node {:?} pipeline {:?} frame {:?} - first", index, (*x).1, (*x).0))
                    //.exchange(|x: &(u64, u64, Vec<u8>)| (*x).1 + 5)
                    .exchange(|x: &(u64, u64, Vec<u8>)| 5)
                    //.map(|x| x * 3)
                    .inspect(move |x: &(u64, u64, Vec<u8>)| println!("node {:?} pipeline {:?} frame {:?} - final ({:?})", 
                                                            index, (*x).1, (*x).0, execute_python_module((*x).0, index as u64, &(*x).2)));
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
                thread::sleep(time::Duration::from_millis(5000));
            }
        } else {
            while worker.step() {
                thread::sleep(time::Duration::from_millis(1));
            }
        }

        
    }).ok();

}