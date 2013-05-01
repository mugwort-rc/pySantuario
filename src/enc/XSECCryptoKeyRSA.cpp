/*
 * XSECCryptoKeyRSA.cpp
 *
 *  Created on: 2013/05/01
 *      Author: mugwort_rc
 */

#include "XSECCryptoKeyRSA.h"

#include <boost/python.hpp>
#include <boost/scoped_ptr.hpp>

#include <xsec/enc/XSECCryptoKeyRSA.hpp>

namespace pyxsec {

class XSECCryptoKeyRSAWrapper
: public XSECCryptoKeyRSA, public boost::python::wrapper<XSECCryptoKeyRSA>
{
public:
XSECCryptoKeyRSAWrapper()
: XSECCryptoKeyRSA()
{}

XSECCryptoKey::KeyType getKeyType() const {
	if(boost::python::override getKeyType = this->get_override("getKeyType")){
		return getKeyType();
	}else{
		return XSECCryptoKeyRSA::getKeyType();
	}
}

XSECCryptoKey * clone() const {
	return this->get_override("clone")();
}

void setOAEPparams(unsigned char * params, unsigned int paramsLen) {
	this->get_override("setOAEPparams")(std::string(reinterpret_cast<char*>(params), paramsLen));
}

unsigned int getOAEPparamsLen(void) const {
	return this->get_override("getOAEPparamsLen")();
}

const unsigned char * getOAEPparams(void) const {
	boost::python::object obj = this->get_override("getOAEPparams")();
	std::string result = boost::python::extract<std::string>(obj);
	boost::scoped_ptr<unsigned char> buffer(new unsigned char[result.size()+1]);
	memset(buffer.get(), 0, result.size()+1);
	memcpy(buffer.get(), result.c_str(), result.size());
	return buffer.get();
}

void setMGF(maskGenerationFunc mgf) {
	this->get_override("setMGF")(mgf);
}

enum maskGenerationFunc getMGF(void) const {
	return this->get_override("getMGF")();
}

bool verifySHA1PKCS1Base64Signature(const unsigned char * hashBuf, unsigned int hashLen, const char * base64Signature, unsigned int sigLen, hashMethod hm) {
	//! TODO: pythonize
	return this->get_override("verifySHA1PKCS1Base64Signature")(hashBuf, hashLen, base64Signature, sigLen, hm);
}

unsigned int signSHA1PKCS1Base64Signature(unsigned char * hashBuf, unsigned int hashLen, char * base64SignatureBuf, unsigned int base64SignatureBufLen, hashMethod hm) {
	//! TODO: pythonize
	return this->get_override("signSHA1PKCS1Base64Signature")(hashBuf, hashLen, base64SignatureBuf, base64SignatureBufLen, hm);
}

unsigned int privateDecrypt(const unsigned char * inBuf, unsigned char * plainBuf, unsigned int inLength, unsigned int maxOutLength, PaddingType padding, hashMethod hm) {
	//! TODO: pythonize
	return this->get_override("privateDecrypt")(inBuf, plainBuf, inLength, maxOutLength, padding, hm);
}

unsigned int publicEncrypt(const unsigned char * inBuf, unsigned char * cipherBuf, unsigned int inLength, unsigned int maxOutLength, PaddingType padding, hashMethod hm) {
	//! TODO: pythonize
	return this->get_override("publicEncrypt")(inBuf, cipherBuf, inLength, maxOutLength, padding, hm);
}

unsigned int getLength(void) const {
	return this->get_override("getLength")();
}

void loadPublicModulusBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadPublicModulusBase64BigNums")(std::string(b64, len));
}

void loadPublicExponentBase64BigNums(const char * b64, unsigned int len) {
	this->get_override("loadPublicExponentBase64BigNums")(std::string(b64, len));
}

//! XSECCryptoKey
const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

};

