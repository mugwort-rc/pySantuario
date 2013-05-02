/*
 * DSIGKeyInfoValue.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoValue.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoValue.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoValueDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoValueDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createBlankDSAKeyValue", &DSIGKeyInfoValueDefVisitor::createBlankDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setDSAP", &DSIGKeyInfoValue::setDSAP)
	.def("setDSAQ", &DSIGKeyInfoValue::setDSAQ)
	.def("setDSAG", &DSIGKeyInfoValue::setDSAG)
	.def("setDSAY", &DSIGKeyInfoValue::setDSAY)
	.def("createBlankRSAKeyValue", &DSIGKeyInfoValueDefVisitor::createBlankRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setDSAP", &DSIGKeyInfoValue::setDSAP)
	.def("setDSAQ", &DSIGKeyInfoValue::setDSAQ)
	.def("createBlankDSAKeyValue", &DSIGKeyInfoValueDefVisitor::createBlankDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("setDSAP", &DSIGKeyInfoValue::setDSAP)
	.def("setDSAQ", &DSIGKeyInfoValue::setDSAQ)
	;
}

static xercesc::DOMElement * createBlankDSAKeyValue(DSIGKeyInfoValue& self, const STR P, const STR Q, const STR G, const STR Y) {
	pyxerces::XMLString buff1(P), buff2(Q), buff3(G), buff4(Y);
	return self.createBlankDSAKeyValue(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static void setDSAP(DSIGKeyInfoValue& self, const STR P) {
	pyxerces::XMLString buff(P);
	self.setDSAP(buff.ptr());
}

static void setDSAQ(DSIGKeyInfoValue& self, const STR Q) {
	pyxerces::XMLString buff(Q);
	self.setDSAQ(buff.ptr());
}

static void setDSAG(DSIGKeyInfoValue& self, const STR G) {
	pyxerces::XMLString buff(G);
	self.setDSAG(buff.ptr());
}

static void setDSAY(DSIGKeyInfoValue& self, const STR Y) {
	pyxerces::XMLString buff(Y);
	self.setDSAY(buff.ptr());
}

static xercesc::DOMElement* createBlankRSAKeyValue(DSIGKeyInfoValue& self, const STR modulus, const STR exponent) {
	pyxerces::XMLString buff1(modulus), buff2(exponent);
	return self.createBlankRSAKeyValue(buff1.ptr(), buff2.ptr());
}

static void setRSAModulus(DSIGKeyInfoValue& self, const STR modulus) {
	pyxerces::XMLString buff(modulus);
	self.setRSAModulus(buff.ptr());
}

static void setRSAExponent(DSIGKeyInfoValue& self, const STR exponent) {
	pyxerces::XMLString buff(exponent);
	self.setRSAExponent(buff.ptr());
}

static xercesc::DOMElement* createBlankECKeyValue(DSIGKeyInfoValue& self, const STR curveName, const STR publicKey) {
	pyxerces::XMLString buff1(curveName), buff2(publicKey);
	return self.createBlankECKeyValue(buff1.ptr(), buff2.ptr());
}

static void setECNamedCurve(DSIGKeyInfoValue& self, const STR curveName) {
	pyxerces::XMLString buff(curveName);
	self.setECNamedCurve(buff.ptr());
}

static void setECPublicKey(DSIGKeyInfoValue& self, const STR publicKey) {
	pyxerces::XMLString buff(publicKey);
	self.setECPublicKey(buff.ptr());
}

};

void DSIGKeyInfoValue_init(void) {
	//! DSIGKeyInfoValue
	boost::python::class_<DSIGKeyInfoValue, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoValue", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
		.def(boost::python::init<const XSECEnv*>())
		.def(DSIGKeyInfoValueDefVisitor<char*>())
		.def("load", &DSIGKeyInfoValue::load)
		.def("getDSAP", &DSIGKeyInfoValue::getDSAP, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getDSAQ", &DSIGKeyInfoValue::getDSAQ, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getDSAG", &DSIGKeyInfoValue::getDSAG, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getDSAY", &DSIGKeyInfoValue::getDSAY, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getRSAModulus", &DSIGKeyInfoValue::getRSAModulus, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getRSAExponent", &DSIGKeyInfoValue::getRSAExponent, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getECNamedCurve", &DSIGKeyInfoValue::getECNamedCurve, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("getECPublicKey", &DSIGKeyInfoValue::getECPublicKey, boost::python::return_value_policy<boost::python::return_by_value>())
		.def("createBlankDSAKeyValue", &DSIGKeyInfoValue::createBlankDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("setDSAP", &DSIGKeyInfoValue::setDSAP)
		.def("setDSAQ", &DSIGKeyInfoValue::setDSAQ)
		.def("setDSAG", &DSIGKeyInfoValue::setDSAG)
		.def("setDSAY", &DSIGKeyInfoValue::setDSAY)
		.def("createBlankRSAKeyValue", &DSIGKeyInfoValue::createBlankRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("setRSAModulus", &DSIGKeyInfoValue::setRSAModulus)
		.def("setRSAExponent", &DSIGKeyInfoValue::setRSAExponent)
		.def("createBlankECKeyValue", &DSIGKeyInfoValue::createBlankECKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("setECNamedCurve", &DSIGKeyInfoValue::setECNamedCurve)
		.def("setECPublicKey", &DSIGKeyInfoValue::setECPublicKey)
		.def("getKeyInfoType", &DSIGKeyInfoValue::getKeyInfoType)
		.def("getKeyName", &DSIGKeyInfoValue::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
		;
}

} /* namespace pyxsec */
