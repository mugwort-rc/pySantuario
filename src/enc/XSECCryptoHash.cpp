/*
 * XSECCryptoHash.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECCryptoHash.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoHash.hpp>

namespace pyxsec {

class XSECCryptoHashWrapper
: public XSECCryptoHash, public boost::python::wrapper<XSECCryptoHash>
{
public:
XSECCryptoHashWrapper()
: XSECCryptoHash()
{}

void reset(void) {
	this->get_override("reset")();
}

void hash(unsigned char * data, unsigned int length) {
	this->get_override("hash")(data, length);
}

unsigned int finish(unsigned char * hash, unsigned int maxLength) {
	return this->get_override("hash")(hash, maxLength);
}

HashType getHashType(void) const {
	return this->get_override("getHashType")();
}

void setKey(XSECCryptoKey * key) {
	this->get_override("setKey")(boost::python::ptr(key));
}

};

void XSECCryptoHash_init(void) {
	//! XSECCryptoHash
	auto XSECCryptoHash_ = boost::python::class_<XSECCryptoHashWrapper, boost::noncopyable>("XSECCryptoHash")
			.def("reset", boost::python::pure_virtual(&XSECCryptoHash::reset))
			.def("hash", boost::python::pure_virtual(&XSECCryptoHash::hash))
			.def("finish", boost::python::pure_virtual(&XSECCryptoHash::finish))
			.def("getHashType", boost::python::pure_virtual(&XSECCryptoHash::getHashType))
			.def("setKey", boost::python::pure_virtual(&XSECCryptoHash::setKey))
			;
	boost::python::scope XSECCryptoHashScope = XSECCryptoHash_;
	//! XSECCryptoHash::HashType
	boost::python::enum_<XSECCryptoHash::HashType>("HashType")
			.value("HASH_NONE", XSECCryptoHash::HASH_NONE)
			.value("HASH_SHA1", XSECCryptoHash::HASH_SHA1)
			.value("HASH_MD5", XSECCryptoHash::HASH_MD5)
			.value("HASH_SHA224", XSECCryptoHash::HASH_SHA224)
			.value("HASH_SHA256", XSECCryptoHash::HASH_SHA256)
			.value("HASH_SHA384", XSECCryptoHash::HASH_SHA384)
			.value("HASH_SHA512", XSECCryptoHash::HASH_SHA512)
			.export_values()
			;
}

} /* namespace pyxsec */
