/*
 * OpenSSLCryptoX509.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "OpenSSLCryptoX509.h"

#include <boost/python.hpp>

#include <xsec/enc/OpenSSL/OpenSSLCryptoX509.hpp>

namespace pyxsec {

class OpenSSLCryptoX509DefVisitor
: public boost::python::def_visitor<OpenSSLCryptoX509DefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("loadX509Base64Bin", &OpenSSLCryptoX509DefVisitor::loadX509Base64Bin)
	.def("loadX509PEM", &OpenSSLCryptoX509DefVisitor::loadX509PEM)
	;
}

static void loadX509Base64Bin(OpenSSLCryptoX509& self, const std::string& buf) {
	self.loadX509Base64Bin(buf.c_str(), buf.size());
}

static void loadX509PEM(OpenSSLCryptoX509& self, const std::string& buf) {
	self.loadX509PEM(buf.c_str());
}

};

void OpenSSLCryptoX509_init(void) {
	//! OpenSSLCryptoX509
	boost::python::class_<OpenSSLCryptoX509, boost::noncopyable, boost::python::bases<XSECCryptoX509> >("OpenSSLCryptoX509")
			.def(boost::python::init<X509*>())
			.def(OpenSSLCryptoX509DefVisitor())
			.def("getPublicKeyType", &OpenSSLCryptoX509::getPublicKeyType)
			.def("clonePublicKey", &OpenSSLCryptoX509::clonePublicKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getProviderName", &OpenSSLCryptoX509::getProviderName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("loadX509Base64Bin", &OpenSSLCryptoX509::loadX509Base64Bin)
			.def("loadX509PEM", &OpenSSLCryptoX509::loadX509PEM)
			.def("getDEREncodingSB", static_cast<const safeBuffer&(OpenSSLCryptoX509::*)(void) const>(&OpenSSLCryptoX509::getDEREncodingSB), boost::python::return_value_policy<boost::python::copy_const_reference>())
			.def("getOpenSSLX509", static_cast<X509*(OpenSSLCryptoX509::*)(void)>(&OpenSSLCryptoX509::getOpenSSLX509), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

} /* namespace pyxsec */
