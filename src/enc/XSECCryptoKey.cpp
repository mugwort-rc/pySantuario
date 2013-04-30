/*
 * XSECCryptoKey.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XSECCryptoKey.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoKey.hpp>

namespace pyxsec {

class XSECCryptoKeyWrapper
: public XSECCryptoKey, public boost::python::wrapper<XSECCryptoKey>
{
public:
XSECCryptoKeyWrapper()
: XSECCryptoKey()
{}

KeyType getKeyType() const {
	if(boost::python::override getKeyType = this->get_override("getKeyType")){
		return getKeyType();
	}else{
		return XSECCryptoKey::getKeyType();
	}
}

const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

XSECCryptoKey * clone() const {
	return this->get_override("clone")();
}

};

void XSECCryptoKey_init(void) {
	//! XSECCryptoKey
	auto XSECCryptoKey_ = boost::python::class_<XSECCryptoKeyWrapper, boost::noncopyable>("XSECCryptoKey")
			.def("getKeyType", &XSECCryptoKey::getKeyType)
			.def("getProviderName", boost::python::pure_virtual(&XSECCryptoKey::getProviderName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("clone", boost::python::pure_virtual(&XSECCryptoKey::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope XSECCryptoKeyScope = XSECCryptoKey_;
	//! XSECCryptoKey::KeyType
	boost::python::enum_<XSECCryptoKey::KeyType>("KeyType")
			.value("KEY_NONE", XSECCryptoKey::KEY_NONE)
			.value("KEY_DSA_PUBLIC", XSECCryptoKey::KEY_DSA_PUBLIC)
			.value("KEY_DSA_PRIVATE", XSECCryptoKey::KEY_DSA_PRIVATE)
			.value("KEY_DSA_PAIR", XSECCryptoKey::KEY_DSA_PAIR)
			.value("KEY_RSA_PUBLIC", XSECCryptoKey::KEY_RSA_PUBLIC)
			.value("KEY_RSA_PRIVATE", XSECCryptoKey::KEY_RSA_PRIVATE)
			.value("KEY_RSA_PAIR", XSECCryptoKey::KEY_RSA_PAIR)
			.value("KEY_HMAC", XSECCryptoKey::KEY_HMAC)
			.value("KEY_SYMMETRIC", XSECCryptoKey::KEY_SYMMETRIC)
			.value("KEY_EC_PUBLIC", XSECCryptoKey::KEY_EC_PUBLIC)
			.value("KEY_EC_PRIVATE", XSECCryptoKey::KEY_EC_PRIVATE)
			.value("KEY_EC_PAIR", XSECCryptoKey::KEY_EC_PAIR)
			.export_values()
			;
}

} /* namespace pyxsec */