class XSECCryptoKeyRSADefVisitor
: public boost::python::def_visitor<XSECCryptoKeyRSADefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setOAEPparams", &XSECCryptoKeyRSADefVisitor::setOAEPparams)
	.def("getOAEPparams", &XSECCryptoKeyRSADefVisitor::getOAEPparams)
	.def("loadPublicModulusBase64BigNums", &XSECCryptoKeyRSADefVisitor::loadPublicModulusBase64BigNums)
	.def("loadPublicExponentBase64BigNums", &XSECCryptoKeyRSADefVisitor::loadPublicExponentBase64BigNums)
	;
}

static void setOAEPparams(XSECCryptoKeyRSA& self, std::string& params) {
	self.setOAEPparams(const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(params.c_str())), params.size());
}

static std::string getOAEPparams(XSECCryptoKeyRSA& self) {
	unsigned int size = self.getOAEPparamsLen();
	const unsigned char* ptr = self.getOAEPparams();
	return std::string(reinterpret_cast<const char*>(ptr), size);
}

static void loadPublicModulusBase64BigNums(XSECCryptoKeyRSA& self, const std::string& b64) {
	self.loadPublicModulusBase64BigNums(b64.c_str(), b64.size());
}

static void loadPublicExponentBase64BigNums(XSECCryptoKeyRSA& self, const std::string& b64) {
	self.loadPublicExponentBase64BigNums(b64.c_str(), b64.size());
}

};

void XSECCryptoKeyRSA_init(void) {
	//! XSECCryptoKeyRSA
	auto XSECCryptoKeyRSA_ = boost::python::class_<XSECCryptoKeyRSAWrapper, boost::noncopyable, boost::python::bases<XSECCryptoKey> >("XSECCryptoKeyRSA")
			.def(XSECCryptoKeyRSADefVisitor())
			.def("getKeyType", &XSECCryptoKeyRSA::getKeyType)
			.def("clone", boost::python::pure_virtual(&XSECCryptoKeyRSA::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setOAEPparams", boost::python::pure_virtual(&XSECCryptoKeyRSA::setOAEPparams))
			.def("getOAEPparamsLen", boost::python::pure_virtual(&XSECCryptoKeyRSA::getOAEPparamsLen))
			//.def("getOAEPparams", boost::python::pure_virtual(&XSECCryptoKeyRSA::getOAEPparams))
			.def("setMGF", boost::python::pure_virtual(&XSECCryptoKeyRSA::setMGF))
			.def("getMGF", boost::python::pure_virtual(&XSECCryptoKeyRSA::getMGF))
			.def("verifySHA1PKCS1Base64Signature", boost::python::pure_virtual(&XSECCryptoKeyRSA::verifySHA1PKCS1Base64Signature))
			.def("signSHA1PKCS1Base64Signature", boost::python::pure_virtual(&XSECCryptoKeyRSA::signSHA1PKCS1Base64Signature))
			.def("privateDecrypt", boost::python::pure_virtual(&XSECCryptoKeyRSA::privateDecrypt))
			.def("publicEncrypt", boost::python::pure_virtual(&XSECCryptoKeyRSA::publicEncrypt))
			.def("getLength", boost::python::pure_virtual(&XSECCryptoKeyRSA::getLength))
			.def("loadPublicModulusBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyRSA::loadPublicModulusBase64BigNums))
			.def("loadPublicExponentBase64BigNums", boost::python::pure_virtual(&XSECCryptoKeyRSA::loadPublicExponentBase64BigNums))
			;
	boost::python::scope XSECCryptoKeyRSAScope = XSECCryptoKeyRSA_;
	//! XSECCryptoKeyRSA::PaddingType
	boost::python::enum_<XSECCryptoKeyRSA::PaddingType>("PaddingType")
			.value("PAD_NONE", XSECCryptoKeyRSA::PAD_NONE)
			.value("PAD_PKCS_1_5", XSECCryptoKeyRSA::PAD_PKCS_1_5)
			.value("PAD_OAEP_MGFP1", XSECCryptoKeyRSA::PAD_OAEP_MGFP1)
			.export_values()
			;
}

} /* namespace pyxsec */
