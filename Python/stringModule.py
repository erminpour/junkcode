#!/usr/bin/python

import string

def main():
    s = "Open the pod bay doors, HAL."
    print s
    print s.upper()

    ## print string constants
    for n in dir(string):
        if n.startswith('_'):
            continue
        v = getattr(string, n)
        if isinstance(v, basestring):
            print '%s=%s' % (n, repr(v))

if __name__ == "__main__":
    main()

