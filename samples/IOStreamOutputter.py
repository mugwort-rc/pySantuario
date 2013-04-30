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
import Xerces
from Xerces.util.XMLUniDefs import *

# ---------------------------------------------------------------------------
#           Much code taken from the DOMPrint Xerces example
# ---------------------------------------------------------------------------

gUnRepFlags   = Xerces.XMLFormatter.UnRep_CharRef

gEndElement   = Xerces.XMLString([ chOpenAngle, chForwardSlash, chNull ])
gEndPI = Xerces.XMLString([ chQuestion, chCloseAngle, chNull])
gStartPI = Xerces.XMLString([ chOpenAngle, chQuestion, chNull ])
gXMLDecl1 = Xerces.XMLString([
        chOpenAngle, chQuestion, chLatin_x, chLatin_m, chLatin_l
    ,   chSpace, chLatin_v, chLatin_e, chLatin_r, chLatin_s, chLatin_i
    ,   chLatin_o, chLatin_n, chEqual, chDoubleQuote, chNull
])
gXMLDecl2 = Xerces.XMLString([
        chDoubleQuote, chSpace, chLatin_e, chLatin_n, chLatin_c
    ,   chLatin_o, chLatin_d, chLatin_i, chLatin_n, chLatin_g, chEqual
    ,   chDoubleQuote, chNull
])
gXMLDecl3 = Xerces.XMLString([
        chDoubleQuote, chSpace, chLatin_s, chLatin_t, chLatin_a
    ,   chLatin_n, chLatin_d, chLatin_a, chLatin_l, chLatin_o
    ,   chLatin_n, chLatin_e, chEqual, chDoubleQuote, chNull
])
gXMLDecl4 = Xerces.XMLString([
        chDoubleQuote, chQuestion, chCloseAngle
    ,   chLF, chNull
])

gStartCDATA = Xerces.XMLString([
        chOpenAngle, chBang, chOpenSquare, chLatin_C, chLatin_D,
        chLatin_A, chLatin_T, chLatin_A, chOpenSquare, chNull
])

gEndCDATA = Xerces.XMLString([
    chCloseSquare, chCloseSquare, chCloseAngle, chNull
])
gStartComment = Xerces.XMLString([
    chOpenAngle, chBang, chDash, chDash, chNull
])

gEndComment = Xerces.XMLString([
    chDash, chDash, chCloseAngle, chNull
])

gStartDoctype = Xerces.XMLString([
    chOpenAngle, chBang, chLatin_D, chLatin_O, chLatin_C, chLatin_T,
    chLatin_Y, chLatin_P, chLatin_E, chSpace, chNull
])
gPublic = Xerces.XMLString([
    chLatin_P, chLatin_U, chLatin_B, chLatin_L, chLatin_I,
    chLatin_C, chSpace, chDoubleQuote, chNull
])
gSystem = Xerces.XMLString([
    chLatin_S, chLatin_Y, chLatin_S, chLatin_T, chLatin_E,
    chLatin_M, chSpace, chDoubleQuote, chNull
])
gStartEntity = Xerces.XMLString([
    chOpenAngle, chBang, chLatin_E, chLatin_N, chLatin_T, chLatin_I,
    chLatin_T, chLatin_Y, chSpace, chNull
])
gNotation = Xerces.XMLString([
    chLatin_N, chLatin_D, chLatin_A, chLatin_T, chLatin_A,
    chSpace, chDoubleQuote, chNull
])

# ---------------------------------------------------------------------------
# Local classes
# ---------------------------------------------------------------------------

class DOMPrintFormatTarget(Xerces.XMLFormatTarget):
    def writeChars(self, toWrite, count, formatter):
        sys.stdout.write(toWrite)

