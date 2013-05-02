/*
 * DSIGKeyInfoSPKIData.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoSPKIData.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoSPKIData.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoSPKIDataDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoSPKIDataDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankSPKIData", &DSIGKeyInfoSPKIDataDefVisitor::createBlankSPKIData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendSexp", &DSIGKeyInfoSPKIDataDefVisitor::appendSexp)
	;
}

static xercesc::DOMElement* createBlankSPKIData(DSIGKeyInfoSPKIData& self, const STR Sexp) {
	pyxerces::XMLString buff(Sexp);
	return self.createBlankSPKIData(buff.ptr());
}

static void appendSexp(DSIGKeyInfoSPKIData& self, const STR Sexp) {
	pyxerces::XMLString buff(Sexp);
	self.appendSexp(buff.ptr());
}

};

void DSIGKeyInfoSPKIData_init(void) {
	//! DSIGKeyInfoSPKIData
	boost::python::class_<DSIGKeyInfoSPKIData, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoSPKIData", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGKeyInfoSPKIDataDefVisitor<char*>())
			.def("load", &DSIGKeyInfoSPKIData::load)
			.def("getSexpSize", &DSIGKeyInfoSPKIData::getSexpSize)
			.def("getSexp", &DSIGKeyInfoSPKIData::getSexp, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getKeyName", &DSIGKeyInfoSPKIData::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("createBlankSPKIData", &DSIGKeyInfoSPKIData::createBlankSPKIData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendSexp", &DSIGKeyInfoSPKIData::appendSexp)
			.def("getKeyInfoType", &DSIGKeyInfoSPKIData::getKeyInfoType)
			;
}

} /* namespace pyxsec */
