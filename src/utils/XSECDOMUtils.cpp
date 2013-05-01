/*
 * XSECDOMUtils.cpp
 *
 *  Created on: 2013/05/01
 *      Author: mugwort_rc
 */

#include "XSECDOMUtils.h"

#include <boost/python.hpp>

#include <xsec/utils/XSECDOMUtils.hpp>

namespace pyxsec {

safeBuffer pyGatherChildrenText(xercesc::DOMNode* parent) {
	safeBuffer result;
	gatherChildrenText(parent, result);
	return result;
}

//! Generate Ids
BOOST_PYTHON_FUNCTION_OVERLOADS(GenerateIdOverloads, generateId, 0, 1)

void XSECDOMUtils_init(void) {
	//! XSECDOMUtils
	// Utilities to manipulate namespaces
	boost::python::def("getDSIGLocalName", &getDSIGLocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("getDSIG11LocalName", &getDSIG11LocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("getECLocalName", &getECLocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("getXPFLocalName", &getXPFLocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("getXENCLocalName", &getXENCLocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("getXENC11LocalName", &getXENC11LocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("getXKMSLocalName", &getXKMSLocalName, boost::python::return_value_policy<boost::python::return_by_value>());
	// Find a nominated DSIG/XENC node in a document
	boost::python::def("findDSIGNode", &findDSIGNode, boost::python::return_value_policy<boost::python::reference_existing_object>());
	boost::python::def("findXENCNode", &findXENCNode, boost::python::return_value_policy<boost::python::reference_existing_object>());
	// Find particular type of node child
	boost::python::def("findFirstChildOfType", &findFirstChildOfType, boost::python::return_value_policy<boost::python::reference_existing_object>());
	boost::python::def("findNextChildOfType", &findNextChildOfType, boost::python::return_value_policy<boost::python::reference_existing_object>());
	boost::python::def("findFirstElementChild", &findFirstElementChild, boost::python::return_value_policy<boost::python::reference_existing_object>());
	boost::python::def("findNextElementChild", &findNextElementChild, boost::python::return_value_policy<boost::python::reference_existing_object>());
	// Make a QName
	//boost::python::def("makeQName", &makeQName, boost::python::return_internal_reference<>());
	// Gather text from children
	boost::python::def("gatherChildrenText", &pyGatherChildrenText);
	// Generate Ids
	boost::python::def("generateId", &generateId, GenerateIdOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()]);
	// String Functions
	boost::python::def("cleanURIEscapes", &cleanURIEscapes, boost::python::return_value_policy<boost::python::return_by_value>());
}

} /* namespace pyxsec */
