/*
 * DSIGSignedInfo.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGSignedInfo.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>
#include <xsec/dsig/DSIGReference.hpp>

#include <xsec/dsig/DSIGSignedInfo.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGSignedInfoStringDefVisitor
 : public boost::python::def_visitor<DSIGSignedInfoStringDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankSignedInfo", &DSIGSignedInfoStringDefVisitor::createBlankSignedInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignedInfo&, const STR, hashMethod, char*)>(&DSIGSignedInfoStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReference", static_cast<DSIGReference*(*)(DSIGSignedInfo&, const STR, const STR, const STR)>(&DSIGSignedInfoStringDefVisitor::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMElement *createBlankSignedInfo(DSIGSignedInfo& self, const STR canonicalizationAlgorithmURI, const STR signatureAlgorithmURI) {
	pyxerces::XMLString buff1(canonicalizationAlgorithmURI), buff2(signatureAlgorithmURI);
	return self.createBlankSignedInfo(buff1.ptr(), buff2.ptr());
}

static DSIGReference * createReference(DSIGSignedInfo& self, const STR URI, const STR hashAlgorithmURI, const STR type) {
	pyxerces::XMLString buff1(URI), buff2(hashAlgorithmURI), buff3(type);
	return self.createReference(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static DSIGReference * createReference(DSIGSignedInfo& self, const STR URI, hashMethod hm, char* type) {
	pyxerces::XMLString buff(URI);
	return self.createReference(buff.ptr(), hm, type);
}

};

void DSIGSignedInfo_init(void) {
	//! DSIGSignedInfo
	boost::python::class_<DSIGSignedInfo, boost::noncopyable>("DSIGSignedInfo", boost::python::init<xercesc::DOMDocument*, XSECSafeBufferFormatter*, xercesc::DOMNode*, const XSECEnv *>())
			.def(boost::python::init<xercesc::DOMDocument*, XSECSafeBufferFormatter*, const XSECEnv *>())
			.def(DSIGSignedInfoStringDefVisitor<char*>())
			.def("load", &DSIGSignedInfo::load)
			.def("verify", &DSIGSignedInfo::verify)
			.def("hash", &DSIGSignedInfo::hash)
			.def("createBlankSignedInfo", static_cast<xercesc::DOMElement*(DSIGSignedInfo::*)(const XMLCh*, const XMLCh*)>(&DSIGSignedInfo::createBlankSignedInfo), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createBlankSignedInfo", static_cast<xercesc::DOMElement*(DSIGSignedInfo::*)(canonicalizationMethod, signatureMethod, hashMethod)>(&DSIGSignedInfo::createBlankSignedInfo), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createReference", static_cast<DSIGReference*(DSIGSignedInfo::*)(const XMLCh*, hashMethod, char*)>(&DSIGSignedInfo::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createReference", static_cast<DSIGReference*(DSIGSignedInfo::*)(const XMLCh*, const XMLCh*, const XMLCh*)>(&DSIGSignedInfo::createReference), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeReference", &DSIGSignedInfo::removeReference, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDOMNode", &DSIGSignedInfo::getDOMNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAlgorithmURI", &DSIGSignedInfo::getAlgorithmURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getCanonicalizationMethod", &DSIGSignedInfo::getCanonicalizationMethod)
			.def("getHashMethod", &DSIGSignedInfo::getHashMethod)
			.def("getSignatureMethod", &DSIGSignedInfo::getSignatureMethod)
			.def("getHMACOutputLength", &DSIGSignedInfo::getHMACOutputLength)
			.def("getReferenceList", &DSIGSignedInfo::getReferenceList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
