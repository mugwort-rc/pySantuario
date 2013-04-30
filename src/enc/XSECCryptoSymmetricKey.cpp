/*
 * XSECCryptoSymmetricKey.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XSECCryptoSymmetricKey.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoSymmetricKey.hpp>

namespace pyxsec {

class XSECCryptoSymmetricKeyWrapper
: public XSECCryptoSymmetricKey, public boost::python::wrapper<XSECCryptoSymmetricKey>
{
public:
XSECCryptoSymmetricKeyWrapper()
: XSECCryptoSymmetricKey()
{}

KeyType getKeyType() const {
	if(boost::python::override getKeyType = this->get_override("getKeyType")){
		return getKeyType();
	}else{
		return XSECCryptoSymmetricKey::getKeyType();
	}
}

const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

XSECCryptoKey * clone() const {
	return this->get_override("clone")();
}

SymmetricKeyType getSymmetricKeyType(void) const {
	return this->get_override("getSymmetricKeyType")();
}

void setKey(const unsigned char * key, unsigned int keyLen) {
	this->get_override("setKey")(key, keyLen);
}

bool decryptInit(bool doPad, SymmetricKeyMode mode, const unsigned char* iv, const unsigned char* tag, unsigned int taglen) {
	return this->get_override("getSymmetricKeyType")(doPad, mode, std::string(reinterpret_cast<const char*>(iv)), std::string(reinterpret_cast<const char*>(tag), taglen), taglen);
}

unsigned int decrypt(const unsigned char * inBuf, unsigned char * plainBuf, unsigned int inLength, unsigned int maxOutLength) {
	//! TODO: pythonize
	return this->get_override("decrypt")(inBuf, plainBuf, inLength, maxOutLength);
}

unsigned int decryptFinish(unsigned char * plainBuf, unsigned int maxOutLength) {
	//! TODO: pythonize
	return this->get_override("decryptFinish")(plainBuf, maxOutLength);
}

bool encryptInit(bool doPad, SymmetricKeyMode mode, const unsigned char * iv) {
	return this->get_override("encryptInit")(doPad, mode, std::string(reinterpret_cast<const char*>(iv)));
}

unsigned int encrypt(const unsigned char * inBuf, unsigned char * cipherBuf, unsigned int inLength, unsigned int maxOutLength) {
	//! TODO: pythonize
	return this->get_override("encrypt")(inBuf, cipherBuf, inLength, maxOutLength);
}

unsigned int encryptFinish(unsigned char * plainBuf, unsigned int maxOutLength, unsigned int taglen) {
	//! TODO: pythonize
	return this->get_override("encryptFinish")(plainBuf, maxOutLength, taglen);
}

};

void XSECCryptoSymmetricKey_init(void) {
	//! XSECCryptoSymmetricKey
	auto XSECCryptoSymmetricKey_ = boost::python::class_<XSECCryptoSymmetricKeyWrapper, boost::noncopyable, boost::python::bases<XSECCryptoKey> >("XSECCryptoSymmetricKey")
			.def("getKeyType", &XSECCryptoSymmetricKey::getKeyType)
			.def("getProviderName", boost::python::pure_virtual(&XSECCryptoSymmetricKey::getProviderName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clone", boost::python::pure_virtual(&XSECCryptoSymmetricKey::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSymmetricKeyType", boost::python::pure_virtual(&XSECCryptoSymmetricKey::getSymmetricKeyType))
			.def("setKey", boost::python::pure_virtual(&XSECCryptoSymmetricKey::setKey))
			.def("decryptInit", boost::python::pure_virtual(&XSECCryptoSymmetricKey::decryptInit))
			.def("decrypt", boost::python::pure_virtual(&XSECCryptoSymmetricKey::decrypt))
			.def("decryptFinish", boost::python::pure_virtual(&XSECCryptoSymmetricKey::decryptFinish))
			.def("encryptInit", boost::python::pure_virtual(&XSECCryptoSymmetricKey::encryptInit))
			.def("encrypt", boost::python::pure_virtual(&XSECCryptoSymmetricKey::encrypt))
			.def("encryptFinish", boost::python::pure_virtual(&XSECCryptoSymmetricKey::encryptFinish))
			;
	boost::python::scope XSECCryptoSymmetricKeyScope = XSECCryptoSymmetricKey_;
	//! XSECCryptoSymmetricKey::SymmetricKeyType
	boost::python::enum_<XSECCryptoSymmetricKey::SymmetricKeyType>("SymmetricKeyType")
			.value("KEY_NONE", XSECCryptoSymmetricKey::KEY_NONE)
			.value("KEY_3DES_192", XSECCryptoSymmetricKey::KEY_3DES_192)
			.value("KEY_AES_128", XSECCryptoSymmetricKey::KEY_AES_128)
			.value("KEY_AES_192", XSECCryptoSymmetricKey::KEY_AES_192)
			.value("KEY_AES_256", XSECCryptoSymmetricKey::KEY_AES_256)
			.export_values()
			;
	//! XSECCryptoSymmetricKey::SymmetricKeyMode
	boost::python::enum_<XSECCryptoSymmetricKey::SymmetricKeyMode>("SymmetricKeyMode")
			.value("MODE_NONE", XSECCryptoSymmetricKey::MODE_NONE)
			.value("MODE_ECB", XSECCryptoSymmetricKey::MODE_ECB)
			.value("MODE_CBC", XSECCryptoSymmetricKey::MODE_CBC)
			.value("MODE_GCM", XSECCryptoSymmetricKey::MODE_GCM)
			.export_values()
			;
}

} /* namespace pyxsec */
