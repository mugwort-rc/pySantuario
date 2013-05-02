/*
 * XENCEncryptedType.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "XENCEncryptedType.h"

#include <boost/python.hpp>

//! for forward delcaration
#include <xsec/xenc/XENCCipherData.hpp>
#include <xsec/dsig/DSIGKeyInfoList.hpp>
#include <xsec/dsig/DSIGKeyInfoName.hpp>
#include <xsec/dsig/DSIGKeyInfoValue.hpp>
#include <xsec/dsig/DSIGKeyInfoX509.hpp>
#include <xsec/xenc/XENCEncryptionMethod.hpp>
#include <xsec/xenc/XENCEncryptedKey.hpp>

#include <xsec/xenc/XENCEncryptedType.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class XENCEncryptedTypeDefVisitor
: public boost::python::def_visitor<XENCEncryptedTypeDefVisitor<STR> >
{
friend class def_visitor_access;

static void setType(XENCEncryptedType& self, const STR uri) {
	pyxerces::XMLString buff(uri);
	self.setType(buff.ptr());
}

static void setMimeType(XENCEncryptedType& self, const STR mimeType) {
	pyxerces::XMLString buff(mimeType);
	self.setMimeType(buff.ptr());
}

static void setEncoding(XENCEncryptedType& self, const STR uri) {
	pyxerces::XMLString buff(uri);
	self.setEncoding(buff.ptr());
}

static DSIGKeyInfoValue * appendDSAKeyValue(XENCEncryptedType& self, const STR P, const STR Q, const STR G, const STR Y) {
	pyxerces::XMLString buff1(P), buff2(Q), buff3(G), buff4(Y);
	return self.appendDSAKeyValue(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static DSIGKeyInfoValue * appendRSAKeyValue(XENCEncryptedType& self, const STR modulus,  const STR exponent) {
	pyxerces::XMLString buff1(modulus), buff2(exponent);
	return self.appendRSAKeyValue(buff1.ptr(), buff2.ptr());
}

static DSIGKeyInfoName * appendKeyName(XENCEncryptedType& self, const STR name, bool isDName = false) {
	pyxerces::XMLString buff(name);
	return self.appendKeyName(buff.ptr(), isDName);
}

BOOST_PYTHON_FUNCTION_OVERLOADS(AppendKeyNameOverloads, appendKeyName, 2, 3)

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setType", &XENCEncryptedTypeDefVisitor::setType)
	.def("setMimeType", &XENCEncryptedTypeDefVisitor::setMimeType)
	.def("setEncoding", &XENCEncryptedTypeDefVisitor::setEncoding)
	.def("appendDSAKeyValue", &XENCEncryptedTypeDefVisitor::appendDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendRSAKeyValue", &XENCEncryptedTypeDefVisitor::appendRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendKeyName", &XENCEncryptedTypeDefVisitor::appendKeyName, AppendKeyNameOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	;
}

};

//! XENCEncryptedType
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XENCEncryptedTypeAppendKeyNameOverloads, appendKeyName, 1, 2)

void XENCEncryptedType_init(void) {
	//! XENCEncryptedType
	boost::python::class_<XENCEncryptedType, boost::noncopyable>("XENCEncryptedType", boost::python::no_init)
			.def(XENCEncryptedTypeDefVisitor<char*>())
			.def("getCipherData", &XENCEncryptedType::getCipherData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! TODO: XENCEncryptionMethod
			.def("getEncryptionMethod", &XENCEncryptedType::getEncryptionMethod, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElement", &XENCEncryptedType::getElement, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getType", &XENCEncryptedType::getType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMimeType", &XENCEncryptedType::getMimeType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getEncoding", &XENCEncryptedType::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setType", &XENCEncryptedType::setType)
			.def("setMimeType", &XENCEncryptedType::setMimeType)
			.def("setEncoding", &XENCEncryptedType::setEncoding)
			.def("getKeyInfoList", &XENCEncryptedType::getKeyInfoList, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("clearKeyInfo", &XENCEncryptedType::clearKeyInfo)
			.def("appendDSAKeyValue", &XENCEncryptedType::appendDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendRSAKeyValue", &XENCEncryptedType::appendRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendX509Data", &XENCEncryptedType::appendX509Data, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendKeyName", &XENCEncryptedType::appendKeyName, XENCEncryptedTypeAppendKeyNameOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("appendEncryptedKey", &XENCEncryptedType::appendEncryptedKey)
			;
}

} /* namespace pyxsec */
