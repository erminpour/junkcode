#!/usr/bin/python

class Foo(object):
    name = None   ## Public
    _name = None  ## Protected
    __name = None ## Private

def main():
    my_foo = Foo()

    ## Public
    print my_foo.name
    my_foo.name = "Public"
    print my_foo.name

    ## Protected (Bad form, use @propery)
    print my_foo._name
    my_foo._name = "Protected"
    print my_foo._name

    ## Mangled name for Foo.__name is Foo._Foo__name
    print my_foo._Foo__name

    ## Throws AttributeError
    try:
        print my_foo.__name
    except AttributeError:
        print 'Caught "AttributeError", use @property.'
        my_foo._Foo__name = 'Private'
        print my_foo._Foo__name
        print dir(my_foo)

if __name__ == '__main__':
    main()

