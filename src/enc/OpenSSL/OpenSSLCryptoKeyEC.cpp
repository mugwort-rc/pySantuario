/*
 * OpenSSLCryptoKeyEC.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoKeyEC.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.hpp>

namespace pyxsec {

void OpenSSLCryptoKeyEC_init(void) {
	//! OpenSSLCryptoKeyEC
	boost::python::class_<OpenSSLCryptoKeyEC, boost::noncopyable, boost::python::bases<XSECCryptoKeyEC> >("OpenSSLCryptoKeyEC")
			.def(boost::python::init<EVP_PKEY*>())
			.def("getKeyType", &OpenSSLCryptoKeyEC::getKeyType)
			.def("getProviderName", &OpenSSLCryptoKeyEC::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clone", &OpenSSLCryptoKeyEC::clone, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("signBase64SignatureDSA", &OpenSSLCryptoKeyEC::signBase64SignatureDSA)
			.def("verifyBase64SignatureDSA", &OpenSSLCryptoKeyEC::verifyBase64SignatureDSA)
			.def("loadPublicKeyBase64", &OpenSSLCryptoKeyEC::loadPublicKeyBase64)
			//.def("getOpenSSLEC", static_cast<EC_KEY*(OpenSSLCryptoKeyEC::*)(void)>(&OpenSSLCryptoKeyEC::getOpenSSLEC), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
