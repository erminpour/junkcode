#!/usr/bin/python

import ipaddress

def is_validip(ipaddr):
    ip = ipaddr.split('/')
    if len(ip) == 1:
        ip.insert(1, '32')
    return ip

ipaddr1 =  is_validip('10.0.0.1/24')
ipaddr2 =  is_validip('::1/64')

print "%s/%s" % (ipaddr1[0], ipaddr1[1])
print "%s/%s" % (ipaddr2[0], ipaddr2[1])


