# pySantuario

## Build

	$ python setup.py build

### Require lib
boost-python / [xml-security-c 1.7.0](http://santuario.apache.org/)  

[pyXerces](https://github.com/mugwort-rc/pyXerces) / M2Crypto  

### Optional lib
[pyXQilla](https://github.com/mugwort-rc/pyXQilla)

## Usage

	import Xerces
	import XQilla  # optional
	import Santuario

### XML Encryption
See samples/simpleEncrypt.py

### XML Decryption
See samples/simpleDecrypt.py

### XML Digital Signature
#### HMAC
See samples/simpleHMAC.py
