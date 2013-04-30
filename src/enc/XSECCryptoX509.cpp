/*
 * XSECCryptoX509.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XSECCryptoX509.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoX509.hpp>

namespace pyxsec {

class XSECCryptoX509DefVisitor
: public boost::python::def_visitor<XSECCryptoX509DefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("loadX509Base64Bin", &XSECCryptoX509DefVisitor::loadX509Base64Bin)
	.def("loadX509PEM", &XSECCryptoX509DefVisitor::loadX509PEM)
	;
}

static void loadX509Base64Bin(XSECCryptoX509& self, const std::string& buf) {
	self.loadX509Base64Bin(buf.c_str(), buf.size());
}

static void loadX509PEM(XSECCryptoX509& self, const std::string& buf) {
	self.loadX509PEM(buf.c_str());
}

};

void XSECCryptoX509_init(void) {
	//! XSECCryptoX509
	boost::python::class_<XSECCryptoX509, boost::noncopyable>("XSECCryptoX509", boost::python::no_init)
			.def(XSECCryptoX509DefVisitor())
			.def("getPublicKeyType", boost::python::pure_virtual(&XSECCryptoX509::getPublicKeyType))
			.def("clonePublicKey", boost::python::pure_virtual(&XSECCryptoX509::clonePublicKey), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getProviderName", boost::python::pure_virtual(&XSECCryptoX509::getProviderName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("loadX509Base64Bin", boost::python::pure_virtual(&XSECCryptoX509::loadX509Base64Bin))
			.def("loadX509PEM", boost::python::pure_virtual(&XSECCryptoX509::loadX509PEM))
			.def("getDEREncodingSB", boost::python::pure_virtual(static_cast<const safeBuffer&(XSECCryptoX509::*)(void) const>(&XSECCryptoX509::getDEREncodingSB)), boost::python::return_value_policy<boost::python::copy_const_reference>())
			;
}

} /* namespace pyxsec */
