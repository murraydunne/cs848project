#include "stdint.h"
#include "common.h"
#include <string>
#include "common_opencv.h"
using namespace cv;
#include "types.h"
#include "return_types.h"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/viz/types.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/viz/widgets.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/viz.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/viz/viz3d.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/viz/vizcore.hpp"

extern "C" {

// parsed: cv::Vec3b
// as:     cv::Vec3b (function)
// Return value: Primitive(void)
cv_return_value_void cv_Vec3b_const() {
    try {
        cv::Vec3b();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::computeNormals
// as:     cv::viz::computeNormals (function)
// Arg ARG cv::viz::Mesh (boxed) mesh= cv::viz::Mesh (boxed) = 
// Arg ARG cv::_OutputArray (boxed) normals= cv::_OutputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_computeNormals_Mesh__OutputArray(void* mesh, void* normals) {
    try {
        cv::viz::computeNormals(*reinterpret_cast<const cv::viz::Mesh*>(mesh), *reinterpret_cast<cv::_OutputArray*>(normals));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::getWindowByName
// as:     cv::viz::getWindowByName (function)
// Arg ARG string window_name= string = 
// Return value: cv::viz::Viz3d (boxed)
cv_return_value_void_X cv_viz_getWindowByName_String(const char* window_name) {
    try {
        cv::viz::Viz3d ret = cv::viz::getWindowByName(String(window_name));
        return { Error::Code::StsOk, NULL, new cv::viz::Viz3d(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::imshow
// as:     cv::viz::imshow (function)
// Arg ARG string window_name= string = 
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = Size(-1, -1)
// Return value: cv::viz::Viz3d (boxed)
cv_return_value_void_X cv_viz_imshow_String__InputArray_Size(const char* window_name, void* image, SizeWrapper window_size) {
    try {
        cv::viz::Viz3d ret = cv::viz::imshow(String(window_name), *reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL, new cv::viz::Viz3d(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::isNan
// as:     cv::viz::isNan (function)
// Arg ARG Primitive(double) x= Primitive(double) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_viz_isNan_double(double x) {
    try {
        bool ret = cv::viz::isNan(x);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::viz::isNan
// as:     cv::viz::isNan (function)
// Arg ARG Primitive(float) x= Primitive(float) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_viz_isNan_float(float x) {
    try {
        bool ret = cv::viz::isNan(x);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::viz::readCloud
// as:     cv::viz::readCloud (function)
// Arg ARG string file= string = 
// Arg ARG cv::_OutputArray (boxed) colors= cv::_OutputArray (boxed) = noArray()
// Arg ARG cv::_OutputArray (boxed) normals= cv::_OutputArray (boxed) = noArray()
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_viz_readCloud_String__OutputArray__OutputArray(const char* file, void* colors, void* normals) {
    try {
        cv::Mat ret = cv::viz::readCloud(String(file), *reinterpret_cast<cv::_OutputArray*>(colors), *reinterpret_cast<cv::_OutputArray*>(normals));
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::readMesh
// as:     cv::viz::readMesh (function)
// Arg ARG string file= string = 
// Return value: cv::viz::Mesh (boxed)
cv_return_value_void_X cv_viz_readMesh_String(const char* file) {
    try {
        cv::viz::Mesh ret = cv::viz::readMesh(String(file));
        return { Error::Code::StsOk, NULL, new cv::viz::Mesh(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::readTrajectory
// as:     cv::viz::readTrajectory (function)
// Arg ARG cv::_OutputArray (boxed) traj= cv::_OutputArray (boxed) = 
// Arg ARG string files_format= string = "pose%05d.xml"
// Arg ARG Primitive(int) start= Primitive(int) = 0
// Arg ARG Primitive(int) end= Primitive(int) = INT_MAX
// Arg ARG string tag= string = "pose"
// Return value: Primitive(void)
cv_return_value_void cv_viz_readTrajectory__OutputArray_String_int_int_String(void* traj, const char* files_format, int start, int end, const char* tag) {
    try {
        cv::viz::readTrajectory(*reinterpret_cast<cv::_OutputArray*>(traj), String(files_format), start, end, String(tag));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::unregisterAllWindows
// as:     cv::viz::unregisterAllWindows (function)
// Return value: Primitive(void)
cv_return_value_void cv_viz_unregisterAllWindows() {
    try {
        cv::viz::unregisterAllWindows();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::writeCloud
// as:     cv::viz::writeCloud (function)
// Arg ARG string file= string = 
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) colors= cv::_InputArray (boxed) = noArray()
// Arg ARG cv::_InputArray (boxed) normals= cv::_InputArray (boxed) = noArray()
// Arg ARG Primitive(bool) binary= Primitive(bool) = false
// Return value: Primitive(void)
cv_return_value_void cv_viz_writeCloud_String__InputArray__InputArray__InputArray_bool(const char* file, void* cloud, void* colors, void* normals, bool binary) {
    try {
        cv::viz::writeCloud(String(file), *reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::_InputArray*>(colors), *reinterpret_cast<const cv::_InputArray*>(normals), binary);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::writeTrajectory
// as:     cv::viz::writeTrajectory (function)
// Arg ARG cv::_InputArray (boxed) traj= cv::_InputArray (boxed) = 
// Arg ARG string files_format= string = "pose%05d.xml"
// Arg ARG Primitive(int) start= Primitive(int) = 0
// Arg ARG string tag= string = "pose"
// Return value: Primitive(void)
cv_return_value_void cv_viz_writeTrajectory__InputArray_String_int_String(void* traj, const char* files_format, int start, const char* tag) {
    try {
        cv::viz::writeTrajectory(*reinterpret_cast<const cv::_InputArray*>(traj), String(files_format), start, String(tag));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::Camera
void cv_Camera_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Camera*>(instance);
}
// parsed: cv::viz::Camera::Camera
// as:     cv::viz::Camera::Camera (constructor) cv::viz::Camera . new
// Arg ARG Primitive(double) fx= Primitive(double) = 
// Arg ARG Primitive(double) fy= Primitive(double) = 
// Arg ARG Primitive(double) cx= Primitive(double) = 
// Arg ARG Primitive(double) cy= Primitive(double) = 
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = 
// Return value: cv::viz::Camera (boxed)
cv_return_value_void_X cv_viz_Camera_Camera_double_double_double_double_Size(double fx, double fy, double cx, double cy, SizeWrapper window_size) {
    try {
        cv::viz::Camera* ret = new cv::viz::Camera(fx, fy, cx, cy, *reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Camera::Camera
// as:     cv::viz::Camera::Camera (constructor) cv::viz::Camera . new
// Arg ARG cv::Vec2d (simple) fov= cv::Vec2d (simple) = 
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = 
// Return value: cv::viz::Camera (boxed)
cv_return_value_void_X cv_viz_Camera_Camera_Vec2d_Size(Vec2dWrapper fov, SizeWrapper window_size) {
    try {
        cv::viz::Camera* ret = new cv::viz::Camera(*reinterpret_cast<const cv::Vec2d*>(&fov), *reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Camera::getClip
// as:     cv::viz::Camera::getClip (method) cv::viz::Camera . getClip
// Return value: cv::Vec2d (simple)
cv_return_value_Vec2dWrapper cv_viz_Camera_getClip_const(void* instance) {
    try {
        cv::Vec2d ret = reinterpret_cast<cv::viz::Camera*>(instance)->getClip();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<Vec2dWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_Vec2dWrapper)
}

// parsed: cv::viz::Camera::setClip
// as:     cv::viz::Camera::setClip (method) cv::viz::Camera . setClip
// Arg ARG cv::Vec2d (simple) clip= cv::Vec2d (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Camera_setClip_Vec2d(void* instance, Vec2dWrapper clip) {
    try {
        reinterpret_cast<cv::viz::Camera*>(instance)->setClip(*reinterpret_cast<const cv::Vec2d*>(&clip));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Camera::getWindowSize
// as:     cv::viz::Camera::getWindowSize (method) cv::viz::Camera . getWindowSize
// Return value: cv::Size (simple)
cv_return_value_SizeWrapper cv_viz_Camera_getWindowSize_const(void* instance) {
    try {
        cv::Size ret = reinterpret_cast<cv::viz::Camera*>(instance)->getWindowSize();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<SizeWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_SizeWrapper)
}

// parsed: cv::viz::Camera::setWindowSize
// as:     cv::viz::Camera::setWindowSize (method) cv::viz::Camera . setWindowSize
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Camera_setWindowSize_Size(void* instance, SizeWrapper window_size) {
    try {
        reinterpret_cast<cv::viz::Camera*>(instance)->setWindowSize(*reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Camera::getFov
// as:     cv::viz::Camera::getFov (method) cv::viz::Camera . getFov
// Return value: cv::Vec2d (simple)
cv_return_value_Vec2dWrapper cv_viz_Camera_getFov_const(void* instance) {
    try {
        cv::Vec2d ret = reinterpret_cast<cv::viz::Camera*>(instance)->getFov();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<Vec2dWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_Vec2dWrapper)
}

// parsed: cv::viz::Camera::setFov
// as:     cv::viz::Camera::setFov (method) cv::viz::Camera . setFov
// Arg ARG cv::Vec2d (simple) fov= cv::Vec2d (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Camera_setFov_Vec2d(void* instance, Vec2dWrapper fov) {
    try {
        reinterpret_cast<cv::viz::Camera*>(instance)->setFov(*reinterpret_cast<const cv::Vec2d*>(&fov));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Camera::getPrincipalPoint
// as:     cv::viz::Camera::getPrincipalPoint (method) cv::viz::Camera . getPrincipalPoint
// Return value: cv::Vec2d (simple)
cv_return_value_Vec2dWrapper cv_viz_Camera_getPrincipalPoint_const(void* instance) {
    try {
        cv::Vec2d ret = reinterpret_cast<cv::viz::Camera*>(instance)->getPrincipalPoint();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<Vec2dWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_Vec2dWrapper)
}

// parsed: cv::viz::Camera::getFocalLength
// as:     cv::viz::Camera::getFocalLength (method) cv::viz::Camera . getFocalLength
// Return value: cv::Vec2d (simple)
cv_return_value_Vec2dWrapper cv_viz_Camera_getFocalLength_const(void* instance) {
    try {
        cv::Vec2d ret = reinterpret_cast<cv::viz::Camera*>(instance)->getFocalLength();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<Vec2dWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_Vec2dWrapper)
}

// parsed: cv::viz::Camera::KinectCamera
// as:     cv::viz::Camera::KinectCamera (method) cv::viz::Camera . KinectCamera
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = 
// Return value: cv::viz::Camera (boxed)
cv_return_value_void_X cv_viz_Camera_KinectCamera_Size(SizeWrapper window_size) {
    try {
        cv::viz::Camera ret = cv::viz::Camera::KinectCamera(*reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL, new cv::viz::Camera(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::Color
void cv_Color_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Color*>(instance);
}
// parsed: cv::viz::Color::Color
// as:     cv::viz::Color::Color (constructor) cv::viz::Color . default
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_Color() {
    try {
        cv::viz::Color* ret = new cv::viz::Color();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::Color
// as:     cv::viz::Color::Color (constructor) cv::viz::Color . new
// Arg ARG Primitive(double) gray= Primitive(double) = 
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_Color_double(double gray) {
    try {
        cv::viz::Color* ret = new cv::viz::Color(gray);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::Color
// as:     cv::viz::Color::Color (constructor) cv::viz::Color . new
// Arg ARG Primitive(double) blue= Primitive(double) = 
// Arg ARG Primitive(double) green= Primitive(double) = 
// Arg ARG Primitive(double) red= Primitive(double) = 
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_Color_double_double_double(double blue, double green, double red) {
    try {
        cv::viz::Color* ret = new cv::viz::Color(blue, green, red);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::Color
// as:     cv::viz::Color::Color (constructor) cv::viz::Color . new
// Arg ARG cv::Scalar (simple) color= cv::Scalar (simple) = 
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_Color_Scalar(ScalarWrapper color) {
    try {
        cv::viz::Color* ret = new cv::viz::Color(*reinterpret_cast<const cv::Scalar*>(&color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::operator Vec3b
// as:     cv::viz::Color::operator Vec3b (convertor method) cv::viz::Color . operator Vec3b
// Return value: cv::Vec3b (simple)
cv_return_value_Vec3bWrapper cv_viz_Color_operator_Vec3b_const(void* instance) {
    try {
        cv::Vec3b ret = reinterpret_cast<cv::viz::Color*>(instance)->operator Vec3b();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<Vec3bWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_Vec3bWrapper)
}

// parsed: cv::viz::Color::black
// as:     cv::viz::Color::black (method) cv::viz::Color . black
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_black() {
    try {
        cv::viz::Color ret = cv::viz::Color::black();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::blue
// as:     cv::viz::Color::blue (method) cv::viz::Color . blue
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_blue() {
    try {
        cv::viz::Color ret = cv::viz::Color::blue();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::green
// as:     cv::viz::Color::green (method) cv::viz::Color . green
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_green() {
    try {
        cv::viz::Color ret = cv::viz::Color::green();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::cyan
// as:     cv::viz::Color::cyan (method) cv::viz::Color . cyan
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_cyan() {
    try {
        cv::viz::Color ret = cv::viz::Color::cyan();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::red
// as:     cv::viz::Color::red (method) cv::viz::Color . red
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_red() {
    try {
        cv::viz::Color ret = cv::viz::Color::red();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::magenta
// as:     cv::viz::Color::magenta (method) cv::viz::Color . magenta
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_magenta() {
    try {
        cv::viz::Color ret = cv::viz::Color::magenta();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::yellow
// as:     cv::viz::Color::yellow (method) cv::viz::Color . yellow
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_yellow() {
    try {
        cv::viz::Color ret = cv::viz::Color::yellow();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::white
// as:     cv::viz::Color::white (method) cv::viz::Color . white
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_white() {
    try {
        cv::viz::Color ret = cv::viz::Color::white();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::gray
// as:     cv::viz::Color::gray (method) cv::viz::Color . gray
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_gray() {
    try {
        cv::viz::Color ret = cv::viz::Color::gray();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::mlab
// as:     cv::viz::Color::mlab (method) cv::viz::Color . mlab
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_mlab() {
    try {
        cv::viz::Color ret = cv::viz::Color::mlab();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::navy
// as:     cv::viz::Color::navy (method) cv::viz::Color . navy
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_navy() {
    try {
        cv::viz::Color ret = cv::viz::Color::navy();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::olive
// as:     cv::viz::Color::olive (method) cv::viz::Color . olive
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_olive() {
    try {
        cv::viz::Color ret = cv::viz::Color::olive();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::maroon
// as:     cv::viz::Color::maroon (method) cv::viz::Color . maroon
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_maroon() {
    try {
        cv::viz::Color ret = cv::viz::Color::maroon();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::teal
// as:     cv::viz::Color::teal (method) cv::viz::Color . teal
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_teal() {
    try {
        cv::viz::Color ret = cv::viz::Color::teal();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::rose
// as:     cv::viz::Color::rose (method) cv::viz::Color . rose
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_rose() {
    try {
        cv::viz::Color ret = cv::viz::Color::rose();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::azure
// as:     cv::viz::Color::azure (method) cv::viz::Color . azure
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_azure() {
    try {
        cv::viz::Color ret = cv::viz::Color::azure();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::lime
// as:     cv::viz::Color::lime (method) cv::viz::Color . lime
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_lime() {
    try {
        cv::viz::Color ret = cv::viz::Color::lime();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::gold
// as:     cv::viz::Color::gold (method) cv::viz::Color . gold
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_gold() {
    try {
        cv::viz::Color ret = cv::viz::Color::gold();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::brown
// as:     cv::viz::Color::brown (method) cv::viz::Color . brown
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_brown() {
    try {
        cv::viz::Color ret = cv::viz::Color::brown();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::orange
// as:     cv::viz::Color::orange (method) cv::viz::Color . orange
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_orange() {
    try {
        cv::viz::Color ret = cv::viz::Color::orange();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::chartreuse
// as:     cv::viz::Color::chartreuse (method) cv::viz::Color . chartreuse
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_chartreuse() {
    try {
        cv::viz::Color ret = cv::viz::Color::chartreuse();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::orange_red
// as:     cv::viz::Color::orange_red (method) cv::viz::Color . orange_red
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_orange_red() {
    try {
        cv::viz::Color ret = cv::viz::Color::orange_red();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::purple
// as:     cv::viz::Color::purple (method) cv::viz::Color . purple
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_purple() {
    try {
        cv::viz::Color ret = cv::viz::Color::purple();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::indigo
// as:     cv::viz::Color::indigo (method) cv::viz::Color . indigo
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_indigo() {
    try {
        cv::viz::Color ret = cv::viz::Color::indigo();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::pink
// as:     cv::viz::Color::pink (method) cv::viz::Color . pink
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_pink() {
    try {
        cv::viz::Color ret = cv::viz::Color::pink();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::cherry
// as:     cv::viz::Color::cherry (method) cv::viz::Color . cherry
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_cherry() {
    try {
        cv::viz::Color ret = cv::viz::Color::cherry();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::bluberry
// as:     cv::viz::Color::bluberry (method) cv::viz::Color . bluberry
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_bluberry() {
    try {
        cv::viz::Color ret = cv::viz::Color::bluberry();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::raspberry
// as:     cv::viz::Color::raspberry (method) cv::viz::Color . raspberry
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_raspberry() {
    try {
        cv::viz::Color ret = cv::viz::Color::raspberry();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::silver
// as:     cv::viz::Color::silver (method) cv::viz::Color . silver
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_silver() {
    try {
        cv::viz::Color ret = cv::viz::Color::silver();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::violet
// as:     cv::viz::Color::violet (method) cv::viz::Color . violet
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_violet() {
    try {
        cv::viz::Color ret = cv::viz::Color::violet();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::apricot
// as:     cv::viz::Color::apricot (method) cv::viz::Color . apricot
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_apricot() {
    try {
        cv::viz::Color ret = cv::viz::Color::apricot();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::turquoise
// as:     cv::viz::Color::turquoise (method) cv::viz::Color . turquoise
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_turquoise() {
    try {
        cv::viz::Color ret = cv::viz::Color::turquoise();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::celestial_blue
// as:     cv::viz::Color::celestial_blue (method) cv::viz::Color . celestial_blue
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_celestial_blue() {
    try {
        cv::viz::Color ret = cv::viz::Color::celestial_blue();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::amethyst
// as:     cv::viz::Color::amethyst (method) cv::viz::Color . amethyst
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_amethyst() {
    try {
        cv::viz::Color ret = cv::viz::Color::amethyst();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Color::not_set
// as:     cv::viz::Color::not_set (method) cv::viz::Color . not_set
// Return value: cv::viz::Color (boxed)
cv_return_value_void_X cv_viz_Color_not_set() {
    try {
        cv::viz::Color ret = cv::viz::Color::not_set();
        return { Error::Code::StsOk, NULL, new cv::viz::Color(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::KeyboardEvent
void cv_KeyboardEvent_delete(void* instance) {
    delete reinterpret_cast<cv::viz::KeyboardEvent*>(instance);
}
// boxed class: cv::viz::Mesh
void cv_Mesh_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Mesh*>(instance);
}
// parsed: cv::viz::Mesh::load
// as:     cv::viz::Mesh::load (method) cv::viz::Mesh . load
// Arg ARG string file= string = 
// Arg ARG Primitive(int) type= Primitive(int) = LOAD_PLY
// Return value: cv::viz::Mesh (boxed)
cv_return_value_void_X cv_viz_Mesh_load_String_int(const char* file, int type) {
    try {
        cv::viz::Mesh ret = cv::viz::Mesh::load(String(file), type);
        return { Error::Code::StsOk, NULL, new cv::viz::Mesh(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::MouseEvent
void cv_MouseEvent_delete(void* instance) {
    delete reinterpret_cast<cv::viz::MouseEvent*>(instance);
}
// boxed class: cv::viz::Viz3d
void cv_Viz3d_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Viz3d*>(instance);
}
// parsed: cv::viz::Viz3d::Viz3d
// as:     cv::viz::Viz3d::Viz3d (constructor) cv::viz::Viz3d . new
// Arg ARG string window_name= string = String()
// Return value: cv::viz::Viz3d (boxed)
cv_return_value_void_X cv_viz_Viz3d_Viz3d_String(const char* window_name) {
    try {
        cv::viz::Viz3d* ret = new cv::viz::Viz3d(String(window_name));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Viz3d::Viz3d
// as:     cv::viz::Viz3d::Viz3d (constructor) cv::viz::Viz3d . copy
// Arg ARG cv::viz::Viz3d (boxed) unnamed_arg= cv::viz::Viz3d (boxed) = 
// Return value: cv::viz::Viz3d (boxed)
cv_return_value_void_X cv_viz_Viz3d_Viz3d_Viz3d(void* unnamed_arg) {
    try {
        cv::viz::Viz3d* ret = new cv::viz::Viz3d(*reinterpret_cast<const cv::viz::Viz3d*>(unnamed_arg));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Viz3d::removeWidget
// as:     cv::viz::Viz3d::removeWidget (method) cv::viz::Viz3d . removeWidget
// Arg ARG string id= string = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_removeWidget_String(void* instance, const char* id) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->removeWidget(String(id));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::getWidget
// as:     cv::viz::Viz3d::getWidget (method) cv::viz::Viz3d . getWidget
// Arg ARG string id= string = 
// Return value: cv::viz::Widget (boxed)
cv_return_value_void_X cv_viz_Viz3d_getWidget_const_String(void* instance, const char* id) {
    try {
        cv::viz::Widget ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->getWidget(String(id));
        return { Error::Code::StsOk, NULL, new cv::viz::Widget(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Viz3d::removeAllWidgets
// as:     cv::viz::Viz3d::removeAllWidgets (method) cv::viz::Viz3d . removeAllWidgets
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_removeAllWidgets(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->removeAllWidgets();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::showImage
// as:     cv::viz::Viz3d::showImage (method) cv::viz::Viz3d . showImage
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = Size(-1, -1)
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_showImage__InputArray_Size(void* instance, void* image, SizeWrapper window_size) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->showImage(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setCamera
// as:     cv::viz::Viz3d::setCamera (method) cv::viz::Viz3d . setCamera
// Arg ARG cv::viz::Camera (boxed) camera= cv::viz::Camera (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setCamera_Camera(void* instance, void* camera) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setCamera(*reinterpret_cast<const cv::viz::Camera*>(camera));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::getCamera
// as:     cv::viz::Viz3d::getCamera (method) cv::viz::Viz3d . getCamera
// Return value: cv::viz::Camera (boxed)
cv_return_value_void_X cv_viz_Viz3d_getCamera_const(void* instance) {
    try {
        cv::viz::Camera ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->getCamera();
        return { Error::Code::StsOk, NULL, new cv::viz::Camera(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Viz3d::resetCameraViewpoint
// as:     cv::viz::Viz3d::resetCameraViewpoint (method) cv::viz::Viz3d . resetCameraViewpoint
// Arg ARG string id= string = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_resetCameraViewpoint_String(void* instance, const char* id) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->resetCameraViewpoint(String(id));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::resetCamera
// as:     cv::viz::Viz3d::resetCamera (method) cv::viz::Viz3d . resetCamera
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_resetCamera(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->resetCamera();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::convertToWindowCoordinates
// as:     cv::viz::Viz3d::convertToWindowCoordinates (method) cv::viz::Viz3d . convertToWindowCoordinates
// Arg ARG cv::Point3d (simple) pt= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) window_coord= cv::Point3d (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_convertToWindowCoordinates_Point3d_Point3d(void* instance, Point3dWrapper pt, Point3dWrapper& window_coord) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->convertToWindowCoordinates(*reinterpret_cast<const cv::Point3d*>(&pt), *reinterpret_cast<cv::Point3d*>(&window_coord));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::converTo3DRay
// as:     cv::viz::Viz3d::converTo3DRay (method) cv::viz::Viz3d . converTo3DRay
// Arg ARG cv::Point3d (simple) window_coord= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) origin= cv::Point3d (simple) = 
// Arg ARG cv::Vec3d (simple) direction= cv::Vec3d (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_converTo3DRay_Point3d_Point3d_Vec3d(void* instance, Point3dWrapper window_coord, Point3dWrapper& origin, Vec3dWrapper& direction) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->converTo3DRay(*reinterpret_cast<const cv::Point3d*>(&window_coord), *reinterpret_cast<cv::Point3d*>(&origin), *reinterpret_cast<cv::Vec3d*>(&direction));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::getWindowSize
// as:     cv::viz::Viz3d::getWindowSize (method) cv::viz::Viz3d . getWindowSize
// Return value: cv::Size (simple)
cv_return_value_SizeWrapper cv_viz_Viz3d_getWindowSize_const(void* instance) {
    try {
        cv::Size ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->getWindowSize();
        return { Error::Code::StsOk, NULL, *reinterpret_cast<SizeWrapper*>(&ret) };
    } CVRS_CATCH(cv_return_value_SizeWrapper)
}

// parsed: cv::viz::Viz3d::setWindowSize
// as:     cv::viz::Viz3d::setWindowSize (method) cv::viz::Viz3d . setWindowSize
// Arg ARG cv::Size (simple) window_size= cv::Size (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setWindowSize_Size(void* instance, SizeWrapper window_size) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setWindowSize(*reinterpret_cast<const cv::Size*>(&window_size));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::getWindowName
// as:     cv::viz::Viz3d::getWindowName (method) cv::viz::Viz3d . getWindowName
// Return value: string
cv_return_value_char_X cv_viz_Viz3d_getWindowName_const(void* instance) {
    try {
        String ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->getWindowName();
        return { Error::Code::StsOk, NULL, strdup(ret.c_str()) };
    } CVRS_CATCH(cv_return_value_char_X)
}

// parsed: cv::viz::Viz3d::getScreenshot
// as:     cv::viz::Viz3d::getScreenshot (method) cv::viz::Viz3d . getScreenshot
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_viz_Viz3d_getScreenshot_const(void* instance) {
    try {
        cv::Mat ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->getScreenshot();
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Viz3d::saveScreenshot
// as:     cv::viz::Viz3d::saveScreenshot (method) cv::viz::Viz3d . saveScreenshot
// Arg ARG string file= string = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_saveScreenshot_String(void* instance, const char* file) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->saveScreenshot(String(file));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setWindowPosition
// as:     cv::viz::Viz3d::setWindowPosition (method) cv::viz::Viz3d . setWindowPosition
// Arg ARG cv::Point (simple) window_position= cv::Point (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setWindowPosition_Point(void* instance, PointWrapper window_position) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setWindowPosition(*reinterpret_cast<const cv::Point*>(&window_position));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setFullScreen
// as:     cv::viz::Viz3d::setFullScreen (method) cv::viz::Viz3d . setFullScreen
// Arg ARG Primitive(bool) mode= Primitive(bool) = true
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setFullScreen_bool(void* instance, bool mode) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setFullScreen(mode);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setBackgroundColor
// as:     cv::viz::Viz3d::setBackgroundColor (method) cv::viz::Viz3d . setBackgroundColor
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::black()
// Arg ARG cv::viz::Color (boxed) color2= cv::viz::Color (boxed) = Color::not_set()
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setBackgroundColor_Color_Color(void* instance, void* color, void* color2) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setBackgroundColor(*reinterpret_cast<const cv::viz::Color*>(color), *reinterpret_cast<const cv::viz::Color*>(color2));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setBackgroundTexture
// as:     cv::viz::Viz3d::setBackgroundTexture (method) cv::viz::Viz3d . setBackgroundTexture
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = noArray()
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setBackgroundTexture__InputArray(void* instance, void* image) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setBackgroundTexture(*reinterpret_cast<const cv::_InputArray*>(image));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setBackgroundMeshLab
// as:     cv::viz::Viz3d::setBackgroundMeshLab (method) cv::viz::Viz3d . setBackgroundMeshLab
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setBackgroundMeshLab(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setBackgroundMeshLab();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::spin
// as:     cv::viz::Viz3d::spin (method) cv::viz::Viz3d . spin
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_spin(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->spin();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::spinOnce
// as:     cv::viz::Viz3d::spinOnce (method) cv::viz::Viz3d . spinOnce
// Arg ARG Primitive(int) time= Primitive(int) = 1
// Arg ARG Primitive(bool) force_redraw= Primitive(bool) = false
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_spinOnce_int_bool(void* instance, int time, bool force_redraw) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->spinOnce(time, force_redraw);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setOffScreenRendering
// as:     cv::viz::Viz3d::setOffScreenRendering (method) cv::viz::Viz3d . setOffScreenRendering
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setOffScreenRendering(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setOffScreenRendering();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::removeAllLights
// as:     cv::viz::Viz3d::removeAllLights (method) cv::viz::Viz3d . removeAllLights
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_removeAllLights(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->removeAllLights();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::addLight
// as:     cv::viz::Viz3d::addLight (method) cv::viz::Viz3d . addLight
// Arg ARG cv::Vec3d (simple) position= cv::Vec3d (simple) = 
// Arg ARG cv::Vec3d (simple) focalPoint= cv::Vec3d (simple) = Vec3d(0, 0, 0)
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Arg ARG cv::viz::Color (boxed) diffuseColor= cv::viz::Color (boxed) = Color::white()
// Arg ARG cv::viz::Color (boxed) ambientColor= cv::viz::Color (boxed) = Color::black()
// Arg ARG cv::viz::Color (boxed) specularColor= cv::viz::Color (boxed) = Color::white()
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_addLight_Vec3d_Vec3d_Color_Color_Color_Color(void* instance, Vec3dWrapper position, Vec3dWrapper focalPoint, void* color, void* diffuseColor, void* ambientColor, void* specularColor) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->addLight(*reinterpret_cast<const cv::Vec3d*>(&position), *reinterpret_cast<const cv::Vec3d*>(&focalPoint), *reinterpret_cast<const cv::viz::Color*>(color), *reinterpret_cast<const cv::viz::Color*>(diffuseColor), *reinterpret_cast<const cv::viz::Color*>(ambientColor), *reinterpret_cast<const cv::viz::Color*>(specularColor));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::wasStopped
// as:     cv::viz::Viz3d::wasStopped (method) cv::viz::Viz3d . wasStopped
// Return value: Primitive(bool)
cv_return_value_bool cv_viz_Viz3d_wasStopped_const(void* instance) {
    try {
        bool ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->wasStopped();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::viz::Viz3d::close
// as:     cv::viz::Viz3d::close (method) cv::viz::Viz3d . close
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_close(void* instance) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->close();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setRenderingProperty
// as:     cv::viz::Viz3d::setRenderingProperty (method) cv::viz::Viz3d . setRenderingProperty
// Arg ARG string id= string = 
// Arg ARG Primitive(int) property= Primitive(int) = 
// Arg ARG Primitive(double) value= Primitive(double) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setRenderingProperty_String_int_double(void* instance, const char* id, int property, double value) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setRenderingProperty(String(id), property, value);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::getRenderingProperty
// as:     cv::viz::Viz3d::getRenderingProperty (method) cv::viz::Viz3d . getRenderingProperty
// Arg ARG string id= string = 
// Arg ARG Primitive(int) property= Primitive(int) = 
// Return value: Primitive(double)
cv_return_value_double cv_viz_Viz3d_getRenderingProperty_String_int(void* instance, const char* id, int property) {
    try {
        double ret = reinterpret_cast<cv::viz::Viz3d*>(instance)->getRenderingProperty(String(id), property);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_double)
}

// parsed: cv::viz::Viz3d::setRepresentation
// as:     cv::viz::Viz3d::setRepresentation (method) cv::viz::Viz3d . setRepresentation
// Arg ARG Primitive(int) representation= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setRepresentation_int(void* instance, int representation) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setRepresentation(representation);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Viz3d::setGlobalWarnings
// as:     cv::viz::Viz3d::setGlobalWarnings (method) cv::viz::Viz3d . setGlobalWarnings
// Arg ARG Primitive(bool) enabled= Primitive(bool) = false
// Return value: Primitive(void)
cv_return_value_void cv_viz_Viz3d_setGlobalWarnings_bool(void* instance, bool enabled) {
    try {
        reinterpret_cast<cv::viz::Viz3d*>(instance)->setGlobalWarnings(enabled);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::WArrow
void cv_WArrow_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WArrow*>(instance);
}
// parsed: cv::viz::WArrow::WArrow
// as:     cv::viz::WArrow::WArrow (constructor) cv::viz::WArrow . new
// Arg ARG cv::Point3d (simple) pt1= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) pt2= cv::Point3d (simple) = 
// Arg ARG Primitive(double) thickness= Primitive(double) = 0.03
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WArrow (boxed)
cv_return_value_void_X cv_viz_WArrow_WArrow_Point3d_Point3d_double_Color(Point3dWrapper pt1, Point3dWrapper pt2, double thickness, void* color) {
    try {
        cv::viz::WArrow* ret = new cv::viz::WArrow(*reinterpret_cast<const cv::Point3d*>(&pt1), *reinterpret_cast<const cv::Point3d*>(&pt2), thickness, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCameraPosition
void cv_WCameraPosition_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCameraPosition*>(instance);
}
// parsed: cv::viz::WCameraPosition::WCameraPosition
// as:     cv::viz::WCameraPosition::WCameraPosition (constructor) cv::viz::WCameraPosition . new
// Arg ARG Primitive(double) scale= Primitive(double) = 1.0
// Return value: cv::viz::WCameraPosition (boxed)
cv_return_value_void_X cv_viz_WCameraPosition_WCameraPosition_double(double scale) {
    try {
        cv::viz::WCameraPosition* ret = new cv::viz::WCameraPosition(scale);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCameraPosition::WCameraPosition
// as:     cv::viz::WCameraPosition::WCameraPosition (constructor) cv::viz::WCameraPosition . new
// Arg ARG cv::Vec2d (simple) fov= cv::Vec2d (simple) = 
// Arg ARG Primitive(double) scale= Primitive(double) = 1.0
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCameraPosition (boxed)
cv_return_value_void_X cv_viz_WCameraPosition_WCameraPosition_Vec2d_double_Color(Vec2dWrapper fov, double scale, void* color) {
    try {
        cv::viz::WCameraPosition* ret = new cv::viz::WCameraPosition(*reinterpret_cast<const cv::Vec2d*>(&fov), scale, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCameraPosition::WCameraPosition
// as:     cv::viz::WCameraPosition::WCameraPosition (constructor) cv::viz::WCameraPosition . new
// Arg ARG cv::Vec2d (simple) fov= cv::Vec2d (simple) = 
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG Primitive(double) scale= Primitive(double) = 1.0
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCameraPosition (boxed)
cv_return_value_void_X cv_viz_WCameraPosition_WCameraPosition_Vec2d__InputArray_double_Color(Vec2dWrapper fov, void* image, double scale, void* color) {
    try {
        cv::viz::WCameraPosition* ret = new cv::viz::WCameraPosition(*reinterpret_cast<const cv::Vec2d*>(&fov), *reinterpret_cast<const cv::_InputArray*>(image), scale, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCircle
void cv_WCircle_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCircle*>(instance);
}
// parsed: cv::viz::WCircle::WCircle
// as:     cv::viz::WCircle::WCircle (constructor) cv::viz::WCircle . new
// Arg ARG Primitive(double) radius= Primitive(double) = 
// Arg ARG Primitive(double) thickness= Primitive(double) = 0.01
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCircle (boxed)
cv_return_value_void_X cv_viz_WCircle_WCircle_double_double_Color(double radius, double thickness, void* color) {
    try {
        cv::viz::WCircle* ret = new cv::viz::WCircle(radius, thickness, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCircle::WCircle
// as:     cv::viz::WCircle::WCircle (constructor) cv::viz::WCircle . new
// Arg ARG Primitive(double) radius= Primitive(double) = 
// Arg ARG cv::Point3d (simple) center= cv::Point3d (simple) = 
// Arg ARG cv::Vec3d (simple) normal= cv::Vec3d (simple) = 
// Arg ARG Primitive(double) thickness= Primitive(double) = 0.01
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCircle (boxed)
cv_return_value_void_X cv_viz_WCircle_WCircle_double_Point3d_Vec3d_double_Color(double radius, Point3dWrapper center, Vec3dWrapper normal, double thickness, void* color) {
    try {
        cv::viz::WCircle* ret = new cv::viz::WCircle(radius, *reinterpret_cast<const cv::Point3d*>(&center), *reinterpret_cast<const cv::Vec3d*>(&normal), thickness, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCloud
void cv_WCloud_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCloud*>(instance);
}
// parsed: cv::viz::WCloud::WCloud
// as:     cv::viz::WCloud::WCloud (constructor) cv::viz::WCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) colors= cv::_InputArray (boxed) = 
// Return value: cv::viz::WCloud (boxed)
cv_return_value_void_X cv_viz_WCloud_WCloud__InputArray__InputArray(void* cloud, void* colors) {
    try {
        cv::viz::WCloud* ret = new cv::viz::WCloud(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::_InputArray*>(colors));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCloud::WCloud
// as:     cv::viz::WCloud::WCloud (constructor) cv::viz::WCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCloud (boxed)
cv_return_value_void_X cv_viz_WCloud_WCloud__InputArray_Color(void* cloud, void* color) {
    try {
        cv::viz::WCloud* ret = new cv::viz::WCloud(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCloud::WCloud
// as:     cv::viz::WCloud::WCloud (constructor) cv::viz::WCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) colors= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) normals= cv::_InputArray (boxed) = 
// Return value: cv::viz::WCloud (boxed)
cv_return_value_void_X cv_viz_WCloud_WCloud__InputArray__InputArray__InputArray(void* cloud, void* colors, void* normals) {
    try {
        cv::viz::WCloud* ret = new cv::viz::WCloud(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::_InputArray*>(colors), *reinterpret_cast<const cv::_InputArray*>(normals));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCloud::WCloud
// as:     cv::viz::WCloud::WCloud (constructor) cv::viz::WCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = 
// Arg ARG cv::_InputArray (boxed) normals= cv::_InputArray (boxed) = 
// Return value: cv::viz::WCloud (boxed)
cv_return_value_void_X cv_viz_WCloud_WCloud__InputArray_Color__InputArray(void* cloud, void* color, void* normals) {
    try {
        cv::viz::WCloud* ret = new cv::viz::WCloud(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::viz::Color*>(color), *reinterpret_cast<const cv::_InputArray*>(normals));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCloudCollection
void cv_WCloudCollection_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCloudCollection*>(instance);
}
// parsed: cv::viz::WCloudCollection::WCloudCollection
// as:     cv::viz::WCloudCollection::WCloudCollection (constructor) cv::viz::WCloudCollection . default
// Return value: cv::viz::WCloudCollection (boxed)
cv_return_value_void_X cv_viz_WCloudCollection_WCloudCollection() {
    try {
        cv::viz::WCloudCollection* ret = new cv::viz::WCloudCollection();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCloudCollection::finalize
// as:     cv::viz::WCloudCollection::finalize (method) cv::viz::WCloudCollection . finalize
// Return value: Primitive(void)
cv_return_value_void cv_viz_WCloudCollection_finalize(void* instance) {
    try {
        reinterpret_cast<cv::viz::WCloudCollection*>(instance)->finalize();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::WCloudNormals
void cv_WCloudNormals_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCloudNormals*>(instance);
}
// parsed: cv::viz::WCloudNormals::WCloudNormals
// as:     cv::viz::WCloudNormals::WCloudNormals (constructor) cv::viz::WCloudNormals . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) normals= cv::_InputArray (boxed) = 
// Arg ARG Primitive(int) level= Primitive(int) = 64
// Arg ARG Primitive(double) scale= Primitive(double) = 0.1
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCloudNormals (boxed)
cv_return_value_void_X cv_viz_WCloudNormals_WCloudNormals__InputArray__InputArray_int_double_Color(void* cloud, void* normals, int level, double scale, void* color) {
    try {
        cv::viz::WCloudNormals* ret = new cv::viz::WCloudNormals(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::_InputArray*>(normals), level, scale, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCone
void cv_WCone_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCone*>(instance);
}
// parsed: cv::viz::WCone::WCone
// as:     cv::viz::WCone::WCone (constructor) cv::viz::WCone . new
// Arg ARG Primitive(double) length= Primitive(double) = 
// Arg ARG Primitive(double) radius= Primitive(double) = 
// Arg ARG Primitive(int) resolution= Primitive(int) = 6.0
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCone (boxed)
cv_return_value_void_X cv_viz_WCone_WCone_double_double_int_Color(double length, double radius, int resolution, void* color) {
    try {
        cv::viz::WCone* ret = new cv::viz::WCone(length, radius, resolution, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WCone::WCone
// as:     cv::viz::WCone::WCone (constructor) cv::viz::WCone . new
// Arg ARG Primitive(double) radius= Primitive(double) = 
// Arg ARG cv::Point3d (simple) center= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) tip= cv::Point3d (simple) = 
// Arg ARG Primitive(int) resolution= Primitive(int) = 6.0
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCone (boxed)
cv_return_value_void_X cv_viz_WCone_WCone_double_Point3d_Point3d_int_Color(double radius, Point3dWrapper center, Point3dWrapper tip, int resolution, void* color) {
    try {
        cv::viz::WCone* ret = new cv::viz::WCone(radius, *reinterpret_cast<const cv::Point3d*>(&center), *reinterpret_cast<const cv::Point3d*>(&tip), resolution, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCoordinateSystem
void cv_WCoordinateSystem_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCoordinateSystem*>(instance);
}
// parsed: cv::viz::WCoordinateSystem::WCoordinateSystem
// as:     cv::viz::WCoordinateSystem::WCoordinateSystem (constructor) cv::viz::WCoordinateSystem . new
// Arg ARG Primitive(double) scale= Primitive(double) = 1.0
// Return value: cv::viz::WCoordinateSystem (boxed)
cv_return_value_void_X cv_viz_WCoordinateSystem_WCoordinateSystem_double(double scale) {
    try {
        cv::viz::WCoordinateSystem* ret = new cv::viz::WCoordinateSystem(scale);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCube
void cv_WCube_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCube*>(instance);
}
// parsed: cv::viz::WCube::WCube
// as:     cv::viz::WCube::WCube (constructor) cv::viz::WCube . new
// Arg ARG cv::Point3d (simple) min_point= cv::Point3d (simple) = Vec3d::all(-0.5)
// Arg ARG cv::Point3d (simple) max_point= cv::Point3d (simple) = Vec3d::all(0.5)
// Arg ARG Primitive(bool) wire_frame= Primitive(bool) = true
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCube (boxed)
cv_return_value_void_X cv_viz_WCube_WCube_Point3d_Point3d_bool_Color(Point3dWrapper min_point, Point3dWrapper max_point, bool wire_frame, void* color) {
    try {
        cv::viz::WCube* ret = new cv::viz::WCube(*reinterpret_cast<const cv::Point3d*>(&min_point), *reinterpret_cast<const cv::Point3d*>(&max_point), wire_frame, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WCylinder
void cv_WCylinder_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WCylinder*>(instance);
}
// parsed: cv::viz::WCylinder::WCylinder
// as:     cv::viz::WCylinder::WCylinder (constructor) cv::viz::WCylinder . new
// Arg ARG cv::Point3d (simple) axis_point1= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) axis_point2= cv::Point3d (simple) = 
// Arg ARG Primitive(double) radius= Primitive(double) = 
// Arg ARG Primitive(int) numsides= Primitive(int) = 30
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WCylinder (boxed)
cv_return_value_void_X cv_viz_WCylinder_WCylinder_Point3d_Point3d_double_int_Color(Point3dWrapper axis_point1, Point3dWrapper axis_point2, double radius, int numsides, void* color) {
    try {
        cv::viz::WCylinder* ret = new cv::viz::WCylinder(*reinterpret_cast<const cv::Point3d*>(&axis_point1), *reinterpret_cast<const cv::Point3d*>(&axis_point2), radius, numsides, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WGrid
void cv_WGrid_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WGrid*>(instance);
}
// parsed: cv::viz::WGrid::WGrid
// as:     cv::viz::WGrid::WGrid (constructor) cv::viz::WGrid . new
// Arg ARG cv::Vec2i (simple) cells= cv::Vec2i (simple) = Vec2i::all(10)
// Arg ARG cv::Vec2d (simple) cells_spacing= cv::Vec2d (simple) = Vec2d::all(1.0)
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WGrid (boxed)
cv_return_value_void_X cv_viz_WGrid_WGrid_Vec2i_Vec2d_Color(Vec2iWrapper cells, Vec2dWrapper cells_spacing, void* color) {
    try {
        cv::viz::WGrid* ret = new cv::viz::WGrid(*reinterpret_cast<const cv::Vec2i*>(&cells), *reinterpret_cast<const cv::Vec2d*>(&cells_spacing), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WGrid::WGrid
// as:     cv::viz::WGrid::WGrid (constructor) cv::viz::WGrid . new
// Arg ARG cv::Point3d (simple) center= cv::Point3d (simple) = 
// Arg ARG cv::Vec3d (simple) normal= cv::Vec3d (simple) = 
// Arg ARG cv::Vec3d (simple) new_yaxis= cv::Vec3d (simple) = 
// Arg ARG cv::Vec2i (simple) cells= cv::Vec2i (simple) = Vec2i::all(10)
// Arg ARG cv::Vec2d (simple) cells_spacing= cv::Vec2d (simple) = Vec2d::all(1.0)
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WGrid (boxed)
cv_return_value_void_X cv_viz_WGrid_WGrid_Point3d_Vec3d_Vec3d_Vec2i_Vec2d_Color(Point3dWrapper center, Vec3dWrapper normal, Vec3dWrapper new_yaxis, Vec2iWrapper cells, Vec2dWrapper cells_spacing, void* color) {
    try {
        cv::viz::WGrid* ret = new cv::viz::WGrid(*reinterpret_cast<const cv::Point3d*>(&center), *reinterpret_cast<const cv::Vec3d*>(&normal), *reinterpret_cast<const cv::Vec3d*>(&new_yaxis), *reinterpret_cast<const cv::Vec2i*>(&cells), *reinterpret_cast<const cv::Vec2d*>(&cells_spacing), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WImage3D
void cv_WImage3D_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WImage3D*>(instance);
}
// parsed: cv::viz::WImage3D::WImage3D
// as:     cv::viz::WImage3D::WImage3D (constructor) cv::viz::WImage3D . new
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::Size2d (simple) size= cv::Size2d (simple) = 
// Return value: cv::viz::WImage3D (boxed)
cv_return_value_void_X cv_viz_WImage3D_WImage3D__InputArray_Size2d(void* image, Size2dWrapper size) {
    try {
        cv::viz::WImage3D* ret = new cv::viz::WImage3D(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::Size2d*>(&size));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WImage3D::WImage3D
// as:     cv::viz::WImage3D::WImage3D (constructor) cv::viz::WImage3D . new
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::Size2d (simple) size= cv::Size2d (simple) = 
// Arg ARG cv::Vec3d (simple) center= cv::Vec3d (simple) = 
// Arg ARG cv::Vec3d (simple) normal= cv::Vec3d (simple) = 
// Arg ARG cv::Vec3d (simple) up_vector= cv::Vec3d (simple) = 
// Return value: cv::viz::WImage3D (boxed)
cv_return_value_void_X cv_viz_WImage3D_WImage3D__InputArray_Size2d_Vec3d_Vec3d_Vec3d(void* image, Size2dWrapper size, Vec3dWrapper center, Vec3dWrapper normal, Vec3dWrapper up_vector) {
    try {
        cv::viz::WImage3D* ret = new cv::viz::WImage3D(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::Size2d*>(&size), *reinterpret_cast<const cv::Vec3d*>(&center), *reinterpret_cast<const cv::Vec3d*>(&normal), *reinterpret_cast<const cv::Vec3d*>(&up_vector));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WImage3D::setImage
// as:     cv::viz::WImage3D::setImage (method) cv::viz::WImage3D . setImage
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_WImage3D_setImage__InputArray(void* instance, void* image) {
    try {
        reinterpret_cast<cv::viz::WImage3D*>(instance)->setImage(*reinterpret_cast<const cv::_InputArray*>(image));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::WImage3D::setSize
// as:     cv::viz::WImage3D::setSize (method) cv::viz::WImage3D . setSize
// Arg ARG cv::Size (simple) size= cv::Size (simple) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_WImage3D_setSize_Size(void* instance, SizeWrapper size) {
    try {
        reinterpret_cast<cv::viz::WImage3D*>(instance)->setSize(*reinterpret_cast<const cv::Size*>(&size));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::WImageOverlay
void cv_WImageOverlay_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WImageOverlay*>(instance);
}
// parsed: cv::viz::WImageOverlay::WImageOverlay
// as:     cv::viz::WImageOverlay::WImageOverlay (constructor) cv::viz::WImageOverlay . new
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::Rect (simple) rect= cv::Rect (simple) = 
// Return value: cv::viz::WImageOverlay (boxed)
cv_return_value_void_X cv_viz_WImageOverlay_WImageOverlay__InputArray_Rect(void* image, RectWrapper rect) {
    try {
        cv::viz::WImageOverlay* ret = new cv::viz::WImageOverlay(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::Rect*>(&rect));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WImageOverlay::setImage
// as:     cv::viz::WImageOverlay::setImage (method) cv::viz::WImageOverlay . setImage
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_WImageOverlay_setImage__InputArray(void* instance, void* image) {
    try {
        reinterpret_cast<cv::viz::WImageOverlay*>(instance)->setImage(*reinterpret_cast<const cv::_InputArray*>(image));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::WLine
void cv_WLine_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WLine*>(instance);
}
// parsed: cv::viz::WLine::WLine
// as:     cv::viz::WLine::WLine (constructor) cv::viz::WLine . new
// Arg ARG cv::Point3d (simple) pt1= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) pt2= cv::Point3d (simple) = 
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WLine (boxed)
cv_return_value_void_X cv_viz_WLine_WLine_Point3d_Point3d_Color(Point3dWrapper pt1, Point3dWrapper pt2, void* color) {
    try {
        cv::viz::WLine* ret = new cv::viz::WLine(*reinterpret_cast<const cv::Point3d*>(&pt1), *reinterpret_cast<const cv::Point3d*>(&pt2), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WMesh
void cv_WMesh_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WMesh*>(instance);
}
// parsed: cv::viz::WMesh::WMesh
// as:     cv::viz::WMesh::WMesh (constructor) cv::viz::WMesh . new
// Arg ARG cv::viz::Mesh (boxed) mesh= cv::viz::Mesh (boxed) = 
// Return value: cv::viz::WMesh (boxed)
cv_return_value_void_X cv_viz_WMesh_WMesh_Mesh(void* mesh) {
    try {
        cv::viz::WMesh* ret = new cv::viz::WMesh(*reinterpret_cast<const cv::viz::Mesh*>(mesh));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WMesh::WMesh
// as:     cv::viz::WMesh::WMesh (constructor) cv::viz::WMesh . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) polygons= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) colors= cv::_InputArray (boxed) = noArray()
// Arg ARG cv::_InputArray (boxed) normals= cv::_InputArray (boxed) = noArray()
// Return value: cv::viz::WMesh (boxed)
cv_return_value_void_X cv_viz_WMesh_WMesh__InputArray__InputArray__InputArray__InputArray(void* cloud, void* polygons, void* colors, void* normals) {
    try {
        cv::viz::WMesh* ret = new cv::viz::WMesh(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::_InputArray*>(polygons), *reinterpret_cast<const cv::_InputArray*>(colors), *reinterpret_cast<const cv::_InputArray*>(normals));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WPaintedCloud
void cv_WPaintedCloud_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WPaintedCloud*>(instance);
}
// parsed: cv::viz::WPaintedCloud::WPaintedCloud
// as:     cv::viz::WPaintedCloud::WPaintedCloud (constructor) cv::viz::WPaintedCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Return value: cv::viz::WPaintedCloud (boxed)
cv_return_value_void_X cv_viz_WPaintedCloud_WPaintedCloud__InputArray(void* cloud) {
    try {
        cv::viz::WPaintedCloud* ret = new cv::viz::WPaintedCloud(*reinterpret_cast<const cv::_InputArray*>(cloud));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WPaintedCloud::WPaintedCloud
// as:     cv::viz::WPaintedCloud::WPaintedCloud (constructor) cv::viz::WPaintedCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::Point3d (simple) p1= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) p2= cv::Point3d (simple) = 
// Return value: cv::viz::WPaintedCloud (boxed)
cv_return_value_void_X cv_viz_WPaintedCloud_WPaintedCloud__InputArray_Point3d_Point3d(void* cloud, Point3dWrapper p1, Point3dWrapper p2) {
    try {
        cv::viz::WPaintedCloud* ret = new cv::viz::WPaintedCloud(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::Point3d*>(&p1), *reinterpret_cast<const cv::Point3d*>(&p2));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WPaintedCloud::WPaintedCloud
// as:     cv::viz::WPaintedCloud::WPaintedCloud (constructor) cv::viz::WPaintedCloud . new
// Arg ARG cv::_InputArray (boxed) cloud= cv::_InputArray (boxed) = 
// Arg ARG cv::Point3d (simple) p1= cv::Point3d (simple) = 
// Arg ARG cv::Point3d (simple) p2= cv::Point3d (simple) = 
// Arg ARG cv::viz::Color (boxed) c1= cv::viz::Color (boxed) = 
// Arg ARG cv::viz::Color (boxed) c2= cv::viz::Color (boxed) = 
// Return value: cv::viz::WPaintedCloud (boxed)
cv_return_value_void_X cv_viz_WPaintedCloud_WPaintedCloud__InputArray_Point3d_Point3d_Color_Color(void* cloud, Point3dWrapper p1, Point3dWrapper p2, void* c1, void* c2) {
    try {
        cv::viz::WPaintedCloud* ret = new cv::viz::WPaintedCloud(*reinterpret_cast<const cv::_InputArray*>(cloud), *reinterpret_cast<const cv::Point3d*>(&p1), *reinterpret_cast<const cv::Point3d*>(&p2), *reinterpret_cast<const cv::viz::Color*>(c1), *reinterpret_cast<const cv::viz::Color*>(c2));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WPlane
void cv_WPlane_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WPlane*>(instance);
}
// parsed: cv::viz::WPlane::WPlane
// as:     cv::viz::WPlane::WPlane (constructor) cv::viz::WPlane . new
// Arg ARG cv::Size2d (simple) size= cv::Size2d (simple) = Size2d(1.0, 1.0)
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WPlane (boxed)
cv_return_value_void_X cv_viz_WPlane_WPlane_Size2d_Color(Size2dWrapper size, void* color) {
    try {
        cv::viz::WPlane* ret = new cv::viz::WPlane(*reinterpret_cast<const cv::Size2d*>(&size), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WPlane::WPlane
// as:     cv::viz::WPlane::WPlane (constructor) cv::viz::WPlane . new
// Arg ARG cv::Point3d (simple) center= cv::Point3d (simple) = 
// Arg ARG cv::Vec3d (simple) normal= cv::Vec3d (simple) = 
// Arg ARG cv::Vec3d (simple) new_yaxis= cv::Vec3d (simple) = 
// Arg ARG cv::Size2d (simple) size= cv::Size2d (simple) = Size2d(1.0, 1.0)
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WPlane (boxed)
cv_return_value_void_X cv_viz_WPlane_WPlane_Point3d_Vec3d_Vec3d_Size2d_Color(Point3dWrapper center, Vec3dWrapper normal, Vec3dWrapper new_yaxis, Size2dWrapper size, void* color) {
    try {
        cv::viz::WPlane* ret = new cv::viz::WPlane(*reinterpret_cast<const cv::Point3d*>(&center), *reinterpret_cast<const cv::Vec3d*>(&normal), *reinterpret_cast<const cv::Vec3d*>(&new_yaxis), *reinterpret_cast<const cv::Size2d*>(&size), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WPolyLine
void cv_WPolyLine_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WPolyLine*>(instance);
}
// parsed: cv::viz::WPolyLine::WPolyLine
// as:     cv::viz::WPolyLine::WPolyLine (constructor) cv::viz::WPolyLine . new
// Arg ARG cv::_InputArray (boxed) points= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) colors= cv::_InputArray (boxed) = 
// Return value: cv::viz::WPolyLine (boxed)
cv_return_value_void_X cv_viz_WPolyLine_WPolyLine__InputArray__InputArray(void* points, void* colors) {
    try {
        cv::viz::WPolyLine* ret = new cv::viz::WPolyLine(*reinterpret_cast<const cv::_InputArray*>(points), *reinterpret_cast<const cv::_InputArray*>(colors));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WPolyLine::WPolyLine
// as:     cv::viz::WPolyLine::WPolyLine (constructor) cv::viz::WPolyLine . new
// Arg ARG cv::_InputArray (boxed) points= cv::_InputArray (boxed) = 
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WPolyLine (boxed)
cv_return_value_void_X cv_viz_WPolyLine_WPolyLine__InputArray_Color(void* points, void* color) {
    try {
        cv::viz::WPolyLine* ret = new cv::viz::WPolyLine(*reinterpret_cast<const cv::_InputArray*>(points), *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WSphere
void cv_WSphere_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WSphere*>(instance);
}
// parsed: cv::viz::WSphere::WSphere
// as:     cv::viz::WSphere::WSphere (constructor) cv::viz::WSphere . new
// Arg ARG cv::Point3d (simple) center= cv::Point3d (simple) = 
// Arg ARG Primitive(double) radius= Primitive(double) = 
// Arg ARG Primitive(int) sphere_resolution= Primitive(int) = 10
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WSphere (boxed)
cv_return_value_void_X cv_viz_WSphere_WSphere_Point3d_double_int_Color(Point3dWrapper center, double radius, int sphere_resolution, void* color) {
    try {
        cv::viz::WSphere* ret = new cv::viz::WSphere(*reinterpret_cast<const cv::Point3d*>(&center), radius, sphere_resolution, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WText
void cv_WText_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WText*>(instance);
}
// parsed: cv::viz::WText::WText
// as:     cv::viz::WText::WText (constructor) cv::viz::WText . new
// Arg ARG string text= string = 
// Arg ARG cv::Point (simple) pos= cv::Point (simple) = 
// Arg ARG Primitive(int) font_size= Primitive(int) = 20
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WText (boxed)
cv_return_value_void_X cv_viz_WText_WText_String_Point_int_Color(const char* text, PointWrapper pos, int font_size, void* color) {
    try {
        cv::viz::WText* ret = new cv::viz::WText(String(text), *reinterpret_cast<const cv::Point*>(&pos), font_size, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WText::setText
// as:     cv::viz::WText::setText (method) cv::viz::WText . setText
// Arg ARG string text= string = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_WText_setText_String(void* instance, const char* text) {
    try {
        reinterpret_cast<cv::viz::WText*>(instance)->setText(String(text));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::WText::getText
// as:     cv::viz::WText::getText (method) cv::viz::WText . getText
// Return value: string
cv_return_value_char_X cv_viz_WText_getText_const(void* instance) {
    try {
        String ret = reinterpret_cast<cv::viz::WText*>(instance)->getText();
        return { Error::Code::StsOk, NULL, strdup(ret.c_str()) };
    } CVRS_CATCH(cv_return_value_char_X)
}

// boxed class: cv::viz::WText3D
void cv_WText3D_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WText3D*>(instance);
}
// parsed: cv::viz::WText3D::WText3D
// as:     cv::viz::WText3D::WText3D (constructor) cv::viz::WText3D . new
// Arg ARG string text= string = 
// Arg ARG cv::Point3d (simple) position= cv::Point3d (simple) = 
// Arg ARG Primitive(double) text_scale= Primitive(double) = 1.
// Arg ARG Primitive(bool) face_camera= Primitive(bool) = true
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WText3D (boxed)
cv_return_value_void_X cv_viz_WText3D_WText3D_String_Point3d_double_bool_Color(const char* text, Point3dWrapper position, double text_scale, bool face_camera, void* color) {
    try {
        cv::viz::WText3D* ret = new cv::viz::WText3D(String(text), *reinterpret_cast<const cv::Point3d*>(&position), text_scale, face_camera, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WText3D::setText
// as:     cv::viz::WText3D::setText (method) cv::viz::WText3D . setText
// Arg ARG string text= string = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_WText3D_setText_String(void* instance, const char* text) {
    try {
        reinterpret_cast<cv::viz::WText3D*>(instance)->setText(String(text));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::WText3D::getText
// as:     cv::viz::WText3D::getText (method) cv::viz::WText3D . getText
// Return value: string
cv_return_value_char_X cv_viz_WText3D_getText_const(void* instance) {
    try {
        String ret = reinterpret_cast<cv::viz::WText3D*>(instance)->getText();
        return { Error::Code::StsOk, NULL, strdup(ret.c_str()) };
    } CVRS_CATCH(cv_return_value_char_X)
}

// boxed class: cv::viz::WTrajectory
void cv_WTrajectory_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WTrajectory*>(instance);
}
// parsed: cv::viz::WTrajectory::WTrajectory
// as:     cv::viz::WTrajectory::WTrajectory (constructor) cv::viz::WTrajectory . new
// Arg ARG cv::_InputArray (boxed) path= cv::_InputArray (boxed) = 
// Arg ARG Primitive(int) display_mode= Primitive(int) = WTrajectory::PATH
// Arg ARG Primitive(double) scale= Primitive(double) = 1.0
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WTrajectory (boxed)
cv_return_value_void_X cv_viz_WTrajectory_WTrajectory__InputArray_int_double_Color(void* path, int display_mode, double scale, void* color) {
    try {
        cv::viz::WTrajectory* ret = new cv::viz::WTrajectory(*reinterpret_cast<const cv::_InputArray*>(path), display_mode, scale, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WTrajectoryFrustums
void cv_WTrajectoryFrustums_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WTrajectoryFrustums*>(instance);
}
// parsed: cv::viz::WTrajectoryFrustums::WTrajectoryFrustums
// as:     cv::viz::WTrajectoryFrustums::WTrajectoryFrustums (constructor) cv::viz::WTrajectoryFrustums . new
// Arg ARG cv::_InputArray (boxed) path= cv::_InputArray (boxed) = 
// Arg ARG cv::Vec2d (simple) fov= cv::Vec2d (simple) = 
// Arg ARG Primitive(double) scale= Primitive(double) = 1.
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WTrajectoryFrustums (boxed)
cv_return_value_void_X cv_viz_WTrajectoryFrustums_WTrajectoryFrustums__InputArray_Vec2d_double_Color(void* path, Vec2dWrapper fov, double scale, void* color) {
    try {
        cv::viz::WTrajectoryFrustums* ret = new cv::viz::WTrajectoryFrustums(*reinterpret_cast<const cv::_InputArray*>(path), *reinterpret_cast<const cv::Vec2d*>(&fov), scale, *reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WTrajectorySpheres
void cv_WTrajectorySpheres_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WTrajectorySpheres*>(instance);
}
// parsed: cv::viz::WTrajectorySpheres::WTrajectorySpheres
// as:     cv::viz::WTrajectorySpheres::WTrajectorySpheres (constructor) cv::viz::WTrajectorySpheres . new
// Arg ARG cv::_InputArray (boxed) path= cv::_InputArray (boxed) = 
// Arg ARG Primitive(double) line_length= Primitive(double) = 0.05
// Arg ARG Primitive(double) radius= Primitive(double) = 0.007
// Arg ARG cv::viz::Color (boxed) from= cv::viz::Color (boxed) = Color::red()
// Arg ARG cv::viz::Color (boxed) to= cv::viz::Color (boxed) = Color::white()
// Return value: cv::viz::WTrajectorySpheres (boxed)
cv_return_value_void_X cv_viz_WTrajectorySpheres_WTrajectorySpheres__InputArray_double_double_Color_Color(void* path, double line_length, double radius, void* from, void* to) {
    try {
        cv::viz::WTrajectorySpheres* ret = new cv::viz::WTrajectorySpheres(*reinterpret_cast<const cv::_InputArray*>(path), line_length, radius, *reinterpret_cast<const cv::viz::Color*>(from), *reinterpret_cast<const cv::viz::Color*>(to));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::viz::WWidgetMerger
void cv_WWidgetMerger_delete(void* instance) {
    delete reinterpret_cast<cv::viz::WWidgetMerger*>(instance);
}
// parsed: cv::viz::WWidgetMerger::WWidgetMerger
// as:     cv::viz::WWidgetMerger::WWidgetMerger (constructor) cv::viz::WWidgetMerger . default
// Return value: cv::viz::WWidgetMerger (boxed)
cv_return_value_void_X cv_viz_WWidgetMerger_WWidgetMerger() {
    try {
        cv::viz::WWidgetMerger* ret = new cv::viz::WWidgetMerger();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::WWidgetMerger::finalize
// as:     cv::viz::WWidgetMerger::finalize (method) cv::viz::WWidgetMerger . finalize
// Return value: Primitive(void)
cv_return_value_void cv_viz_WWidgetMerger_finalize(void* instance) {
    try {
        reinterpret_cast<cv::viz::WWidgetMerger*>(instance)->finalize();
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Widget::setRenderingProperty
// as:     cv::viz::Widget::setRenderingProperty (method) cv::viz::Widget (trait) . setRenderingProperty
// Arg ARG Primitive(int) property= Primitive(int) = 
// Arg ARG Primitive(double) value= Primitive(double) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Widget_setRenderingProperty_int_double(void* instance, int property, double value) {
    try {
        reinterpret_cast<cv::viz::Widget*>(instance)->setRenderingProperty(property, value);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::viz::Widget::getRenderingProperty
// as:     cv::viz::Widget::getRenderingProperty (method) cv::viz::Widget (trait) . getRenderingProperty
// Arg ARG Primitive(int) property= Primitive(int) = 
// Return value: Primitive(double)
cv_return_value_double cv_viz_Widget_getRenderingProperty_const_int(void* instance, int property) {
    try {
        double ret = reinterpret_cast<cv::viz::Widget*>(instance)->getRenderingProperty(property);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_double)
}

// boxed class: cv::viz::Widget
void cv_Widget_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Widget*>(instance);
}
// parsed: cv::viz::Widget::Widget
// as:     cv::viz::Widget::Widget (constructor) cv::viz::Widget (trait) . default
// Return value: cv::viz::Widget (boxed)
cv_return_value_void_X cv_viz_Widget_Widget() {
    try {
        cv::viz::Widget* ret = new cv::viz::Widget();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Widget::Widget
// as:     cv::viz::Widget::Widget (constructor) cv::viz::Widget (trait) . copy
// Arg ARG cv::viz::Widget (boxed) other= cv::viz::Widget (boxed) = 
// Return value: cv::viz::Widget (boxed)
cv_return_value_void_X cv_viz_Widget_Widget_Widget(void* other) {
    try {
        cv::viz::Widget* ret = new cv::viz::Widget(*reinterpret_cast<const cv::viz::Widget*>(other));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Widget::fromPlyFile
// as:     cv::viz::Widget::fromPlyFile (method) cv::viz::Widget (trait) . fromPlyFile
// Arg ARG string file_name= string = 
// Return value: cv::viz::Widget (boxed)
cv_return_value_void_X cv_viz_Widget_fromPlyFile_String(const char* file_name) {
    try {
        cv::viz::Widget ret = cv::viz::Widget::fromPlyFile(String(file_name));
        return { Error::Code::StsOk, NULL, new cv::viz::Widget(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Widget2D::setColor
// as:     cv::viz::Widget2D::setColor (method) cv::viz::Widget2D (trait) . setColor
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Widget2D_setColor_Color(void* instance, void* color) {
    try {
        reinterpret_cast<cv::viz::Widget2D*>(instance)->setColor(*reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::Widget2D
void cv_Widget2D_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Widget2D*>(instance);
}
// parsed: cv::viz::Widget2D::Widget2D
// as:     cv::viz::Widget2D::Widget2D (constructor) cv::viz::Widget2D (trait) . default
// Return value: cv::viz::Widget2D (boxed)
cv_return_value_void_X cv_viz_Widget2D_Widget2D() {
    try {
        cv::viz::Widget2D* ret = new cv::viz::Widget2D();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::viz::Widget3D::setColor
// as:     cv::viz::Widget3D::setColor (method) cv::viz::Widget3D (trait) . setColor
// Arg ARG cv::viz::Color (boxed) color= cv::viz::Color (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_viz_Widget3D_setColor_Color(void* instance, void* color) {
    try {
        reinterpret_cast<cv::viz::Widget3D*>(instance)->setColor(*reinterpret_cast<const cv::viz::Color*>(color));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// boxed class: cv::viz::Widget3D
void cv_Widget3D_delete(void* instance) {
    delete reinterpret_cast<cv::viz::Widget3D*>(instance);
}
// parsed: cv::viz::Widget3D::Widget3D
// as:     cv::viz::Widget3D::Widget3D (constructor) cv::viz::Widget3D (trait) . default
// Return value: cv::viz::Widget3D (boxed)
cv_return_value_void_X cv_viz_Widget3D_Widget3D() {
    try {
        cv::viz::Widget3D* ret = new cv::viz::Widget3D();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}



}
