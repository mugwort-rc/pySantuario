/*
 * DSIGTransformXPath.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGTransformXPath.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/dsig/DSIGTransformXPath.hpp>

namespace pyxsec {

void DSIGTransformXPath_init(void) {
	//! DSIGTransformXPath
	boost::python::class_<DSIGTransformXPath, boost::noncopyable, boost::python::bases<DSIGTransform> >("DSIGTransformXPath", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", &DSIGTransformXPath::getTransformType)
			.def("appendTransformer", &DSIGTransformXPath::appendTransformer)
			.def("createBlankTransform", &DSIGTransformXPath::createBlankTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", &DSIGTransformXPath::load)
			.def("setExpression", &DSIGTransformXPath::setExpression)
			.def("getExpression", &DSIGTransformXPath::getExpression)
			.def("setNamespace", &DSIGTransformXPath::setNamespace)
			.def("getNamespaces", &DSIGTransformXPath::getNamespaces, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("deleteNamespace", &DSIGTransformXPath::deleteNamespace)
			;
}

} /* namespace pyxsec */
