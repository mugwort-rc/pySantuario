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
// enc
#include "enc/XSECCryptoKey.h"
#include "enc/XSECCryptoKeyRSA.h"
#include "enc/XSECCryptoSymmetricKey.h"
#include "enc/XSECCryptoX509.h"
#include "enc/OpenSSL/OpenSSLCryptoSymmetricKey.h"
#include "enc/OpenSSL/OpenSSLCryptoKeyRSA.h"
#include "enc/OpenSSL/OpenSSLCryptoX509.h"
// framework
#include "framework/XSECException.h"
#include "framework/XSECProvider.h"
// utils
#include "utils/XSECDOMUtils.h"
#include "utils/XSECPlatformUtils.h"
// xenc
#include "xenc/XENCCipher.h"
#include "xenc/XENCEncryptedData.h"
#include "xenc/XENCEncryptedKey.h"
#include "xenc/XENCEncryptedType.h"

BOOST_PYTHON_MODULE(__Santuario)
{
	// ==================================================
	// bases
	// --------------------------------------------------
	// dsig
	pyxsec::DSIGKeyInfo_init();

	// enc
	pyxsec::XSECCryptoKey_init();
	pyxsec::XSECCryptoX509_init();

	// xenc
	pyxsec::XENCEncryptedType_init();

	// inherited (depth:2) classes
	// enc
	pyxsec::XSECCryptoKeyRSA_init();
	pyxsec::XSECCryptoSymmetricKey_init();

	// ==================================================
	// common
	// --------------------------------------------------
	pyxsec::OpenSSL_init();

	// ==================================================
	// dsig
	// --------------------------------------------------
	pyxsec::DSIGConstants_init();

	// ==================================================
	// enc
	// --------------------------------------------------
	// OpenSSL
	pyxsec::OpenSSLCryptoSymmetricKey_init();
	pyxsec::OpenSSLCryptoKeyRSA_init();
	pyxsec::OpenSSLCryptoX509_init();

	// ==================================================
	// framework
	// --------------------------------------------------
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
	pyxsec::XENCEncryptedData_init();
	pyxsec::XENCEncryptedKey_init();
}
