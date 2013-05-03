/*
 * OpenSSLCryptoKeyDSA.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoKeyDSA.h"

#include <boost/python.hpp>

//! for forward declaration
#include <openssl/dsa.h>

#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.hpp>

namespace pyxsec {

void OpenSSLCryptoKeyDSA_init(void) {
	//! OpenSSLCryptoKeyDSA
	boost::python::class_<OpenSSLCryptoKeyDSA, boost::noncopyable, boost::python::bases<XSECCryptoKeyDSA> >("OpenSSLCryptoKeyDSA")
			.def(boost::python::init<EVP_PKEY*>())
			.def("getKeyType", &OpenSSLCryptoKeyDSA::getKeyType)
			.def("getProviderName", &OpenSSLCryptoKeyDSA::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clone", &OpenSSLCryptoKeyDSA::clone, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("signBase64Signature", &OpenSSLCryptoKeyDSA::signBase64Signature)
			.def("verifyBase64Signature", &OpenSSLCryptoKeyDSA::verifyBase64Signature)
			.def("getKeyType", &OpenSSLCryptoKeyDSA::getKeyType)
			.def("loadPBase64BigNums", &OpenSSLCryptoKeyDSA::loadPBase64BigNums)
			.def("loadQBase64BigNums", &OpenSSLCryptoKeyDSA::loadQBase64BigNums)
			.def("loadGBase64BigNums", &OpenSSLCryptoKeyDSA::loadGBase64BigNums)
			.def("loadYBase64BigNums", &OpenSSLCryptoKeyDSA::loadYBase64BigNums)
			.def("loadJBase64BigNums", &OpenSSLCryptoKeyDSA::loadJBase64BigNums)
			.def("getOpenSSLDSA", static_cast<DSA*(OpenSSLCryptoKeyDSA::*)(void)>(&OpenSSLCryptoKeyDSA::getOpenSSLDSA), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
