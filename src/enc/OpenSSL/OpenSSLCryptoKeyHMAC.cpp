/*
 * OpenSSLCryptoKeyHMAC.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoKeyHMAC.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyHMAC.hpp>

namespace pyxsec {

class OpenSSLCryptoKeyHMACDefVisitor
: public boost::python::def_visitor<OpenSSLCryptoKeyHMACDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setKey", &OpenSSLCryptoKeyHMACDefVisitor::setKey)
	.def("getKey", &OpenSSLCryptoKeyHMACDefVisitor::getKey)
	;
}

static void setKey(OpenSSLCryptoKeyHMAC& self, const char* key) {
	std::string buff(key);
	self.setKey(const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(buff.c_str())), buff.size());
}

static std::string getKey(OpenSSLCryptoKeyHMAC& self) {
	safeBuffer buffer;
	unsigned int size = self.getKey(buffer);
	return std::string(buffer.rawCharBuffer(), size);
}

};

void OpenSSLCryptoKeyHMAC_init(void) {
	//! OpenSSLCryptoKeyHMAC
	boost::python::class_<OpenSSLCryptoKeyHMAC, boost::noncopyable, boost::python::bases<XSECCryptoKeyHMAC> >("OpenSSLCryptoKeyHMAC")
			.def(OpenSSLCryptoKeyHMACDefVisitor())
			.def("getKeyType", &XSECCryptoKeyHMAC::getKeyType)
			.def("clone", &XSECCryptoKeyHMAC::clone, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getProviderName", &XSECCryptoKeyHMAC::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setKey", &XSECCryptoKeyHMAC::setKey)
			.def("getKey", &XSECCryptoKeyHMAC::getKey)
			;
}

} /* namespace pyxsec */
