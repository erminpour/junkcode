#!/usr/bin/python -tt

print issubclass(list, object);

def func():
    pass

print func.__class__
print issubclass(func.__class__, object);


