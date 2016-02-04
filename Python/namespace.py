#!/usr/bin/python -tt

var = "I'm a global String"
def foo():
    var = "I'm a String"
    print locals()
    print var

print globals()
foo()


