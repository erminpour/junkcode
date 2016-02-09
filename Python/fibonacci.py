#!/usr/bin/python


##
## Recursive Fibonacci sequence.
def rFibonacci(n):
    if n < 2:
        return n
    return (rFibonacci(n-1) + rFibonacci(n-2))

##
## Iterative Fibonacci sequence.
def iFibonacci(n):
    var1 = 0
    var2 = 1
    for x in range(0, n):
        temp = var1
        var1 = var2
        var2 = temp + var2
    return var1


def main():
    fibRange = 10
    print "Recursive Fibonacci:"
    for x in range(0,fibRange+1):
        print "rFibonacci(%d)\t=\t%s" % (x, rFibonacci(x))
    print "Iterative Fibonacci:"
    for x in range(0,fibRange+1):
        print "iFibonacci(%d)\t=\t%s" % (x, iFibonacci(x))

if __name__ == '__main__':
    main()

