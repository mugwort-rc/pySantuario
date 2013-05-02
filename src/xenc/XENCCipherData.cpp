/*
 * XENCCipherData.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XENCCipherData.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>

#include <xsec/xenc/XENCCipherData.hpp>

namespace pyxsec {

void XENCCipherData_init(void) {
	//! XENCCipherData
	auto XENCCipherData_ = boost::python::class_<XENCCipherData, boost::noncopyable>("XENCCipherData", boost::python::no_init)
			.def("getCipherDataType", boost::python::pure_virtual(&XENCCipherData::getCipherDataType))
			//! TODO XENCCipherValue
			.def("getCipherValue", boost::python::pure_virtual(&XENCCipherData::getCipherValue), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XENCCipherReference
			.def("getCipherReference", boost::python::pure_virtual(&XENCCipherData::getCipherReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElement", boost::python::pure_virtual(&XENCCipherData::getElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope XENCCipherDataScope = XENCCipherData_;
	//! XENCCipherData::XENCCipherDataType
	boost::python::enum_<XENCCipherData::XENCCipherDataType>("XENCCipherDataType")
			.value("NO_TYPE", XENCCipherData::NO_TYPE)
			.value("VALUE_TYPE", XENCCipherData::VALUE_TYPE)
			.value("REFERENCE_TYPE", XENCCipherData::REFERENCE_TYPE)
			.export_values()
			;
}

} /* namespace pyxsec */
