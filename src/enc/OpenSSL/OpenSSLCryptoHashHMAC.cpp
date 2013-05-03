/*
 * OpenSSLCryptoHashHMAC.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoHashHMAC.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.hpp>

namespace pyxsec {

void OpenSSLCryptoHashHMAC_init(void) {
	//! OpenSSLCryptoHashHMAC
	boost::python::class_<OpenSSLCryptoHashHMAC, boost::noncopyable, boost::python::bases<XSECCryptoHash> >("OpenSSLCryptoHashHMAC", boost::python::init<XSECCryptoHash::HashType>())
			.def("setKey", &OpenSSLCryptoHashHMAC::setKey)
			.def("reset", &OpenSSLCryptoHashHMAC::reset)
			.def("hash", &OpenSSLCryptoHashHMAC::hash)
			.def("finish", &OpenSSLCryptoHashHMAC::finish)
			.def("getHashType", &OpenSSLCryptoHashHMAC::getHashType)
			.def("getOpenSSLHMAC_CTX", &OpenSSLCryptoHashHMAC::getOpenSSLHMAC_CTX, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
