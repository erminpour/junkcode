#!/usr/bin/python

def outer_func():
    x = 42
    def inner():
        print x
        print locals()

    return inner

foo = outer_func()
foo()

