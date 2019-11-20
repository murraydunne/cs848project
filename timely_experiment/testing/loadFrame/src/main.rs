
// Testing loading a video frame by frame using rust-opencv binding  

use opencv::prelude::*;
use opencv::core;
use opencv::highgui;
// use opencv::imgproc;
use opencv::videoio;

fn main() {
    println!("Hello, world!");

    let window = "video capture";
    highgui::named_window(window, 1).unwrap();
    let mut cam = videoio::VideoCapture::new_from_file_with_backend("../../video-data/policeChase.mp4",videoio::CAP_ANY).unwrap();
    let opened = videoio::VideoCapture::is_opened(&cam).unwrap();
    if !opened {
        panic!("Unable to open default camera!");
    }
    loop {
        let mut currentframe = 0;
        let mut frame = core::Mat::default().unwrap();
        cam.read(&mut frame);
        highgui::imshow(window, &frame);
        highgui::wait_key(0);
    }
}