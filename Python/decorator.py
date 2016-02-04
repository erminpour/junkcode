#!/usr/bin/python -tt

def print_greeting(name):
    return "Hello %s" % name

def ptag_decorate(func):
    def func_wrapper(name):
        return "<p>%s</p>" % func(name)
    return func_wrapper

def btag_decorate(func):
    def func_wrapper(name):
        return "<b>%s</b>" % func(name)
    return func_wrapper

myfunc = ptag_decorate(print_greeting)
print myfunc("Victor");

myfunc = ptag_decorate(btag_decorate(print_greeting))
print myfunc("Victor");

myfunc = print_greeting
print myfunc("Victor");

