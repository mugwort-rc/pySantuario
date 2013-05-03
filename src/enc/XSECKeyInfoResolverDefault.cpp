/*
 * XSECKeyInfoResolverDefault.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECKeyInfoResolverDefault.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECKeyInfoResolverDefault.hpp>

namespace pyxsec {

void XSECKeyInfoResolverDefault_init(void) {
	//! XSECKeyInfoResolverDefault
	boost::python::class_<XSECKeyInfoResolverDefault, boost::noncopyable, boost::python::bases<XSECKeyInfoResolver> >("XSECKeyInfoResolverDefault")
			.def("resolveKey", &XSECKeyInfoResolverDefault::resolveKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("clone", &XSECKeyInfoResolverDefault::clone, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
