#!/usr/bin/python


def rFactorial(n):
    if n < 1:
        return 1
    return n * rFactorial(n-1)

def iFactorial(n):
    result = 1
    for x in range(1, n+1):
        result *= x
    return result

def main():
    factoralRange = 10
    for x in range(0, factoralRange+1):
        print "rFactorial(%d)\t=\t%d" % (x, rFactorial(x))
    for x in range(0, factoralRange+1):
        print "iFactorial(%d)\t=\t%d" % (x, iFactorial(x))


if __name__ == '__main__':
    main()


