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

letter = '''
<Letter>
<ToAddress>The address of the Recipient</ToAddress>
<FromAddress>The address of the Sender</FromAddress>
<xenc:EncryptedData Type="http://www.w3.org/2001/04/xmlenc#Element" xmlns:xenc="http://www.w3.org/2001/04/xmlenc#">
<xenc:EncryptionMethod Algorithm="http://www.w3.org/2001/04/xmlenc#tripledes-cbc"/>
<ds:KeyInfo xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
<xenc:EncryptedKey xmlns:xenc="http://www.w3.org/2001/04/xmlenc#">
<xenc:EncryptionMethod Algorithm="http://www.w3.org/2001/04/xmlenc#rsa-1_5"/>
<xenc:CipherData>
<xenc:CipherValue>UDH9I9k6dRvlIS7fHLMONtlP24mqEDPzsjSYUg4X5SSzUFskiVaOIzhYPeF21ZeG
MCmdo6wsu6TQB0XebmvJR2wgvYqDd2L2IbXZ1zj2/G7FbVsB/GSGxuQTFw22aMFd
l47P8bKjxX8cUwwYFzbGAUfkgeQp5DglmnJYJPO1cTw=
</xenc:CipherValue>
</xenc:CipherData>
</xenc:EncryptedKey>
</ds:KeyInfo>
<xenc:CipherData>
<xenc:CipherValue>Q7M6QhZOqjyYXdUDOw809dGEJWkyAygRv7r3EJ8FlcY7dYpn78ON79N/ZB5wJxQt
koyHvWimPWkNRlKGP10DJ42PIGDvuTnTBFHCKbvaMrEjkll8PUd8zHQ0OJIaWIYi
AKydplJy2rCzppwn0bI0YQ==
</xenc:CipherValue>
</xenc:CipherData>
</xenc:EncryptedData></Letter>'''

# PKCS8 PEM encoded PrivateKey structure (not Encrypted)
s_privateKey = '''
-----BEGIN RSA PRIVATE KEY-----
MIICXAIBAAKBgQDQj3pktZckAzwshRnfvLhz3daNU6xpAzoHo3qjCftxDwH1RynP
A5eycJVkV8mwH2C1PFktpjtQTZ2CvPjuKmUV5zEvmYzuIo6SWYaVZN/PJjzsEZMa
VA+U8GhfX1YF/rsuFzXCi8r6FVd3LN//pXHEwoDGdJUdlpdVEuX1iFKlNQIDAQAB
AoGAYQ7Uc7e6Xa0PvNw4XVHzOSC870pISxqQT+u5b9R+anAEhkQW5dsTJpyUOX1N
RCRmGhG6oq7gnY9xRN1yr0uVfJNtc9/HnzJL7L1jeJC8Ub+zbEBvNuPDL2P21ArW
tcXRycUlfRCRBLop7rfOYPXsjtboAGnQY/6hK4rOF4XGrQUCQQD3Euj+0mZqRRZ4
M1yN2wVP0mKOMg2i/HZXaNeVd9X/wyBgK6b7BxHf6onf/mIBWnJnRBlvdCrSdhuT
lPKEoSgvAkEA2BhfWwQihqD4qJcV65nfosjzOZG41rHX69nIqHI7Ejx5ZgeQByH9
Ym96yXoSpZj9ZlFsJYNogTBBnUBjs+jL2wJAFjpVS9eR7y2X/+hfA0QZDj1XMIPA
RlGANAzymDfXwNLFLuG+fAb+zK5FCSnRl12TvUabIzPIRnbptDVKPDRjcQJBALn8
0CVv+59P8HR6BR3QRBDBT8Xey+3NB4Aw42lHV9wsPHg6ThY1hPYx6MZ70IzCjmZ/
8cqfvVRjijWj86wm0z0CQFKfRfBRraOZqfmOiAB4+ILhbJwKBBO6avX9TPgMYkyN
mWKCxS+9fPiy1iI+G+B9xkw2gJ9i8P81t7fsOvdTDFA=
-----END RSA PRIVATE KEY-----'''

def main():
	# Use xerces to parse the document
	parser = Xerces.XercesDOMParser()
	parser.setDoNamespaces(True)
	parser.setCreateEntityReferenceNodes(True)
	parser.setDoSchema(True)

	# Create an input source

	memIS = Xerces.MemBufInputSource(letter, 'XSECMem')

	parser.parse(memIS)
	errorCount = parser.getErrorCount()
	if errorCount > 0:
		print 'Error parsing input document'
		sys.exit(1)

	doc = parser.getDocument()

	# Decrypt Operations

	try:
		# Create the cipher object that we need
		prov   = Santuario.XSECProvider()
		cipher = prov.newCipher(doc)

		# Load the private key via OpenSSL and then wrap in an OpenSSLCrypto construct
		pk = Santuario.OpenSSL.load_PEM_PrivateKey(s_privateKey)

		# NOTE : For simplicity - no error checking here
		k = Santuario.OpenSSLCryptoKeyRSA(pk)
		cipher.setKEK(k)

		# Find the EncryptedData node
		encryptedNode = Santuario.findXENCNode(doc, 'EncryptedData')

		# Do the decrypt
		cipher.decryptElement(encryptedNode.toDOMElement())

	except Santuario.XSECException, e:
		print 'An error occurred during an encryption operation\n   Message:', e.getMsg()
		sys.exit(1)

	# Output
	formatter, target = docSetup(doc)
	write(formatter, doc)

	sys.exit(0)
	

if __name__ == '__main__':
	main()

