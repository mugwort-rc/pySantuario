/*
 * DSIGKeyInfoExt.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoExt.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoExt.hpp>

namespace pyxsec {

void DSIGKeyInfoExt_init(void) {
	//! DSIGKeyInfoExt
	boost::python::class_<DSIGKeyInfoExt, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoExt", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def("load", &DSIGKeyInfoExt::load)
			.def("getKeyInfoType", &DSIGKeyInfoExt::getKeyInfoType)
			.def("getKeyName", &DSIGKeyInfoExt::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxsec */
