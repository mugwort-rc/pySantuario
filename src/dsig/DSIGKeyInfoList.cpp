/*
 * DSIGKeyInfoList.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoList.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/dsig/DSIGKeyInfoValue.hpp>
#include <xsec/dsig/DSIGKeyInfoDEREncoded.hpp>
#include <xsec/dsig/DSIGKeyInfoX509.hpp>
#include <xsec/dsig/DSIGKeyInfoName.hpp>
#include <xsec/dsig/DSIGKeyInfoPGPData.hpp>
#include <xsec/dsig/DSIGKeyInfoSPKIData.hpp>
#include <xsec/dsig/DSIGKeyInfoMgmtData.hpp>
#include <xsec/dsig/DSIGSignature.hpp>
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoList.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoListStringDefVisitor
: public boost::python::def_visitor<DSIGKeyInfoListStringDefVisitor<STR> >
{
friend class def_visitor_access;

static DSIGKeyInfoValue * appendDSAKeyValue(DSIGKeyInfoList& self, const STR P, const STR Q, const STR G, const STR Y) {
	pyxerces::XMLString buff1(P), buff2(Q), buff3(G), buff4(Y);
	return self.appendDSAKeyValue(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static DSIGKeyInfoValue * appendRSAKeyValue(DSIGKeyInfoList& self, const STR modulus, const STR exponent) {
	pyxerces::XMLString buff1(modulus), buff2(exponent);
	return self.appendRSAKeyValue(buff1.ptr(), buff2.ptr());
}

//! appendECKeyValue not found.
//static DSIGKeyInfoValue * appendECKeyValue(DSIGKeyInfoList& self, const STR curveName, const STR keyValue) {
//	pyxerces::XMLString buff1(curveName), buff2(keyValue);
//	return self.appendECKeyValue(buff1.ptr(), buff2.ptr());
//}

static DSIGKeyInfoName * appendKeyName(DSIGKeyInfoList& self, const STR name, bool isDName = false) {
	pyxerces::XMLString buff(name);
	return self.appendKeyName(buff.ptr(), isDName);
}

static DSIGKeyInfoPGPData * appendPGPData(DSIGKeyInfoList& self, const STR id, const STR packet) {
	pyxerces::XMLString buff1(id), buff2(packet);
	return self.appendPGPData(buff1.ptr(), buff2.ptr());
}

static DSIGKeyInfoSPKIData * appendSPKIData(DSIGKeyInfoList& self, const STR sexp) {
	pyxerces::XMLString buff(sexp);
	return self.appendSPKIData(buff.ptr());
}

static DSIGKeyInfoMgmtData * appendMgmtData(DSIGKeyInfoList& self, const STR data) {
	pyxerces::XMLString buff(data);
	return self.appendMgmtData(buff.ptr());
}

static DSIGKeyInfoDEREncoded * appendDEREncoded(DSIGKeyInfoList& self, const STR data) {
	pyxerces::XMLString buff(data);
	return self.appendDEREncoded(buff.ptr());
}

BOOST_PYTHON_FUNCTION_OVERLOADS(AppendKeyNameOverloads, appendKeyName, 2, 3)

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("appendDSAKeyValue", &DSIGKeyInfoListStringDefVisitor::appendDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendRSAKeyValue", &DSIGKeyInfoListStringDefVisitor::appendRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	//! appendECKeyValue not found.
	//.def("appendECKeyValue", &DSIGKeyInfoListStringDefVisitor::appendECKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendKeyName", &DSIGKeyInfoListStringDefVisitor::appendKeyName, AppendKeyNameOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
	.def("appendPGPData", &DSIGKeyInfoListStringDefVisitor::appendPGPData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendSPKIData", &DSIGKeyInfoListStringDefVisitor::appendSPKIData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendMgmtData", &DSIGKeyInfoListStringDefVisitor::appendMgmtData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("appendDEREncoded", &DSIGKeyInfoListStringDefVisitor::appendDEREncoded, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

};

void DSIGKeyInfoList_init(void) {
	//! DSIGKeyInfoList
	boost::python::class_<DSIGKeyInfoList, boost::noncopyable>("DSIGKeyInfoList", boost::python::init<const XSECEnv*>())
			.def(DSIGKeyInfoListStringDefVisitor<char*>())
			.def("getSize", &DSIGKeyInfoList::getSize)
			.def("item", static_cast<DSIGKeyInfo*(DSIGKeyInfoList::*)(DSIGKeyInfoList::size_type)>(&DSIGKeyInfoList::item), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("addKeyInfo", &DSIGKeyInfoList::addKeyInfo)
			.def("addAndInsertKeyInfo", &DSIGKeyInfoList::addAndInsertKeyInfo)
			.def("addXMLKeyInfo", &DSIGKeyInfoList::addXMLKeyInfo)
			.def("loadListFromXML", &DSIGKeyInfoList::loadListFromXML)
			.def("removeKeyInfo", &DSIGKeyInfoList::removeKeyInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setEnvironment", &DSIGKeyInfoList::setEnvironment)
			.def("empty", &DSIGKeyInfoList::empty)
			.def("isEmpty", &DSIGKeyInfoList::isEmpty)
			.def("createKeyInfo", &DSIGKeyInfoList::createKeyInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendDSAKeyValue", &DSIGKeyInfoList::appendDSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendRSAKeyValue", &DSIGKeyInfoList::appendRSAKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//! appendECKeyValue not found.
			//.def("appendECKeyValue", &DSIGKeyInfoList::appendECKeyValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendX509Data", &DSIGKeyInfoList::appendX509Data, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendKeyName", &DSIGKeyInfoList::appendKeyName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendPGPData", &DSIGKeyInfoList::appendPGPData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendSPKIData", &DSIGKeyInfoList::appendSPKIData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendMgmtData", &DSIGKeyInfoList::appendMgmtData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("appendDEREncoded", &DSIGKeyInfoList::appendDEREncoded, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxsec */
