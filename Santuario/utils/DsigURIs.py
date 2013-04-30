# -*- coding: utf-8 -*-

# Name Spaces
URI_ID_DSIG   = 'http://www.w3.org/2000/09/xmldsig#'
URI_ID_DSIG11 = 'http://www.w3.org/2009/xmldsig11#'
URI_ID_EC     = 'http://www.w3.org/2001/10/xml-exc-c14n#'

# Also used as algorithm ID for XPATH_FILTER
URI_ID_XPF    = 'http://www.w3.org/2002/06/xmldsig-filter2'
URI_ID_XENC   = 'http://www.w3.org/2001/04/xmlenc#'
URI_ID_XENC11 = 'http://www.w3.org/2009/xmlenc11#'

# Hashing Algorithms
URI_ID_SHA1    = 'http://www.w3.org/2000/09/xmldsig#sha1'
URI_ID_MD5    = 'http://www.w3.org/2001/04/xmldsig-more#md5'
URI_ID_SHA224 = 'http://www.w3.org/2001/04/xmldsig-more#sha224'
URI_ID_SHA256 = 'http://www.w3.org/2001/04/xmlenc#sha256'
URI_ID_SHA384 = 'http://www.w3.org/2001/04/xmldsig-more#sha384'
URI_ID_SHA512 = 'http://www.w3.org/2001/04/xmlenc#sha512'

# Encryption Algorithms
URI_ID_3DES_CBC   = 'http://www.w3.org/2001/04/xmlenc#tripledes-cbc'
URI_ID_AES128_CBC = 'http://www.w3.org/2001/04/xmlenc#aes128-cbc'
URI_ID_AES192_CBC = 'http://www.w3.org/2001/04/xmlenc#aes192-cbc'
URI_ID_AES256_CBC = 'http://www.w3.org/2001/04/xmlenc#aes256-cbc'
URI_ID_AES128_GCM = 'http://www.w3.org/2009/xmlenc11#aes128-gcm'
URI_ID_AES192_GCM = 'http://www.w3.org/2009/xmlenc11#aes192-gcm'
URI_ID_AES256_GCM = 'http://www.w3.org/2009/xmlenc11#aes256-gcm'


# Key Wrap Algorithm
URI_ID_KW_3DES       = 'http://www.w3.org/2001/04/xmlenc#kw-tripledes'
URI_ID_KW_AES128     = 'http://www.w3.org/2001/04/xmlenc#kw-aes128'
URI_ID_KW_AES192     = 'http://www.w3.org/2001/04/xmlenc#kw-aes192'
URI_ID_KW_AES256     = 'http://www.w3.org/2001/04/xmlenc#kw-aes256'
URI_ID_KW_AES128_PAD = 'http://www.w3.org/2009/xmlenc11#kw-aes-128-pad'
URI_ID_KW_AES192_PAD = 'http://www.w3.org/2009/xmlenc11#kw-aes-192-pad'
URI_ID_KW_AES256_PAD = 'http://www.w3.org/2009/xmlenc11#kw-aes-256-pad'

# Key Transport algorithms
URI_ID_RSA_1_5        = 'http://www.w3.org/2001/04/xmlenc#rsa-1_5'
URI_ID_RSA_OAEP_MGFP1 = 'http://www.w3.org/2001/04/xmlenc#rsa-oaep-mgf1p'
URI_ID_RSA_OAEP       = 'http://www.w3.org/2009/xmlenc11#rsa-oaep'

# OAEP MGFs
URI_ID_MGF1_BASE   = 'http://www.w3.org/2009/xmlenc11#mgf1'
URI_ID_MGF1_SHA1   = 'http://www.w3.org/2009/xmlenc11#mgf1sha1'
URI_ID_MGF1_SHA224 = 'http://www.w3.org/2009/xmlenc11#mgf1sha224'
URI_ID_MGF1_SHA256 = 'http://www.w3.org/2009/xmlenc11#mgf1sha256'
URI_ID_MGF1_SHA384 = 'http://www.w3.org/2009/xmlenc11#mgf1sha384'
URI_ID_MGF1_SHA512 = 'http://www.w3.org/2009/xmlenc11#mgf1sha512'

