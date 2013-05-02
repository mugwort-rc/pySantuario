/*
 * DSIGTransformBase64.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGTransformBase64.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/dsig/DSIGTransformBase64.hpp>

namespace pyxsec {

void DSIGTransformBase64_init(void) {
	//! DSIGTransformBase64
	boost::python::class_<DSIGTransformBase64, boost::noncopyable, boost::python::bases<DSIGTransform> >("DSIGTransformBase64", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", &DSIGTransformBase64::getTransformType)
			.def("appendTransformer", &DSIGTransformBase64::appendTransformer)
			.def("createBlankTransform", &DSIGTransformBase64::createBlankTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", &DSIGTransformBase64::load)
			;
}

} /* namespace pyxsec */
