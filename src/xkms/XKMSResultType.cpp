/*
 * XKMSResultType.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XKMSResultType.h"

#include <boost/python.hpp>

#include <xsec/xkms/XKMSResultType.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <class STR>
class XKMSResultTypeStringDefVisitor
: public boost::python::def_visitor<XKMSResultTypeStringDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setRequestId", &XKMSResultTypeStringDefVisitor::setRequestId)
	.def("setRequestSignatureValue", &XKMSResultTypeStringDefVisitor::setRequestSignatureValue)
	;
}

static void setRequestId(XKMSResultType& self, const STR id) {
	pyxerces::XMLString buff(id);
	self.setRequestId(buff.ptr());
}

static void setRequestSignatureValue(XKMSResultType& self, const STR value) {
	pyxerces::XMLString buff(value);
	self.setRequestSignatureValue(buff.ptr());
}

};

void XKMSResultType_init(void) {
	//! XKMSResultType
	auto XKMSResultType_ = boost::python::class_<XKMSResultType, boost::noncopyable, boost::python::bases<XKMSMessageAbstractType> >("XKMSResultType", boost::python::no_init)
			.def(XKMSResultTypeStringDefVisitor<char*>())
			.def("getResultMajor", boost::python::pure_virtual(&XKMSResultType::getResultMajor))
			.def("getResultMinor", boost::python::pure_virtual(&XKMSResultType::getResultMinor))
			.def("getRequestId", boost::python::pure_virtual(&XKMSResultType::getRequestId), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getRequestSignatureValue", boost::python::pure_virtual(&XKMSResultType::getRequestSignatureValue), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setResultMajor", boost::python::pure_virtual(&XKMSResultType::setResultMajor))
			.def("setResultMinor", boost::python::pure_virtual(&XKMSResultType::setResultMinor))
			.def("setRequestId", boost::python::pure_virtual(&XKMSResultType::setRequestId))
			.def("setRequestSignatureValue", boost::python::pure_virtual(&XKMSResultType::setRequestSignatureValue))
			;
	boost::python::scope XKMSResultTypeScope = XKMSResultType_;
	//! XKMSResultType::ResultMajor
	boost::python::enum_<XKMSResultType::ResultMajor>("ResultMajor")
			.value("NoneMajor", XKMSResultType::NoneMajor)
			.value("Success", XKMSResultType::Success)
			.value("VersionMismatch", XKMSResultType::VersionMismatch)
			.value("Sender", XKMSResultType::Sender)
			.value("Receiver", XKMSResultType::Receiver)
			.value("Represent", XKMSResultType::Represent)
			.value("Pending", XKMSResultType::Pending)
			.export_values()
			;
	//! XKMSResultType::ResultMinor
	boost::python::enum_<XKMSResultType::ResultMinor>("ResultMinor")
			.value("NoneMinor", XKMSResultType::NoneMinor)
			.value("NoMatch", XKMSResultType::NoMatch)
			.value("TooManyResponses", XKMSResultType::TooManyResponses)
			.value("Incomplete", XKMSResultType::Incomplete)
			.value("Failure", XKMSResultType::Failure)
			.value("Refused", XKMSResultType::Refused)
			.value("NoAuthentication", XKMSResultType::NoAuthentication)
			.value("MessageNotSupported", XKMSResultType::MessageNotSupported)
			.value("UnknownResponseId", XKMSResultType::UnknownResponseId)
			.value("RepresentRequired", XKMSResultType::RepresentRequired)
			.value("NotSynchronous", XKMSResultType::NotSynchronous)
			.export_values()
			;
}

} /* namespace pyxsec */
