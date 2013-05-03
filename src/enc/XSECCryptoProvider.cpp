/*
 * XSECCryptoProvider.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECCryptoProvider.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoProvider.hpp>

namespace pyxsec {

class XSECCryptoProviderWrapper
: public XSECCryptoProvider, public boost::python::wrapper<XSECCryptoProvider>
{
public:
XSECCryptoProviderWrapper()
: XSECCryptoProvider()
{}

XSECCryptoHash* hashSHA1() const {
	return this->get_override("hashSHA1")();
}

XSECCryptoHash* hashSHA(int length = 160) const {
	return this->get_override("hashSHA")(length);
}

XSECCryptoHash* hashHMACSHA1() const {
	return this->get_override("hashHMACSHA1")();
}

XSECCryptoHash* hashHMACSHA(int length = 160) const {
	return this->get_override("hashHMACSHA")(length);
}

XSECCryptoHash* hashMD5() const {
	return this->get_override("hashMD5")();
}

XSECCryptoHash* hashHMACMD5() const {
	return this->get_override("hashHMACMD5")();
}

XSECCryptoKeyHMAC* keyHMAC() const {
	return this->get_override("keyHMAC")();
}

XSECCryptoBase64* base64() const {
	return this->get_override("base64")();
}

XSECCryptoKeyDSA* keyDSA() const {
	return this->get_override("keyDSA")();
}

XSECCryptoKeyRSA* keyRSA() const {
	return this->get_override("keyRSA")();
}

XSECCryptoKeyEC* keyEC() const {
	return this->get_override("keyEC")();
}

XSECCryptoKey* keyDER(const char* buf, unsigned long buflen, bool base64) const {
	return this->get_override("keyDER")(buf, buflen, base64);
}

XSECCryptoX509* X509() const {
	return this->get_override("X509")();
}

bool algorithmSupported(XSECCryptoSymmetricKey::SymmetricKeyType alg) const {
	return this->get_override("algorithmSupported")(alg);
}

bool algorithmSupported(XSECCryptoHash::HashType alg) const {
	return this->get_override("algorithmSupported")(alg);
}

XSECCryptoSymmetricKey* keySymmetric(XSECCryptoSymmetricKey::SymmetricKeyType alg) const {
	return this->get_override("keySymmetric")(alg);
}

unsigned int getRandom(unsigned char * buffer, unsigned int numOctets) const {
	//! TODO: pythonize
	return this->get_override("getRandom")(buffer, numOctets);
}

const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

};

void XSECCryptoProvider_init(void) {
	//! XSECCryptoProvider
	boost::python::class_<XSECCryptoProviderWrapper, boost::noncopyable>("XSECCryptoProvider")
			.def("hashSHA1", boost::python::pure_virtual(&XSECCryptoProvider::hashSHA1), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashSHA", boost::python::pure_virtual(&XSECCryptoProvider::hashSHA), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashHMACSHA1", boost::python::pure_virtual(&XSECCryptoProvider::hashHMACSHA1), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashHMACSHA", boost::python::pure_virtual(&XSECCryptoProvider::hashHMACSHA), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashMD5", boost::python::pure_virtual(&XSECCryptoProvider::hashMD5), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("hashHMACMD5", boost::python::pure_virtual(&XSECCryptoProvider::hashHMACMD5), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyHMAC", boost::python::pure_virtual(&XSECCryptoProvider::keyHMAC), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("base64", boost::python::pure_virtual(&XSECCryptoProvider::base64), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyDSA", boost::python::pure_virtual(&XSECCryptoProvider::keyDSA), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyRSA", boost::python::pure_virtual(&XSECCryptoProvider::keyRSA), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyEC", boost::python::pure_virtual(&XSECCryptoProvider::keyEC), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("keyDER", boost::python::pure_virtual(&XSECCryptoProvider::keyDER), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("X509", boost::python::pure_virtual(&XSECCryptoProvider::X509), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("algorithmSupported", boost::python::pure_virtual(static_cast<bool(XSECCryptoProvider::*)(XSECCryptoSymmetricKey::SymmetricKeyType) const>(&XSECCryptoProvider::algorithmSupported)))
			.def("algorithmSupported", boost::python::pure_virtual(static_cast<bool(XSECCryptoProvider::*)(XSECCryptoHash::HashType) const>(&XSECCryptoProvider::algorithmSupported)))
			.def("keySymmetric", boost::python::pure_virtual(&XSECCryptoProvider::keySymmetric), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRandom", boost::python::pure_virtual(&XSECCryptoProvider::getRandom))
			.def("getProviderName", boost::python::pure_virtual(&XSECCryptoProvider::getProviderName), boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxsec */
