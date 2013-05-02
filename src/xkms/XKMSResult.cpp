/*
 * XKMSResult.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XKMSResult.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>

#include <xsec/xkms/XKMSResult.hpp>

namespace pyxsec {

void XKMSResult_init(void) {
	//! XKMSResult
	boost::python::class_<XKMSResult, boost::noncopyable, boost::python::bases<XKMSResultType> >("XKMSResult", boost::python::no_init)
			.def("getElement", &XKMSResult::getElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
