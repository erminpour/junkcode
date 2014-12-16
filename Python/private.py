#!/usr/bin/python -tt


class Foo:
    def public(self):
        print "You can see me."

    def __private(self):
        print "You can't see me."

if __name__ == "__main__":
    f = Foo()
    f.public()
    ## Attribute error
    ## f.__private()

    ## Python mangles private members
    ## from "__function()" to "_ClassName__function()"
    f._Foo__private()
