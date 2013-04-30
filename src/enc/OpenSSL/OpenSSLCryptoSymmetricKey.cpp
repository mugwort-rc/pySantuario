/*
 * OpenSSLCryptoSymmetricKey.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoSymmetricKey.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp>

namespace pyxsec {

class OpenSSLCryptoSymmetricKeyDefVisitor
: public boost::python::def_visitor<OpenSSLCryptoSymmetricKeyDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setKey", &OpenSSLCryptoSymmetricKeyDefVisitor::setKey)
	;
}

static void setKey(OpenSSLCryptoSymmetricKey& self, const std::string& key) {
	self.setKey(reinterpret_cast<const unsigned char*>(key.c_str()), key.size());
}

};

//! OpenSSLCryptoSymmetricKey
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(OpenSSLCryptoSymmetricKeyDecryptInitOverloads, decryptInit, 0, 5)
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(OpenSSLCryptoSymmetricKeyEncryptInitOverloads, encryptInit, 0, 3)
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(OpenSSLCryptoSymmetricKeyEncryptFinishOverloads, encryptFinish, 2, 3)

void OpenSSLCryptoSymmetricKey_init(void) {
	//! OpenSSLCryptoSymmetricKey
	boost::python::class_<OpenSSLCryptoSymmetricKey, boost::noncopyable, boost::python::bases<XSECCryptoSymmetricKey> >("OpenSSLCryptoSymmetricKey", boost::python::init<XSECCryptoSymmetricKey::SymmetricKeyType>())
			.def(OpenSSLCryptoSymmetricKeyDefVisitor())
			.def("getProviderName", &OpenSSLCryptoSymmetricKey::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clone", &OpenSSLCryptoSymmetricKey::clone, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSymmetricKeyType", &OpenSSLCryptoSymmetricKey::getSymmetricKeyType)
			.def("setKey", &OpenSSLCryptoSymmetricKey::setKey)
			.def("decryptInit", &OpenSSLCryptoSymmetricKey::decryptInit)//, OpenSSLCryptoSymmetricKeyDecryptInitOverloads())
			.def("decrypt", &OpenSSLCryptoSymmetricKey::decrypt)
			.def("decryptFinish", &OpenSSLCryptoSymmetricKey::decryptFinish)
			.def("encryptInit", &OpenSSLCryptoSymmetricKey::encryptInit)//, OpenSSLCryptoSymmetricKeyEncryptInitOverloads())
			.def("encrypt", &OpenSSLCryptoSymmetricKey::encrypt)
			.def("encryptFinish", &OpenSSLCryptoSymmetricKey::encryptFinish)//, OpenSSLCryptoSymmetricKeyEncryptFinishOverloads())
			.def("getOpenSSLEVP_CIPHER_CTX", static_cast<EVP_CIPHER_CTX*(OpenSSLCryptoSymmetricKey::*)(void)>(&OpenSSLCryptoSymmetricKey::getOpenSSLEVP_CIPHER_CTX), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