# Transforms
URI_ID_BASE64       = 'http://www.w3.org/2000/09/xmldsig#base64'
URI_ID_XPATH        = 'http://www.w3.org/TR/1999/REC-xpath-19991116'
URI_ID_XSLT         = 'http://www.w3.org/TR/1999/REC-xslt-19991116'
URI_ID_ENVELOPE     = 'http://www.w3.org/2000/09/xmldsig#enveloped-signature'
URI_ID_C14N_NOC     = 'http://www.w3.org/TR/2001/REC-xml-c14n-20010315'
URI_ID_C14N_COM     = 'http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments'
URI_ID_C14N11_NOC   = 'http://www.w3.org/2006/12/xml-c14n11'
URI_ID_C14N11_COM   = 'http://www.w3.org/2006/12/xml-c14n11#WithComments'
URI_ID_EXC_C14N_NOC = 'http://www.w3.org/2001/10/xml-exc-c14n#'
URI_ID_EXC_C14N_COM = 'http://www.w3.org/2001/10/xml-exc-c14n#WithComments'
XPATH_EXPR_ENVELOPE = 'count(ancestor-or-self::dsig:Signature | here()/ancestor::dsig:Signature[1]) > count(ancestor-or-self::dsig:Signature)'

# Signature Algorithms
URI_ID_SIG_BASE     = 'http://www.w3.org/2000/09/xmldsig#'
URI_ID_SIG_BASEMORE = 'http://www.w3.org/2001/04/xmldsig-more#'
URI_ID_SIG_BASE11   = 'http://www.w3.org/2009/xmldsig11#'
URI_ID_SIG_DSA      = 'dsa'
URI_ID_SIG_ECDSA    = 'ecdsa'
URI_ID_SIG_HMAC     = 'hmac'
URI_ID_SIG_SHA1     = 'sha1'
URI_ID_SIG_SHA224   = 'sha224'
URI_ID_SIG_SHA256   = 'sha256'
URI_ID_SIG_SHA384   = 'sha384'
URI_ID_SIG_SHA512   = 'sha512'
URI_ID_SIG_RSA      = 'rsa'
URI_ID_SIG_MD5      = 'md5'

URI_ID_DSA_SHA1     = 'http://www.w3.org/2000/09/xmldsig#dsa-sha1'
URI_ID_DSA_SHA256   = 'http://www.w3.org/2009/xmldsig11#dsa-sha256'
URI_ID_HMAC_SHA1    = 'http://www.w3.org/2000/09/xmldsig#hmac-sha1'
URI_ID_HMAC_SHA224  = 'http://www.w3.org/2001/04/xmldsig-more#hmac-sha224'
URI_ID_HMAC_SHA256  = 'http://www.w3.org/2001/04/xmldsig-more#hmac-sha256'
URI_ID_HMAC_SHA384  = 'http://www.w3.org/2001/04/xmldsig-more#hmac-sha384'
URI_ID_HMAC_SHA512  = 'http://www.w3.org/2001/04/xmldsig-more#hmac-sha512'
URI_ID_RSA_SHA1     = 'http://www.w3.org/2000/09/xmldsig#rsa-sha1'
URI_ID_RSA_SHA224   = 'http://www.w3.org/2001/04/xmldsig-more#rsa-sha224'
URI_ID_RSA_SHA256   = 'http://www.w3.org/2001/04/xmldsig-more#rsa-sha256'
URI_ID_RSA_SHA384   = 'http://www.w3.org/2001/04/xmldsig-more#rsa-sha384'
URI_ID_RSA_SHA512   = 'http://www.w3.org/2001/04/xmldsig-more#rsa-sha512'
URI_ID_RSA_MD5      = 'http://www.w3.org/2001/04/xmldsig-more#rsa-md5'
URI_ID_ECDSA_SHA1   = 'http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1'
URI_ID_ECDSA_SHA224 = 'http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha224'
URI_ID_ECDSA_SHA256 = 'http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256'
URI_ID_ECDSA_SHA384 = 'http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha384'
URI_ID_ECDSA_SHA512 = 'http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha512'

# Encryption defines
URI_ID_XENC_ELEMENT = 'http://www.w3.org/2001/04/xmlenc#Element'
URI_ID_XENC_CONTENT = 'http://www.w3.org/2001/04/xmlenc#Content'

# General
URI_ID_XMLNS    = 'http://www.w3.org/2000/xmlns/'
URI_ID_MANIFEST = 'http://www.w3.org/2000/09/xmldsig#Manifest'
URI_ID_RAWX509  = 'http://www.w3.org/2000/09/xmldsig#rawX509Certificate'

# Internal Crypto Providers
PROV_OPENSSL = 'OpenSSL Provider'
PROV_WINCAPI = 'WinCAPI Provider'
PROV_NSS     = 'NSS Provider'
