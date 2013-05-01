/*
 * OpenSSL.cpp
 *
 *  Created on: 2013/05/01
 *      Author: mugwort_rc
 */

#include "OpenSSL.h"

#include <boost/python.hpp>

#include <openssl/evp.h>
#include <openssl/pem.h>

namespace pyxsec {

class OpenSSLUtils{
public:
~OpenSSLUtils()
{}

static EVP_PKEY* load_PEM_PrivateKey(const std::string& pem) {
	BIO * bio = BIO_new(BIO_s_mem());
	BIO_puts(bio, pem.c_str());
	return PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
}

private:
OpenSSLUtils(const OpenSSLUtils&);
OpenSSLUtils& operator =(const OpenSSLUtils&);

};

void OpenSSL_init(void) {
	//! OpenSSL
	boost::python::class_<OpenSSLUtils, boost::noncopyable>("OpenSSL", boost::python::no_init)
			.def("load_PEM_PrivateKey", &OpenSSLUtils::load_PEM_PrivateKey, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.staticmethod("load_PEM_PrivateKey")
			;
}

} /* namespace pyxsec */
