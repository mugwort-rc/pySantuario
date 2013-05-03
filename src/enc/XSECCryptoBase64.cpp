/*
 * XSECCryptoBase64.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECCryptoBase64.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoBase64.hpp>

namespace pyxsec {

class XSECCryptoBase64Wrapper
: public XSECCryptoBase64, public boost::python::wrapper<XSECCryptoBase64>
{
friend class def_visitor_access;
public:
XSECCryptoBase64Wrapper()
: XSECCryptoBase64()
{}

void decodeInit(void) {
	this->get_override("decodeInit")();
}

unsigned int decode(const unsigned char * inData, unsigned int inLength, unsigned char * outData, unsigned int outLength) {
	//! TODO: pythonize
	return this->get_override("decode")(inData, inLength, outData, outLength);
}

unsigned int decodeFinish(unsigned char * outData, unsigned int outLength) {
	//! TODO: pythonize
	return this->get_override("decodeFinish")(outData, outLength);
}

void encodeInit(void) {
	this->get_override("encodeInit")();
}

unsigned int encode(const unsigned char * inData, unsigned int inLength, unsigned char * outData, unsigned int outLength) {
	//! TODO: pythonize
	return this->get_override("encode")(inData, inLength, outData, outLength);
}

unsigned int encodeFinish(unsigned char * outData, unsigned int outLength) {
	//! TODO: pythonize
	return this->get_override("encodeFinish")(outData, outLength);
}

};

void XSECCryptoBase64_init(void) {
	//! XSECCryptoBase64
	boost::python::class_<XSECCryptoBase64Wrapper, boost::noncopyable>("XSECCryptoBase64")
			.def("decodeInit", boost::python::pure_virtual(&XSECCryptoBase64::decodeInit))
			.def("decode", boost::python::pure_virtual(&XSECCryptoBase64::decode))
			.def("decodeFinish", boost::python::pure_virtual(&XSECCryptoBase64::decodeFinish))
			.def("encodeInit", boost::python::pure_virtual(&XSECCryptoBase64::encodeInit))
			.def("encode", boost::python::pure_virtual(&XSECCryptoBase64::encode))
			.def("encodeFinish", boost::python::pure_virtual(&XSECCryptoBase64::encodeFinish))
			.def("cleanBuffer", &XSECCryptoBase64::cleanBuffer, boost::python::return_value_policy<boost::python::return_by_value>())
			.staticmethod("cleanBuffer")
			;
}

} /* namespace pyxsec */
