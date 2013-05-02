/*
 * DSIGTransformEnvelope.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGTransformEnvelope.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/dsig/DSIGTransformEnvelope.hpp>

namespace pyxsec {

void DSIGTransformEnvelope_init(void) {
	//! DSIGTransformEnvelope
	boost::python::class_<DSIGTransformEnvelope, boost::noncopyable>("DSIGTransformEnvelope", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("getTransformType", &DSIGTransformEnvelope::getTransformType)
			.def("appendTransformer", &DSIGTransformEnvelope::appendTransformer)
			.def("createBlankTransform", &DSIGTransformEnvelope::createBlankTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("load", &DSIGTransformEnvelope::load)
			;
}

} /* namespace pyxsec */
