/*
 * DSIGKeyInfo.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfo.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/dsig/DSIGSignature.hpp>
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfo.hpp>

namespace pyxsec {

class DSIGKeyInfoWrapper
: public DSIGKeyInfo, public boost::python::wrapper<DSIGKeyInfo>
{
public:
DSIGKeyInfoWrapper(XSECEnv* env)
: DSIGKeyInfo(env)
{}

keyInfoType getKeyInfoType(void) const {
	return this->get_override("getKeyInfoType")();
}

xercesc::DOMNode *getKeyInfoDOMNode(void) {
	if(boost::python::override getKeyInfoDOMNode = this->get_override("getKeyInfoDOMNode")){
		return getKeyInfoDOMNode();
	}else{
		return DSIGKeyInfo::getKeyInfoDOMNode();
	}
}

const XMLCh * getKeyName(void) const {
	return this->get_override("getKeyName")();
}

void load(void) {
	this->get_override("load")();
}

};

void DSIGKeyInfo_init(void) {
	//! DSIGKeyInfo
	auto DSIGKeyInfo_ = boost::python::class_<DSIGKeyInfoWrapper, boost::noncopyable>("DSIGKeyInfo", boost::python::init<XSECEnv*>())
			.def("getKeyInfoType", boost::python::pure_virtual(&DSIGKeyInfo::getKeyInfoType))
			.def("getKeyInfoDOMNode", &DSIGKeyInfo::getKeyInfoDOMNode, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getKeyName", boost::python::pure_virtual(&DSIGKeyInfo::getKeyName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("load", boost::python::pure_virtual(&DSIGKeyInfo::load))
			;
	boost::python::scope DSIGKeyInfoScope = DSIGKeyInfo_;
	//! DSIGKeyInfo::keyInfoType
	boost::python::enum_<DSIGKeyInfo::keyInfoType>("keyInfoType")
			.value("KEYINFO_EXTENSION", DSIGKeyInfo::KEYINFO_EXTENSION)
			.value("KEYINFO_NOTSET", DSIGKeyInfo::KEYINFO_NOTSET)
			.value("KEYINFO_X509", DSIGKeyInfo::KEYINFO_X509)
			.value("KEYINFO_VALUE_DSA", DSIGKeyInfo::KEYINFO_VALUE_DSA)
			.value("KEYINFO_VALUE_RSA", DSIGKeyInfo::KEYINFO_VALUE_RSA)
			.value("KEYINFO_NAME", DSIGKeyInfo::KEYINFO_NAME)
			.value("KEYINFO_PGPDATA", DSIGKeyInfo::KEYINFO_PGPDATA)
			.value("KEYINFO_SPKIDATA", DSIGKeyInfo::KEYINFO_SPKIDATA)
			.value("KEYINFO_MGMTDATA", DSIGKeyInfo::KEYINFO_MGMTDATA)
			.value("KEYINFO_ENCRYPTEDKEY", DSIGKeyInfo::KEYINFO_ENCRYPTEDKEY)
			.value("KEYINFO_VALUE_EC", DSIGKeyInfo::KEYINFO_VALUE_EC)
			.value("KEYINFO_DERENCODED", DSIGKeyInfo::KEYINFO_DERENCODED)
			.export_values()
			;
}

} /* namespace pyxsec */
