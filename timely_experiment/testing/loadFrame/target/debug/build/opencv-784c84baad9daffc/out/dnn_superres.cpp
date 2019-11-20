#include "stdint.h"
#include "common.h"
#include <string>
#include "common_opencv.h"
using namespace cv;
#include "types.h"
#include "return_types.h"
#include "/Users/calumbruton/.cargo/registry/src/github.com-1ecc6299db9ec823/opencv-0.26.6/headers/4.1/opencv2/dnn_superres.hpp"

extern "C" {

// boxed class: cv::dnn_superres::DnnSuperResImpl
void cv_DnnSuperResImpl_delete(void* instance) {
    delete reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance);
}
// parsed: cv::dnn_superres::DnnSuperResImpl::DnnSuperResImpl
// as:     cv::dnn_superres::DnnSuperResImpl::DnnSuperResImpl (constructor) cv::dnn_superres::DnnSuperResImpl . default
// Return value: cv::dnn_superres::DnnSuperResImpl (boxed)
cv_return_value_void_X cv_dnn_superres_DnnSuperResImpl_DnnSuperResImpl() {
    try {
        cv::dnn_superres::DnnSuperResImpl* ret = new cv::dnn_superres::DnnSuperResImpl();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::DnnSuperResImpl
// as:     cv::dnn_superres::DnnSuperResImpl::DnnSuperResImpl (constructor) cv::dnn_superres::DnnSuperResImpl . new
// Arg ARG string algo= string = 
// Arg ARG Primitive(int) scale= Primitive(int) = 
// Return value: cv::dnn_superres::DnnSuperResImpl (boxed)
cv_return_value_void_X cv_dnn_superres_DnnSuperResImpl_DnnSuperResImpl_std_string_int(const char* algo, int scale) {
    try {
        cv::dnn_superres::DnnSuperResImpl* ret = new cv::dnn_superres::DnnSuperResImpl(String(algo), scale);
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_void_X)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::readModel
// as:     cv::dnn_superres::DnnSuperResImpl::readModel (method) cv::dnn_superres::DnnSuperResImpl . readModel
// Arg ARG string path= string = 
// Return value: Primitive(void)
cv_return_value_void cv_dnn_superres_DnnSuperResImpl_readModel_std_string(void* instance, const char* path) {
    try {
        reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->readModel(String(path));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::readModel
// as:     cv::dnn_superres::DnnSuperResImpl::readModel (method) cv::dnn_superres::DnnSuperResImpl . readModel
// Arg ARG string weights= string = 
// Arg ARG string definition= string = 
// Return value: Primitive(void)
cv_return_value_void cv_dnn_superres_DnnSuperResImpl_readModel_std_string_std_string(void* instance, const char* weights, const char* definition) {
    try {
        reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->readModel(String(weights), String(definition));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::setModel
// as:     cv::dnn_superres::DnnSuperResImpl::setModel (method) cv::dnn_superres::DnnSuperResImpl . setModel
// Arg ARG string algo= string = 
// Arg ARG Primitive(int) scale= Primitive(int) = 
// Return value: Primitive(void)
cv_return_value_void cv_dnn_superres_DnnSuperResImpl_setModel_std_string_int(void* instance, const char* algo, int scale) {
    try {
        reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->setModel(String(algo), scale);
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::upsample
// as:     cv::dnn_superres::DnnSuperResImpl::upsample (method) cv::dnn_superres::DnnSuperResImpl . upsample
// Arg ARG cv::_InputArray (boxed) img= cv::_InputArray (boxed) = 
// Arg ARG cv::_OutputArray (boxed) result= cv::_OutputArray (boxed) = 
// Return value: Primitive(void)
cv_return_value_void cv_dnn_superres_DnnSuperResImpl_upsample__InputArray__OutputArray(void* instance, void* img, void* result) {
    try {
        reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->upsample(*reinterpret_cast<const cv::_InputArray*>(img), *reinterpret_cast<cv::_OutputArray*>(result));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::upsampleMultioutput
// as:     cv::dnn_superres::DnnSuperResImpl::upsampleMultioutput (method) cv::dnn_superres::DnnSuperResImpl . upsampleMultioutput
// Arg ARG cv::_InputArray (boxed) img= cv::_InputArray (boxed) = 
// Arg ARG Vector[cv::Mat (boxed)] imgs_new= Vector[cv::Mat (boxed)] = 
// Arg ARG Vector[Primitive(int)] scale_factors= Vector[Primitive(int)] = 
// Arg ARG Vector[string] node_names= Vector[string] = 
// Return value: Primitive(void)
cv_return_value_void cv_dnn_superres_DnnSuperResImpl_upsampleMultioutput__InputArray_VectorOfMat_VectorOfint_VectorOfString(void* instance, void* img, void* imgs_new, void* scale_factors, void* node_names) {
    try {
        reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->upsampleMultioutput(*reinterpret_cast<const cv::_InputArray*>(img), *reinterpret_cast<std::vector<cv::Mat>*>(imgs_new), *reinterpret_cast<const std::vector<int>*>(scale_factors), *reinterpret_cast<const std::vector<String>*>(node_names));
        return { Error::Code::StsOk, NULL };
    } CVRS_CATCH(cv_return_value_void)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::getScale
// as:     cv::dnn_superres::DnnSuperResImpl::getScale (method) cv::dnn_superres::DnnSuperResImpl . getScale
// Return value: Primitive(int)
cv_return_value_int cv_dnn_superres_DnnSuperResImpl_getScale(void* instance) {
    try {
        int ret = reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->getScale();
        return { Error::Code::StsOk, NULL, ret };
    } CVRS_CATCH(cv_return_value_int)
}

// parsed: cv::dnn_superres::DnnSuperResImpl::getAlgorithm
// as:     cv::dnn_superres::DnnSuperResImpl::getAlgorithm (method) cv::dnn_superres::DnnSuperResImpl . getAlgorithm
// Return value: string
cv_return_value_char_X cv_dnn_superres_DnnSuperResImpl_getAlgorithm(void* instance) {
    try {
        String ret = reinterpret_cast<cv::dnn_superres::DnnSuperResImpl*>(instance)->getAlgorithm();
        return { Error::Code::StsOk, NULL, strdup(ret.c_str()) };
    } CVRS_CATCH(cv_return_value_char_X)
}



}
