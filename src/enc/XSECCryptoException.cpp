/*
 * XSECCryptoException.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XSECCryptoException.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoException.hpp>

namespace pyxsec {

void XSECCryptoException_init(void) {
	//! XSECCryptoException
	auto XSECCryptoException_ = boost::python::class_<XSECCryptoException>("XSECCryptoException", boost::python::init<XSECCryptoException::XSECCryptoExceptionType, boost::python::optional<const char*> >())
			.def(boost::python::init<XSECCryptoException::XSECCryptoExceptionType, safeBuffer&>())
			.def("getMsg", &XSECCryptoException::getMsg)
			.def("getType", &XSECCryptoException::getType)
			;
	boost::python::scope XSECCryptoExceptionScope = XSECCryptoException_;
	//! XSECCryptoException::XSECCryptoExceptionType
	boost::python::enum_<XSECCryptoException::XSECCryptoExceptionType>("XSECCryptoExceptionType")
			.value("None", XSECCryptoException::None)
			.value("GeneralError", XSECCryptoException::GeneralError)
			.value("MDError", XSECCryptoException::MDError)
			.value("Base64Error", XSECCryptoException::Base64Error)
			.value("MemoryError", XSECCryptoException::MemoryError)
			.value("X509Error", XSECCryptoException::X509Error)
			.value("DSAError", XSECCryptoException::DSAError)
			.value("RSAError", XSECCryptoException::RSAError)
			.value("SymmetricError", XSECCryptoException::SymmetricError)
			.value("UnsupportedError", XSECCryptoException::UnsupportedError)
			.value("UnsupportedAlgorithm", XSECCryptoException::UnsupportedAlgorithm)
			.value("ECError", XSECCryptoException::ECError)
			.value("UnknownError", XSECCryptoException::UnknownError)
			.export_values()
			;
}

} /* namespace pyxsec */
