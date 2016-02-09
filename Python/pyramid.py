#!/usr/bin/python
from __future__ import print_function


def buildPyramid(n):
    for x in range(0, n):
        print ('X', end="")
        for y in range(0, n):
            print ('X', end="")
        print ('\n', end="")


def buildHalfPyramid(n):
    for x in range(0, n):
        print ('X', end="")
        for y in range(0, n):
            if y < x: 
                print ('X', end="")
        print ('\n', end="")


def main():
    pyramidSize = 10
    buildPyramid(pyramidSize)
    buildHalfPyramid(pyramidSize)

if __name__ == '__main__':
    main()

