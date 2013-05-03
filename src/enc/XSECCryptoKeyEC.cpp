/*
 * XSECCryptoKeyEC.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECCryptoKeyEC.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoKeyEC.hpp>

namespace pyxsec {

class XSECCryptoKeyECWrapper
: public XSECCryptoKeyEC, public boost::python::wrapper<XSECCryptoKeyEC>
{
public:
XSECCryptoKeyECWrapper()
: XSECCryptoKeyEC()
{}

XSECCryptoKey::KeyType getKeyType() const {
	if(boost::python::override getKeyType = this->get_override("getKeyType")){
		return getKeyType();
	}else{
		return XSECCryptoKeyEC::getKeyType();
	}
}

XSECCryptoKey * clone() const {
	return this->get_override("clone")();
}

bool verifyBase64SignatureDSA(unsigned char * hashBuf, unsigned int hashLen, char * base64Signature, unsigned int sigLen) {
	return this->get_override("verifyBase64SignatureDSA")(hashBuf, hashLen, base64Signature, sigLen);
}

unsigned int signBase64SignatureDSA(unsigned char * hashBuf, unsigned int hashLen, char * base64SignatureBuf, unsigned int base64SignatureBufLen) {
	return this->get_override("signBase64SignatureDSA")(hashBuf, hashLen, base64SignatureBuf, base64SignatureBufLen);
}

void loadPublicKeyBase64(const char* curveName, const char * b64, unsigned int len) {
	this->get_override("loadPublicKeyBase64")(curveName, b64, len);
}

//! XSECCryptoKey
const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

};

void XSECCryptoKeyEC_init(void) {
	//! XSECCryptoKeyEC
	boost::python::class_<XSECCryptoKeyECWrapper, boost::noncopyable, boost::python::bases<XSECCryptoKey> >("XSECCryptoKeyEC")
			.def("getKeyType", &XSECCryptoKeyEC::getKeyType)
			.def("clone", boost::python::pure_virtual(&XSECCryptoKeyEC::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("verifyBase64SignatureDSA", boost::python::pure_virtual(&XSECCryptoKeyEC::verifyBase64SignatureDSA))
			.def("signBase64SignatureDSA", boost::python::pure_virtual(&XSECCryptoKeyEC::signBase64SignatureDSA))
			.def("loadPublicKeyBase64", boost::python::pure_virtual(&XSECCryptoKeyEC::loadPublicKeyBase64))
			;
}

} /* namespace pyxsec */
