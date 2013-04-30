/*
 * XENCEncryptedData.cpp
 *
 *  Created on: 2013/05/01
 *      Author: mugwort_rc
 */

#include "XENCEncryptedData.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>

#include <xsec/xenc/XENCEncryptedData.hpp>

namespace pyxsec {

void XENCEncryptedData_init(void) {
	//! XENCEncryptedData
	boost::python::class_<XENCEncryptedData, boost::noncopyable, boost::python::bases<XENCEncryptedType> >("XENCEncryptedData", boost::python::no_init)
			;
}

} /* namespace pyxsec */
