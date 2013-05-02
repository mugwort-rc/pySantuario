/*
 * XKMSMessageAbstractType.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XKMSMessageAbstractType.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>
#include <xsec/dsig/DSIGSignature.hpp>

#include <xsec/xkms/XKMSMessageAbstractType.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class XKMSMessageAbstractTypeDefVisitor
: public boost::python::def_visitor<XKMSMessageAbstractTypeDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setId", &XKMSMessageAbstractTypeDefVisitor::setId)
	.def("setService", &XKMSMessageAbstractTypeDefVisitor::setService)
	.def("setNonce", &XKMSMessageAbstractTypeDefVisitor::setNonce)
	.def("appendOpaqueClientDataItem", &XKMSMessageAbstractTypeDefVisitor::appendOpaqueClientDataItem)
	;
}

static void setId(XKMSMessageAbstractType& self, const STR id) {
	pyxerces::XMLString buff(id);
	self.setId(buff.ptr());
}

static void setService(XKMSMessageAbstractType& self, const STR service) {
	pyxerces::XMLString buff(service);
	self.setService(buff.ptr());
}

static void setNonce(XKMSMessageAbstractType& self, const STR uri) {
	pyxerces::XMLString buff(uri);
	self.setNonce(buff.ptr());
}

static void appendOpaqueClientDataItem(XKMSMessageAbstractType& self, const STR item) {
	pyxerces::XMLString buff(item);
	self.appendOpaqueClientDataItem(buff.ptr());
}

};

void XKMSMessageAbstractType_init(void) {
	//! XKMSMessageAbstractType
	auto XKMSMessageAbstractType_ = boost::python::class_<XKMSMessageAbstractType, boost::noncopyable>("XKMSMessageAbstractType", boost::python::no_init)
			.def(XKMSMessageAbstractTypeDefVisitor<char*>())
			.def("getMessageType", boost::python::pure_virtual(&XKMSMessageAbstractType::getMessageType))
			.def("isSigned", boost::python::pure_virtual(&XKMSMessageAbstractType::isSigned))
			.def("getSignature", boost::python::pure_virtual(&XKMSMessageAbstractType::getSignature), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElement", boost::python::pure_virtual(&XKMSMessageAbstractType::getElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getId", boost::python::pure_virtual(&XKMSMessageAbstractType::getId), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getService", boost::python::pure_virtual(&XKMSMessageAbstractType::getService), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNonce", boost::python::pure_virtual(&XKMSMessageAbstractType::getNonce), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setId", boost::python::pure_virtual(&XKMSMessageAbstractType::setId))
			.def("setService", boost::python::pure_virtual(&XKMSMessageAbstractType::setService))
			.def("setNonce", boost::python::pure_virtual(&XKMSMessageAbstractType::setNonce))
			.def("addSignature", boost::python::pure_virtual(&XKMSMessageAbstractType::addSignature), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getOpaqueClientDataSize", boost::python::pure_virtual(&XKMSMessageAbstractType::getOpaqueClientDataSize))
			.def("getOpaqueClientDataItemStr", boost::python::pure_virtual(&XKMSMessageAbstractType::getOpaqueClientDataItemStr), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("appendOpaqueClientDataItem", boost::python::pure_virtual(&XKMSMessageAbstractType::appendOpaqueClientDataItem))
			;
	boost::python::scope XKMSMessageAbstractTypeScope = XKMSMessageAbstractType_;
	//! XKMSMessageAbstractType::messageType
	boost::python::enum_<XKMSMessageAbstractType::messageType>("messageType")
			.value("None", XKMSMessageAbstractType::None)
			.value("CompoundRequest", XKMSMessageAbstractType::CompoundRequest)
			.value("CompoundResult", XKMSMessageAbstractType::CompoundResult)
			.value("LocateRequest", XKMSMessageAbstractType::LocateRequest)
			.value("LocateResult", XKMSMessageAbstractType::LocateResult)
			.value("ValidateRequest", XKMSMessageAbstractType::ValidateRequest)
			.value("ValidateResult", XKMSMessageAbstractType::ValidateResult)
			.value("PendingRequest", XKMSMessageAbstractType::PendingRequest)
			.value("StatusRequest", XKMSMessageAbstractType::StatusRequest)
			.value("StatusResult", XKMSMessageAbstractType::StatusResult)
			.value("Result", XKMSMessageAbstractType::Result)
			.value("RegisterRequest", XKMSMessageAbstractType::RegisterRequest)
			.value("RegisterResult", XKMSMessageAbstractType::RegisterResult)
			.value("RevokeRequest", XKMSMessageAbstractType::RevokeRequest)
			.value("RevokeResult", XKMSMessageAbstractType::RevokeResult)
			.value("RecoverRequest", XKMSMessageAbstractType::RecoverRequest)
			.value("RecoverResult", XKMSMessageAbstractType::RecoverResult)
			.value("ReissueRequest", XKMSMessageAbstractType::ReissueRequest)
			.value("ReissueResult", XKMSMessageAbstractType::ReissueResult)
			.export_values()
			;
}

} /* namespace pyxsec */
