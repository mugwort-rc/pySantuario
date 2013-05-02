/*
 * DSIGKeyInfoDEREncoded.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoDEREncoded.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoDEREncoded.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoDEREncodedDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoDEREncodedDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankDEREncoded", &DSIGKeyInfoDEREncodedDefVisitor::createBlankDEREncoded, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setData", &DSIGKeyInfoDEREncodedDefVisitor::setData)
	;
}

static xercesc::DOMElement * createBlankDEREncoded(DSIGKeyInfoDEREncoded& self, const STR data) {
	pyxerces::XMLString buff(data);
	return self.createBlankDEREncoded(buff.ptr());
}

static void setData(DSIGKeyInfoDEREncoded& self, const STR data) {
	pyxerces::XMLString buff(data);
	self.setData(buff.ptr());
}

};

void DSIGKeyInfoDEREncoded_init(void) {
	//! DSIGKeyInfoDEREncoded
	boost::python::class_<DSIGKeyInfoDEREncoded, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoMgmtData", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGKeyInfoDEREncodedDefVisitor<char*>())
			.def("load", &DSIGKeyInfoDEREncoded::load)
			.def("getKeyName", &DSIGKeyInfoDEREncoded::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getData", &DSIGKeyInfoDEREncoded::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("createBlankMgmtData", &DSIGKeyInfoDEREncoded::createBlankDEREncoded, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setData", &DSIGKeyInfoDEREncoded::setData)
			.def("getKeyInfoType", &DSIGKeyInfoDEREncoded::getKeyInfoType)
			;
}

} /* namespace pyxsec */
