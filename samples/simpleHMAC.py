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
from Santuario import CANON_C14N_COM, SIGNATURE_HMAC, HASH_SHA1

from IOStreamOutputter import docSetup, write

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
To whom it may concern

...
"""))

	return doc

def main():
	# Create a blank Document
	impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

	# Create a letter
	doc = createLetter(impl)
	rootElem = doc.getDocumentElement()

	# The signature
	prov = Santuario.XSECProvider()

	try:
		# Create a signature object
		sig = prov.newSignature()
		sig.setDSIGNSPrefix('ds')

		# Use it to create a blank signature DOM structure from the doc
		sigNode = sig.createBlankSignature(doc, CANON_C14N_COM, SIGNATURE_HMAC, HASH_SHA1)

		# Inser the signature DOM nodes into the doc
		rootElem.appendChild(doc.createTextNode('\n'))
		rootElem.appendChild(sigNode)
		rootElem.appendChild(doc.createTextNode('\n'))

		# Create an envelope reference for the text to be signed
		ref = sig.createReference('')
		ref.appendEnvelopedSignatureTransform()

		# Set the HMAC Key to be the string "secret"
		hmacKey = Santuario.OpenSSLCryptoKeyHMAC()
		hmacKey.setKey("secret")
		sig.setSigningKey(hmacKey)

		# Add a KeyInfo element
		sig.appendKeyName('The secret key is "secret"')

		# Sign
		sig.sign()

	except Santuario.XSECException, e:
		print 'An error occured during a signature load\n   Message:', e.getMsg()
		sys.exit(1)

	# Output
	formatter, target = docSetup(doc)
	write(formatter, doc)

	sys.exit(0)

if __name__ == '__main__':
	main()

