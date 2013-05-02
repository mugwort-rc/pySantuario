/*
 * XSECKeyInfoResolver.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECKeyInfoResolver.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECKeyInfoResolver.hpp>

namespace pyxsec {

class XSECKeyInfoResolverWrapper
: public XSECKeyInfoResolver, public boost::python::wrapper<XSECKeyInfoResolver>
{
public:
XSECKeyInfoResolverWrapper()
: XSECKeyInfoResolver()
{}

XSECCryptoKey * resolveKey(DSIGKeyInfoList * lst) {
	return this->get_override("resolveKey")(boost::python::ptr(lst));
}

XSECKeyInfoResolver * clone(void) const {
	return this->get_override("clone")();
}

};

void XSECKeyInfoResolver_init(void) {
	//! XSECKeyInfoResolver
	boost::python::class_<XSECKeyInfoResolverWrapper, boost::noncopyable>("XSECKeyInfoResolver")
			.def("resolveKey", boost::python::pure_virtual(&XSECKeyInfoResolver::resolveKey), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("clone", boost::python::pure_virtual(&XSECKeyInfoResolver::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
