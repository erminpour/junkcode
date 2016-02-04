#!/usr/bin/python -tt


def add(x, y):
    return x+y
def sub(x, y):
    return x-y
def mul(x, y):
    return x*y
def div(x, y):
    return x/y

def applyCalc(func, x, y):
    return func(x, y)

print applyCalc(add, 1, 12);
print applyCalc(sub, 2, 12);
print applyCalc(mul, 3, 12);
print applyCalc(div, 0, 12);



