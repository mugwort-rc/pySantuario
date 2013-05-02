/*
 * XSECEnv.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "XSECEnv.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECURIResolver.hpp>

#include <xsec/framework/XSECEnv.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class XSECEnvDefVisitor
: public boost::python::def_visitor<XSECEnvDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setDSIGNSPrefix", &XSECEnvDefVisitor::setDSIGNSPrefix)
	.def("setDSIG11NSPrefix", &XSECEnvDefVisitor::setDSIG11NSPrefix)
	.def("setECNSPrefix", &XSECEnvDefVisitor::setECNSPrefix)
	.def("setXPFNSPrefix", &XSECEnvDefVisitor::setXPFNSPrefix)
	.def("setXENCNSPrefix", &XSECEnvDefVisitor::setXENCNSPrefix)
	.def("setXENC11NSPrefix", &XSECEnvDefVisitor::setXENC11NSPrefix)
	.def("setXKMSNSPrefix", &XSECEnvDefVisitor::setXKMSNSPrefix)
	.def("registerIdAttributeName", &XSECEnvDefVisitor::registerIdAttributeName)
	.def("deregisterIdAttributeName", &XSECEnvDefVisitor::deregisterIdAttributeName)
	.def("isRegisteredIdAttributeName", &XSECEnvDefVisitor::isRegisteredIdAttributeName)
	.def("registerIdAttributeNameNS", &XSECEnvDefVisitor::registerIdAttributeNameNS)
	.def("deregisterIdAttributeNameNS", &XSECEnvDefVisitor::deregisterIdAttributeNameNS)
	.def("isRegisteredIdAttributeNameNS", &XSECEnvDefVisitor::isRegisteredIdAttributeNameNS)
	;
}

static void setDSIGNSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setDSIGNSPrefix(buff.ptr());
}

static void setDSIG11NSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setDSIG11NSPrefix(buff.ptr());
}

static void setECNSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setECNSPrefix(buff.ptr());
}

static void setXPFNSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXPFNSPrefix(buff.ptr());
}

static void setXENCNSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXENCNSPrefix(buff.ptr());
}

static void setXENC11NSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXENC11NSPrefix(buff.ptr());
}

static void setXKMSNSPrefix(XSECEnv& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.setXKMSNSPrefix(buff.ptr());
}

static void registerIdAttributeName(XSECEnv& self, const STR name){
	pyxerces::XMLString buff(name);
	self.registerIdAttributeName(buff.ptr());
}

static bool deregisterIdAttributeName(XSECEnv& self, const STR name) {
	pyxerces::XMLString buff(name);
	return self.deregisterIdAttributeName(buff.ptr());
}

static bool isRegisteredIdAttributeName(XSECEnv& self, const STR name) {
	pyxerces::XMLString buff(name);
	return self.isRegisteredIdAttributeName(buff.ptr());
}

static void registerIdAttributeNameNS(XSECEnv& self, const STR ns, const STR name) {
	pyxerces::XMLString buff1(ns), buff2(name);
	self.registerIdAttributeNameNS(buff1.ptr(), buff2.ptr());
}

static bool deregisterIdAttributeNameNS(XSECEnv& self, const STR ns, const STR name) {
	pyxerces::XMLString buff1(ns), buff2(name);
	return self.deregisterIdAttributeNameNS(buff1.ptr(), buff2.ptr());
}

static bool isRegisteredIdAttributeNameNS(XSECEnv& self, const STR ns, const STR name) {
	pyxerces::XMLString buff1(ns), buff2(name);
	return self.isRegisteredIdAttributeNameNS(buff1.ptr(), buff2.ptr());
}

};

void XSECEnv_init(void) {
	//! XSECEnv
	boost::python::class_<XSECEnv>("XSECEnv", boost::python::init<xercesc::DOMDocument*>())
			.def(XSECEnvDefVisitor<char*>())
			.def("setDSIGNSPrefix", &XSECEnv::setDSIGNSPrefix)
			.def("setDSIG11NSPrefix", &XSECEnv::setDSIG11NSPrefix)
			.def("setECNSPrefix", &XSECEnv::setECNSPrefix)
			.def("setXPFNSPrefix", &XSECEnv::setXPFNSPrefix)
			.def("setXENCNSPrefix", &XSECEnv::setXENCNSPrefix)
			.def("setXENC11NSPrefix", &XSECEnv::setXENC11NSPrefix)
			.def("setXKMSNSPrefix", &XSECEnv::setXKMSNSPrefix)
			.def("getDSIGNSPrefix", &XSECEnv::getDSIGNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getDSIG11NSPrefix", &XSECEnv::getDSIG11NSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getECNSPrefix", &XSECEnv::getECNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXPFNSPrefix", &XSECEnv::getXPFNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXENCNSPrefix", &XSECEnv::getXENCNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXENC11NSPrefix", &XSECEnv::getXENC11NSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getXKMSNSPrefix", &XSECEnv::getXKMSNSPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setPrettyPrintFlag", &XSECEnv::setPrettyPrintFlag)
			.def("getPrettyPrintFlag", &XSECEnv::getPrettyPrintFlag)
			.def("doPrettyPrint", &XSECEnv::doPrettyPrint)
			.def("getParentDocument", &XSECEnv::getParentDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setParentDocument", &XSECEnv::setParentDocument)
			.def("setURIResolver", &XSECEnv::setURIResolver)
			.def("getURIResolver", &XSECEnv::getURIResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setIdByAttributeName", &XSECEnv::setIdByAttributeName)
			.def("getIdByAttributeName", &XSECEnv::getIdByAttributeName)
			.def("registerIdAttributeName", &XSECEnv::registerIdAttributeName)
			.def("deregisterIdAttributeName", &XSECEnv::deregisterIdAttributeName)
			.def("isRegisteredIdAttributeName", &XSECEnv::isRegisteredIdAttributeName)
			.def("registerIdAttributeNameNS", &XSECEnv::registerIdAttributeNameNS)
			.def("deregisterIdAttributeNameNS", &XSECEnv::deregisterIdAttributeNameNS)
			.def("isRegisteredIdAttributeNameNS", &XSECEnv::isRegisteredIdAttributeNameNS)
			.def("getIdAttributeNameListSize", &XSECEnv::getIdAttributeNameListSize)
			.def("getIdAttributeNameListItem", &XSECEnv::getIdAttributeNameListItem, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getIdAttributeNameListItemNS", &XSECEnv::getIdAttributeNameListItemNS, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getIdAttributeNameListItemIsNS", &XSECEnv::getIdAttributeNameListItemIsNS)
			.def("getSBFormatter", &XSECEnv::getSBFormatter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
