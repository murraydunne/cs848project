use timely::dataflow::operators::*;
use timely::dataflow::channels::pact::Pipeline;
use std::{thread, time};
use pyo3::{prelude::*, types::{IntoPyDict, PyModule}};
use std::boxed::Box;

#[macro_use]
extern crate lazy_static;


fn execute_python_module(param: u64, worker: u64) -> f64 {
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

    static ref PYMODULE : &'static pyo3::types::module::PyModule =   PyModule::from_code(*PY, "
import keras

vgg_model = keras.applications.vgg16.VGG16(weights='imagenet')
print(\"Creation context\")

def main(inp):
    return 45.6
            ", "pymodule.py", "pymodule").map_err(|e| e.print_and_set_sys_last_vars(*PY)).unwrap();

    }
    

    println!("{:?} - We have a python.", worker);
    


    println!("{:?} - We have a module.", worker);

    let something = PYMODULE.call1("main", (param,));

    println!("{:?} - We called it!", worker);

    let pyresult: f64 = (*something.unwrap()).extract().unwrap();
    return pyresult;
}

use opencv::prelude::*;
use opencv::core;
use opencv::videoio;
use opencv::highgui;

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
                    //.exchange(|x: &(u64, u64)| (*x).1 + 5)
                    .exchange(|x: &(u64, u64)| 5)
                    //.map(|x| x * 3)
                    /*.unary(Pipeline, "WithState", |_, _| {
                        let mut vector : Vec<(u64, u64)> = Vec::new();
                        let pymodule = PyModule::from_code(Python::acquire_gil().python(), "
#import keras

#vgg_model = keras.applications.vgg16.VGG16(weights='imagenet')

def main(inp):
    return 45.6
                        ", "pymodule.py", "pymodule");

                        move |input, output| {
                            while let Some((time, data)) = input.next() {
                                data.swap(&mut vector);
                                let mut session = output.session(&time);
                                for datum in vector.drain(..) {
                                    let val : f64 = (*pymodule.as_ref().unwrap().call1("main", (datum.0,)).unwrap()).extract().unwrap();

                                    println!("node {:?} pipeline {:?} frame {:?} - second (val {:?})", 
                                            index, datum.1, datum.0, val);
                                    session.give(datum);
                                }
                            }
                        }
                    })*/
                    .inspect(move |x: &(u64, u64)| println!("node {:?} pipeline {:?} frame {:?} - final ({:?})", 
                                                            index, (*x).1, (*x).0, execute_python_module((*x).0, index as u64)));
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