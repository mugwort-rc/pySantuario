/*
 * DSIGSignature.cpp
 *
 *  Created on: 2013/05/01
 *      Author: mugwort_rc
 */

#include "DSIGSignature.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/utils/XSECBinTXFMInputStream.hpp>
#include <xsec/framework/XSECURIResolver.hpp>
#include <xsec/enc/XSECKeyInfoResolver.hpp>
#include <xsec/dsig/DSIGKeyInfoValue.hpp>
#include <xsec/dsig/DSIGKeyInfoX509.hpp>
#include <xsec/dsig/DSIGKeyInfoName.hpp>
#include <xsec/dsig/DSIGKeyInfoPGPData.hpp>
#include <xsec/dsig/DSIGKeyInfoSPKIData.hpp>
#include <xsec/dsig/DSIGKeyInfoMgmtData.hpp>
#include <xsec/dsig/DSIGObject.hpp>
#include <xsec/dsig/DSIGReference.hpp>

#include <xsec/dsig/DSIGSignature.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGSignatureStringDefVisitor
 : public boost::python::def_visitor<DSIGSignatureStringDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setDSIGNSPrefix", &DSIGSignatureStringDefVisitor::setDSIGNSPrefix)
	.def("setECNSPrefix", &DSIGSignatureStringDefVisitor::setECNSPrefix)
	.def("setXPFNSPrefix", &DSIGSignatureStringDefVisitor::setXPFNSPrefix)
	.def("createBlankSignature", &DSIGSignatureStringDefVisitor::createBlankSignature, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignature&, const STR, hashMethod, char*)>(&DSIGSignatureStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignature&, const STR, hashMethod)>(&DSIGSignatureStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignature&, const STR)>(&DSIGSignatureStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignature&, const STR, const STR, const STR)>(&DSIGSignatureStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignature&, const STR, const STR)>(&DSIGSignatureStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendDSAKeyValue", &DSIGSignatureStringDefVisitor::appendDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendRSAKeyValue", &DSIGSignatureStringDefVisitor::appendRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendKeyName", static_cast<DSIGKeyInfoName*(*)(DSIGSignature&, const STR, bool)>(&DSIGSignatureStringDefVisitor::appendKeyName), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendKeyName", static_cast<DSIGKeyInfoName*(*)(DSIGSignature&, const STR)>(&DSIGSignatureStringDefVisitor::appendKeyName), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendPGPData", &DSIGSignatureStringDefVisitor::appendPGPData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendSPKIData", &DSIGSignatureStringDefVisitor::appendSPKIData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendMgmtData", &DSIGSignatureStringDefVisitor::appendMgmtData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("registerIdAttributeName", &DSIGSignatureStringDefVisitor::registerIdAttributeName)
	.def("deregisterIdAttributeName", &DSIGSignatureStringDefVisitor::deregisterIdAttributeName)
	.def("registerIdAttributeName", &DSIGSignatureStringDefVisitor::registerIdAttributeNameNS)
	.def("deregisterIdAttributeName", &DSIGSignatureStringDefVisitor::deregisterIdAttributeNameNS)
	;
}

static void setDSIGNSPrefix(DSIGSignature& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setDSIGNSPrefix(buff.ptr());
}

static void setECNSPrefix(DSIGSignature& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setECNSPrefix(buff.ptr());
}

static void setXPFNSPrefix(DSIGSignature& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXPFNSPrefix(buff.ptr());
}

static xercesc::DOMElement *createBlankSignature(DSIGSignature& self, xercesc::DOMDocument *doc, const STR canonicalizationAlgorithmURI, const STR signatureAlgorithmURI) {
	pyxerces::XMLString buff1(canonicalizationAlgorithmURI), buff2(signatureAlgorithmURI);
	return self.createBlankSignature(doc, buff1.ptr(), buff2.ptr());
}

static DSIGReference* createReference(DSIGSignature& self, const STR URI, hashMethod hm, char* type) {
	pyxerces::XMLString buff(URI);
	return self.createReference(buff.ptr(), hm, type);
}

static DSIGReference* createReference(DSIGSignature& self, const STR URI, hashMethod hm) {
	pyxerces::XMLString buff(URI);
	return self.createReference(buff.ptr(), hm);
}

static DSIGReference* createReference(DSIGSignature& self, const STR URI) {
	return createReference(self, URI, HASH_SHA1);
}

