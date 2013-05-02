/*
 * DSIGXPathFilterExpr.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGXPathFilterExpr.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGXPathFilterExpr.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <class STR>
class DSIGXPathFilterExprDefVisitor
: public boost::python::def_visitor<DSIGXPathFilterExprDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setFilter", &DSIGXPathFilterExprDefVisitor::setFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setNamespace", &DSIGXPathFilterExprDefVisitor::setNamespace)
	.def("deleteNamespace", &DSIGXPathFilterExprDefVisitor::deleteNamespace)
	;
}

static xercesc::DOMElement * setFilter(DSIGXPathFilterExpr& self, xpathFilterType filterType, const STR filterExpr) {
	pyxerces::XMLString buff(filterExpr);
	return self.setFilter(filterType, buff.ptr());
}

static void setNamespace(DSIGXPathFilterExpr& self, const STR prefix, const STR value) {
	pyxerces::XMLString buff1(prefix), buff2(value);
	self.setNamespace(buff1.ptr(), buff2.ptr());
}

static void deleteNamespace(DSIGXPathFilterExpr& self, const STR prefix) {
	pyxerces::XMLString buff(prefix);
	self.deleteNamespace(buff.ptr());
}

};

void DSIGXPathFilterExpr_init(void) {
	//! DSIGXPathFilterExpr
	boost::python::class_<DSIGXPathFilterExpr, boost::noncopyable>("DSIGXPathFilterExpr", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGXPathFilterExprDefVisitor<char*>())
			.def("load", &DSIGXPathFilterExpr::load)
			.def("getFilterType", &DSIGXPathFilterExpr::getFilterType)
			.def("setFilter", &DSIGXPathFilterExpr::setFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFilter", &DSIGXPathFilterExpr::getFilter, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setNamespace", &DSIGXPathFilterExpr::setNamespace)
			.def("getNamespaces", &DSIGXPathFilterExpr::getNamespaces, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("deleteNamespace", &DSIGXPathFilterExpr::deleteNamespace)
			;
}

} /* namespace pyxsec */
