/*
 * DSIGConstants.cpp
 *
 *  Created on: 2013/04/30
 *      Author: mugwort_rc
 */

#include "DSIGConstants.h"

#include <boost/python.hpp>

#include <xsec/dsig/DSIGConstants.hpp>

#include "../common/XMLString.h"

namespace pyxsec {

boost::python::tuple pyCanonicalizationMethod2URI(canonicalizationMethod cm) {
	safeBuffer buffer;
	bool result = canonicalizationMethod2URI(buffer, cm);
	return boost::python::make_tuple(result, buffer);
}

boost::python::tuple pySignatureHashMethod2URI(signatureMethod sm, hashMethod hm) {
	safeBuffer buffer;
	bool result = signatureHashMethod2URI(buffer, sm, hm);
	return boost::python::make_tuple(result, buffer);
}

boost::python::tuple pyHashMethod2URI(hashMethod hm) {
	safeBuffer buffer;
	bool result = hashMethod2URI(buffer, hm);
	return boost::python::make_tuple(result, buffer);
}

boost::python::tuple pyEncryptionMethod2URI(encryptionMethod em) {
	safeBuffer buffer;
	bool result = encryptionMethod2URI(buffer, em);
	return boost::python::make_tuple(result, buffer);
}

boost::python::tuple pyMaskGenerationFunc2URI(maskGenerationFunc mgf) {
	safeBuffer buffer;
	bool result = maskGenerationFunc2URI(buffer, mgf);
	return boost::python::make_tuple(result, buffer);
}

boost::python::tuple pyXSECmapURIToSignatureMethods(const char* URI) {
	pyxerces::XMLString buff(URI);
	signatureMethod sm;
	hashMethod hm;
	bool result = XSECmapURIToSignatureMethods(buff.ptr(), sm, hm);
	return boost::python::make_tuple(result, sm, hm);
}

boost::python::tuple pyXSECmapURIToHashMethod(const char* URI) {
	pyxerces::XMLString buff(URI);
	hashMethod hm;
	bool result = XSECmapURIToHashMethod(buff.ptr(), hm);
	return boost::python::make_tuple(result, hm);
}

boost::python::tuple pyXSECmapURIToCanonicalizationMethod(const char* URI) {
	pyxerces::XMLString buff(URI);
	canonicalizationMethod cm;
	bool result = XSECmapURIToCanonicalizationMethod(buff.ptr(), cm);
	return boost::python::make_tuple(result, cm);
}

boost::python::tuple pyXSECmapURIToMaskGenerationFunc(const char* URI) {
	pyxerces::XMLString buff(URI);
	maskGenerationFunc mgf;
	bool result = XSECmapURIToMaskGenerationFunc(buff.ptr(), mgf);
	return boost::python::make_tuple(result, mgf);
}

void DSIGConstants_init(void) {
	//! DSIGConstants
	//! canonicalizationMethod
	boost::python::enum_<canonicalizationMethod>("canonicalizationMethod")
			.value("CANON_NONE", canonicalizationMethod::CANON_NONE)
			.value("CANON_C14N_NOC", canonicalizationMethod::CANON_C14N_NOC)
			.value("CANON_C14N_COM", canonicalizationMethod::CANON_C14N_COM)
			.value("CANON_C14NE_NOC", canonicalizationMethod::CANON_C14NE_NOC)
			.value("CANON_C14NE_COM", canonicalizationMethod::CANON_C14NE_COM)
			.value("CANON_C14N11_NOC", canonicalizationMethod::CANON_C14N11_NOC)
			.value("CANON_C14N11_COM", canonicalizationMethod::CANON_C14N11_COM)
			.export_values()
			;
	//! signatureMethod
	boost::python::enum_<signatureMethod>("signatureMethod")
			.value("SIGNATURE_NONE", signatureMethod::SIGNATURE_NONE)
			.value("SIGNATURE_DSA", signatureMethod::SIGNATURE_DSA)
			.value("SIGNATURE_HMAC", signatureMethod::SIGNATURE_HMAC)
			.value("SIGNATURE_RSA", signatureMethod::SIGNATURE_RSA)
			.value("SIGNATURE_ECDSA", signatureMethod::SIGNATURE_ECDSA)
			.export_values()
			;
	//! hashMethod
	boost::python::enum_<hashMethod>("hashMethod")
			.value("HASH_NONE", hashMethod::HASH_NONE)
			.value("HASH_SHA1", hashMethod::HASH_SHA1)
			.value("HASH_MD5", hashMethod::HASH_MD5)
			.value("HASH_SHA224", hashMethod::HASH_SHA224)
			.value("HASH_SHA256", hashMethod::HASH_SHA256)
			.value("HASH_SHA384", hashMethod::HASH_SHA384)
			.value("HASH_SHA512", hashMethod::HASH_SHA512)
			.export_values()
			;
	//! transformType
	boost::python::enum_<transformType>("transformType")
			.value("TRANSFORM_BASE64", transformType::TRANSFORM_BASE64)
			.value("TRANSFORM_C14N", transformType::TRANSFORM_C14N)
			.value("TRANSFORM_C14N11", transformType::TRANSFORM_C14N11)
			.value("TRANSFORM_EXC_C14N", transformType::TRANSFORM_EXC_C14N)
			.value("TRANSFORM_ENVELOPED_SIGNATURE", transformType::TRANSFORM_ENVELOPED_SIGNATURE)
			.value("TRANSFORM_XPATH", transformType::TRANSFORM_XPATH)
			.value("TRANSFORM_XSLT", transformType::TRANSFORM_XSLT)
			.value("TRANSFORM_XPATH_FILTER", transformType::TRANSFORM_XPATH_FILTER)
			.export_values()
			;
	//! xpathFilterType
	boost::python::enum_<xpathFilterType>("xpathFilterType")
			.value("FILTER_UNION", xpathFilterType::FILTER_UNION)
			.value("FILTER_INTERSECT", xpathFilterType::FILTER_INTERSECT)
			.value("FILTER_SUBTRACT", xpathFilterType::FILTER_SUBTRACT)
			.export_values()
			;
	//! encryptionMethod
	boost::python::enum_<encryptionMethod>("encryptionMethod")
			.value("ENCRYPT_NONE", encryptionMethod::ENCRYPT_NONE)
			.value("ENCRYPT_3DES_CBC", encryptionMethod::ENCRYPT_3DES_CBC)
			.value("ENCRYPT_AES128_CBC", encryptionMethod::ENCRYPT_AES128_CBC)
			.value("ENCRYPT_AES192_CBC", encryptionMethod::ENCRYPT_AES192_CBC)
			.value("ENCRYPT_AES256_CBC", encryptionMethod::ENCRYPT_AES256_CBC)
			.value("ENCRYPT_KW_AES128", encryptionMethod::ENCRYPT_KW_AES128)
			.value("ENCRYPT_KW_AES192", encryptionMethod::ENCRYPT_KW_AES192)
			.value("ENCRYPT_KW_AES256", encryptionMethod::ENCRYPT_KW_AES256)
			.value("ENCRYPT_KW_3DES", encryptionMethod::ENCRYPT_KW_3DES)
			.value("ENCRYPT_RSA_15", encryptionMethod::ENCRYPT_RSA_15)
			.value("ENCRYPT_RSA_OAEP_MGFP1", encryptionMethod::ENCRYPT_RSA_OAEP_MGFP1)
			.value("ENCRYPT_RSA_OAEP", encryptionMethod::ENCRYPT_RSA_OAEP)
			.value("ENCRYPT_AES128_GCM", encryptionMethod::ENCRYPT_AES128_GCM)
			.value("ENCRYPT_AES192_GCM", encryptionMethod::ENCRYPT_AES192_GCM)
			.value("ENCRYPT_AES256_GCM", encryptionMethod::ENCRYPT_AES256_GCM)
			.value("ENCRYPT_KW_AES128_PAD", encryptionMethod::ENCRYPT_KW_AES128_PAD)
			.value("ENCRYPT_KW_AES192_PAD", encryptionMethod::ENCRYPT_KW_AES192_PAD)
			.value("ENCRYPT_KW_AES256_PAD", encryptionMethod::ENCRYPT_KW_AES256_PAD)
			.export_values()
			;
	//! maskGenerationFunc
	boost::python::enum_<maskGenerationFunc>("maskGenerationFunc")
			.value("MGF_NONE", maskGenerationFunc::MGF_NONE)
			.value("MGF1_SHA1", maskGenerationFunc::MGF1_SHA1)
			.value("MGF1_SHA224", maskGenerationFunc::MGF1_SHA224)
			.value("MGF1_SHA256", maskGenerationFunc::MGF1_SHA256)
			.value("MGF1_SHA384", maskGenerationFunc::MGF1_SHA384)
			.value("MGF1_SHA512", maskGenerationFunc::MGF1_SHA512)
			.export_values()
			;

	//! some utility functions
	boost::python::def("canonicalizationMethod2URI", &pyCanonicalizationMethod2URI);
	boost::python::def("signatureHashMethod2URI", &pySignatureHashMethod2URI);
	boost::python::def("hashMethod2URI", &pyHashMethod2URI);
	boost::python::def("encryptionMethod2URI", &pyEncryptionMethod2URI);
	boost::python::def("maskGenerationFunc2URI", &pyMaskGenerationFunc2URI);
	boost::python::def("canonicalizationMethod2UNICODEURI", &canonicalizationMethod2UNICODEURI, boost::python::return_value_policy<boost::python::return_by_value>());
	//! URI Inverse Mappings
	boost::python::def("XSECmapURIToSignatureMethods", &pyXSECmapURIToSignatureMethods);
	boost::python::def("XSECmapURIToHashMethod", &pyXSECmapURIToHashMethod);
	boost::python::def("XSECmapURIToCanonicalizationMethod", &pyXSECmapURIToCanonicalizationMethod);
	boost::python::def("XSECmapURIToMaskGenerationFunc", &pyXSECmapURIToMaskGenerationFunc);
/*
	//! Constant Strings Class
	//! DSIGConstants
	boost::python::class_<DSIGConstants, boost::noncopyable>("DSIGConstants")
			//! General strings
			.setattr("s_unicodeStrEmpty", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrEmpty))
			.setattr("s_unicodeStrNL", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrNL))
			.setattr("s_unicodeStrXmlns", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrXmlns))
			.setattr("s_unicodeStrURI", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURI))
			//! DSIG Element Strings
			.setattr("s_unicodeStrAlgorithm", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrAlgorithm))
			//! URI_IDs
			.setattr("s_unicodeStrURIDSIG", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIDSIG))
			.setattr("s_unicodeStrURIDSIG11", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIDSIG11))
			.setattr("s_unicodeStrURIEC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIEC))
			.setattr("s_unicodeStrURIXPF", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXPF))
			.setattr("s_unicodeStrURIXENC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXENC))
			.setattr("s_unicodeStrURIXENC11", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXENC11))
			.setattr("s_unicodeStrURISIGBASE", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISIGBASE))
			.setattr("s_unicodeStrURISIGBASEMORE", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISIGBASEMORE))
			.setattr("s_unicodeStrURISIGBASE11", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISIGBASE11))
			.setattr("s_unicodeStrURIRawX509", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRawX509))
			.setattr("s_unicodeStrURISHA1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISHA1))
			.setattr("s_unicodeStrURISHA224", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISHA224))
			.setattr("s_unicodeStrURISHA256", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISHA256))
			.setattr("s_unicodeStrURISHA384", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISHA384))
			.setattr("s_unicodeStrURISHA512", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURISHA512))
			.setattr("s_unicodeStrURIMD5", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMD5))
			.setattr("s_unicodeStrURIBASE64", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIBASE64))
			.setattr("s_unicodeStrURIXPATH", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXPATH))
			.setattr("s_unicodeStrURIXSLT", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXSLT))
			.setattr("s_unicodeStrURIENVELOPE", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIENVELOPE))
			.setattr("s_unicodeStrURIC14N_NOC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIC14N_NOC))
			.setattr("s_unicodeStrURIC14N_COM", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIC14N_COM))
			.setattr("s_unicodeStrURIC14N11_NOC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIC14N11_NOC))
			.setattr("s_unicodeStrURIC14N11_COM", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIC14N11_COM))
			.setattr("s_unicodeStrURIEXC_C14N_NOC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIEXC_C14N_NOC))
			.setattr("s_unicodeStrURIEXC_C14N_COM", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIEXC_C14N_COM))
			.setattr("s_unicodeStrURIDSA_SHA1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIDSA_SHA1))
			.setattr("s_unicodeStrURIDSA_SHA256", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIDSA_SHA256))
			.setattr("s_unicodeStrURIRSA_MD5", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_MD5))
			.setattr("s_unicodeStrURIRSA_SHA1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_SHA1))
			.setattr("s_unicodeStrURIRSA_SHA224", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_SHA224))
			.setattr("s_unicodeStrURIRSA_SHA256", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_SHA256))
			.setattr("s_unicodeStrURIRSA_SHA384", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_SHA384))
			.setattr("s_unicodeStrURIRSA_SHA512", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_SHA512))
			.setattr("s_unicodeStrURIECDSA_SHA1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIECDSA_SHA1))
			.setattr("s_unicodeStrURIECDSA_SHA224", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIECDSA_SHA224))
			.setattr("s_unicodeStrURIECDSA_SHA224", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIECDSA_SHA224))
			.setattr("s_unicodeStrURIECDSA_SHA384", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIECDSA_SHA384))
			.setattr("s_unicodeStrURIECDSA_SHA512", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIECDSA_SHA512))
			.setattr("s_unicodeStrURIHMAC_SHA1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIHMAC_SHA1))
			.setattr("s_unicodeStrURIHMAC_SHA224", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIHMAC_SHA224))
			.setattr("s_unicodeStrURIHMAC_SHA256", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIHMAC_SHA256))
			.setattr("s_unicodeStrURIHMAC_SHA384", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIHMAC_SHA384))
			.setattr("s_unicodeStrURIHMAC_SHA512", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIHMAC_SHA512))
			.setattr("s_unicodeStrURIXMLNS", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXMLNS))
			.setattr("s_unicodeStrURIMANIFEST", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMANIFEST))
			//! URIs for Encryption
			.setattr("s_unicodeStrURI3DES_CBC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURI3DES_CBC))
			.setattr("s_unicodeStrURIAES128_CBC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIAES128_CBC))
			.setattr("s_unicodeStrURIAES192_CBC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIAES192_CBC))
			.setattr("s_unicodeStrURIAES256_CBC", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIAES256_CBC))
			.setattr("s_unicodeStrURIAES128_GCM", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIAES128_GCM))
			.setattr("s_unicodeStrURIAES192_GCM", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIAES192_GCM))
			.setattr("s_unicodeStrURIAES256_GCM", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIAES256_GCM))
			.setattr("s_unicodeStrURIKW_3DES", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_3DES))
			.setattr("s_unicodeStrURIKW_AES128", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_AES128))
			.setattr("s_unicodeStrURIKW_AES192", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_AES192))
			.setattr("s_unicodeStrURIKW_AES256", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_AES256))
			.setattr("s_unicodeStrURIKW_AES128_PAD", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_AES128_PAD))
			.setattr("s_unicodeStrURIKW_AES192_PAD", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_AES192_PAD))
			.setattr("s_unicodeStrURIKW_AES256_PAD", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIKW_AES256_PAD))
			.setattr("s_unicodeStrURIRSA_1_5", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_1_5))
			.setattr("s_unicodeStrURIRSA_OAEP_MGFP1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_OAEP_MGFP1))
			.setattr("s_unicodeStrURIRSA_OAEP", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIRSA_OAEP))
			.setattr("s_unicodeStrURIMGF1_BASE", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMGF1_BASE))
			.setattr("s_unicodeStrURIMGF1_SHA1", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMGF1_SHA1))
			.setattr("s_unicodeStrURIMGF1_SHA224", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMGF1_SHA224))
			.setattr("s_unicodeStrURIMGF1_SHA256", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMGF1_SHA256))
			.setattr("s_unicodeStrURIMGF1_SHA384", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMGF1_SHA384))
			.setattr("s_unicodeStrURIMGF1_SHA512", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIMGF1_SHA512))
			.setattr("s_unicodeStrURIXENC_ELEMENT", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXENC_ELEMENT))
			.setattr("s_unicodeStrURIXENC_CONTENT", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrURIXENC_CONTENT))
			.setattr("s_unicodeStrPROVOpenSSL", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrPROVOpenSSL))
			.setattr("s_unicodeStrPROVWinCAPI", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrPROVWinCAPI))
			.setattr("s_unicodeStrPROVNSS", pyxerces::XMLChPtr(DSIGConstants::s_unicodeStrPROVNSS))
			//! functions
			.def("create", &DSIGConstants::create)
			.def("destroy", &DSIGConstants::destroy)
			.staticmethod("create")
			.staticmethod("destroy")
			;
			*/
}

} /* namespace pyxsec */
