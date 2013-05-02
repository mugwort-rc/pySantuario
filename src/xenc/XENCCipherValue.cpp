/*
 * XENCCipherValue.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XENCCipherValue.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>

#include <xsec/xenc/XENCCipherValue.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class XENCCipherValueDefVisitor
: public boost::python::def_visitor<XENCCipherValueDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setCipherString", &XENCCipherValueDefVisitor::setCipherString)
	;
}

static void setCipherString(XENCCipherValue& self, const STR value) {
	pyxerces::XMLString buff(value);
	self.setCipherString(buff.ptr());
}

};

void XENCCipherValue_init(void) {
	//! XENCCipherValue
	boost::python::class_<XENCCipherValue, boost::noncopyable>("XENCCipherValue", boost::python::no_init)
			.def(XENCCipherValueDefVisitor<char*>())
			.def("getCipherString", boost::python::pure_virtual(&XENCCipherValue::getCipherString), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getElement", boost::python::pure_virtual(&XENCCipherValue::getElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setCipherString", boost::python::pure_virtual(&XENCCipherValue::setCipherString))
			;
}

} /* namespace pyxsec */
