/*
 * DSIGTransformXSL.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGTransformXSL.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/dsig/DSIGTransformXSL.hpp>

namespace pyxsec {

void DSIGTransformXSL_init(void) {
	//! DSIGTransformXSL
	boost::python::class_<DSIGTransformXSL, boost::noncopyable, boost::python::bases<DSIGTransform> >("DSIGTransformXPath", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", &DSIGTransformXSL::getTransformType)
			.def("appendTransformer", &DSIGTransformXSL::appendTransformer)
			.def("createBlankTransform", &DSIGTransformXSL::createBlankTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", &DSIGTransformXSL::load)
			.def("setStylesheet", &DSIGTransformXSL::setStylesheet, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getStylesheet", &DSIGTransformXSL::getStylesheet, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
