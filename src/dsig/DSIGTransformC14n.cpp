/*
 * DSIGTransformC14n.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGTransformC14n.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/dsig/DSIGTransformC14n.hpp>

namespace pyxsec {

void DSIGTransformC14n_init(void) {
	//! DSIGTransformC14n
	boost::python::class_<DSIGTransformC14n, boost::noncopyable, boost::python::bases<DSIGTransform> >("DSIGTransformXPath", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", &DSIGTransformC14n::getTransformType)
			.def("appendTransformer", &DSIGTransformC14n::appendTransformer)
			.def("createBlankTransform", &DSIGTransformC14n::createBlankTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", &DSIGTransformC14n::load)
			.def("setCanonicalizationMethod", &DSIGTransformC14n::setCanonicalizationMethod)
			.def("getCanonicalizationMethod", &DSIGTransformC14n::getCanonicalizationMethod)
			.def("addInclusiveNamespace", &DSIGTransformC14n::addInclusiveNamespace)
			.def("setInclusiveNamespaces", &DSIGTransformC14n::setInclusiveNamespaces)
			.def("getPrefixList", &DSIGTransformC14n::getPrefixList, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clearInclusiveNamespaces", &DSIGTransformC14n::clearInclusiveNamespaces)
			;
}

} /* namespace pyxsec */
