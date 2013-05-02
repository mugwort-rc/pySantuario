/*
 * DSIGTransformXPathFilter.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGTransformXPathFilter.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>
#include <xsec/dsig/DSIGXPathFilterExpr.hpp>

#include <xsec/dsig/DSIGTransformXPathFilter.hpp>

namespace pyxsec {

void DSIGTransformXPathFilter_init(void) {
	//! DSIGTransformXPathFilter
	boost::python::class_<DSIGTransformXPathFilter, boost::noncopyable, boost::python::bases<DSIGTransform> >("DSIGTransformXPath", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", &DSIGTransformXPathFilter::getTransformType)
			.def("appendTransformer", &DSIGTransformXPathFilter::appendTransformer)
			.def("createBlankTransform", &DSIGTransformXPathFilter::createBlankTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", &DSIGTransformXPathFilter::load)
			.def("appendFilter", &DSIGTransformXPathFilter::appendFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getExprNum", &DSIGTransformXPathFilter::getExprNum)
			.def("expr", &DSIGTransformXPathFilter::expr, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
