/*
 * DSIGKeyInfoName.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoName.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoName.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoNameStringDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoNameStringDefVisitor<STR> >
{
friend class def_visitor_access;

public:

static xercesc::DOMElement * createBlankKeyName(DSIGKeyInfoName& self, const STR name, bool isDName = false) {
	pyxerces::XMLString buff(name);
	return self.createBlankKeyName(buff.ptr(), isDName);
}

static void setKeyName(DSIGKeyInfoName& self, const STR name, bool isDName = false) {
	pyxerces::XMLString buff(name);
	return self.setKeyName(buff.ptr(), isDName);
}

BOOST_PYTHON_FUNCTION_OVERLOADS(DSIGKeyInfoNameStringDefVisitorCreateBlankKeyNameOverloads, createBlankKeyName, 2, 3)
BOOST_PYTHON_FUNCTION_OVERLOADS(DSIGKeyInfoNameStringDefVisitorSetKeyNameOverloads, setKeyName, 2, 3)

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankKeyName", &DSIGKeyInfoNameStringDefVisitor::createBlankKeyName, DSIGKeyInfoNameStringDefVisitorCreateBlankKeyNameOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("setKeyName", &DSIGKeyInfoNameStringDefVisitor::setKeyName, DSIGKeyInfoNameStringDefVisitorSetKeyNameOverloads())
	;
}

};

//! DSIGKeyInfoName
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DSIGKeyInfoNameCreateBlankKeyName, createBlankKeyName, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DSIGKeyInfoNameSetKeyName, setKeyName, 1, 2)

void DSIGKeyInfoName_init(void) {
	//! DSIGKeyInfoName
	boost::python::class_<DSIGKeyInfoName, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoName", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def("load", &DSIGKeyInfoName::load)
			.def("getKeyName", &DSIGKeyInfoName::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getDecodedKeyName", &DSIGKeyInfoName::getDecodedKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("createBlankKeyName", &DSIGKeyInfoName::createBlankKeyName, DSIGKeyInfoNameCreateBlankKeyName()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("setKeyName", &DSIGKeyInfoName::setKeyName, DSIGKeyInfoNameSetKeyName())
			.def("getKeyInfoType", &DSIGKeyInfoName::getKeyInfoType)
			;
}

} /* namespace pyxsec */
