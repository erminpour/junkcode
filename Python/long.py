#!/usr/bin/python -tt

import sys


def main():
    ## set int_var to max int number
    int_var = sys.maxint 
    print("int_var == %d\ntype == %s" % (int_var, type(int_var)))

    ## increment by one, promoted to long
    int_var += 1
    print("int_var == %d\ntype == %s" % (int_var, type(int_var)))


if __name__ == '__main__':
    main()

