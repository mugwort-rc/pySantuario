/*
 * XSECCryptoKeyDSA.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECCryptoKeyDSA.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoKeyDSA.hpp>

namespace pyxsec {

class XSECCryptoKeyDSAWrapper
: public XSECCryptoKeyDSA, public boost::python::wrapper<XSECCryptoKeyDSA>
{
public:
XSECCryptoKeyDSAWrapper()
: XSECCryptoKeyDSA()
{}

XSECCryptoKey::KeyType getKeyType() const {
	if(boost::python::override getKeyType = this->get_override("getKeyType")){
		return getKeyType();
	}else{
		return XSECCryptoKeyDSA::getKeyType();
	}
}

XSECCryptoKey * clone() const {
	return this->get_override("clone")();
}

bool verifyBase64Signature(unsigned char * hashBuf, unsigned int hashLen, char * base64Signature, unsigned int sigLen) {
	return this->get_override("verifyBase64Signature")(hashBuf, hashLen, base64Signature, sigLen);
}

unsigned int signBase64Signature(unsigned char * hashBuf, unsigned int hashLen, char * base64SignatureBuf, unsigned int base64SignatureBufLen) {
	return this->get_override("verifyBase64Signature")(hashBuf, hashLen, base64SignatureBuf, base64SignatureBufLen);
}

void loadPBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadPBase64BigNums")(b64, len);
}

void loadQBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadQBase64BigNums")(b64, len);
}

void loadGBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadGBase64BigNums")(b64, len);
}

void loadYBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadYBase64BigNums")(b64, len);
}

void loadJBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadJBase64BigNums")(b64, len);
}

//! XSECCryptoKey
const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

};

void XSECCryptoKeyDSA_init(void) {
	//! XSECCryptoKeyDSA
	boost::python::class_<XSECCryptoKeyDSAWrapper, boost::noncopyable, boost::python::bases<XSECCryptoKey> >("XSECCryptoKeyDSA")
			.def("getKeyType", &XSECCryptoKeyDSA::getKeyType)
			.def("clone", boost::python::pure_virtual(&XSECCryptoKeyDSA::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("verifyBase64Signature", boost::python::pure_virtual(&XSECCryptoKeyDSA::verifyBase64Signature))
			.def("signBase64Signature", boost::python::pure_virtual(&XSECCryptoKeyDSA::signBase64Signature))
			.def("loadPBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyDSA::loadPBase64BigNums))
			.def("loadQBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyDSA::loadQBase64BigNums))
			.def("loadGBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyDSA::loadGBase64BigNums))
			.def("loadYBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyDSA::loadYBase64BigNums))
			.def("loadJBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyDSA::loadJBase64BigNums))
			;
}

} /* namespace pyxsec */
