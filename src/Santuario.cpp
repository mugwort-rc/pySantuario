/*
 * Santuario.cpp
 *
 *  Created on: 2013/02/21
 *      Author: mugwort_rc
 */

#include <Python.h>
#include <boost/python.hpp>
#define BOOST_PYTHON_STATIC_LIB

// common
#include "common/OpenSSL.h"
// dsig
#include "dsig/DSIGConstants.h"
#include "dsig/DSIGKeyInfo.h"
#include "dsig/DSIGKeyInfoList.h"
#include "dsig/DSIGKeyInfoDEREncoded.h"
#include "dsig/DSIGKeyInfoExt.h"
#include "dsig/DSIGKeyInfoMgmtData.h"
#include "dsig/DSIGKeyInfoName.h"
#include "dsig/DSIGKeyInfoPGPData.h"
#include "dsig/DSIGKeyInfoSPKIData.h"
#include "dsig/DSIGKeyInfoValue.h"
#include "dsig/DSIGKeyInfoX509.h"
#include "dsig/DSIGObject.h"
#include "dsig/DSIGReference.h"
#include "dsig/DSIGReferenceList.h"
#include "dsig/DSIGSignature.h"
#include "dsig/DSIGTransform.h"
#include "dsig/DSIGTransformBase64.h"
#include "dsig/DSIGTransformC14n.h"
#include "dsig/DSIGTransformEnvelope.h"
#include "dsig/DSIGTransformList.h"
#include "dsig/DSIGTransformXPath.h"
#include "dsig/DSIGTransformXPathFilter.h"
#include "dsig/DSIGTransformXSL.h"
#include "dsig/DSIGXPathFilterExpr.h"
// enc
#include "enc/XSECCryptoException.h"
#include "enc/XSECCryptoKey.h"
#include "enc/XSECCryptoKeyHMAC.h"
#include "enc/XSECCryptoKeyRSA.h"
#include "enc/XSECCryptoSymmetricKey.h"
#include "enc/XSECCryptoX509.h"
#include "enc/XSECKeyInfoResolver.h"
#include "enc/OpenSSL/OpenSSLCryptoKeyHMAC.h"
#include "enc/OpenSSL/OpenSSLCryptoKeyRSA.h"
#include "enc/OpenSSL/OpenSSLCryptoSymmetricKey.h"
#include "enc/OpenSSL/OpenSSLCryptoX509.h"
// framework
#include "framework/XSECEnv.h"
#include "framework/XSECException.h"
#include "framework/XSECProvider.h"
// utils
#include "utils/XSECDOMUtils.h"
#include "utils/XSECPlatformUtils.h"
// xenc
#include "xenc/XENCCipher.h"
#include "xenc/XENCCipherData.h"
#include "xenc/XENCCipherReference.h"
#include "xenc/XENCCipherValue.h"
#include "xenc/XENCEncryptedData.h"
#include "xenc/XENCEncryptedKey.h"
#include "xenc/XENCEncryptedType.h"
#include "xenc/XENCEncryptionMethod.h"
// xkms
#include "xkms/XKMSMessageAbstractType.h"
#include "xkms/XKMSMessageFactory.h"
#include "xkms/XKMSResult.h"
#include "xkms/XKMSResultType.h"

BOOST_PYTHON_MODULE(__Santuario)
{
	// ==================================================
	// bases
	// --------------------------------------------------
	// dsig
	pyxsec::DSIGKeyInfo_init();
	pyxsec::DSIGTransform_init();

	// enc
	pyxsec::XSECCryptoKey_init();
	pyxsec::XSECCryptoKeyHMAC_init();
	pyxsec::XSECCryptoX509_init();

	// xenc
	pyxsec::XENCEncryptedType_init();

	// xkms
	pyxsec::XKMSMessageAbstractType_init();

	// inherited (depth:2) classes
	// enc
	pyxsec::XSECCryptoKeyRSA_init();
	pyxsec::XSECCryptoSymmetricKey_init();
	pyxsec::XKMSResultType_init();

	// ==================================================
	// common
	// --------------------------------------------------
	pyxsec::OpenSSL_init();

	// ==================================================
	// dsig
	// --------------------------------------------------
	pyxsec::DSIGConstants_init();
	pyxsec::DSIGKeyInfoList_init();
	pyxsec::DSIGKeyInfoDEREncoded_init();
	pyxsec::DSIGKeyInfoExt_init();
	pyxsec::DSIGKeyInfoMgmtData_init();
	pyxsec::DSIGKeyInfoName_init();
	pyxsec::DSIGKeyInfoPGPData_init();
	pyxsec::DSIGKeyInfoSPKIData_init();
	pyxsec::DSIGKeyInfoValue_init();
	pyxsec::DSIGKeyInfoX509_init();
	pyxsec::DSIGObject_init();
	pyxsec::DSIGReference_init();
	pyxsec::DSIGReferenceList_init();
	pyxsec::DSIGSignature_init();
	pyxsec::DSIGTransformBase64_init();
	pyxsec::DSIGTransformC14n_init();
	pyxsec::DSIGTransformEnvelope_init();
	pyxsec::DSIGTransformList_init();
	pyxsec::DSIGTransformXPath_init();
	pyxsec::DSIGTransformXPathFilter_init();
	pyxsec::DSIGTransformXSL_init();
	pyxsec::DSIGXPathFilterExpr_init();

	// ==================================================
	// enc
	// --------------------------------------------------
	pyxsec::XSECCryptoException_init();
	pyxsec::XSECKeyInfoResolver_init();
	// OpenSSL
	pyxsec::OpenSSLCryptoKeyHMAC_init();
	pyxsec::OpenSSLCryptoKeyRSA_init();
	pyxsec::OpenSSLCryptoSymmetricKey_init();
	pyxsec::OpenSSLCryptoX509_init();

	// ==================================================
	// framework
	// --------------------------------------------------
	pyxsec::XSECEnv_init();
	pyxsec::XSECException_init();
	pyxsec::XSECProvider_init();

	// ==================================================
	// utils
	// --------------------------------------------------
	pyxsec::XSECDOMUtils_init();
	pyxsec::XSECPlatformUtils_init();

	// ==================================================
	// xenc
	// --------------------------------------------------
	pyxsec::XENCCipher_init();
	pyxsec::XENCCipherData_init();
	pyxsec::XENCCipherReference_init();
	pyxsec::XENCCipherValue_init();
	pyxsec::XENCEncryptedData_init();
	pyxsec::XENCEncryptedKey_init();
	pyxsec::XENCEncryptionMethod_init();
	// ==================================================
	// xkms
	// --------------------------------------------------
	pyxsec::XKMSMessageFactory_init();
	pyxsec::XKMSResult_init();
}
