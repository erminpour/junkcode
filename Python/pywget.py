#!/usr/bin/env python

import sys
import urllib2

def pywget(urlstr, fname):
    response = urllib2.urlopen(urlstr)
    f = open(fname, "w")
    f.write(response.read())
    f.close()
    print "written " + fname

if __name__ == '__main__':
    urlstr = sys.argv[1]
    fname = urlstr.split('/')[-1]
    pywget(urlstr, fname)

