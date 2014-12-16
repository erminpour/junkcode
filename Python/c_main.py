#!/usr/bin/python


def main():
    print "Inside the %s module." % (__name__)

if __name__ == '__main__':
    print "Called from command line."
    main()
