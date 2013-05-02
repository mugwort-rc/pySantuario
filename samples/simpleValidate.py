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

from IOStreamOutputter import docSetup, write

docToValidate = '''<PurchaseOrder>
<Company>Widgets.Org</Company>
<Product>A large widget</Product>
<Amount>$16.50</Amount>
<Due>16 January 2010</Due>
<ds:Signature xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
<ds:SignedInfo>
<ds:CanonicalizationMethod Algorithm="http://www.w3.org/TR/2001/REC-xml-c14n-20010315"/>
<ds:SignatureMethod Algorithm="http://www.w3.org/2000/09/xmldsig#dsa-sha1"/>
<ds:Reference URI="#xpointer(/)">
<ds:Transforms>
<ds:Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"/>
<ds:Transform Algorithm="http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments"/>
</ds:Transforms>
<ds:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha1"/>
<ds:DigestValue>n+6y945h/SvlVF9qBq+Lb4TrcOI=</ds:DigestValue>
</ds:Reference>
</ds:SignedInfo>
<ds:SignatureValue>OmToLo8uEnK37nCFXDiZwgcsZGJ0aZ4AyECUy78DL91AHRRWdjllSQ==</ds:SignatureValue>
<ds:KeyInfo>
<ds:X509Data>
<ds:X509SubjectName>C=AU, ST=Vic, O=XML-Security-C Project, CN=Samples Demo Certificate</ds:X509SubjectName>
</ds:X509Data>
</ds:KeyInfo>
</ds:Signature>
</PurchaseOrder>
'''

cert = '''
MIIEETCCA9GgAwIBAgICEAEwCQYHKoZIzjgEAzB5MQswCQYDVQQGEwJBVTEMMAoG
A1UECBMDVmljMRIwEAYDVQQHEwlNZWxib3VybmUxHzAdBgNVBAoTFlhNTC1TZWN1
cml0eS1DIFByb2plY3QxEDAOBgNVBAsTB1hTRUMtQ0ExFTATBgNVBAMTDFhTRUMt
Q0EgUm9vdDAeFw0wMjExMDUwMzE1NDFaFw0wMzExMDUwMzE1NDFaMF8xCzAJBgNV
BAYTAkFVMQwwCgYDVQQIEwNWaWMxHzAdBgNVBAoTFlhNTC1TZWN1cml0eS1DIFBy
b2plY3QxITAfBgNVBAMTGFNhbXBsZXMgRGVtbyBDZXJ0aWZpY2F0ZTCCAbgwggEs
BgcqhkjOOAQBMIIBHwKBgQDj1jBku/y6COfkxmHMLS1behxr3ah8sFAk71EyuXLy
2Ony989WUc52/5M3nNY9E/75KB3uKNcrnGY8Tfw85Wrehv7jSImCuxljtnomABTj
9LBuGL9TfYBNBJI/0jNR0GOo0kQphoKFOvldtRIwRmtU5Mcamg9e5FOEjYJCSah5
rwIVAOzWxorDrF4uwMIC/ss6PfibdNgHAoGBANLAOsJjpBQx43DgnNSkVJ518Tqz
IHKpg9crAsCRd+Keipt/tVnOTA29uJZMo2wUSGC8Vj7tlreMJtxDUnLcRdX6EZwj
WR9nBhLpzClndctjjLF5IkzCechQk7CNKmO2Z2gaD6K/hdfMixF/LH/1iHeYjTNZ
vAhcExd1PRpV0207A4GFAAKBgQDNS3VPzSAL+I71/0EneTxLIyvAlROjnLVDd5LT
vEAorjepo8v5/qgXNK4O32NlNZxSOD612Mr1Q8sLYDnx006t8x01A7St8f/jcd9y
dIIomKMEs2hwahHt8p/jFdRJNXFFe4gQ2DM2cKRhZTEuL9qpv2AnPIIlGqnrlo1L
o4gDb6OCAQEwgf4wCQYDVR0TBAIwADAsBglghkgBhvhCAQ0EHxYdT3BlblNTTCBH
ZW5lcmF0ZWQgQ2VydGlmaWNhdGUwHQYDVR0OBBYEFA7Em1VK6/7qc88l7n8JnIOT
QEArMIGjBgNVHSMEgZswgZiAFBKNX9CsAIsjUIFmVq4wE4wlOGC5oX2kezB5MQsw
CQYDVQQGEwJBVTEMMAoGA1UECBMDVmljMRIwEAYDVQQHEwlNZWxib3VybmUxHzAd
BgNVBAoTFlhNTC1TZWN1cml0eS1DIFByb2plY3QxEDAOBgNVBAsTB1hTRUMtQ0Ex
FTATBgNVBAMTDFhTRUMtQ0EgUm9vdIIBADAJBgcqhkjOOAQDAy8AMCwCFDA7nNZe
C6gSs+N7RRq7vLmx/IjjAhRJvfPZ/hvoN8fNpTmRoHtuzkSjcQ=='''

