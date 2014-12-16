#!/usr/bin/python

import platform

def explore():
    for n in dir(platform):
        if n.startswith('_'):
            continue
        v = getattr(platform, n)
        if hasattr(v, '__call__'):
            try:
                print '%s = %s' % (n, v())
            except TypeError:
                #print '%s = ***TypeError***' % (n)
                continue

def platformHardwareOS():
    print 'uname        :', platform.uname()
    print
    print 'system       :', platform.system()
    print 'node         :', platform.node()
    print 'release      :', platform.release()
    print 'version      :', platform.version()
    print 'machine      :', platform.machine()
    print 'processor    :', platform.processor()


def platformIdentifier():
    print 'Normal       :', platform.platform()
    print 'Aliased      :', platform.platform(aliased=True)
    print 'Terse        :', platform.platform(terse=True)

def platformPython():
    print 'Version      :', platform.python_version()
    print 'Version tuple:', platform.python_version_tuple()
    print 'Compiler     :', platform.python_compiler()
    print 'Build        :', platform.python_build()

def main():
    #platformPython()
    #platformIdentifier()
    #platformHardwareOS()
    explore()

if __name__ == "__main__":
    main() 

