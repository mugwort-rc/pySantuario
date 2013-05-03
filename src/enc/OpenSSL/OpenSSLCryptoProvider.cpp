/*
 * OpenSSLCryptoProvider.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoProvider.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoProvider.hpp>

namespace pyxsec {

//! OpenSSLCryptoProvider
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(HashSHAOverloads, hashSHA, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(HashHMACSHAOverloads, hashHMACSHA, 0, 1)

void OpenSSLCryptoProvider_init(void) {
	//! OpenSSLCryptoProvider
	boost::python::class_<OpenSSLCryptoProvider, boost::noncopyable, boost::python::bases<XSECCryptoProvider> >("OpenSSLCryptoProvider")
			.def("hashSHA1", &OpenSSLCryptoProvider::hashSHA1, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashSHA", &OpenSSLCryptoProvider::hashSHA, HashSHAOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("hashHMACSHA1", &OpenSSLCryptoProvider::hashHMACSHA1, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashHMACSHA", &OpenSSLCryptoProvider::hashHMACSHA, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashMD5", &OpenSSLCryptoProvider::hashMD5, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashHMACMD5", &OpenSSLCryptoProvider::hashHMACMD5, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyHMAC", &OpenSSLCryptoProvider::keyHMAC, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("base64", &OpenSSLCryptoProvider::base64, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyDSA", &OpenSSLCryptoProvider::keyDSA, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyRSA", &OpenSSLCryptoProvider::keyRSA, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyEC", &OpenSSLCryptoProvider::keyEC, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyDER", &OpenSSLCryptoProvider::keyDER, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("X509", &OpenSSLCryptoProvider::X509, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("algorithmSupported", static_cast<bool(OpenSSLCryptoProvider::*)(XSECCryptoSymmetricKey::SymmetricKeyType)const>(&OpenSSLCryptoProvider::algorithmSupported))
			.def("algorithmSupported", static_cast<bool(OpenSSLCryptoProvider::*)(XSECCryptoHash::HashType)const>(&OpenSSLCryptoProvider::algorithmSupported))
			.def("keySymmetric", &OpenSSLCryptoProvider::keySymmetric, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRandom", &OpenSSLCryptoProvider::getRandom)
			.def("curveNameToNID", &OpenSSLCryptoProvider::curveNameToNID)
			.def("getProviderName", &OpenSSLCryptoProvider::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxsec */
