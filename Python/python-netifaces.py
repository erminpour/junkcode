#!/usr/bin/python -tt


import netifaces as nif
#print dir(nif)


def show_interfaces():
    for NIC in nif.interfaces():
        print "\n" + NIC + ": "
        #print nif.ifaddresses(NIC)
        #print nif.ifaddresses(NIC)[nif.AF_LINK]
        #print nif.AF_LINK
        #print nif.ifaddresses(NIX)[nif.AF_INET]
        #print nif.AF_INET
        print "IPADDR=" + \
            nif.ifaddresses(NIC)[nif.AF_INET][0]['addr']
        print "NETMASK=" + \
            nif.ifaddresses(NIC)[nif.AF_INET][0]['netmask']
        print "MACADDR=" + \
            nif.ifaddresses(NIC)[nif.AF_LINK][0]['addr']


def main():
    show_interfaces()

if __name__ == '__main__':
    main()
