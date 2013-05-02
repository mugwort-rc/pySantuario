/*
 * DSIGKeyInfoMgmtData.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoMgmtData.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoMgmtData.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoMgmtDataDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoMgmtDataDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankMgmtData", &DSIGKeyInfoMgmtDataDefVisitor::createBlankMgmtData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setData", &DSIGKeyInfoMgmtDataDefVisitor::setData)
	;
}

static xercesc::DOMElement * createBlankMgmtData(DSIGKeyInfoMgmtData& self, const STR data) {
	pyxerces::XMLString buff(data);
	return self.createBlankMgmtData(buff.ptr());
}

static void setData(DSIGKeyInfoMgmtData& self, const STR data) {
	pyxerces::XMLString buff(data);
	self.setData(buff.ptr());
}

};

void DSIGKeyInfoMgmtData_init(void) {
	//! DSIGKeyInfoMgmtData
	boost::python::class_<DSIGKeyInfoMgmtData, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoMgmtData", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGKeyInfoMgmtDataDefVisitor<char*>())
			.def("load", &DSIGKeyInfoMgmtData::load)
			.def("getKeyName", &DSIGKeyInfoMgmtData::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getData", &DSIGKeyInfoMgmtData::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("createBlankMgmtData", &DSIGKeyInfoMgmtData::createBlankMgmtData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setData", &DSIGKeyInfoMgmtData::setData)
			.def("getKeyInfoType", &DSIGKeyInfoMgmtData::getKeyInfoType)
			;
}

} /* namespace pyxsec */
