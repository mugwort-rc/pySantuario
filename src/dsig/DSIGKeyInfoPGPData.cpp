/*
 * DSIGKeyInfoPGPData.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoPGPData.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoPGPData.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoPGPDataDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoPGPDataDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankPGPData", &DSIGKeyInfoPGPDataDefVisitor::createBlankPGPData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setKeyID", &DSIGKeyInfoPGPDataDefVisitor::setKeyID)
	.def("setKeyPacket", &DSIGKeyInfoPGPDataDefVisitor::setKeyPacket)
	;
}

static xercesc::DOMElement* createBlankPGPData(DSIGKeyInfoPGPData& self, const STR id, const STR packet) {
	pyxerces::XMLString buff1(id), buff2(packet);
	return self.createBlankPGPData(buff1.ptr(), buff2.ptr());
}

static void setKeyID(DSIGKeyInfoPGPData& self, const STR id) {
	pyxerces::XMLString buff(id);
	self.setKeyID(buff.ptr());
}

static void setKeyPacket(DSIGKeyInfoPGPData& self, const STR packet) {
	pyxerces::XMLString buff(packet);
	self.setKeyPacket(buff.ptr());
}

};

void DSIGKeyInfoPGPData_init(void) {
	//! DSIGKeyInfoPGPData
	boost::python::class_<DSIGKeyInfoPGPData, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoPGPData", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGKeyInfoPGPDataDefVisitor<char*>())
			.def("load", &DSIGKeyInfoPGPData::load)
			.def("getKeyID", &DSIGKeyInfoPGPData::getKeyID, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getKeyPacket", &DSIGKeyInfoPGPData::getKeyPacket, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getKeyName", &DSIGKeyInfoPGPData::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("createBlankPGPData", &DSIGKeyInfoPGPData::createBlankPGPData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setKeyID", &DSIGKeyInfoPGPData::setKeyID)
			.def("setKeyPacket", &DSIGKeyInfoPGPData::setKeyPacket)
			.def("getKeyInfoType", &DSIGKeyInfoPGPData::getKeyInfoType)
			;
}

} /* namespace pyxsec */
