#include "stdint.h"
#include "common.h"
#include <string>
#include "common_opencv.h"
using namespace cv;
#include "types.h"
#include "return_types.h"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/bif.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/face_alignment.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/facemark.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/facemarkAAM.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/facemarkLBF.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/facemark_train.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/facerec.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/mace.hpp"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/face/predict_collector.hpp"

extern "C" {

// parsed: cv::face::createFacemarkAAM
// as:     cv::face::createFacemarkAAM (function)
// Return value: SmartPtr[cv::face::Facemark (boxed)]
cv_return_value_void_X cv_face_createFacemarkAAM() {
    try {
        Ptr<cv::face::Facemark> ret = cv::face::createFacemarkAAM();
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::Facemark>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::createFacemarkKazemi
// as:     cv::face::createFacemarkKazemi (function)
// Return value: SmartPtr[cv::face::Facemark (boxed)]
cv_return_value_void_X cv_face_createFacemarkKazemi() {
    try {
        Ptr<cv::face::Facemark> ret = cv::face::createFacemarkKazemi();
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::Facemark>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::createFacemarkLBF
// as:     cv::face::createFacemarkLBF (function)
// Return value: SmartPtr[cv::face::Facemark (boxed)]
cv_return_value_void_X cv_face_createFacemarkLBF() {
    try {
        Ptr<cv::face::Facemark> ret = cv::face::createFacemarkLBF();
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::Facemark>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::drawFacemarks
// as:     cv::face::drawFacemarks (function)
// Arg ARG cv::_InputOutputArray (boxed) image= cv::_InputOutputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) points= cv::_InputArray (boxed) = 
// Arg ARG cv::Scalar (simple) color= cv::Scalar (simple) = Scalar(255,0,0)
// Return value: Primitive(void)
cv_return_value_void cv_face_drawFacemarks__InputOutputArray__InputArray_Scalar(void* image, void* points, ScalarWrapper color) {
    try {
        cv::face::drawFacemarks(*reinterpret_cast<cv::_InputOutputArray*>(image), *reinterpret_cast<const cv::_InputArray*>(points), *reinterpret_cast<cv::Scalar*>(&color));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::getFacesHAAR
// as:     cv::face::getFacesHAAR (function)
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) faces= cv::_OutputArray (boxed) = 
// Arg ARG string face_cascade_name= string = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_getFacesHAAR__InputArray__OutputArray_String(void* image, void* faces, const char* face_cascade_name) {
    try {
        bool ret = cv::face::getFacesHAAR(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<cv::_OutputArray*>(faces), String(face_cascade_name));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::getFaces
// as:     cv::face::getFaces (function)
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) faces= cv::_OutputArray (boxed) = 
// Arg ARG RawPtr[cv::face::CParams (boxed)] * params= (ptr) RawPtr[cv::face::CParams (boxed)] = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_getFaces__InputArray__OutputArray_CParams(void* image, void* faces, void* params) {
    try {
        bool ret = cv::face::getFaces(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<cv::_OutputArray*>(faces), reinterpret_cast<cv::face::CParams*>(params));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::loadDatasetList
// as:     cv::face::loadDatasetList (function)
// Arg ARG string imageList= string = 
// Arg ARG string annotationList= string = 
// Arg ARG Vector[string] images= Vector[string] = 
// Arg ARG Vector[string] annotations= Vector[string] = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_loadDatasetList_String_String_VectorOfString_VectorOfString(const char* imageList, const char* annotationList, void* images, void* annotations) {
    try {
        bool ret = cv::face::loadDatasetList(String(imageList), String(annotationList), *reinterpret_cast<std::vector<String>*>(images), *reinterpret_cast<std::vector<String>*>(annotations));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::loadFacePoints
// as:     cv::face::loadFacePoints (function)
// Arg ARG string filename= string = 
// Arg ARG cv::_OutputArray (boxed) points= cv::_OutputArray (boxed) = 
// Arg ARG Primitive(float) offset= Primitive(float) = 0.0f
// Return value: Primitive(bool)
cv_return_value_bool cv_face_loadFacePoints_String__OutputArray_float(const char* filename, void* points, float offset) {
    try {
        bool ret = cv::face::loadFacePoints(String(filename), *reinterpret_cast<cv::_OutputArray*>(points), offset);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::loadTrainingData
// as:     cv::face::loadTrainingData (function)
// Arg ARG string imageList= string = 
// Arg ARG string groundTruth= string = 
// Arg ARG Vector[string] images= Vector[string] = 
// Arg ARG cv::_OutputArray (boxed) facePoints= cv::_OutputArray (boxed) = 
// Arg ARG Primitive(float) offset= Primitive(float) = 0.0f
// Return value: Primitive(bool)
cv_return_value_bool cv_face_loadTrainingData_String_String_VectorOfString__OutputArray_float(const char* imageList, const char* groundTruth, void* images, void* facePoints, float offset) {
    try {
        bool ret = cv::face::loadTrainingData(String(imageList), String(groundTruth), *reinterpret_cast<std::vector<String>*>(images), *reinterpret_cast<cv::_OutputArray*>(facePoints), offset);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::loadTrainingData
// as:     cv::face::loadTrainingData (function)
// Arg ARG string filename= string = 
// Arg ARG Vector[string] images= Vector[string] = 
// Arg ARG cv::_OutputArray (boxed) facePoints= cv::_OutputArray (boxed) = 
// Arg ARG Primitive(char) delim= Primitive(char) = ' '
// Arg ARG Primitive(float) offset= Primitive(float) = 0.0f
// Return value: Primitive(bool)
cv_return_value_bool cv_face_loadTrainingData_String_VectorOfString__OutputArray_char_float(const char* filename, void* images, void* facePoints, char delim, float offset) {
    try {
        bool ret = cv::face::loadTrainingData(String(filename), *reinterpret_cast<std::vector<String>*>(images), *reinterpret_cast<cv::_OutputArray*>(facePoints), delim, offset);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::loadTrainingData
// as:     cv::face::loadTrainingData (function)
// Arg ARG Vector[string] filename= Vector[string] = 
// Arg ARG Vector[Vector[cv::Point2f (simple)]] trainlandmarks= Vector[Vector[cv::Point2f (simple)]] = 
// Arg ARG Vector[string] trainimages= Vector[string] = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_loadTrainingData_VectorOfString_VectorOfVectorOfPoint2f_VectorOfString(void* filename, void* trainlandmarks, void* trainimages) {
    try {
        bool ret = cv::face::loadTrainingData(*reinterpret_cast<std::vector<String>*>(filename), *reinterpret_cast<std::vector<std::vector<cv::Point2f>>*>(trainlandmarks), *reinterpret_cast<std::vector<String>*>(trainimages));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::BIF::getNumBands
// as:     cv::face::BIF::getNumBands (method) cv::face::BIF (trait) . getNumBands
// Return value: Primitive(int)
cv_return_value_int cv_face_BIF_getNumBands_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::BIF*>(instance)->getNumBands();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::BIF::getNumRotations
// as:     cv::face::BIF::getNumRotations (method) cv::face::BIF (trait) . getNumRotations
// Return value: Primitive(int)
cv_return_value_int cv_face_BIF_getNumRotations_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::BIF*>(instance)->getNumRotations();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::BIF::compute
// as:     cv::face::BIF::compute (method) cv::face::BIF (trait) . compute
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) features= cv::_OutputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_BIF_compute_const__InputArray__OutputArray(void* instance, void* image, void* features) {
    try {
        reinterpret_cast<cv::face::BIF*>(instance)->compute(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<cv::_OutputArray*>(features));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::BIF::create
// as:     cv::face::BIF::create (method) cv::face::BIF (trait) . create
// Arg ARG Primitive(int) num_bands= Primitive(int) = 8
// Arg ARG Primitive(int) num_rotations= Primitive(int) = 12
// Return value: SmartPtr[cv::face::BIF (boxed)]
cv_return_value_void_X cv_face_BIF_create_int_int(int num_bands, int num_rotations) {
    try {
        Ptr<cv::face::BIF> ret = cv::face::BIF::create(num_bands, num_rotations);
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::BIF>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::BasicFaceRecognizer::getNumComponents
// as:     cv::face::BasicFaceRecognizer::getNumComponents (method) cv::face::BasicFaceRecognizer (trait) . getNumComponents
// Return value: Primitive(int)
cv_return_value_int cv_face_BasicFaceRecognizer_getNumComponents_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getNumComponents();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::BasicFaceRecognizer::setNumComponents
// as:     cv::face::BasicFaceRecognizer::setNumComponents (method) cv::face::BasicFaceRecognizer (trait) . setNumComponents
// Arg ARG Primitive(int) val= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_BasicFaceRecognizer_setNumComponents_int(void* instance, int val) {
    try {
        reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->setNumComponents(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::BasicFaceRecognizer::getThreshold
// as:     cv::face::BasicFaceRecognizer::getThreshold (method) cv::face::BasicFaceRecognizer (trait) . getThreshold
// Return value: Primitive(double)
cv_return_value_double cv_face_BasicFaceRecognizer_getThreshold_const(void* instance) {
    try {
        double ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getThreshold();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_double)
}

// parsed: cv::face::BasicFaceRecognizer::setThreshold
// as:     cv::face::BasicFaceRecognizer::setThreshold (method) cv::face::BasicFaceRecognizer (trait) . setThreshold
// Arg ARG Primitive(double) val= Primitive(double) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_BasicFaceRecognizer_setThreshold_double(void* instance, double val) {
    try {
        reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->setThreshold(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::BasicFaceRecognizer::getProjections
// as:     cv::face::BasicFaceRecognizer::getProjections (method) cv::face::BasicFaceRecognizer (trait) . getProjections
// Return value: Vector[cv::Mat (boxed)]
cv_return_value_void_X cv_face_BasicFaceRecognizer_getProjections_const(void* instance) {
    try {
        std::vector<cv::Mat> ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getProjections();
        return { Error::Code::StsOk, NULL, new std::vector<cv::Mat>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::BasicFaceRecognizer::getLabels
// as:     cv::face::BasicFaceRecognizer::getLabels (method) cv::face::BasicFaceRecognizer (trait) . getLabels
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_BasicFaceRecognizer_getLabels_const(void* instance) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getLabels();
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::BasicFaceRecognizer::getEigenValues
// as:     cv::face::BasicFaceRecognizer::getEigenValues (method) cv::face::BasicFaceRecognizer (trait) . getEigenValues
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_BasicFaceRecognizer_getEigenValues_const(void* instance) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getEigenValues();
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::BasicFaceRecognizer::getEigenVectors
// as:     cv::face::BasicFaceRecognizer::getEigenVectors (method) cv::face::BasicFaceRecognizer (trait) . getEigenVectors
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_BasicFaceRecognizer_getEigenVectors_const(void* instance) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getEigenVectors();
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::BasicFaceRecognizer::getMean
// as:     cv::face::BasicFaceRecognizer::getMean (method) cv::face::BasicFaceRecognizer (trait) . getMean
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_BasicFaceRecognizer_getMean_const(void* instance) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->getMean();
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::BasicFaceRecognizer::read
// as:     cv::face::BasicFaceRecognizer::read (method) cv::face::BasicFaceRecognizer (trait) . read
// Arg ARG cv::FileNode (boxed) fn= cv::FileNode (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_BasicFaceRecognizer_read_FileNode(void* instance, void* fn) {
    try {
        reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->read(*reinterpret_cast<const cv::FileNode*>(fn));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::BasicFaceRecognizer::write
// as:     cv::face::BasicFaceRecognizer::write (method) cv::face::BasicFaceRecognizer (trait) . write
// Arg ARG cv::FileStorage (boxed) fs= cv::FileStorage (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_BasicFaceRecognizer_write_const_FileStorage(void* instance, void* fs) {
    try {
        reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->write(*reinterpret_cast<cv::FileStorage*>(fs));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::BasicFaceRecognizer::empty
// as:     cv::face::BasicFaceRecognizer::empty (method) cv::face::BasicFaceRecognizer (trait) . empty
// Return value: Primitive(bool)
cv_return_value_bool cv_face_BasicFaceRecognizer_empty_const(void* instance) {
    try {
        bool ret = reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance)->empty();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// boxed class: cv::face::BasicFaceRecognizer
void cv_BasicFaceRecognizer_delete(void* instance) {
    delete reinterpret_cast<cv::face::BasicFaceRecognizer*>(instance);
}
// boxed class: cv::face::CParams
void cv_CParams_delete(void* instance) {
    delete reinterpret_cast<cv::face::CParams*>(instance);
}
// parsed: cv::face::CParams::CParams
// as:     cv::face::CParams::CParams (constructor) cv::face::CParams . new
// Arg ARG string cascade_model= string = 
// Arg ARG Primitive(double) sf= Primitive(double) = 1.1
// Arg ARG Primitive(int) minN= Primitive(int) = 3
// Arg ARG cv::Size (simple) minSz= cv::Size (simple) = Size(30, 30)
// Arg ARG cv::Size (simple) maxSz= cv::Size (simple) = Size()
// Return value: cv::face::CParams (boxed)
cv_return_value_void_X cv_face_CParams_CParams_String_double_int_Size_Size(const char* cascade_model, double sf, int minN, SizeWrapper minSz, SizeWrapper maxSz) {
    try {
        cv::face::CParams* ret = new cv::face::CParams(String(cascade_model), sf, minN, *reinterpret_cast<cv::Size*>(&minSz), *reinterpret_cast<cv::Size*>(&maxSz));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::EigenFaceRecognizer
void cv_EigenFaceRecognizer_delete(void* instance) {
    delete reinterpret_cast<cv::face::EigenFaceRecognizer*>(instance);
}
// parsed: cv::face::EigenFaceRecognizer::create
// as:     cv::face::EigenFaceRecognizer::create (method) cv::face::EigenFaceRecognizer . create
// Arg ARG Primitive(int) num_components= Primitive(int) = 0
// Arg ARG Primitive(double) threshold= Primitive(double) = DBL_MAX
// Return value: SmartPtr[cv::face::EigenFaceRecognizer (boxed)]
cv_return_value_void_X cv_face_EigenFaceRecognizer_create_int_double(int num_components, double threshold) {
    try {
        Ptr<cv::face::EigenFaceRecognizer> ret = cv::face::EigenFaceRecognizer::create(num_components, threshold);
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::EigenFaceRecognizer>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FaceRecognizer::train
// as:     cv::face::FaceRecognizer::train (method) cv::face::FaceRecognizer (trait) . train
// Arg ARG cv::_InputArray (boxed) src= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) labels= cv::_InputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_train__InputArray__InputArray(void* instance, void* src, void* labels) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->train(*reinterpret_cast<const cv::_InputArray*>(src), *reinterpret_cast<const cv::_InputArray*>(labels));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::update
// as:     cv::face::FaceRecognizer::update (method) cv::face::FaceRecognizer (trait) . update
// Arg ARG cv::_InputArray (boxed) src= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) labels= cv::_InputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_update__InputArray__InputArray(void* instance, void* src, void* labels) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->update(*reinterpret_cast<const cv::_InputArray*>(src), *reinterpret_cast<const cv::_InputArray*>(labels));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::predict
// as:     cv::face::FaceRecognizer::predict (method) cv::face::FaceRecognizer (trait) . predict
// Arg ARG cv::_InputArray (boxed) src= cv::_InputArray (boxed) = 
// Return value: Primitive(int)
cv_return_value_int cv_face_FaceRecognizer_predict_const__InputArray(void* instance, void* src) {
    try {
        int ret = reinterpret_cast<cv::face::FaceRecognizer*>(instance)->predict(*reinterpret_cast<const cv::_InputArray*>(src));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::FaceRecognizer::predict
// as:     cv::face::FaceRecognizer::predict (method) cv::face::FaceRecognizer (trait) . predict
// Arg ARG cv::_InputArray (boxed) src= cv::_InputArray (boxed) = 
// Arg ARG Primitive(int) label= Primitive(int) = 
// Arg ARG Primitive(double) confidence= Primitive(double) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_predict_const__InputArray_int_double(void* instance, void* src, int& label, double& confidence) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->predict(*reinterpret_cast<const cv::_InputArray*>(src), label, confidence);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::write
// as:     cv::face::FaceRecognizer::write (method) cv::face::FaceRecognizer (trait) . write
// Arg ARG string filename= string = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_write_const_String(void* instance, const char* filename) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->write(String(filename));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::read
// as:     cv::face::FaceRecognizer::read (method) cv::face::FaceRecognizer (trait) . read
// Arg ARG string filename= string = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_read_String(void* instance, const char* filename) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->read(String(filename));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::write
// as:     cv::face::FaceRecognizer::write (method) cv::face::FaceRecognizer (trait) . write
// Arg ARG cv::FileStorage (boxed) fs= cv::FileStorage (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_write_const_FileStorage(void* instance, void* fs) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->write(*reinterpret_cast<cv::FileStorage*>(fs));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::read
// as:     cv::face::FaceRecognizer::read (method) cv::face::FaceRecognizer (trait) . read
// Arg ARG cv::FileNode (boxed) fn= cv::FileNode (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_read_FileNode(void* instance, void* fn) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->read(*reinterpret_cast<const cv::FileNode*>(fn));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::empty
// as:     cv::face::FaceRecognizer::empty (method) cv::face::FaceRecognizer (trait) . empty
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FaceRecognizer_empty_const(void* instance) {
    try {
        bool ret = reinterpret_cast<cv::face::FaceRecognizer*>(instance)->empty();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FaceRecognizer::setLabelInfo
// as:     cv::face::FaceRecognizer::setLabelInfo (method) cv::face::FaceRecognizer (trait) . setLabelInfo
// Arg ARG Primitive(int) label= Primitive(int) = 
// Arg ARG string strInfo= string = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_setLabelInfo_int_String(void* instance, int label, const char* strInfo) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->setLabelInfo(label, String(strInfo));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FaceRecognizer::getLabelInfo
// as:     cv::face::FaceRecognizer::getLabelInfo (method) cv::face::FaceRecognizer (trait) . getLabelInfo
// Arg ARG Primitive(int) label= Primitive(int) = 
// Return value: string
cv_return_value_char_X cv_face_FaceRecognizer_getLabelInfo_const_int(void* instance, int label) {
    try {
        String ret = reinterpret_cast<cv::face::FaceRecognizer*>(instance)->getLabelInfo(label);
        return { Error::Code::StsOk, NULL, strdup(ret.c_str()) };
    } CVRS_CATCH(cv_return_value_char_X)
}

// parsed: cv::face::FaceRecognizer::getLabelsByString
// as:     cv::face::FaceRecognizer::getLabelsByString (method) cv::face::FaceRecognizer (trait) . getLabelsByString
// Arg ARG string str= string = 
// Return value: Vector[Primitive(int)]
cv_return_value_void_X cv_face_FaceRecognizer_getLabelsByString_const_String(void* instance, const char* str) {
    try {
        std::vector<int> ret = reinterpret_cast<cv::face::FaceRecognizer*>(instance)->getLabelsByString(String(str));
        return { Error::Code::StsOk, NULL, new std::vector<int>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FaceRecognizer::getThreshold
// as:     cv::face::FaceRecognizer::getThreshold (method) cv::face::FaceRecognizer (trait) . getThreshold
// Return value: Primitive(double)
cv_return_value_double cv_face_FaceRecognizer_getThreshold_const(void* instance) {
    try {
        double ret = reinterpret_cast<cv::face::FaceRecognizer*>(instance)->getThreshold();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_double)
}

// parsed: cv::face::FaceRecognizer::setThreshold
// as:     cv::face::FaceRecognizer::setThreshold (method) cv::face::FaceRecognizer (trait) . setThreshold
// Arg ARG Primitive(double) val= Primitive(double) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FaceRecognizer_setThreshold_double(void* instance, double val) {
    try {
        reinterpret_cast<cv::face::FaceRecognizer*>(instance)->setThreshold(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::Facemark::loadModel
// as:     cv::face::Facemark::loadModel (method) cv::face::Facemark (trait) . loadModel
// Arg ARG string model= string = 
// Return value: Primitive(void)
cv_return_value_void cv_face_Facemark_loadModel_String(void* instance, const char* model) {
    try {
        reinterpret_cast<cv::face::Facemark*>(instance)->loadModel(String(model));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::Facemark::fit
// as:     cv::face::Facemark::fit (method) cv::face::Facemark (trait) . fit
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) faces= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) landmarks= cv::_OutputArray (boxed) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_Facemark_fit__InputArray__InputArray__OutputArray(void* instance, void* image, void* faces, void* landmarks) {
    try {
        bool ret = reinterpret_cast<cv::face::Facemark*>(instance)->fit(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::_InputArray*>(faces), *reinterpret_cast<cv::_OutputArray*>(landmarks));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FacemarkAAM::fitConfig
// as:     cv::face::FacemarkAAM::fitConfig (method) cv::face::FacemarkAAM (trait) . fitConfig
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) roi= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) _landmarks= cv::_OutputArray (boxed) = 
// Arg ARG Vector[cv::face::FacemarkAAM::Config (boxed)] runtime_params= Vector[cv::face::FacemarkAAM::Config (boxed)] = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FacemarkAAM_fitConfig__InputArray__InputArray__OutputArray_VectorOfConfig(void* instance, void* image, void* roi, void* _landmarks, void* runtime_params) {
    try {
        bool ret = reinterpret_cast<cv::face::FacemarkAAM*>(instance)->fitConfig(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::_InputArray*>(roi), *reinterpret_cast<cv::_OutputArray*>(_landmarks), *reinterpret_cast<const std::vector<cv::face::FacemarkAAM::Config>*>(runtime_params));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FacemarkAAM::create
// as:     cv::face::FacemarkAAM::create (method) cv::face::FacemarkAAM (trait) . create
// Arg ARG cv::face::FacemarkAAM::Params (boxed) parameters= cv::face::FacemarkAAM::Params (boxed) = FacemarkAAM::Params()
// Return value: SmartPtr[cv::face::FacemarkAAM (boxed)]
cv_return_value_void_X cv_face_FacemarkAAM_create_Params(void* parameters) {
    try {
        Ptr<cv::face::FacemarkAAM> ret = cv::face::FacemarkAAM::create(*reinterpret_cast<const cv::face::FacemarkAAM::Params*>(parameters));
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::FacemarkAAM>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::FacemarkAAM::Config
void cv_FacemarkAAM_Config_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkAAM::Config*>(instance);
}
// parsed: cv::face::FacemarkAAM::Config::Config
// as:     cv::face::FacemarkAAM::Config::Config (constructor) cv::face::FacemarkAAM::Config . new
// Arg ARG cv::Mat (boxed) rot= cv::Mat (boxed) = Mat::eye(2,2,CV_32F)
// Arg ARG cv::Point2f (simple) trans= cv::Point2f (simple) = Point2f(0.0f, 0.0f)
// Arg ARG Primitive(float) scaling= Primitive(float) = 1.0f
// Arg ARG Primitive(int) scale_id= Primitive(int) = 0
// Return value: cv::face::FacemarkAAM::Config (boxed)
cv_return_value_void_X cv_face_FacemarkAAM_Config_Config_Mat_Point2f_float_int(void* rot, Point2fWrapper trans, float scaling, int scale_id) {
    try {
        cv::face::FacemarkAAM::Config* ret = new cv::face::FacemarkAAM::Config(*reinterpret_cast<cv::Mat*>(rot), *reinterpret_cast<cv::Point2f*>(&trans), scaling, scale_id);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::FacemarkAAM::Data
void cv_FacemarkAAM_Data_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkAAM::Data*>(instance);
}
// boxed class: cv::face::FacemarkAAM::Model
void cv_FacemarkAAM_Model_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkAAM::Model*>(instance);
}
// boxed class: cv::face::FacemarkAAM::Model::Texture
void cv_FacemarkAAM_Model_Texture_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkAAM::Model::Texture*>(instance);
}
// boxed class: cv::face::FacemarkAAM::Params
void cv_FacemarkAAM_Params_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkAAM::Params*>(instance);
}
// parsed: cv::face::FacemarkAAM::Params::Params
// as:     cv::face::FacemarkAAM::Params::Params (constructor) cv::face::FacemarkAAM::Params . default
// Return value: cv::face::FacemarkAAM::Params (boxed)
cv_return_value_void_X cv_face_FacemarkAAM_Params_Params() {
    try {
        cv::face::FacemarkAAM::Params* ret = new cv::face::FacemarkAAM::Params();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FacemarkAAM::Params::read
// as:     cv::face::FacemarkAAM::Params::read (method) cv::face::FacemarkAAM::Params . read
// Arg ARG cv::FileNode (boxed) unnamed_arg= cv::FileNode (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FacemarkAAM_Params_read_FileNode(void* instance, void* unnamed_arg) {
    try {
        reinterpret_cast<cv::face::FacemarkAAM::Params*>(instance)->read(*reinterpret_cast<const cv::FileNode*>(unnamed_arg));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FacemarkAAM::Params::write
// as:     cv::face::FacemarkAAM::Params::write (method) cv::face::FacemarkAAM::Params . write
// Arg ARG cv::FileStorage (boxed) unnamed_arg= cv::FileStorage (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FacemarkAAM_Params_write_const_FileStorage(void* instance, void* unnamed_arg) {
    try {
        reinterpret_cast<cv::face::FacemarkAAM::Params*>(instance)->write(*reinterpret_cast<cv::FileStorage*>(unnamed_arg));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FacemarkKazemi::training
// as:     cv::face::FacemarkKazemi::training (method) cv::face::FacemarkKazemi (trait) . training
// Arg ARG Vector[cv::Mat (boxed)] images= Vector[cv::Mat (boxed)] = 
// Arg ARG Vector[Vector[cv::Point2f (simple)]] landmarks= Vector[Vector[cv::Point2f (simple)]] = 
// Arg ARG string configfile= string = 
// Arg ARG cv::Size (simple) scale= cv::Size (simple) = 
// Arg ARG string modelFilename= string = "face_landmarks.dat"
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FacemarkKazemi_training_VectorOfMat_VectorOfVectorOfPoint2f_std_string_Size_std_string(void* instance, void* images, void* landmarks, const char* configfile, SizeWrapper scale, const char* modelFilename) {
    try {
        bool ret = reinterpret_cast<cv::face::FacemarkKazemi*>(instance)->training(*reinterpret_cast<std::vector<cv::Mat>*>(images), *reinterpret_cast<std::vector<std::vector<cv::Point2f>>*>(landmarks), String(configfile), *reinterpret_cast<cv::Size*>(&scale), String(modelFilename));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FacemarkKazemi::getFaces
// as:     cv::face::FacemarkKazemi::getFaces (method) cv::face::FacemarkKazemi (trait) . getFaces
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) faces= cv::_OutputArray (boxed) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FacemarkKazemi_getFaces__InputArray__OutputArray(void* instance, void* image, void* faces) {
    try {
        bool ret = reinterpret_cast<cv::face::FacemarkKazemi*>(instance)->getFaces(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<cv::_OutputArray*>(faces));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FacemarkKazemi::create
// as:     cv::face::FacemarkKazemi::create (method) cv::face::FacemarkKazemi (trait) . create
// Arg ARG cv::face::FacemarkKazemi::Params (boxed) parameters= cv::face::FacemarkKazemi::Params (boxed) = FacemarkKazemi::Params()
// Return value: SmartPtr[cv::face::FacemarkKazemi (boxed)]
cv_return_value_void_X cv_face_FacemarkKazemi_create_Params(void* parameters) {
    try {
        Ptr<cv::face::FacemarkKazemi> ret = cv::face::FacemarkKazemi::create(*reinterpret_cast<const cv::face::FacemarkKazemi::Params*>(parameters));
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::FacemarkKazemi>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::FacemarkKazemi::Params
void cv_FacemarkKazemi_Params_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkKazemi::Params*>(instance);
}
// parsed: cv::face::FacemarkKazemi::Params::Params
// as:     cv::face::FacemarkKazemi::Params::Params (constructor) cv::face::FacemarkKazemi::Params . default
// Return value: cv::face::FacemarkKazemi::Params (boxed)
cv_return_value_void_X cv_face_FacemarkKazemi_Params_Params() {
    try {
        cv::face::FacemarkKazemi::Params* ret = new cv::face::FacemarkKazemi::Params();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::FacemarkLBF
void cv_FacemarkLBF_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkLBF*>(instance);
}
// parsed: cv::face::FacemarkLBF::create
// as:     cv::face::FacemarkLBF::create (method) cv::face::FacemarkLBF . create
// Arg ARG cv::face::FacemarkLBF::Params (boxed) parameters= cv::face::FacemarkLBF::Params (boxed) = FacemarkLBF::Params()
// Return value: SmartPtr[cv::face::FacemarkLBF (boxed)]
cv_return_value_void_X cv_face_FacemarkLBF_create_Params(void* parameters) {
    try {
        Ptr<cv::face::FacemarkLBF> ret = cv::face::FacemarkLBF::create(*reinterpret_cast<const cv::face::FacemarkLBF::Params*>(parameters));
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::FacemarkLBF>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::FacemarkLBF::BBox
void cv_FacemarkLBF_BBox_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkLBF::BBox*>(instance);
}
// parsed: cv::face::FacemarkLBF::BBox::BBox
// as:     cv::face::FacemarkLBF::BBox::BBox (constructor) cv::face::FacemarkLBF::BBox . default
// Return value: cv::face::FacemarkLBF::BBox (boxed)
cv_return_value_void_X cv_face_FacemarkLBF_BBox_BBox() {
    try {
        cv::face::FacemarkLBF::BBox* ret = new cv::face::FacemarkLBF::BBox();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FacemarkLBF::BBox::BBox
// as:     cv::face::FacemarkLBF::BBox::BBox (constructor) cv::face::FacemarkLBF::BBox . new
// Arg ARG Primitive(double) x= Primitive(double) = 
// Arg ARG Primitive(double) y= Primitive(double) = 
// Arg ARG Primitive(double) w= Primitive(double) = 
// Arg ARG Primitive(double) h= Primitive(double) = 
// Return value: cv::face::FacemarkLBF::BBox (boxed)
cv_return_value_void_X cv_face_FacemarkLBF_BBox_BBox_double_double_double_double(double x, double y, double w, double h) {
    try {
        cv::face::FacemarkLBF::BBox* ret = new cv::face::FacemarkLBF::BBox(x, y, w, h);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FacemarkLBF::BBox::project
// as:     cv::face::FacemarkLBF::BBox::project (method) cv::face::FacemarkLBF::BBox . project
// Arg ARG cv::Mat (boxed) shape= cv::Mat (boxed) = 
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_FacemarkLBF_BBox_project_const_Mat(void* instance, void* shape) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::FacemarkLBF::BBox*>(instance)->project(*reinterpret_cast<const cv::Mat*>(shape));
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FacemarkLBF::BBox::reproject
// as:     cv::face::FacemarkLBF::BBox::reproject (method) cv::face::FacemarkLBF::BBox . reproject
// Arg ARG cv::Mat (boxed) shape= cv::Mat (boxed) = 
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_FacemarkLBF_BBox_reproject_const_Mat(void* instance, void* shape) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::FacemarkLBF::BBox*>(instance)->reproject(*reinterpret_cast<const cv::Mat*>(shape));
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::FacemarkLBF::Params
void cv_FacemarkLBF_Params_delete(void* instance) {
    delete reinterpret_cast<cv::face::FacemarkLBF::Params*>(instance);
}
// parsed: cv::face::FacemarkLBF::Params::Params
// as:     cv::face::FacemarkLBF::Params::Params (constructor) cv::face::FacemarkLBF::Params . default
// Return value: cv::face::FacemarkLBF::Params (boxed)
cv_return_value_void_X cv_face_FacemarkLBF_Params_Params() {
    try {
        cv::face::FacemarkLBF::Params* ret = new cv::face::FacemarkLBF::Params();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::FacemarkLBF::Params::read
// as:     cv::face::FacemarkLBF::Params::read (method) cv::face::FacemarkLBF::Params . read
// Arg ARG cv::FileNode (boxed) unnamed_arg= cv::FileNode (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FacemarkLBF_Params_read_FileNode(void* instance, void* unnamed_arg) {
    try {
        reinterpret_cast<cv::face::FacemarkLBF::Params*>(instance)->read(*reinterpret_cast<const cv::FileNode*>(unnamed_arg));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FacemarkLBF::Params::write
// as:     cv::face::FacemarkLBF::Params::write (method) cv::face::FacemarkLBF::Params . write
// Arg ARG cv::FileStorage (boxed) unnamed_arg= cv::FileStorage (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_FacemarkLBF_Params_write_const_FileStorage(void* instance, void* unnamed_arg) {
    try {
        reinterpret_cast<cv::face::FacemarkLBF::Params*>(instance)->write(*reinterpret_cast<cv::FileStorage*>(unnamed_arg));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FacemarkTrain::addTrainingSample
// as:     cv::face::FacemarkTrain::addTrainingSample (method) cv::face::FacemarkTrain (trait) . addTrainingSample
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_InputArray (boxed) landmarks= cv::_InputArray (boxed) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FacemarkTrain_addTrainingSample__InputArray__InputArray(void* instance, void* image, void* landmarks) {
    try {
        bool ret = reinterpret_cast<cv::face::FacemarkTrain*>(instance)->addTrainingSample(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<const cv::_InputArray*>(landmarks));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FacemarkTrain::training
// as:     cv::face::FacemarkTrain::training (method) cv::face::FacemarkTrain (trait) . training
// Arg ARG RawPtr[Primitive(void)] * parameters= (ptr) RawPtr[Primitive(void)] = 0
// Return value: Primitive(void)
cv_return_value_void cv_face_FacemarkTrain_training_void_X(void* instance, void* parameters) {
    try {
        reinterpret_cast<cv::face::FacemarkTrain*>(instance)->training(parameters);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::FacemarkTrain::getFaces
// as:     cv::face::FacemarkTrain::getFaces (method) cv::face::FacemarkTrain (trait) . getFaces
// Arg ARG cv::_InputArray (boxed) image= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) faces= cv::_OutputArray (boxed) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FacemarkTrain_getFaces__InputArray__OutputArray(void* instance, void* image, void* faces) {
    try {
        bool ret = reinterpret_cast<cv::face::FacemarkTrain*>(instance)->getFaces(*reinterpret_cast<const cv::_InputArray*>(image), *reinterpret_cast<cv::_OutputArray*>(faces));
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::FacemarkTrain::getData
// as:     cv::face::FacemarkTrain::getData (method) cv::face::FacemarkTrain (trait) . getData
// Arg ARG RawPtr[Primitive(void)] * items= (ptr) RawPtr[Primitive(void)] = 0
// Return value: Primitive(bool)
cv_return_value_bool cv_face_FacemarkTrain_getData_void_X(void* instance, void* items) {
    try {
        bool ret = reinterpret_cast<cv::face::FacemarkTrain*>(instance)->getData(items);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// boxed class: cv::face::FisherFaceRecognizer
void cv_FisherFaceRecognizer_delete(void* instance) {
    delete reinterpret_cast<cv::face::FisherFaceRecognizer*>(instance);
}
// parsed: cv::face::FisherFaceRecognizer::create
// as:     cv::face::FisherFaceRecognizer::create (method) cv::face::FisherFaceRecognizer . create
// Arg ARG Primitive(int) num_components= Primitive(int) = 0
// Arg ARG Primitive(double) threshold= Primitive(double) = DBL_MAX
// Return value: SmartPtr[cv::face::FisherFaceRecognizer (boxed)]
cv_return_value_void_X cv_face_FisherFaceRecognizer_create_int_double(int num_components, double threshold) {
    try {
        Ptr<cv::face::FisherFaceRecognizer> ret = cv::face::FisherFaceRecognizer::create(num_components, threshold);
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::FisherFaceRecognizer>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::LBPHFaceRecognizer::getGridX
// as:     cv::face::LBPHFaceRecognizer::getGridX (method) cv::face::LBPHFaceRecognizer (trait) . getGridX
// Return value: Primitive(int)
cv_return_value_int cv_face_LBPHFaceRecognizer_getGridX_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getGridX();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::LBPHFaceRecognizer::setGridX
// as:     cv::face::LBPHFaceRecognizer::setGridX (method) cv::face::LBPHFaceRecognizer (trait) . setGridX
// Arg ARG Primitive(int) val= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_LBPHFaceRecognizer_setGridX_int(void* instance, int val) {
    try {
        reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->setGridX(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::LBPHFaceRecognizer::getGridY
// as:     cv::face::LBPHFaceRecognizer::getGridY (method) cv::face::LBPHFaceRecognizer (trait) . getGridY
// Return value: Primitive(int)
cv_return_value_int cv_face_LBPHFaceRecognizer_getGridY_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getGridY();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::LBPHFaceRecognizer::setGridY
// as:     cv::face::LBPHFaceRecognizer::setGridY (method) cv::face::LBPHFaceRecognizer (trait) . setGridY
// Arg ARG Primitive(int) val= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_LBPHFaceRecognizer_setGridY_int(void* instance, int val) {
    try {
        reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->setGridY(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::LBPHFaceRecognizer::getRadius
// as:     cv::face::LBPHFaceRecognizer::getRadius (method) cv::face::LBPHFaceRecognizer (trait) . getRadius
// Return value: Primitive(int)
cv_return_value_int cv_face_LBPHFaceRecognizer_getRadius_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getRadius();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::LBPHFaceRecognizer::setRadius
// as:     cv::face::LBPHFaceRecognizer::setRadius (method) cv::face::LBPHFaceRecognizer (trait) . setRadius
// Arg ARG Primitive(int) val= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_LBPHFaceRecognizer_setRadius_int(void* instance, int val) {
    try {
        reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->setRadius(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::LBPHFaceRecognizer::getNeighbors
// as:     cv::face::LBPHFaceRecognizer::getNeighbors (method) cv::face::LBPHFaceRecognizer (trait) . getNeighbors
// Return value: Primitive(int)
cv_return_value_int cv_face_LBPHFaceRecognizer_getNeighbors_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getNeighbors();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::LBPHFaceRecognizer::setNeighbors
// as:     cv::face::LBPHFaceRecognizer::setNeighbors (method) cv::face::LBPHFaceRecognizer (trait) . setNeighbors
// Arg ARG Primitive(int) val= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_LBPHFaceRecognizer_setNeighbors_int(void* instance, int val) {
    try {
        reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->setNeighbors(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::LBPHFaceRecognizer::getThreshold
// as:     cv::face::LBPHFaceRecognizer::getThreshold (method) cv::face::LBPHFaceRecognizer (trait) . getThreshold
// Return value: Primitive(double)
cv_return_value_double cv_face_LBPHFaceRecognizer_getThreshold_const(void* instance) {
    try {
        double ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getThreshold();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_double)
}

// parsed: cv::face::LBPHFaceRecognizer::setThreshold
// as:     cv::face::LBPHFaceRecognizer::setThreshold (method) cv::face::LBPHFaceRecognizer (trait) . setThreshold
// Arg ARG Primitive(double) val= Primitive(double) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_LBPHFaceRecognizer_setThreshold_double(void* instance, double val) {
    try {
        reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->setThreshold(val);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::LBPHFaceRecognizer::getHistograms
// as:     cv::face::LBPHFaceRecognizer::getHistograms (method) cv::face::LBPHFaceRecognizer (trait) . getHistograms
// Return value: Vector[cv::Mat (boxed)]
cv_return_value_void_X cv_face_LBPHFaceRecognizer_getHistograms_const(void* instance) {
    try {
        std::vector<cv::Mat> ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getHistograms();
        return { Error::Code::StsOk, NULL, new std::vector<cv::Mat>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::LBPHFaceRecognizer::getLabels
// as:     cv::face::LBPHFaceRecognizer::getLabels (method) cv::face::LBPHFaceRecognizer (trait) . getLabels
// Return value: cv::Mat (boxed)
cv_return_value_void_X cv_face_LBPHFaceRecognizer_getLabels_const(void* instance) {
    try {
        cv::Mat ret = reinterpret_cast<cv::face::LBPHFaceRecognizer*>(instance)->getLabels();
        return { Error::Code::StsOk, NULL, new cv::Mat(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::LBPHFaceRecognizer::create
// as:     cv::face::LBPHFaceRecognizer::create (method) cv::face::LBPHFaceRecognizer (trait) . create
// Arg ARG Primitive(int) radius= Primitive(int) = 1
// Arg ARG Primitive(int) neighbors= Primitive(int) = 8
// Arg ARG Primitive(int) grid_x= Primitive(int) = 8
// Arg ARG Primitive(int) grid_y= Primitive(int) = 8
// Arg ARG Primitive(double) threshold= Primitive(double) = DBL_MAX
// Return value: SmartPtr[cv::face::LBPHFaceRecognizer (boxed)]
cv_return_value_void_X cv_face_LBPHFaceRecognizer_create_int_int_int_int_double(int radius, int neighbors, int grid_x, int grid_y, double threshold) {
    try {
        Ptr<cv::face::LBPHFaceRecognizer> ret = cv::face::LBPHFaceRecognizer::create(radius, neighbors, grid_x, grid_y, threshold);
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::LBPHFaceRecognizer>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::MACE::salt
// as:     cv::face::MACE::salt (method) cv::face::MACE (trait) . salt
// Arg ARG string passphrase= string = 
// Return value: Primitive(void)
cv_return_value_void cv_face_MACE_salt_String(void* instance, const char* passphrase) {
    try {
        reinterpret_cast<cv::face::MACE*>(instance)->salt(String(passphrase));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::PredictCollector::init
// as:     cv::face::PredictCollector::init (method) cv::face::PredictCollector (trait) . init
// Arg ARG Primitive(size_t) size= Primitive(size_t) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_PredictCollector_init_size_t(void* instance, std::size_t size) {
    try {
        reinterpret_cast<cv::face::PredictCollector*>(instance)->init(size);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::PredictCollector::collect
// as:     cv::face::PredictCollector::collect (method) cv::face::PredictCollector (trait) . collect
// Arg ARG Primitive(int) label= Primitive(int) = 
// Arg ARG Primitive(double) dist= Primitive(double) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_PredictCollector_collect_int_double(void* instance, int label, double dist) {
    try {
        bool ret = reinterpret_cast<cv::face::PredictCollector*>(instance)->collect(label, dist);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// boxed class: cv::face::StandardCollector
void cv_StandardCollector_delete(void* instance) {
    delete reinterpret_cast<cv::face::StandardCollector*>(instance);
}
// parsed: cv::face::StandardCollector::StandardCollector
// as:     cv::face::StandardCollector::StandardCollector (constructor) cv::face::StandardCollector . new
// Arg ARG Primitive(double) threshold_= Primitive(double) = DBL_MAX
// Return value: cv::face::StandardCollector (boxed)
cv_return_value_void_X cv_face_StandardCollector_StandardCollector_double(double threshold_) {
    try {
        cv::face::StandardCollector* ret = new cv::face::StandardCollector(threshold_);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::face::StandardCollector::init
// as:     cv::face::StandardCollector::init (method) cv::face::StandardCollector . init
// Arg ARG Primitive(size_t) size= Primitive(size_t) = 
// Return value: Primitive(void)
cv_return_value_void cv_face_StandardCollector_init_size_t(void* instance, std::size_t size) {
    try {
        reinterpret_cast<cv::face::StandardCollector*>(instance)->init(size);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::face::StandardCollector::collect
// as:     cv::face::StandardCollector::collect (method) cv::face::StandardCollector . collect
// Arg ARG Primitive(int) label= Primitive(int) = 
// Arg ARG Primitive(double) dist= Primitive(double) = 
// Return value: Primitive(bool)
cv_return_value_bool cv_face_StandardCollector_collect_int_double(void* instance, int label, double dist) {
    try {
        bool ret = reinterpret_cast<cv::face::StandardCollector*>(instance)->collect(label, dist);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_bool)
}

// parsed: cv::face::StandardCollector::getMinLabel
// as:     cv::face::StandardCollector::getMinLabel (method) cv::face::StandardCollector . getMinLabel
// Return value: Primitive(int)
cv_return_value_int cv_face_StandardCollector_getMinLabel_const(void* instance) {
    try {
        int ret = reinterpret_cast<cv::face::StandardCollector*>(instance)->getMinLabel();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::face::StandardCollector::getMinDist
// as:     cv::face::StandardCollector::getMinDist (method) cv::face::StandardCollector . getMinDist
// Return value: Primitive(double)
cv_return_value_double cv_face_StandardCollector_getMinDist_const(void* instance) {
    try {
        double ret = reinterpret_cast<cv::face::StandardCollector*>(instance)->getMinDist();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_double)
}

// parsed: cv::face::StandardCollector::create
// as:     cv::face::StandardCollector::create (method) cv::face::StandardCollector . create
// Arg ARG Primitive(double) threshold= Primitive(double) = DBL_MAX
// Return value: SmartPtr[cv::face::StandardCollector (boxed)]
cv_return_value_void_X cv_face_StandardCollector_create_double(double threshold) {
    try {
        Ptr<cv::face::StandardCollector> ret = cv::face::StandardCollector::create(threshold);
        return { Error::Code::StsOk, NULL, new Ptr<cv::face::StandardCollector>(ret) };
    } CVRS_CATCH(cv_return_value_void_X)
}

// boxed class: cv::face::StandardCollector::PredictResult
void cv_StandardCollector_PredictResult_delete(void* instance) {
    delete reinterpret_cast<cv::face::StandardCollector::PredictResult*>(instance);
}
// parsed: cv::face::StandardCollector::PredictResult::PredictResult
// as:     cv::face::StandardCollector::PredictResult::PredictResult (constructor) cv::face::StandardCollector::PredictResult . new
// Arg ARG Primitive(int) label_= Primitive(int) = -1
// Arg ARG Primitive(double) distance_= Primitive(double) = DBL_MAX
// Return value: cv::face::StandardCollector::PredictResult (boxed)
cv_return_value_void_X cv_face_StandardCollector_PredictResult_PredictResult_int_double(int label_, double distance_) {
    try {
        cv::face::StandardCollector::PredictResult* ret = new cv::face::StandardCollector::PredictResult(label_, distance_);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}



}