static DSIGReference * createReference(DSIGSignature& self, const STR URI, const STR hashAlgorithmURI, const STR type) {
	pyxerces::XMLString buff1(URI), buff2(hashAlgorithmURI), buff3(type);
	return self.createReference(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static DSIGReference * createReference(DSIGSignature& self, const STR URI, const STR hashAlgorithmURI) {
	pyxerces::XMLString buff1(URI), buff2(hashAlgorithmURI);
	return self.createReference(buff1.ptr(), buff2.ptr());
}

static DSIGKeyInfoValue * appendDSAKeyValue(DSIGSignature& self, const STR P, const STR Q, const STR G, const STR Y) {
	pyxerces::XMLString buff1(P), buff2(Q), buff3(G), buff4(Y);
	return self.appendDSAKeyValue(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static DSIGKeyInfoValue * appendRSAKeyValue(DSIGSignature& self, const STR modulus, const STR exponent) {
	pyxerces::XMLString buff1(modulus), buff2(exponent);
	return self.appendRSAKeyValue(buff1.ptr(), buff2.ptr());
}

static DSIGKeyInfoName * appendKeyName(DSIGSignature& self, const STR name, bool isDName) {
	pyxerces::XMLString buff(name);
	return self.appendKeyName(buff.ptr(), isDName);
}

static DSIGKeyInfoName * appendKeyName(DSIGSignature& self, const STR name) {
	return appendKeyName(self, name, false);
}

static DSIGKeyInfoPGPData * appendPGPData(DSIGSignature& self, const STR id, const STR packet) {
	pyxerces::XMLString buff1(id), buff2(packet);
	return self.appendPGPData(buff1.ptr(), buff2.ptr());
}

static DSIGKeyInfoSPKIData * appendSPKIData(DSIGSignature& self, const STR sexp) {
	pyxerces::XMLString buff(sexp);
	return self.appendSPKIData(buff.ptr());
}

static DSIGKeyInfoMgmtData * appendMgmtData(DSIGSignature& self, const STR data) {
	pyxerces::XMLString buff(data);
	return self.appendMgmtData(buff.ptr());
}

static void registerIdAttributeName(DSIGSignature& self, const STR name) {
	pyxerces::XMLString buff(name);
	self.registerIdAttributeName(buff.ptr());
}

static bool deregisterIdAttributeName(DSIGSignature& self, const STR name) {
	pyxerces::XMLString buff(name);
	return self.deregisterIdAttributeName(buff.ptr());
}

static void registerIdAttributeNameNS(DSIGSignature& self, const STR ns, const STR name) {
	pyxerces::XMLString buff1(ns), buff2(name);
	self.registerIdAttributeNameNS(buff1.ptr(), buff2.ptr());
}

static bool deregisterIdAttributeNameNS(DSIGSignature& self, const STR ns, const STR name) {
	pyxerces::XMLString buff1(ns), buff2(name);
	return self.deregisterIdAttributeNameNS(buff1.ptr(), buff2.ptr());
}

};

class DSIGSignatureDefVisitor
: public boost::python::def_visitor<DSIGSignatureDefVisitor>
{
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setSigningKey", &DSIGSignatureDefVisitor::setSigningKey)
	;
}

static void setSigningKey(DSIGSignature& self, XSECCryptoKey* key) {
	self.setSigningKey(key->clone());
}

};

void DSIGSignature_init(void) {
	//! DSIGSignature
	boost::python::class_<DSIGSignature, boost::noncopyable>("DSIGSignature", boost::python::no_init)
			.def(DSIGSignatureDefVisitor())
			.def(DSIGSignatureStringDefVisitor<char*>())
			.def("load", &DSIGSignature::load)
			//.def("setSigningKey", &DSIGSignature::setSigningKey)    //!< must be set key clone
			.def("verify", &DSIGSignature::verify)
			.def("verifySignatureOnly", &DSIGSignature::verifySignatureOnly)
			.def("sign", &DSIGSignature::sign)
			.def("setDSIGNSPrefix", &DSIGSignature::setDSIGNSPrefix)
			.def("setECNSPrefix", &DSIGSignature::setECNSPrefix)
			.def("setXPFNSPrefix", &DSIGSignature::setXPFNSPrefix)
			.def("setPrettyPrint", &DSIGSignature::setPrettyPrint)
			.def("getPrettyPrint", &DSIGSignature::getPrettyPrint)
			.def("createBlankSignature", static_cast<xercesc::DOMElement*(DSIGSignature::*)(xercesc::DOMDocument*, const XMLCh*, const XMLCh*)>(&DSIGSignature::createBlankSignature), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createBlankSignature", static_cast<xercesc::DOMElement*(DSIGSignature::*)(xercesc::DOMDocument*, canonicalizationMethod, signatureMethod, hashMethod)>(&DSIGSignature::createBlankSignature), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createReference", static_cast<DSIGReference*(DSIGSignature::*)(const XMLCh*, hashMethod, char*)>(&DSIGSignature::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createReference", static_cast<DSIGReference*(DSIGSignature::*)(const XMLCh*, const XMLCh*, const XMLCh*)>(&DSIGSignature::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeReference", &DSIGSignature::removeReference, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("calculateSignedInfoAndReferenceHash", &DSIGSignature::calculateSignedInfoAndReferenceHash)
			.def("calculateSignedInfoHash", &DSIGSignature::calculateSignedInfoHash)
			//! TODO: DSIGReferenceList
			.def("getReferenceList", static_cast<DSIGReferenceList*(DSIGSignature::*)(void)>(&DSIGSignature::getReferenceList), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XSECBinTXFMInputStream
			.def("makeBinInputStream", &DSIGSignature::makeBinInputStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getErrMsgs", &DSIGSignature::getErrMsgs, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getDSIGNSPrefix", &DSIGSignature::getDSIGNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getECNSPrefix", &DSIGSignature::getECNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXPFNSPrefix", &DSIGSignature::getXPFNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getParentDocument", &DSIGSignature::getParentDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getCanonicalizationMethod", &DSIGSignature::getCanonicalizationMethod)
			.def("getAlgorithmURI", &DSIGSignature::getAlgorithmURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getHashMethod", &DSIGSignature::getHashMethod)
			.def("getSignatureMethod", &DSIGSignature::getSignatureMethod)
			.def("getSignatureValue", &DSIGSignature::getSignatureValue, boost::python::return_value_policy<boost::python::return_by_value>())
			//! TODO: XSECSafeBufferFormatter
			.def("getSBFormatter", &DSIGSignature::getSBFormatter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setInterlockingReferences", &DSIGSignature::setInterlockingReferences)
			.def("getInterlockingReferences", &DSIGSignature::getInterlockingReferences)
			.def("setURIResolver", &DSIGSignature::setURIResolver)
			//! TODO: XSECURIResolver
			.def("getURIResolver", &DSIGSignature::getURIResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setKeyInfoResolver", &DSIGSignature::setKeyInfoResolver)
			//! TODO: XSECKeyInfoResolver
			.def("getKeyInfoResolver", &DSIGSignature::getKeyInfoResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XSECKeyInfoResolver
			.def("getKeyInfoList", static_cast<DSIGKeyInfoList*(DSIGSignature::*)(void)>(&DSIGSignature::getKeyInfoList), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("clearKeyInfo", &DSIGSignature::clearKeyInfo)
			//! TODO: DSIGKeyInfoValue
			.def("appendDSAKeyValue", &DSIGSignature::appendDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendRSAKeyValue", &DSIGSignature::appendRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: DSIGKeyInfoX509
			.def("appendX509Data", &DSIGSignature::appendX509Data, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendKeyName", &DSIGSignature::appendKeyName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: DSIGKeyInfoPGPData
			.def("appendPGPData", &DSIGSignature::appendPGPData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: DSIGKeyInfoSPKIData
			.def("appendSPKIData", &DSIGSignature::appendSPKIData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: DSIGKeyInfoMgmtData
			.def("appendMgmtData", &DSIGSignature::appendMgmtData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: DSIGObject
			.def("appendObject", &DSIGSignature::appendObject, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getObjectLength", &DSIGSignature::getObjectLength)
			.def("getObjectItem", static_cast<DSIGObject*(DSIGSignature::*)(int)>(&DSIGSignature::getObjectItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setIdByAttributeName", &DSIGSignature::setIdByAttributeName)
			.def("getIdByAttributeName", &DSIGSignature::getIdByAttributeName)
			.def("registerIdAttributeName", &DSIGSignature::registerIdAttributeName)
			.def("deregisterIdAttributeName", &DSIGSignature::deregisterIdAttributeName)
			.def("registerIdAttributeNameNS", &DSIGSignature::registerIdAttributeNameNS)
			.def("deregisterIdAttributeNameNS", &DSIGSignature::deregisterIdAttributeNameNS)
			;
}

} /* namespace pyxsec */
