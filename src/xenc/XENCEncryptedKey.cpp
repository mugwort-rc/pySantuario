/*
 * XENCEncryptedKey.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XENCEncryptedKey.h"

#include <boost/python.hpp>

#include <xsec/xenc/XENCEncryptedKey.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class XENCEncryptedKeyDefVisitor
: public boost::python::def_visitor<XENCEncryptedKeyDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setCarriedKeyName", &XENCEncryptedKeyDefVisitor::setCarriedKeyName)
	.def("setRecipient", &XENCEncryptedKeyDefVisitor::setRecipient)
	;
}

static void setCarriedKeyName(XENCEncryptedKey& self, const STR name) {
	pyxerces::XMLString buff(name);
	self.setCarriedKeyName(buff.ptr());
}

static void setRecipient(XENCEncryptedKey& self, const STR recipient) {
	pyxerces::XMLString buff(recipient);
	self.setRecipient(buff.ptr());
}

};

void XENCEncryptedKey_init(void) {
	//! XENCEncryptedKey
	boost::python::class_<XENCEncryptedKey, boost::noncopyable, boost::python::bases<XENCEncryptedType, DSIGKeyInfo> >("XENCEncryptedKey", boost::python::no_init)
			.def(XENCEncryptedKeyDefVisitor<char*>())
			.def("getCarriedKeyName", &XENCEncryptedKey::getCarriedKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getRecipient", &XENCEncryptedKey::getRecipient, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setCarriedKeyName", &XENCEncryptedKey::setCarriedKeyName)
			.def("setRecipient", &XENCEncryptedKey::setRecipient)
			;
}

} /* namespace pyxsec */
