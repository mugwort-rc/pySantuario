/*
 * OpenSSLCryptoHash.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoHash.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoHash.hpp>

namespace pyxsec {

void OpenSSLCryptoHash_init(void) {
	//! OpenSSLCryptoHash
	boost::python::class_<OpenSSLCryptoHash, boost::noncopyable, boost::python::bases<XSECCryptoHash> >("OpenSSLCryptoHash", boost::python::init<XSECCryptoHash::HashType>())
			.def("setKey", &OpenSSLCryptoHash::setKey)
			.def("reset", &OpenSSLCryptoHash::reset)
			.def("hash", &OpenSSLCryptoHash::hash)
			.def("finish", &OpenSSLCryptoHash::finish)
			.def("getHashType", &OpenSSLCryptoHash::getHashType)
			.def("getOpenSSLEVP_MD_CTX", &OpenSSLCryptoHash::getOpenSSLEVP_MD_CTX, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
