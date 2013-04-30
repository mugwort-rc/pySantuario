/*
 * XSECProvider.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XSECProvider.h"

#include <boost/python.hpp>

//! for forward delcaration
#include <xsec/framework/XSECURIResolver.hpp>

#include <xsec/framework/XSECProvider.hpp>

namespace pyxsec {

void XSECProvider_init(void) {
	//! XSECProvider
	boost::python::class_<XSECProvider, boost::noncopyable>("XSECProvider")
			//! TODO: DSIGSignature
			.def("newSignatureFromDOM", static_cast<DSIGSignature*(XSECProvider::*)(xercesc::DOMDocument*, xercesc::DOMNode*)>(&XSECProvider::newSignatureFromDOM), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("newSignatureFromDOM", static_cast<DSIGSignature*(XSECProvider::*)(xercesc::DOMDocument*)>(&XSECProvider::newSignatureFromDOM), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("newSignature", &XSECProvider::newSignature, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("releaseSignature", &XSECProvider::releaseSignature)
			//! TODO: XENCCipher
			.def("newCipher", &XSECProvider::newCipher, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("releaseCipher", &XSECProvider::releaseCipher)
			//! TODO: XKMSMessageFactory
			.def("getXKMSMessageFactory", &XSECProvider::getXKMSMessageFactory, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setDefaultURIResolver", &XSECProvider::setDefaultURIResolver)
			;
}

} /* namespace pyxsec */
