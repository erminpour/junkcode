#!/usr/bin/python -tt

from __future__ import print_function
import sys
import libvirt
assert(libvirt.getVersion() >= 9004) # 0.9.4

def listVmUp(conn):
    for id in conn.listDomainsID():
        dom = conn.lookupByID(id)
        print ("%s\t\"UP\"" % dom.name())

def listVmDown(conn):
    for name in conn.listDefinedDomains():
        dom = conn.lookupByName(name)
        print ("%s\t\"DOWN\"" % dom.name())

def main():
    uri = "qemu:///system"
    #uri = "qemu+ssh://victorhugo@127.0.0.1/system"

    conn = libvirt.openReadOnly(uri)
    if conn == None:
        print('Failed to connect to %s" % uri', file=sys.stderr)
        sys.exit(1)

    remote_name = conn.getHostname()
    print("HOST : %s" % remote_name)
    listVmUp(conn)
    listVmDown(conn)
    return 0

if __name__ == '__main__':
    sys.exit(main())
