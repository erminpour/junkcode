#!/usr/bin/python -tt


class MyClass(object):
    def normal_method(self, x):
        print "Executing normal_method(%s, %s)" % (self, x)

    @classmethod
    def class_method(cls, x):
        print "Executing class_method(%s, %s)" % (cls, x)

    @staticmethod
    def static_method(x):
        print "Executing static_method(%s)" % (x)

if __name__ == "__main__":
    myClass = MyClass()
    myClass.normal_method(42)
    ## TypeError
    #MyClass.normal_method(5)

    myClass.class_method(42)
    MyClass.class_method(42)

    myClass.static_method(42)
    MyClass.static_method(42)
