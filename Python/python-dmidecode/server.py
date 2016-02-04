#!/usr/bin/python -tt
import dmidecode

#['DMIXML_DOC', 'DMIXML_NODE', 'QuerySection', 'QueryTypeId', '__builtins__', '__doc__', '__file__', '__name__', '__package__', 'baseboard', 'bios', 'cache', 'chassis', 'clear_warnings', 'connector', 'dmi', 'dmidecodeXML', 'dump', 'get_dev', 'get_warnings', 'libxml2', 'memory', 'options', 'processor', 'pythonmap', 'set_dev', 'slot', 'system', 'type', 'version', 'xmlapi']


biosDict = {}
biosDict = dmidecode.bios()
#print dmidecode.bios()
print biosDict['0x0000']['data']
print "Vendor: " + biosDict['0x0000']['data']['Vendor']

