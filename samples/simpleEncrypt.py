# -*- coding: utf-8 -*-
"""

 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements. See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership. The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License. You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. See the License for the
 specific language governing permissions and limitations
 under the License.

"""

import sys
import Xerces, Santuario
import M2Crypto

from IOStreamOutputter import docSetup, write

cert = """MIIC7jCCAq6gAwIBAgICEAMwCQYHKoZIzjgEAzB5MQswCQYDVQQGEwJBVTEMMAoG
A1UECBMDVmljMRIwEAYDVQQHEwlNZWxib3VybmUxHzAdBgNVBAoTFlhNTC1TZWN1
cml0eS1DIFByb2plY3QxEDAOBgNVBAsTB1hTRUMtQ0ExFTATBgNVBAMTDFhTRUMt
Q0EgUm9vdDAeFw0wMjEyMTIxMDEzMTlaFw0xMjEyMDkxMDEzMTlaMFYxCzAJBgNV
BAYTAkFVMQwwCgYDVQQIEwNWaWMxHzAdBgNVBAoTFlhNTC1TZWN1cml0eS1DIFBy
b2plY3QxGDAWBgNVBAMTD1JTQSBTYW1wbGUgQ2VydDCBnzANBgkqhkiG9w0BAQEF
AAOBjQAwgYkCgYEA0I96ZLWXJAM8LIUZ37y4c93WjVOsaQM6B6N6own7cQ8B9Ucp
zwOXsnCVZFfJsB9gtTxZLaY7UE2dgrz47iplFecxL5mM7iKOklmGlWTfzyY87BGT
GlQPlPBoX19WBf67Lhc1wovK+hVXdyzf/6VxxMKAxnSVHZaXVRLl9YhSpTUCAwEA
AaOCAQEwgf4wCQYDVR0TBAIwADAsBglghkgBhvhCAQ0EHxYdT3BlblNTTCBHZW5l
cmF0ZWQgQ2VydGlmaWNhdGUwHQYDVR0OBBYEFGq6U1SwYNRyTJGAwARirEdavfXB
MIGjBgNVHSMEgZswgZiAFBKNX9CsAIsjUIFmVq4wE4wlOGC5oX2kezB5MQswCQYD
VQQGEwJBVTEMMAoGA1UECBMDVmljMRIwEAYDVQQHEwlNZWxib3VybmUxHzAdBgNV
BAoTFlhNTC1TZWN1cml0eS1DIFByb2plY3QxEDAOBgNVBAsTB1hTRUMtQ0ExFTAT
BgNVBAMTDFhTRUMtQ0EgUm9vdIIBADAJBgcqhkjOOAQDAy8AMCwCFGoKhVPnDeg9
nbEFo2KDDlG/NiUqAhRJxQPLXDhehQjn6eqQWOUlkFtA9A=="""

def createLetter(impl):
	doc = impl.createDocument('', 'Letter', None)
	rootElem = doc.getDocumentElement()

	# Add the ToAddress
	addressElem = doc.createElement('ToAddress')
	rootElem.appendChild(doc.createTextNode('\n'))
	rootElem.appendChild(addressElem)
	addressElem.appendChild(doc.createTextNode('The address of the Recipient'))

	# Add the FromAddress
	addressElem = doc.createElement('FromAddress')
	rootElem.appendChild(doc.createTextNode('\n'))
	rootElem.appendChild(addressElem)
	addressElem.appendChild(doc.createTextNode('The address of the Sender'))

	# Add some text
	textElem = doc.createElement('Text')
	rootElem.appendChild(doc.createTextNode('\n'))
	rootElem.appendChild(textElem)
	textElem.appendChild(doc.createTextNode("""
To whom it may concern, my secret 
credit card number is : 
  0123 4567 89ab cdef

..."""))

	return doc, textElem

def main():
	# Create a blank Document
	impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

	# Create a letter
	doc, toEncrypt = createLetter(impl)

	try:
		# Create the cipher object that we need
		prov   = Santuario.XSECProvider()
		cipher = prov.newCipher(doc)

		# Now generate a random key that we can use to encrypt the element
		#
		# First check the status of the random generation in OpenSSL
		keyBuf = M2Crypto.Rand.rand_bytes(24)

		# Wrap this in a Symmetric 3DES key
		key = Santuario.OpenSSLCryptoSymmetricKey(Santuario.XSECCryptoSymmetricKey.KEY_3DES_192)
		key.setKey(keyBuf)
		cipher.setKey(key)

		# Encrypt the element that needs to be hidden
		cipher.encryptElement(toEncrypt, Santuario.ENCRYPT_3DES_CBC)

		# Now lets create an EncryptedKey element to hold the generated key

		# First lets load the public key in the certificate
		x509 = Santuario.OpenSSLCryptoX509()
		x509.loadX509Base64Bin(cert)

		# Now set the Key Encrypting Key (NOTE: Not the normal key)
		cipher.setKEK(x509.clonePublicKey())

		# Now do the encrypt, using RSA with PKCS 1.5 padding
		encryptedKey = cipher.encryptKey(keyBuf, Santuario.ENCRYPT_RSA_15)

		#
		# Add the encrypted Key to the previously created EncryptedData, which
		# we first retrieve from the cipher object.  This will automatically create
		# the appropriate <KeyInfo> element within the EncryptedData
		#
		encryptedData = cipher.getEncryptedData()
		encryptedData.appendEncryptedKey(encryptedKey)

	except Santuario.XSECException, e:
		print 'An error occurred during an encryption operation\n   Message:', e.getMsg()
		sys.exit(1)

	# Output
	formatter, target = docSetup(doc)
	write(formatter, doc)

	sys.exit(0)

if __name__ == '__main__':
	main()