# ---------------------------------------------------------------------------
#  ostream << DOMNode
#
#  Stream out a DOM node, and, recursively, all of its children. This
#  function is the heart of writing a DOM tree out as XML source. Give it
#  a document node and it will do the whole thing.
# ---------------------------------------------------------------------------
def write(formatter, toWrite):
    # Get the name and value out for convenience
    nodeName  = toWrite.getNodeName()
    nodeValue = toWrite.getNodeValue()
    lent      = len(nodeValue)

    nodeType = toWrite.getNodeType()
    if nodeType == Xerces.DOMNode.TEXT_NODE:
        formatter.formatBuf(nodeValue, lent, Xerces.XMLFormatter.CharEscapes)

    elif nodeType == Xerces.DOMNode.PROCESSING_INSTRUCTION_NODE:
        formatter << Xerces.XMLFormatter.NoEscapes << gStartPI  << nodeName
        if lent > 0:
            formatter << chSpace << nodeValue
        formatter << Xerces.XMLFormatter.NoEscapes << gEndPI

    elif nodeType == Xerces.DOMNode.DOCUMENT_NODE:
        child = toWrite.getFirstChild()
        while child is not None:
            write(formatter, child)
            # add linefeed in requested output encoding
            formatter << chLF
            sys.stdout.flush()
            child = child.getNextSibling()

    elif nodeType == Xerces.DOMNode.ELEMENT_NODE:
        # The name has to be representable without any escapes
        formatter  << Xerces.XMLFormatter.NoEscapes << chOpenAngle << nodeName

        # Output the element start tag.

        # Output any attributes on this element
        attributes = toWrite.getAttributes()
        attrCount = attributes.getLength()
        for i in range(attrCount):
            attribute = attributes.item(i)

            #
            # Again the name has to be completely representable. But the
            # attribute can have refs and requires the attribute style
            # escaping.
            #
            formatter  << Xerces.XMLFormatter.NoEscapes << chSpace << attribute.getNodeName() << chEqual << chDoubleQuote << Xerces.XMLFormatter.AttrEscapes << attribute.getNodeValue() << Xerces.XMLFormatter.NoEscapes << chDoubleQuote

        #
        # Test for the presence of children, which includes both
        # text content and nested elements.
        #
        child = toWrite.getFirstChild()
        if child is not None:
            # There are children. Close start-tag, and output children.
            # No escapes are legal here
            formatter << Xerces.XMLFormatter.NoEscapes << chCloseAngle
            while child is not None:
                write(formatter, child)
                child = child.getNextSibling()

            #
            # Done with children.  Output the end tag.
            #
            formatter << Xerces.XMLFormatter.NoEscapes << gEndElement << nodeName << chCloseAngle
        else:
            #
            # There were no children. Output the short form close of
            # the element start tag, making it an empty-element tag.
            #
            formatter << Xerces.XMLFormatter.NoEscapes << chForwardSlash << chCloseAngle

    elif nodeType == Xerces.DOMNode.ENTITY_REFERENCE_NODE:
        formatter << Xerces.XMLFormatter.NoEscapes << chAmpersand << nodeName << chSemiColon

    elif nodeType == Xerces.DOMNode.CDATA_SECTION_NODE:
        formatter << Xerces.XMLFormatter.NoEscapes << gStartCDATA << nodeValue << gEndCDATA

    elif nodeType == Xerces.DOMNode.COMMENT_NODE:
        formatter << Xerces.XMLFormatter.NoEscapes << gStartComment << nodeValue << gEndComment

    elif nodeType == Xerces.DOMNode.DOCUMENT_TYPE_NODE:
        doctype = toWrite.toDOMDocumentType()
        formatter << Xerces.XMLFormatter.NoEscapes  << gStartDoctype << nodeName
        id = doctype.getPublicId()
        if str(id):
            formatter << Xerces.XMLFormatter.NoEscapes << chSpace << gPublic << id << chDoubleQuote
            id = doctype.getSystemId()
            if str(id):
                formatter << Xerces.XMLFormatter.NoEscapes << chSpace << chDoubleQuote << id << chDoubleQuote
        else:
            id = doctype.getSystemId()
            if str(id):
                formatter << Xerces.XMLFormatter.NoEscapes << chSpace << gSystem << id << chDoubleQuote

        id = doctype.getInternalSubset()
        if str(id):
            formatter << Xerces.XMLFormatter.NoEscapes << chOpenSquare << id << chCloseSquare
        formatter << Xerces.XMLFormatter.NoEscapes << chCloseAngle

    elif nodeType == Xerces.DOMNode.ENTITY_NODE:
        formatter << Xerces.XMLFormatter.NoEscapes << gStartEntity << nodeName
        id = toWrite.toDOMEntity().getPublicId()
        if str(id):
            formatter << Xerces.XMLFormatter.NoEscapes << gPublic << id << chDoubleQuote
        id = toWrite.toDOMEntity().getSystemId()
        if str(id):
            formatter << Xerces.XMLFormatter.NoEscapes << gSystem << id << chDoubleQuote
        id = toWrite.toDOMEntity().getNotationName()
        if str(id):
            formatter << Xerces.XMLFormatter.NoEscapes << gNotation << id << chDoubleQuote
        formatter << Xerces.XMLFormatter.NoEscapes << chCloseAngle << chLF

    else:
        sys.stderr.write('Unrecognized node type = %d\n'%toWrite.getNodeType())

# ---------------------------------------------------------------------------
#           End of outputter
# ---------------------------------------------------------------------------

class DOMMemFormatTarget(Xerces.XMLFormatTarget):
    def __init__(self):
        Xerces.XMLFormatTarget.__init__(self)
        self.buffer = ''

    def setBuffer(self, toSet):
        self.buffer = toSet

    # -----------------------------------------------------------------------
    # Implementations of the format target interface
    # -----------------------------------------------------------------------
    def writeChars(self, toWrite, count, formatter):
        self.buffer = toWrite

def docSetup(doc):
    # Print out the doc
    formatTarget = DOMPrintFormatTarget()
    return Xerces.XMLFormatter('UTF-8', '', formatTarget, Xerces.XMLFormatter.NoEscapes, gUnRepFlags), formatTarget

# ---------------------------------------------------------------------------
#           End of outputter
# ---------------------------------------------------------------------------
