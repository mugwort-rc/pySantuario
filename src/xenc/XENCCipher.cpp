/*
 * XENCCipher.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XENCCipher.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>
#include <xsec/enc/XSECCryptoKey.hpp>
#include <xsec/xenc/XENCEncryptedData.hpp>
#include <xsec/xenc/XENCEncryptedKey.hpp>
#include <xsec/enc/XSECKeyInfoResolver.hpp>
#include <xsec/utils/XSECBinTXFMInputStream.hpp>
#include <xsec/transformers/TXFMChain.hpp>

#include <xsec/xenc/XENCCipher.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

class XENCCipherDefVisitor
: public boost::python::def_visitor<XENCCipherDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("encryptKey", &XENCCipherDefVisitor::encryptKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setKey", &XENCCipherDefVisitor::setKey)
	.def("setKEK", &XENCCipherDefVisitor::setKEK)
	;
}

static XENCEncryptedKey * encryptKey(XENCCipher& self, const std::string& key, encryptionMethod em) {
	return self.encryptKey(reinterpret_cast<const unsigned char*>(key.c_str()), key.size(), em);
}

static void setKey(XENCCipher& self, XSECCryptoKey * key) {
	self.setKey(key->clone());
}

static void setKEK(XENCCipher& self, XSECCryptoKey * key) {
	self.setKEK(key->clone());
}

};

template <class STR>
class XENCCipherStrDefVisitor
: public boost::python::def_visitor<XENCCipherStrDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("encryptElement", &XENCCipherStrDefVisitor::encryptElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("encryptElementDetached", &XENCCipherStrDefVisitor::encryptElementDetached, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("encryptElementContent", &XENCCipherStrDefVisitor::encryptElementContent, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("encryptElementContentDetached", &XENCCipherStrDefVisitor::encryptElementContentDetached, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("encryptKey", &XENCCipherStrDefVisitor::encryptKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("encryptBinInputStream", &XENCCipherStrDefVisitor::encryptBinInputStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("encryptTXFMChain", &XENCCipherStrDefVisitor::encryptTXFMChain, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setXENCNSPrefix", &XENCCipherStrDefVisitor::setXENCNSPrefix)
	.def("createEncryptedData", &XENCCipherStrDefVisitor::createEncryptedData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMDocument* encryptElement(XENCCipher& self, xercesc::DOMElement* element, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptElement(element, em, buff.ptr());
}

static xercesc::DOMNode* encryptElementDetached(XENCCipher& self, xercesc::DOMElement* element, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptElementDetached(element, em, buff.ptr());
}

static xercesc::DOMDocument* encryptElementContent(XENCCipher& self, xercesc::DOMElement* element, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptElementContent(element, em, buff.ptr());
}

static xercesc::DOMNode* encryptElementContentDetached(XENCCipher& self, xercesc::DOMElement* element, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptElementContentDetached(element, em, buff.ptr());
}

static XENCEncryptedKey * encryptKey(XENCCipher& self, const std::string& key, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptKey(reinterpret_cast<const unsigned char*>(key.c_str()), key.size(), em, buff.ptr());
}

static XENCEncryptedData * encryptBinInputStream(XENCCipher& self, xercesc::BinInputStream * plainText, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptBinInputStream(plainText, em, buff.ptr());
}

static XENCEncryptedData * encryptTXFMChain(XENCCipher& self, TXFMChain * plainText, encryptionMethod em, const STR& algorithmURI) {
	pyxerces::XMLString buff(algorithmURI);
	return self.encryptTXFMChain(plainText, em, buff.ptr());
}

static void setXENCNSPrefix(XENCCipher& self, const STR& prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXENCNSPrefix(buff.ptr());
}

static XENCEncryptedData* createEncryptedData(XENCCipher& self, XENCCipherData::XENCCipherDataType type, const STR& algorithm, const STR& value) {
	pyxerces::XMLString buff1(algorithm), buff2(value);
	return self.createEncryptedData(type, buff1.ptr(), buff2.ptr());
}

};

//! XENCCipher
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptElementOverloads, encryptElement, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptElementDetachedOverloads, encryptElementDetached, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptElementContentOverloads, encryptElement, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptElementContentDetachedOverloads, encryptElementDetached, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptKeyOverloads, encryptKey, 3, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptBinInputStreamOverloads, encryptBinInputStream, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCCipherEncryptTXFMChainOverloads, encryptTXFMChain, 2, 3)

void XENCCipher_init(void) {
	//! XENCCipher
	boost::python::class_<XENCCipher, boost::noncopyable>("XENCCipher", boost::python::no_init)
			.def(XENCCipherDefVisitor())
			.def(XENCCipherStrDefVisitor<std::string>())
			.def("decryptElement", static_cast<xercesc::DOMDocument*(XENCCipher::*)(xercesc::DOMElement*)>(&XENCCipher::decryptElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("decryptElementDetached", static_cast<xercesc::DOMNode*(XENCCipher::*)(xercesc::DOMElement*)>(&XENCCipher::decryptElementDetached), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("decryptElement", static_cast<xercesc::DOMDocument*(XENCCipher::*)()>(&XENCCipher::decryptElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("decryptElementDetached", static_cast<xercesc::DOMNode*(XENCCipher::*)()>(&XENCCipher::decryptElementDetached), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XSECBinTXFMInputStream
			.def("decryptToBinInputStream", &XENCCipher::decryptToBinInputStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("decryptKey", static_cast<int(XENCCipher::*)(XENCEncryptedKey*, XMLByte*, int)>(&XENCCipher::decryptKey))
			.def("decryptKey", static_cast<int(XENCCipher::*)(xercesc::DOMElement*, XMLByte*, int)>(&XENCCipher::decryptKey))
			.def("encryptElement", &XENCCipher::encryptElement, XENCCipherEncryptElementOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("encryptElementDetached", &XENCCipher::encryptElementDetached, XENCCipherEncryptElementDetachedOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("encryptElementContent", &XENCCipher::encryptElementContent, XENCCipherEncryptElementContentOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("encryptElementContentDetached", &XENCCipher::encryptElementContentDetached, XENCCipherEncryptElementContentDetachedOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("encryptKey", &XENCCipher::encryptKey, XENCCipherEncryptKeyOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("encryptBinInputStream", &XENCCipher::encryptBinInputStream, XENCCipherEncryptBinInputStreamOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			//! TODO: TXFMChain
			.def("encryptTXFMChain", &XENCCipher::encryptTXFMChain, XENCCipherEncryptTXFMChainOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("getDocument", &XENCCipher::getDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXENCNSPrefix", &XENCCipher::getXENCNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getEncryptedData", &XENCCipher::getEncryptedData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPrettyPrint", &XENCCipher::getPrettyPrint)
			.def("getExclusiveC14nSerialisation", &XENCCipher::getExclusiveC14nSerialisation)
			//! TODO: XSECCryptoKey
			//.def("setKey", &XENCCipher::setKey)  //!< must be set key clone
			//.def("setKEK", &XENCCipher::setKEK)  //!< must be set key clone
			//! TODO: XSECKeyInfoResolver
			.def("setKeyInfoResolver", &XENCCipher::setKeyInfoResolver)
			.def("setXENCNSPrefix", &XENCCipher::setXENCNSPrefix)
			.def("setPrettyPrint", &XENCCipher::setPrettyPrint)
			.def("setExclusiveC14nSerialisation", &XENCCipher::setExclusiveC14nSerialisation)
			.def("createEncryptedData", &XENCCipher::createEncryptedData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadEncryptedKey", &XENCCipher::loadEncryptedKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadEncryptedData", &XENCCipher::loadEncryptedData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
