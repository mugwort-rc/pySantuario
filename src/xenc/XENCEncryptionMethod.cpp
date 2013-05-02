/*
 * XENCEncryptionMethod.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "XENCEncryptionMethod.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMElement.hpp>

#include <xsec/xenc/XENCEncryptionMethod.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

class XENCEncryptionMethodWrapper
: public XENCEncryptionMethod, public boost::python::wrapper<XENCEncryptionMethod>
{
public:
XENCEncryptionMethodWrapper()
: XENCEncryptionMethod()
{}

const XMLCh * getAlgorithm(void) const {
	return this->get_override("getAlgorithm")();
}

const XMLCh * getDigestMethod(void) const {
	return this->get_override("getDigestMethod")();
}

const XMLCh * getOAEPparams(void) const {
	return this->get_override("getOAEPparams")();
}

const XMLCh * getMGF(void) const {
	return this->get_override("getMGF")();
}

int getKeySize(void) const {
	return this->get_override("getKeySize")();
}

xercesc::DOMElement * getElement(void) const {
	return this->get_override("getElement")();
}

void setDigestMethod(const XMLCh * method) {
	this->get_override("setDigestMethod")(method);
}

void setOAEPparams(const XMLCh * params) {
	this->get_override("setOAEPparams")(params);
}

void setMGF(const XMLCh * mgf) {
	this->get_override("setMGF")(mgf);
}

void setKeySize(int size) {
	this->get_override("setKeySize")(size);
}

};

template <typename STR>
class XENCEncryptionMethodDefVisitor
: public boost::python::def_visitor<XENCEncryptionMethodDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setDigestMethod", &XENCEncryptionMethodDefVisitor::setDigestMethod)
	.def("setOAEPparams", &XENCEncryptionMethodDefVisitor::setOAEPparams)
	.def("setMGF", &XENCEncryptionMethodDefVisitor::setMGF)
	;
}

static void setDigestMethod(XENCEncryptionMethod& self, const STR method) {
	pyxerces::XMLString buff(method);
	self.setDigestMethod(buff.ptr());
}

void setOAEPparams(XENCEncryptionMethod& self, const STR params) {
	pyxerces::XMLString buff(params);
	self.setOAEPparams(buff.ptr());
}

void setMGF(XENCEncryptionMethod& self, const STR mgf) {
	pyxerces::XMLString buff(mgf);
	self.setOAEPparams(buff.ptr());
}

};

void XENCEncryptionMethod_init(void) {
	//! XENCEncryptionMethod
	boost::python::class_<XENCEncryptionMethodWrapper, boost::noncopyable>("XENCEncryptionMethod")
			.def(XENCEncryptionMethodDefVisitor<char*>())
			.def("getAlgorithm", boost::python::pure_virtual(&XENCEncryptionMethod::getAlgorithm), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getDigestMethod", boost::python::pure_virtual(&XENCEncryptionMethod::getDigestMethod), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getOAEPparams", boost::python::pure_virtual(&XENCEncryptionMethod::getOAEPparams), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMGF", boost::python::pure_virtual(&XENCEncryptionMethod::getMGF), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getKeySize", boost::python::pure_virtual(&XENCEncryptionMethod::getKeySize))
			.def("getElement", boost::python::pure_virtual(&XENCEncryptionMethod::getElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setDigestMethod", boost::python::pure_virtual(&XENCEncryptionMethod::setDigestMethod))
			.def("setOAEPparams", boost::python::pure_virtual(&XENCEncryptionMethod::setOAEPparams))
			.def("setMGF", boost::python::pure_virtual(&XENCEncryptionMethod::setMGF))
			.def("setKeySize", boost::python::pure_virtual(&XENCEncryptionMethod::setKeySize))
			;
}

} /* namespace pyxsec */
