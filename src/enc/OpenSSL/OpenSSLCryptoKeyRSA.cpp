/*
 * OpenSSLCryptoKeyRSA.cpp
 *
 *  Created on: 2013/05/01
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoKeyRSA.h"

#include <boost/python.hpp>

//! for forward declaration
#include <openssl/rsa.h>

#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.hpp>

namespace pyxsec {

class OpenSSLCryptoKeyRSADefVisitor
: public boost::python::def_visitor<OpenSSLCryptoKeyRSADefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setOAEPparams", &OpenSSLCryptoKeyRSADefVisitor::setOAEPparams)
	.def("getOAEPparams", &OpenSSLCryptoKeyRSADefVisitor::getOAEPparams)
	.def("loadPublicModulusBase64BigNums", &OpenSSLCryptoKeyRSADefVisitor::loadPublicModulusBase64BigNums)
	.def("loadPublicExponentBase64BigNums", &OpenSSLCryptoKeyRSADefVisitor::loadPublicExponentBase64BigNums)
	;
}

static void setOAEPparams(OpenSSLCryptoKeyRSA& self, std::string& params) {
	self.setOAEPparams(const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(params.c_str())), params.size());
}

static std::string getOAEPparams(OpenSSLCryptoKeyRSA& self) {
	unsigned int size = self.getOAEPparamsLen();
	const unsigned char* ptr = self.getOAEPparams();
	return std::string(reinterpret_cast<const char*>(ptr), size);
}

static void loadPublicModulusBase64BigNums(OpenSSLCryptoKeyRSA& self, const std::string& b64) {
	self.loadPublicModulusBase64BigNums(b64.c_str(), b64.size());
}

static void loadPublicExponentBase64BigNums(OpenSSLCryptoKeyRSA& self, const std::string& b64) {
	self.loadPublicExponentBase64BigNums(b64.c_str(), b64.size());
}

};

void OpenSSLCryptoKeyRSA_init(void) {
	//! OpenSSLCryptoKeyRSA
	boost::python::class_<OpenSSLCryptoKeyRSA, boost::noncopyable, boost::python::bases<XSECCryptoKeyRSA> >("OpenSSLCryptoKeyRSA")
			.def(boost::python::init<EVP_PKEY*>())
			.def(OpenSSLCryptoKeyRSADefVisitor())
			.def("getKeyType", &OpenSSLCryptoKeyRSA::getKeyType)
			.def("getProviderName", &OpenSSLCryptoKeyRSA::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clone", &OpenSSLCryptoKeyRSA::clone, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setOAEPparams", &OpenSSLCryptoKeyRSA::setOAEPparams)
			.def("getOAEPparamsLen", &OpenSSLCryptoKeyRSA::getOAEPparamsLen)
			//.def("getOAEPparams", &OpenSSLCryptoKeyRSA::getOAEPparams)
			.def("setMGF", &OpenSSLCryptoKeyRSA::setMGF)
			.def("getMGF", &OpenSSLCryptoKeyRSA::getMGF)
			.def("verifySHA1PKCS1Base64Signature", &OpenSSLCryptoKeyRSA::verifySHA1PKCS1Base64Signature)
			.def("signSHA1PKCS1Base64Signature", &OpenSSLCryptoKeyRSA::signSHA1PKCS1Base64Signature)
			.def("privateDecrypt", &OpenSSLCryptoKeyRSA::privateDecrypt)
			.def("publicEncrypt", &OpenSSLCryptoKeyRSA::publicEncrypt)
			.def("getLength", &OpenSSLCryptoKeyRSA::getLength)
			.def("loadPublicModulusBase64BigNums", &OpenSSLCryptoKeyRSA::loadPublicModulusBase64BigNums)
			.def("loadPublicExponentBase64BigNums", &OpenSSLCryptoKeyRSA::loadPublicExponentBase64BigNums)
			.def("getOpenSSLRSA", static_cast<RSA*(OpenSSLCryptoKeyRSA::*)()>(&OpenSSLCryptoKeyRSA::getOpenSSLRSA), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
