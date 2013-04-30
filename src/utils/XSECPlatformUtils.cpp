/*
 * XSECPlatformUtils.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "XSECPlatformUtils.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/transformers/TXFMBase.hpp>
#include <xsec/framework/XSECAlgorithmMapper.hpp>
#include <xsec/framework/XSECAlgorithmHandler.hpp>

#include <xsec/utils/XSECPlatformUtils.hpp>

namespace pyxsec {

BOOST_PYTHON_FUNCTION_OVERLOADS(XSECPlatformUtilsInitializeOverloads, XSECPlatformUtils::Initialise, 0, 1)

void XSECPlatformUtils_init(void) {
	//! XSECPlatformUtils
	boost::python::class_<XSECPlatformUtils, boost::noncopyable>("XSECPlatformUtils", boost::python::no_init)
			.def_readwrite("initCount", &XSECPlatformUtils::initCount)
			.def_readwrite("g_cryptoProvider", &XSECPlatformUtils::g_cryptoProvider)
			.def_readonly("g_algorithmMapper", &XSECPlatformUtils::g_algorithmMapper)
			.def("Initialise", &XSECPlatformUtils::Initialise, XSECPlatformUtilsInitializeOverloads())
			.def("SetCryptoProvider", &XSECPlatformUtils::SetCryptoProvider)
			.def("registerAlgorithmHandler", &XSECPlatformUtils::registerAlgorithmHandler)
			.def("whitelistAlgorithm", &XSECPlatformUtils::whitelistAlgorithm)
			.def("blacklistAlgorithm", &XSECPlatformUtils::blacklistAlgorithm)
			//! TODO: TransformFactory
			//.def("SetReferenceLoggingSink", &XSECPlatformUtils::SetReferenceLoggingSink)
			//.def("GetReferenceLoggingSink", &XSECPlatformUtils::GetReferenceLoggingSink, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("Terminate", &XSECPlatformUtils::Terminate)
			.staticmethod("Initialise")
			.staticmethod("SetCryptoProvider")
			.staticmethod("registerAlgorithmHandler")
			.staticmethod("whitelistAlgorithm")
			.staticmethod("blacklistAlgorithm")
			//.staticmethod("SetReferenceLoggingSink")
			//.staticmethod("GetReferenceLoggingSink")
			.staticmethod("Terminate")
			;
}

} /* namespace pyxsec */
