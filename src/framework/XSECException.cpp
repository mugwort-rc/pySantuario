/*
 * XSECException.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XSECException.h"

#include <boost/python.hpp>

#include <xsec/framework/XSECException.hpp>

namespace pyxsec {

void XSECException_init(void) {
	//! XSECException
	auto XSECException_ = boost::python::class_<XSECException>("XSECException", boost::python::init<XSECException::XSECExceptionType, boost::python::optional<const XMLCh*> >())
			.def(boost::python::init<XSECException::XSECExceptionType, const char*>())
			.def("getMsg", &XSECException::getMsg, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getType", &XSECException::getType)
			;
	boost::python::scope XSECExceptionScope = XSECException_;
	//! XSECException::XSECExceptionType
	boost::python::enum_<XSECException::XSECExceptionType>("XSECExceptionType")
			.value("None", XSECException::None)
			.value("MemoryAllocationFail", XSECException::MemoryAllocationFail)
			.value("NoHashFoundInDigestValue", XSECException::NoHashFoundInDigestValue)
			.value("UnknownDSIGAttribute", XSECException::UnknownDSIGAttribute)
			.value("ExpectedDSIGChildNotFound", XSECException::ExpectedDSIGChildNotFound)
			.value("UnknownTransform", XSECException::UnknownTransform)
			.value("TransformInputOutputFail", XSECException::TransformInputOutputFail)
			.value("IDNotFoundInDOMDoc", XSECException::IDNotFoundInDOMDoc)
			.value("UnsupportedXpointerExpr", XSECException::UnsupportedXpointerExpr)
			.value("XPathError", XSECException::XPathError)
			.value("XSLError", XSECException::XSLError)
			.value("Unsupported", XSECException::Unsupported)
			.value("LoadEmptySignature", XSECException::LoadEmptySignature)
			.value("LoadNonSignature", XSECException::LoadNonSignature)
			.value("UnknownCanonicalization", XSECException::UnknownCanonicalization)
			.value("UnknownSignatureAlgorithm", XSECException::UnknownSignatureAlgorithm)
			.value("LoadEmptyX509", XSECException::LoadEmptyX509)
			.value("LoadNonX509", XSECException::LoadNonX509)
			.value("OpenSSLError", XSECException::OpenSSLError)
			.value("SigVfyError", XSECException::SigVfyError)
			.value("LoadEmptySignedInfo", XSECException::LoadEmptySignedInfo)
			.value("LoadNonSignedInfo", XSECException::LoadNonSignedInfo)
			.value("ExpectedReferenceURI", XSECException::ExpectedReferenceURI)
			.value("NotLoaded", XSECException::NotLoaded)
			.value("CryptoProviderError", XSECException::CryptoProviderError)
			.value("KeyInfoError", XSECException::KeyInfoError)
			.value("SigningError", XSECException::SigningError)
			.value("LoadEmptyInfoName", XSECException::LoadEmptyInfoName)
			.value("LoadNonInfoName", XSECException::LoadNonInfoName)
			.value("UnknownKeyValue", XSECException::UnknownKeyValue)
			.value("SignatureCreationError", XSECException::SignatureCreationError)
			.value("ErrorOpeningURI", XSECException::ErrorOpeningURI)
			.value("ProviderError", XSECException::ProviderError)
			.value("InternalError", XSECException::InternalError)
			.value("EnvelopeError", XSECException::EnvelopeError)
			.value("UnsupportedFunction", XSECException::UnsupportedFunction)
			.value("TransformError", XSECException::TransformError)
			.value("SafeBufferError", XSECException::SafeBufferError)
			.value("HTTPURIInputStreamError", XSECException::HTTPURIInputStreamError)
			.value("LoadEmptyXPathFilter", XSECException::LoadEmptyXPathFilter)
			.value("XPathFilterError", XSECException::XPathFilterError)
			.value("DNameDecodeError", XSECException::DNameDecodeError)
			// Encryption errors
			.value("EncryptedTypeError", XSECException::EncryptedTypeError)
			.value("ExpectedXENCChildNotFound", XSECException::ExpectedXENCChildNotFound)
			.value("CipherDataError", XSECException::CipherDataError)
			.value("CipherValueError", XSECException::CipherValueError)
			.value("CipherError", XSECException::CipherError)
			.value("AlgorithmMapperError", XSECException::AlgorithmMapperError)
			.value("EncryptionMethodError", XSECException::EncryptionMethodError)
			.value("CipherReferenceError", XSECException::CipherReferenceError)
			.value("ObjectError", XSECException::ObjectError)
			// XKMS Error
			.value("XKMSError", XSECException::XKMSError)
			.value("ExpectedXKMSChildNotFound", XSECException::ExpectedXKMSChildNotFound)
			.value("MessageAbstractTypeError", XSECException::MessageAbstractTypeError)
			.value("RequestAbstractTypeError", XSECException::RequestAbstractTypeError)
			.value("ResultTypeError", XSECException::ResultTypeError)
			.value("StatusError", XSECException::StatusError)
			.value("UnknownError", XSECException::UnknownError)
			;
}

} /* namespace pyxsec */
