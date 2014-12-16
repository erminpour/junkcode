#!/usr/bin/python -tt

import sys


def main():
    print "Name of this program: %s" % (sys.argv[0])
    print "Number of arguments: %d" % (len(sys.argv))
    print "Arguments: %s" % (str(sys.argv))

if __name__ == "__main__":
    main()
