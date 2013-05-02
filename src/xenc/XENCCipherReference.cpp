/*
 * XENCCipherReference.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XENCCipherReference.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>
#include <xsec/dsig/DSIGTransformList.hpp>
#include <xsec/dsig/DSIGTransformBase64.hpp>
#include <xsec/dsig/DSIGTransformXPath.hpp>
#include <xsec/dsig/DSIGTransformXPathFilter.hpp>
#include <xsec/dsig/DSIGTransformXSL.hpp>
#include <xsec/dsig/DSIGTransformC14n.hpp>

#include <xsec/xenc/XENCCipherReference.hpp>

namespace pyxsec {

void XENCCipherReference_init(void) {
	//! XENCCipherReference
	boost::python::class_<XENCCipherReference, boost::noncopyable>("XENCCipherReference", boost::python::no_init)
			.def("getTransforms", boost::python::pure_virtual(&XENCCipherReference::getTransforms), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURI", boost::python::pure_virtual(&XENCCipherReference::getURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElement", boost::python::pure_virtual(&XENCCipherReference::getElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendBase64Transform", boost::python::pure_virtual(&XENCCipherReference::appendBase64Transform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendXPathTransform", boost::python::pure_virtual(&XENCCipherReference::appendXPathTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendXPathFilterTransform", boost::python::pure_virtual(&XENCCipherReference::appendXPathFilterTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendXSLTransform", boost::python::pure_virtual(&XENCCipherReference::appendXSLTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendCanonicalizationTransform", boost::python::pure_virtual(&XENCCipherReference::appendCanonicalizationTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
