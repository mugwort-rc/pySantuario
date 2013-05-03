/*
 * XSECCryptoUtils.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECCryptoUtils.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoUtils.hpp>

namespace pyxsec {

void XSECCryptoUtils_init(void) {
	//! XSECCryptoUtils
	boost::python::def("CalculateXKMSAuthenticationKey", &CalculateXKMSAuthenticationKey);
	boost::python::def("CalculateXKMSRevocationCodeIdentifierEncoding1", &CalculateXKMSRevocationCodeIdentifierEncoding1);
	boost::python::def("CalculateXKMSRevocationCodeIdentifierEncoding2", &CalculateXKMSRevocationCodeIdentifierEncoding2);
	boost::python::def("CalculateXKMSRevocationCodeIdentifierEncoding2From1", &CalculateXKMSRevocationCodeIdentifierEncoding2From1);
	boost::python::def("CalculateXKMSKEK", &CalculateXKMSKEK);
	//! TODO: pythonize
	boost::python::def("EncodeToBase64XMLCh", &EncodeToBase64XMLCh, boost::python::return_value_policy<boost::python::return_by_value>());
	boost::python::def("DecodeFromBase64XMLCh", &DecodeFromBase64XMLCh);
	boost::python::def("DecodeFromBase64", &DecodeFromBase64);
	boost::python::def("ASN2DSASig", &ASN2DSASig);
	boost::python::def("getRSASigOID", &getRSASigOID, boost::python::return_value_policy<boost::python::return_opaque_pointer>());
}

} /* namespace pyxsec */
