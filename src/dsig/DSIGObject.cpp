/*
 * DSIGObject.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGObject.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGObject.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGObjectDefVisitor
: public boost::python::def_visitor<DSIGObjectDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setId", &DSIGObjectDefVisitor::setId)
	.def("setMimeType", &DSIGObjectDefVisitor::setMimeType)
	.def("setEncoding", &DSIGObjectDefVisitor::setEncoding)
	;
}

static void setId(DSIGObject& self, const STR id) {
	pyxerces::XMLString buff(id);
	self.setId(buff.ptr());
}

static void setMimeType(DSIGObject& self, const STR type) {
	pyxerces::XMLString buff(type);
	self.setMimeType(buff.ptr());
}

static void setEncoding(DSIGObject& self, const STR encoding) {
	pyxerces::XMLString buff(encoding);
	self.setEncoding(buff.ptr());
}

};

void DSIGObject_init(void) {
	//! DSIGObject
	boost::python::class_<DSIGObject, boost::noncopyable>("DSIGObject", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGObjectDefVisitor<char*>())
			.def("load", &DSIGObject::load)
			.def("createBlankObject", &DSIGObject::createBlankObject, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getId", &DSIGObject::getId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMimeType", &DSIGObject::getMimeType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getEncoding", &DSIGObject::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElement", &DSIGObject::getElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setId", &DSIGObject::setId)
			.def("setMimeType", &DSIGObject::setMimeType)
			.def("setEncoding", &DSIGObject::setEncoding)
			.def("appendChild", &DSIGObject::appendChild)
			;
}

} /* namespace pyxsec */
