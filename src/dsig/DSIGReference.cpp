/*
 * DSIGReference.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGReference.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/dsig/DSIGTransformList.hpp>
#include <xsec/dsig/DSIGTransformBase64.hpp>
#include <xsec/dsig/DSIGTransformC14n.hpp>
#include <xsec/dsig/DSIGTransformEnvelope.hpp>
#include <xsec/dsig/DSIGTransformXPath.hpp>
#include <xsec/dsig/DSIGTransformXPathFilter.hpp>
#include <xsec/dsig/DSIGTransformXSL.hpp>
#include <xsec/dsig/DSIGSignature.hpp>
#include <xsec/dsig/DSIGSignedInfo.hpp>
#include <xsec/transformers/TXFMBase.hpp>
#include <xsec/transformers/TXFMChain.hpp>
#include <xsec/utils/XSECBinTXFMInputStream.hpp>
#include <xsec/framework/XSECURIResolver.hpp>
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGReference.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGReferenceDefVisitor
: public boost::python::def_visitor<DSIGReferenceDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankReference", static_cast<xercesc::DOMElement*(*)(DSIGReference&, const STR, hashMethod, char*)>(&DSIGReferenceDefVisitor::createBlankReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createBlankReference", static_cast<xercesc::DOMElement*(*)(DSIGReference&, const STR, const STR, const STR)>(&DSIGReferenceDefVisitor::createBlankReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createBlankReference", &DSIGReferenceDefVisitor::appendCanonicalizationTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setId", &DSIGReferenceDefVisitor::setId)
	.def("setType", &DSIGReferenceDefVisitor::setType)
	.def("getURIBaseTXFM", &DSIGReferenceDefVisitor::getURIBaseTXFM, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMElement* createBlankReference(DSIGReference& self, const STR URI, hashMethod hm, char * type) {
	pyxerces::XMLString buff(URI);
	return self.createBlankReference(buff.ptr(), hm, type);
}

static xercesc::DOMElement* createBlankReference(DSIGReference& self, const STR URI, const STR hashAlgorithmURI, const STR type) {
	pyxerces::XMLString buff1(URI), buff2(hashAlgorithmURI), buff3(type);
	return self.createBlankReference(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static DSIGTransformC14n * appendCanonicalizationTransform(DSIGReference& self, const STR canonicalizationAlgorithmURI) {
	pyxerces::XMLString buff(canonicalizationAlgorithmURI);
	return self.appendCanonicalizationTransform(buff.ptr());
}

static void setId(DSIGReference& self, const STR id) {
	pyxerces::XMLString buff(id);
	self.setId(buff.ptr());
}

static void setType(DSIGReference& self, const STR type) {
	pyxerces::XMLString buff(type);
	self.setType(buff.ptr());
}

static TXFMBase * getURIBaseTXFM(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument * doc, const STR URI, const XSECEnv * env) {
	pyxerces::XMLString buff(URI);
	return DSIGReference::getURIBaseTXFM(doc, buff.ptr(), env);
}

};

//! DSIGReference
BOOST_PYTHON_FUNCTION_OVERLOADS(DSIGReferenceHashReferenceListOverloads, DSIGReference::hashReferenceList, 1, 2)

void DSIGReference_init(void) {
	//! DSIGReference
	boost::python::class_<DSIGReference, boost::noncopyable>("DSIGReference", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGReferenceDefVisitor<char*>())
			.def("load", &DSIGReference::load)
			.def("createBlankReference", static_cast<xercesc::DOMElement*(DSIGReference::*)(const XMLCh*, hashMethod, char*)>(&DSIGReference::createBlankReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createBlankReference", static_cast<xercesc::DOMElement*(DSIGReference::*)(const XMLCh*, const XMLCh*, const XMLCh*)>(&DSIGReference::createBlankReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendEnvelopedSignatureTransform", &DSIGReference::appendEnvelopedSignatureTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendBase64Transform", &DSIGReference::appendBase64Transform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendXPathTransform", &DSIGReference::appendXPathTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendXPathFilterTransform", &DSIGReference::appendXPathFilterTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendXSLTransform", &DSIGReference::appendXSLTransform, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendCanonicalizationTransform", static_cast<DSIGTransformC14n*(DSIGReference::*)(const XMLCh*)>(&DSIGReference::appendCanonicalizationTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendCanonicalizationTransform", static_cast<DSIGTransformC14n*(DSIGReference::*)(canonicalizationMethod)>(&DSIGReference::appendCanonicalizationTransform), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: TXFMBase
			.def("setPreHashTXFM", &DSIGReference::setPreHashTXFM)
			.def("setId", &DSIGReference::setId)
			.def("setType", &DSIGReference::setType)
			//! TODO: XSECBinTXFMInputStream
			.def("makeBinInputStream", &DSIGReference::makeBinInputStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURI", &DSIGReference::getURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getHashMethod", &DSIGReference::getHashMethod)
			.def("getAlgorithmURI", &DSIGReference::getAlgorithmURI, boost::python::return_value_policy<boost::python::return_by_value>())
			//! TODO: DSIGTransformList
			.def("getTransforms", &DSIGReference::getTransforms, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isManifest", &DSIGReference::isManifest)
			.def("getManifestReferenceList", &DSIGReference::getManifestReferenceList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("calculateHash", &DSIGReference::calculateHash)
			.def("readHash", &DSIGReference::readHash)
			.def("checkHash", &DSIGReference::checkHash)
			.def("setHash", &DSIGReference::setHash)
			//! TODO: TXFMChain
			.def("createTXFMChainFromList", &DSIGReference::createTXFMChainFromList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XSECSafeBufferFormatter
			.def("loadTransforms", &DSIGReference::loadTransforms, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIBaseTXFM", &DSIGReference::getURIBaseTXFM, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadReferenceListFromXML", &DSIGReference::loadReferenceListFromXML, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("verifyReferenceList", &DSIGReference::verifyReferenceList)
			.def("hashReferenceList", &DSIGReference::hashReferenceList, DSIGReferenceHashReferenceListOverloads())
			.staticmethod("createTXFMChainFromList")
			.staticmethod("loadTransforms")
			.staticmethod("getURIBaseTXFM")
			.staticmethod("loadReferenceListFromXML")
			.staticmethod("verifyReferenceList")
			.staticmethod("hashReferenceList")
			;
}

} /* namespace pyxsec */
