#!/usr/bin/python

##
## Java style getter/setter
def java_getter_setter():
    class Foo(object):
        __var = None
        def __init__(self, var):
            self.__var = var

        def get_var(self):
            return self.__var

        def set_var(self, var):
            self.__var = var

    java_style = Foo('42')
    print java_style.get_var()
    java_style.set_var('number 9')
    print java_style.get_var()
    print type(java_style)

    ##
    ## Throws AttributeError
    try:
        print java_style.__var
    except AttributeError:
        print 'caught "java_style.__var" AttributeError'

##
## Python @property
def python_property():
    class Bar(object):
        #var = None
        __var = None

        @property
        def var(self):
            return self.__var

        @var.setter
        def var(self, var):
            self.__var = var

    py_prop = Bar()
    py_prop.var = '42'
    print py_prop.var
    py_prop.var = 'number 9'
    print py_prop.var
    print type(py_prop)

    ##
    ## Throws AttributeError
    try:
        print py_prop.__var
    except AttributeError:
        print 'caught "py_prop.__var" AttributeError'


def main():
    java_getter_setter()
    python_property()

if __name__ == '__main__':
    main()

