/*
 * DSIGTransform.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGTransform.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/dsig/DSIGTransform.hpp>

namespace pyxsec {

class DSIGTransformWrapper
: public DSIGTransform, public boost::python::wrapper<DSIGTransform>{
public:
DSIGTransformWrapper(const XSECEnv * env, xercesc::DOMNode * node)
: DSIGTransform(env, node)
{}

DSIGTransformWrapper(const XSECEnv * env)
: DSIGTransform(env)
{}

transformType getTransformType() {
	return this->get_override("getTransformType")();
}

void appendTransformer(TXFMChain * input) {
	this->get_override("appendTransformer")(boost::python::ptr(input));
}

xercesc::DOMElement* createBlankTransform(xercesc::DOMDocument * parentDoc) {
	return this->get_override("createBlankTransform")(boost::python::ptr(parentDoc));
}

void load(void) {
	this->get_override("load")();
}

};

void DSIGTransform_init(void) {
	//! DSIGTransform
	boost::python::class_<DSIGTransformWrapper, boost::noncopyable>("DSIGTransform", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", boost::python::pure_virtual(&DSIGTransform::getTransformType))
			.def("appendTransformer", boost::python::pure_virtual(&DSIGTransform::appendTransformer))
			.def("createBlankTransform", boost::python::pure_virtual(&DSIGTransform::createBlankTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", boost::python::pure_virtual(&DSIGTransform::load))
			;
}

} /* namespace pyxsec */
