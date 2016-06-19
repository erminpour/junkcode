#!/usr/bin/python

def fizz_buzz():
    for x in range(1, 101):
        if x % 3 == 0 and x % 5 == 0:
            print "FizzBuzz"
            continue
        elif x % 3 == 0:
            print "Fizz"
            continue
        elif x % 5 == 0:
            print "Buzz"
            continue
        print x

def main():
    fizz_buzz()

if __name__ == '__main__':
    main()


