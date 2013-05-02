/*
 * XKMSMessageFactory.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XKMSMessageFactory.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>
#include <xsec/xenc/XENCEncryptedData.hpp>
#include <xsec/dsig/DSIGSignature.hpp>
#include <xsec/xkms/XKMSCompoundRequest.hpp>
#include <xsec/xkms/XKMSCompoundResult.hpp>
#include <xsec/xkms/XKMSLocateRequest.hpp>
#include <xsec/xkms/XKMSLocateResult.hpp>
#include <xsec/xkms/XKMSRequestAbstractType.hpp>
#include <xsec/xkms/XKMSResult.hpp>
#include <xsec/xkms/XKMSValidateRequest.hpp>
#include <xsec/xkms/XKMSValidateResult.hpp>
#include <xsec/xkms/XKMSPendingRequest.hpp>
#include <xsec/xkms/XKMSStatusRequest.hpp>
#include <xsec/xkms/XKMSStatusResult.hpp>
#include <xsec/xkms/XKMSRegisterRequest.hpp>
#include <xsec/xkms/XKMSRegisterResult.hpp>
#include <xsec/xkms/XKMSRevokeResult.hpp>
#include <xsec/xkms/XKMSRevokeRequest.hpp>
#include <xsec/xkms/XKMSRecoverResult.hpp>
#include <xsec/xkms/XKMSRecoverRequest.hpp>
#include <xsec/xkms/XKMSReissueResult.hpp>
#include <xsec/xkms/XKMSReissueRequest.hpp>

#include <xsec/xkms/XKMSMessageFactory.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class XKMSMessageFactoryDefVisitor
: public boost::python::def_visitor<XKMSMessageFactoryDefVisitor<STR> >
{
friend class def_visitor_access;


static XKMSCompoundRequest * createCompoundRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createCompoundRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSLocateRequest * createLocateRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createLocateRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSValidateRequest * createValidateRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createValidateRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSPendingRequest * createPendingRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createPendingRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSStatusRequest * createStatusRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createStatusRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSLocateResult * createLocateResult(XKMSMessageFactory& self, XKMSLocateRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createLocateResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSValidateResult * createValidateResult(XKMSMessageFactory& self, XKMSValidateRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createValidateResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSCompoundResult * createCompoundResult(XKMSMessageFactory& self, XKMSCompoundRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createCompoundResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSResult * createResult(XKMSMessageFactory& self, XKMSRequestAbstractType * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSStatusResult * createStatusResult(XKMSMessageFactory& self, XKMSStatusRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createStatusResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSRegisterRequest * createRegisterRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createRegisterRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSRegisterResult * createRegisterResult(XKMSMessageFactory& self, XKMSRegisterRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createRegisterResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSRevokeRequest * createRevokeRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createRevokeRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSRevokeResult * createRevokeResult(XKMSMessageFactory& self, XKMSRevokeRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createRevokeResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSRecoverRequest * createRecoverRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createRecoverRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSRecoverResult * createRecoverResult(XKMSMessageFactory& self, XKMSRecoverRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createRecoverResult(request, doc, rmaj, rmin, buff.ptr());
}

static XKMSReissueRequest * createReissueRequest(XKMSMessageFactory& self, const STR service, xercesc::DOMDocument * doc, const STR id = NULL) {
	pyxerces::XMLString buff1(service), buff2(id);
	return self.createReissueRequest(buff1.ptr(), doc, buff2.ptr());
}

static XKMSReissueResult * createReissueResult(XKMSMessageFactory& self, XKMSReissueRequest * request, xercesc::DOMDocument * doc, XKMSResultType::ResultMajor rmaj, XKMSResultType::ResultMinor rmin, const STR id) {
	pyxerces::XMLString buff(id);
	return self.createReissueResult(request, doc, rmaj, rmin, buff.ptr());
}

static void setDSIGNSPrefix(XKMSMessageFactory& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setDSIGNSPrefix(buff.ptr());
}

static void setECNSPrefix(XKMSMessageFactory& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setECNSPrefix(buff.ptr());
}

static void setXPFNSPrefix(XKMSMessageFactory& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXPFNSPrefix(buff.ptr());
}

static void setXENCNSPrefix(XKMSMessageFactory& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXENCNSPrefix(buff.ptr());
}

static void setXKMSNSPrefix(XKMSMessageFactory& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXKMSNSPrefix(buff.ptr());
}

BOOST_PYTHON_FUNCTION_OVERLOADS(CreateCompoundRequestOverloads, createCompoundRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateLocateRequestOverloads, createLocateRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateValidateRequestOverloads, createValidateRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreatePendingRequestOverloads, createPendingRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateStatusRequestOverloads, createStatusRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateRegisterRequestOverloads, createRegisterRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateRevokeRequestOverloads, createRevokeRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateRecoverRequestOverloads, createRecoverRequest, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(CreateReissueRequestOverloads, createReissueRequest, 3, 4)

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createCompoundRequest", &XKMSMessageFactoryDefVisitor::createCompoundRequest, CreateCompoundRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createLocateRequest", &XKMSMessageFactoryDefVisitor::createLocateRequest, CreateLocateRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createValidateRequest", &XKMSMessageFactoryDefVisitor::createValidateRequest, CreateValidateRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createPendingRequest", &XKMSMessageFactoryDefVisitor::createPendingRequest, CreatePendingRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createStatusRequest", &XKMSMessageFactoryDefVisitor::createStatusRequest, CreateStatusRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createLocateResult", &XKMSMessageFactoryDefVisitor::createLocateResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createValidateResult", &XKMSMessageFactoryDefVisitor::createValidateResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createCompoundResult", &XKMSMessageFactoryDefVisitor::createCompoundResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createResult", &XKMSMessageFactoryDefVisitor::createResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createStatusResult", &XKMSMessageFactoryDefVisitor::createStatusResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createRegisterRequest", &XKMSMessageFactoryDefVisitor::createRegisterRequest, CreateRegisterRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createRegisterResult", &XKMSMessageFactoryDefVisitor::createRegisterResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createRevokeRequest", &XKMSMessageFactoryDefVisitor::createRevokeRequest, CreateRevokeRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createRevokeResult", &XKMSMessageFactoryDefVisitor::createRevokeResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createRecoverRequest", &XKMSMessageFactoryDefVisitor::createRecoverRequest, CreateRecoverRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createRecoverResult", &XKMSMessageFactoryDefVisitor::createRecoverResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createReissueRequest", &XKMSMessageFactoryDefVisitor::createReissueRequest, CreateReissueRequestOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("createReissueResult", &XKMSMessageFactoryDefVisitor::createReissueResult, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setDSIGNSPrefix", &XKMSMessageFactoryDefVisitor::setDSIGNSPrefix)
	.def("setECNSPrefix", &XKMSMessageFactoryDefVisitor::setECNSPrefix)
	.def("setXPFNSPrefix", &XKMSMessageFactoryDefVisitor::setXPFNSPrefix)
	.def("setXENCNSPrefix", &XKMSMessageFactoryDefVisitor::setXENCNSPrefix)
	.def("setXKMSNSPrefix", &XKMSMessageFactoryDefVisitor::setXKMSNSPrefix)
	;
}

};

void XKMSMessageFactory_init(void) {
	//! XKMSMessageFactory
	boost::python::class_<XKMSMessageFactory, boost::noncopyable>("XKMSMessageFactory", boost::python::no_init)
			.def(XKMSMessageFactoryDefVisitor<char*>())
			//! TODO: XKMSMessageAbstractType
			.def("newMessageFromDOM", boost::python::pure_virtual(&XKMSMessageFactory::newMessageFromDOM), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSCompoundRequest
			.def("createCompoundRequest", boost::python::pure_virtual(static_cast<XKMSCompoundRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createCompoundRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSLocateRequest
			.def("createLocateRequest", boost::python::pure_virtual(static_cast<XKMSLocateRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createLocateRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSValidateRequest
			.def("createValidateRequest", boost::python::pure_virtual(static_cast<XKMSValidateRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createValidateRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSPendingRequest
			.def("createPendingRequest", boost::python::pure_virtual(static_cast<XKMSPendingRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createPendingRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSStatusRequest
			.def("createStatusRequest", boost::python::pure_virtual(static_cast<XKMSStatusRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createStatusRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSLocateResult
			.def("createLocateResult", boost::python::pure_virtual(static_cast<XKMSLocateResult*(XKMSMessageFactory::*)(XKMSLocateRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createLocateResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSValidateResult
			.def("createValidateResult", boost::python::pure_virtual(static_cast<XKMSValidateResult*(XKMSMessageFactory::*)(XKMSValidateRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createValidateResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSCompoundResult
			.def("createCompoundResult", boost::python::pure_virtual(static_cast<XKMSCompoundResult*(XKMSMessageFactory::*)(XKMSCompoundRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createCompoundResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSResult
			.def("createResult", boost::python::pure_virtual(static_cast<XKMSResult*(XKMSMessageFactory::*)(XKMSRequestAbstractType*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSStatusResult
			.def("createStatusResult", boost::python::pure_virtual(static_cast<XKMSStatusResult*(XKMSMessageFactory::*)(XKMSStatusRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createStatusResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSRegisterRequest
			.def("createRegisterRequest", boost::python::pure_virtual(static_cast<XKMSRegisterRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createRegisterRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSRegisterResult
			.def("createRegisterResult", boost::python::pure_virtual(static_cast<XKMSRegisterResult*(XKMSMessageFactory::*)(XKMSRegisterRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createRegisterResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSRevokeRequest
			.def("createRevokeRequest", boost::python::pure_virtual(static_cast<XKMSRevokeRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createRevokeRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSRevokeResult
			.def("createRevokeResult", boost::python::pure_virtual(static_cast<XKMSRevokeResult*(XKMSMessageFactory::*)(XKMSRevokeRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createRevokeResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSRecoverRequest
			.def("createRecoverRequest", boost::python::pure_virtual(static_cast<XKMSRecoverRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createRecoverRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSRecoverResult
			.def("createRecoverResult", boost::python::pure_virtual(static_cast<XKMSRecoverResult*(XKMSMessageFactory::*)(XKMSRecoverRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createRecoverResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSReissueRequest
			.def("createReissueRequest", boost::python::pure_virtual(static_cast<XKMSReissueRequest*(XKMSMessageFactory::*)(const XMLCh*, xercesc::DOMDocument*, const XMLCh*)>(&XKMSMessageFactory::createReissueRequest)), (boost::python::arg("service"), boost::python::arg("doc"), boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSReissueResult
			.def("createReissueResult", boost::python::pure_virtual(static_cast<XKMSReissueResult*(XKMSMessageFactory::*)(XKMSReissueRequest*, xercesc::DOMDocument*, XKMSResultType::ResultMajor, XKMSResultType::ResultMinor, const XMLCh*)>(&XKMSMessageFactory::createReissueResult)), (boost::python::arg("request"), boost::python::arg("doc"), boost::python::arg("rmaj"), boost::python::arg("rmin") = XKMSResultType::NoneMinor, boost::python::arg("id") = NULL), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setDSIGNSPrefix", boost::python::pure_virtual(&XKMSMessageFactory::setDSIGNSPrefix))
			.def("setECNSPrefix", boost::python::pure_virtual(&XKMSMessageFactory::setECNSPrefix))
			.def("setXPFNSPrefix", boost::python::pure_virtual(&XKMSMessageFactory::setXPFNSPrefix))
			.def("setXENCNSPrefix", boost::python::pure_virtual(&XKMSMessageFactory::setXENCNSPrefix))
			.def("setXKMSNSPrefix", boost::python::pure_virtual(&XKMSMessageFactory::setXKMSNSPrefix))
			//! TODO: XKMSRequestAbstractType
			.def("toRequestAbstractType", boost::python::pure_virtual(&XKMSMessageFactory::toRequestAbstractType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XKMSResultType
			.def("toResultType", boost::python::pure_virtual(&XKMSMessageFactory::toResultType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
