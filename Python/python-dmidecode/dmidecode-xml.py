#!/usr/bin/python

import dmidecode

def main():
    dmixml = dmidecode.dmidecodeXML()
    dmixml.SetResultType(dmidecode.DMIXML_DOC) # DMIXML_DOC, DMIXML_NODE
    xmldoc = dmixml.QuerySection('all')

    # Do some XPath queries on the XML document
    print "Performing XPath queries against XML document."
    dmixp = xmldoc.xpathNewContext()

    # What to look for - XPath expressions
    keys = ['/dmidecode/SystemInfo/Manufacturer',
            '/dmidecode/SystemInfo/ProductName',
            '/dmidecode/SystemInfo/SystemUUID']

    # Extract data and print
    for k in keys:
        data = dmixp.xpathEval(k)
        for d in data:
            print "%s: %s" % (k, d.get_content())

if __name__ == '__main__':
    main()

