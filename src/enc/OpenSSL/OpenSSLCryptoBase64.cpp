/*
 * OpenSSLCryptoBase64.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoBase64.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoBase64.hpp>

namespace pyxsec {

void OpenSSLCryptoBase64_init(void) {
	//! OpenSSLCryptoBase64
	boost::python::class_<OpenSSLCryptoBase64, boost::noncopyable, boost::python::bases<XSECCryptoBase64> >("OpenSSLCryptoBase64")
			.def("decodeInit", &OpenSSLCryptoBase64::decodeInit)
			.def("decode", &OpenSSLCryptoBase64::decode)
			.def("decodeFinish", &OpenSSLCryptoBase64::decodeFinish)
			.def("encodeInit", &OpenSSLCryptoBase64::encodeInit)
			.def("encode", &OpenSSLCryptoBase64::encode)
			.def("encodeFinish", &OpenSSLCryptoBase64::encodeFinish)
			.def("b642BN", &OpenSSLCryptoBase64::b642BN, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.staticmethod("b642BN")
			.def("getOpenSSLEncodeEVP_ENCODE_CTX", &OpenSSLCryptoBase64::getOpenSSLEncodeEVP_ENCODE_CTX, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getOpenSSLDecodeEVP_ENCODE_CTX", &OpenSSLCryptoBase64::getOpenSSLDecodeEVP_ENCODE_CTX, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
