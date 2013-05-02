/*
 * DSIGKeyInfoX509.cpp
 *
 *  Created on: 2013/05/02
 *      Author: mugwort_rc
 */

#include "DSIGKeyInfoX509.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/framework/XSECEnv.hpp>

#include <xsec/dsig/DSIGKeyInfoX509.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

template <typename STR>
class DSIGKeyInfoX509DefVisitor
: public boost::python::def_visitor<DSIGKeyInfoX509DefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setX509SubjectName", &DSIGKeyInfoX509DefVisitor::setX509SubjectName)
	.def("setX509IssuerSerial", &DSIGKeyInfoX509DefVisitor::setX509IssuerSerial)
	.def("setX509Digest", &DSIGKeyInfoX509DefVisitor::setX509Digest)
	.def("setX509CRL", &DSIGKeyInfoX509DefVisitor::setX509CRL)
	.def("appendX509CRL", &DSIGKeyInfoX509DefVisitor::appendX509CRL)
	.def("setX509SKI", &DSIGKeyInfoX509DefVisitor::setX509SKI)
	.def("setRawRetrievalURI", &DSIGKeyInfoX509DefVisitor::setRawRetrievalURI)
	.def("appendX509Certificate", &DSIGKeyInfoX509DefVisitor::appendX509Certificate)
	;
}

static void setX509SubjectName(DSIGKeyInfoX509& self, const STR name) {
	pyxerces::XMLString buff(name);
	self.setX509SubjectName(buff.ptr());
}

static void setX509IssuerSerial(DSIGKeyInfoX509& self, const STR name, const STR serial) {
	pyxerces::XMLString buff1(name), buff2(serial);
	self.setX509IssuerSerial(buff1.ptr(), buff2.ptr());
}

static void setX509Digest(DSIGKeyInfoX509& self, const STR algorithm, const STR value) {
	pyxerces::XMLString buff1(algorithm), buff2(value);
	self.setX509Digest(buff1.ptr(), buff2.ptr());
}

static void setX509CRL(DSIGKeyInfoX509& self, const STR crl) {
	pyxerces::XMLString buff(crl);
	self.setX509CRL(buff.ptr());
}

static void appendX509CRL(DSIGKeyInfoX509& self, const STR crl) {
	pyxerces::XMLString buff(crl);
	self.appendX509CRL(buff.ptr());
}

static void setX509SKI(DSIGKeyInfoX509& self, const STR ski) {
	pyxerces::XMLString buff(ski);
	self.setX509SKI(buff.ptr());
}

static void setRawRetrievalURI(DSIGKeyInfoX509& self, const STR uri) {
	pyxerces::XMLString buff(uri);
	self.setRawRetrievalURI(buff.ptr());
}

static void appendX509Certificate(DSIGKeyInfoX509& self, const STR base64Certificate) {
	pyxerces::XMLString buff(base64Certificate);
	self.appendX509Certificate(buff.ptr());
}

};

void DSIGKeyInfoX509_init(void) {
	//! DSIGKeyInfoX509
	boost::python::class_<DSIGKeyInfoX509, boost::noncopyable, boost::python::bases<DSIGKeyInfo> >("DSIGKeyInfoX509", boost::python::init<const XSECEnv*, xercesc::DOMNode*>())
			.def(boost::python::init<const XSECEnv*>())
			.def(DSIGKeyInfoX509DefVisitor<char*>())
			.def("load", &DSIGKeyInfoX509::load)
			.def("getX509SubjectName", &DSIGKeyInfoX509::getX509SubjectName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getKeyName", &DSIGKeyInfoX509::getKeyName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509DigestAlgorithm", &DSIGKeyInfoX509::getX509DigestAlgorithm, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509DigestValue", &DSIGKeyInfoX509::getX509DigestValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509IssuerName", &DSIGKeyInfoX509::getX509IssuerName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509IssuerSerialNumber", &DSIGKeyInfoX509::getX509IssuerSerialNumber, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509CRL", &DSIGKeyInfoX509::getX509CRL, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509CRLListSize", &DSIGKeyInfoX509::getX509CRLListSize)
			.def("getX509CRLItem", &DSIGKeyInfoX509::getX509CRLItem, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getX509SKI", &DSIGKeyInfoX509::getX509SKI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getRawRetrievalURI", &DSIGKeyInfoX509::getRawRetrievalURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getCertificateListSize", &DSIGKeyInfoX509::getCertificateListSize)
			.def("getCertificateItem", &DSIGKeyInfoX509::getCertificateItem, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getCertificateCryptoItem", static_cast<XSECCryptoX509*(DSIGKeyInfoX509::*)(int)>(&DSIGKeyInfoX509::getCertificateCryptoItem), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getKeyInfoType", &DSIGKeyInfoX509::getKeyInfoType)
			.def("createBlankX509Data", &DSIGKeyInfoX509::createBlankX509Data, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setX509SubjectName", &DSIGKeyInfoX509::setX509SubjectName)
			.def("setX509IssuerSerial", &DSIGKeyInfoX509::setX509IssuerSerial)
			.def("setX509Digest", &DSIGKeyInfoX509::setX509Digest)
			.def("setX509CRL", &DSIGKeyInfoX509::setX509CRL)
			.def("appendX509CRL", &DSIGKeyInfoX509::appendX509CRL)
			.def("setX509SKI", &DSIGKeyInfoX509::setX509SKI)
			.def("setRawRetrievalURI", &DSIGKeyInfoX509::setRawRetrievalURI)
			.def("appendX509Certificate", &DSIGKeyInfoX509::appendX509Certificate)
			;
}

} /* namespace pyxsec */
