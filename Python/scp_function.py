#!/usr/bin/env python
"""scp_function.py
   Write a function to scp a file from one host to another.
   Return true if copy is successful, false for any failure.
"""
import sys
import subprocess


__author__ = "Victor Hugo Erminpour"
__license__ = "GPL"
__version__ = "1.0"
__email__ = "victorhugoerminpour@gmail.com"
__status__ = "Prototype"


def scp(source, destination):
    proc = subprocess.Popen(["scp", "-r", source, destination])
    proc.wait()
    return proc.returncode


def main():
    ## parse cmdline
    if len(sys.argv) != 3:
        print "Invalid number of arguments"
        print "Usage: %s <source-file> <dest-file>" % (sys.argv[0])
        sys.exit(1)

    source = sys.argv[1]
    dest = sys.argv[2]

    returnCode = scp(source, dest)

    if returnCode == 0:
        print("File copy SUCCESS.")
    else:
        print("File copy FAILED.")

    return returnCode

if __name__ == "__main__":
    sys.exit(main())