def main():
	# Use xerces to parse the document
	parser = Xerces.XercesDOMParser()
	parser.setDoNamespaces(True)
	parser.setCreateEntityReferenceNodes(True)
	parser.setDoSchema(True)
	
	# Create an input source
	memIS = Xerces.MemBufInputSource(docToValidate, 'XSECMem')

	parser.parse(memIS)
	errorCount = parser.getErrorCount()
	if errorCount > 0:
		print 'Error parsing input document'
		sys.exit(1)

	doc = parser.getDocument()

	# Find the Amount node
	amt = doc.getDocumentElement()

	if amt is not None:
		amt = amt.getFirstChild()

	while amt is not None and (amt.getNodeType() != Xerces.DOMNode.ELEMENT_NODE or amt.getNodeName() != 'Amount'):
		amt = amt.getNextSibling()

	if amt is not None:
		amt = amt.getFirstChild()

	if amt is None or amt.getNodeType() != Xerces.DOMNode.TEXT_NODE:
		print 'Error finding amount in purchase order'
		sys.exit(1)

	formatter, target = docSetup(doc)

	# Now create a signature object to validate the document
	prov = Santuario.XSECProvider()
	sig = prov.newSignatureFromDOM(doc)

	try:
		# Use the OpenSSL interface objects to get a signing key
		x509 = Santuario.OpenSSLCryptoX509()
		x509.loadX509Base64Bin(cert)

		sig.load()
		kinfList = sig.getKeyInfoList()

		# See if we can find a Key Name
		size = kinfList.getSize()

		for i in range(size):
			kname = kinfList.item(i).getKeyName()
			if kname is not None:
				print 'Key Name =', kname

		sig.setSigningKey(x509.clonePublicKey())

		sys.stdout.write('Amount = ')
		write(formatter, amt)
		sys.stdout.write(' -> ')

		if sig.verify():
			sys.stdout.write('Signature Valid\n')
		else:
			sys.stdout.write('Incorrect Signature\n')
			print sig.getErrMsgs()

		amt.setNodeValue('$0.50')

		sys.stdout.write('Amount = ')
		write(formatter, amt)
		sys.stdout.write(' -> ')

		if sig.verify():
			sys.stdout.write('Signature Valid\n')
		else:
			sys.stdout.write('Incorrect Signature\n')
			print sig.getErrMsgs()

		amt.setNodeValue('$16.50')

		sys.stdout.write('Amount = ')
		write(formatter, amt)
		sys.stdout.write(' -> ')

		if sig.verify():
			sys.stdout.write('Signature Valid\n')
		else:
			sys.stdout.write('Incorrect Signature\n')
			print sig.getErrMsgs()

	except Santuario.XSECException, e:
		print 'An error occured during a signature load\n   Message:', e.getMsg()
		sys.exit(1)

	except Santuario.XSECCryptoException, e:
		print 'An error occured in the XML-Security-C Crypto routines\n   Message:', e.getMsg()
		sys.exit(1)

	sys.exit(0)

if __name__ == '__main__':
	main()

