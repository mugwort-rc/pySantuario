/*
 * XSECCryptoKeyHMAC.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XSECCryptoKeyHMAC.h"

#include <boost/python.hpp>

#include <xsec/enc/XSECCryptoKeyHMAC.hpp>

namespace pyxsec {

class XSECCryptoKeyHMACWrapper
: public XSECCryptoKeyHMAC, public boost::python::wrapper<XSECCryptoKeyHMAC>
{
public:
	XSECCryptoKeyHMACWrapper()
: XSECCryptoKeyHMAC()
{}

KeyType getKeyType() const {
	if(boost::python::override getKeyType = this->get_override("getKeyType")){
		return getKeyType();
	}else{
		return XSECCryptoKeyHMAC::getKeyType();
	}
}

XSECCryptoKey * clone() const {
	return this->get_override("clone")();
}

void setKey(unsigned char * inBuf, unsigned int inLength) {
	this->get_override("setKey")(inBuf, inLength);
}

unsigned int getKey(safeBuffer &outBuf) const {
	return this->get_override("setKey")(boost::ref(outBuf));
}

//! XSECCryptoKey
const XMLCh * getProviderName() const {
	return this->get_override("getProviderName")();
}

};

class XSECCryptoKeyHMACDefVisitor
: public boost::python::def_visitor<XSECCryptoKeyHMACDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setKey", &XSECCryptoKeyHMACDefVisitor::setKey)
	.def("getKey", &XSECCryptoKeyHMACDefVisitor::getKey)
	;
}

static void setKey(XSECCryptoKeyHMAC& self, const char* key) {
	std::string buff(key);
	self.setKey(const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(buff.c_str())), buff.size());
}

static std::string getKey(XSECCryptoKeyHMAC& self) {
	safeBuffer buffer;
	unsigned int size = self.getKey(buffer);
	return std::string(buffer.rawCharBuffer(), size);
}

};

void XSECCryptoKeyHMAC_init(void) {
	//! XSECCryptoKeyHMAC
	boost::python::class_<XSECCryptoKeyHMACWrapper, boost::noncopyable, boost::python::bases<XSECCryptoKey> >("XSECCryptoKeyHMAC")
			.def(XSECCryptoKeyHMACDefVisitor())
			.def("getKeyType", &XSECCryptoKeyHMAC::getKeyType)
			.def("clone", boost::python::pure_virtual(&XSECCryptoKeyHMAC::clone), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setKey", boost::python::pure_virtual(&XSECCryptoKeyHMAC::setKey))
			.def("getKey", boost::python::pure_virtual(&XSECCryptoKeyHMAC::getKey))
			;
}

} /* namespace pyxsec */
