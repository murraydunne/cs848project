extern crate timely;
#[macro_use]
extern crate abomonation;
extern crate rand;
#[macro_use]
extern crate lazy_static;
#[macro_use]
extern crate ref_thread_local;

use timely::dataflow::InputHandle;
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};
use std::{thread, time};
use rand::Rng;
use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;
use pyo3::{prelude::*, types::{PyModule, PyByteArray}};
use opencv::core;
use opencv::videoio;
use std::ptr;
use ref_thread_local::RefThreadLocal;

mod sarge_context;
mod sarge_origin;
mod sarge_exchange;
mod sarge_map;
mod sarge_end;

use crate::sarge_origin::SargeOrigin;
use crate::sarge_exchange::SargeExchange;
use crate::sarge_map::SargeMap;
use crate::sarge_end::SargeEnd;



fn execute_python_module(param: u64, worker: u64, frame: &Vec<u8>) -> String {

    lazy_static! {

    static ref GIL : pyo3::prelude::GILGuard = Python::acquire_gil();
    static ref PY : pyo3::python::Python<'static> = GIL.python();

    // https://www.learnopencv.com/keras-tutorial-using-pre-trained-imagenet-models/
    static ref PYMODULE : &'static pyo3::types::module::PyModule =   PyModule::from_code(*PY, "
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

import tensorflow as tf
from keras import backend as K
config = tf.ConfigProto()
config.gpu_options.allow_growth=True
sess = tf.Session(config=config)
K.set_session(sess)

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
            ", "pymodule.py", "pymodule").map_err(|e| {
                println!("PYTHON ERROR CASE 1 @@@@@@@@@@@@@@@@@@");
                e.print_and_set_sys_last_vars(*PY)
            }).unwrap();

    }

    //let buff = PyBuffer::new(*PY);
    let buff = PyByteArray::new(*PY, frame);

    let something = PYMODULE.call1("main", (buff,));

    let pyresult: String = (*something.map_err(|e| {
        println!("PYTHON ERROR CASE 2 @@@@@@@@@@@@@@@@@@");
        e.print_and_set_sys_last_vars(*PY)
    }).unwrap()).extract().map_err(|e| {
        println!("PYTHON ERROR CASE 3 @@@@@@@@@@@@@@@@@@");
        e.print_and_set_sys_last_vars(*PY)
    }).unwrap();

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

    // initializes and runs a timely dataflow.
    timely::execute_from_args(std::env::args(), |worker| {

        let index = worker.index();
        let mut input = InputHandle::new();

        // create a new input, exchange data, and inspect its output
        let probe = worker.dataflow(|scope|
            scope.input_from(&mut input)
                .sarge_origin(5, 2) // start sergeant pipeline with 5 replicas and 3 RTCs, 
                // since we have 2 stages (2x sarge_exchange) we need (5 x 2 + 3) = 13 replicas
                .sarge_exchange()
                .sarge_map(500000000, 0.0, 10, move |x| {
                    ref_thread_local! {
                        static managed cam : videoio::VideoCapture = videoio::VideoCapture::new_from_file_with_backend("video-data/train-video.mp4",videoio::CAP_ANY).unwrap();
                    }

                    let mut frame : core::Mat = core::Mat::default().unwrap();
                    let mut bcam = cam.borrow_mut();
                    bcam.read(&mut frame);
                    let framesize = frame.size().unwrap().width * frame.size().unwrap().height * 3;
                    //println!("Got frame {}, with width {} and height {}", datum.0, frame.size().unwrap().width, frame.size().unwrap().height);
                    // let first = frame.at<double>(i,j);
                    let buff : Vec::<u8> = unsafe { from_buf_raw(frame.ptr(0).unwrap(), framesize as usize).to_owned() };


                    println!("worker {}:\tstage 1:\tdata {}", index, buff.len());

                    buff
                }, |y| Vec::<u8>::new())
                .sarge_exchange()
                .sarge_map(65000000, 0.0, 10, move |x| {
                    //let mut rng = rand::thread_rng();
                    //thread::sleep(time::Duration::from_millis(rng.gen_range(0, 100)));
                    let res : String = execute_python_module(0, index as u64, &x);

                    println!("worker {}:\tstage 2:\tdata {}", index, res);
                    res
                }, |y| "".to_owned())
                .sarge_exchange()
                .sarge_map(30000000, 0.0, 10, move |x| {
                    let mut nth = 0;

                    let mut rng = rand::thread_rng();
                    let roll : f32 = rng.gen();

                    if roll < 0.2 {
                        nth = 2;
                    }

                    let obj = x.split(":").nth(nth).unwrap().to_owned();
                    
                    println!("worker {}:\tstage 3:\tdata {}", index, obj);
                    obj
                }, |y| y)
                .sarge_end(move |x| {
                    println!("worker {}:\tselected {}", index, x);
                })
                .probe()
        );

        input.advance_to(1);
        for round in 1..1001 {
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