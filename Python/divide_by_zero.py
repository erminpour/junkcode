#!/usr/bin/python


def divide_numbers(x, y):
    z = x / y


def divide_numbers_exception(x, y):
    try:
        divide_numbers(x, y)
    except ZeroDivisionError, errno:
        print "ERROR: %s" % errno

if __name__ == "__main__":
    divide_numbers_exception(1, 0)
    divide_numbers(1, 0)
