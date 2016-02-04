#!/usr/bin/python

import optparse
import re

xmlstring = """<interface type="bond" name="bond0">
  <start mode="onboot"/>
  <protocol family="ipv4">
    <ip address="%IPADDR%" prefix="%PREFIX%"/>
    <route gateway="%GATEWAY%"/>
  </protocol>
  <bond mode="active-backup">
    <miimon freq="100" updelay="10" carrier="ioctl"/>
    <interface type="ethernet" name="%IFACE1%"/>
    <interface type="ethernet" name="%IFACE2%"/>
  </bond>
</interface>"""


def main():
    ipaddr = "10.0.0.42"
    prefix = "24"
    gw = "10.0.0.1"
    iface1 = "eth1"
    iface2 = "eth2"

    substitutions = {'IPADDR': ipaddr, 'PREFIX' : prefix, \
                     'GATEWAY' : gw, 'IFACE1' : iface1, 'IFACE2' : iface2 }
    pattern = re.compile(r'%([^%]+)%')
    global xmlstring
    xmlstring = re.sub(pattern, lambda m: substitutions[m.group(1)], xmlstring)
    print xmlstring

if __name__ == '__main__':
    main()



