#!/usr/bin/python -tt

def main():
    obj = main
    print("ID\t=\t%s" % id(obj))
    print("CALL\t=\t%s" % ("Yes" if callable(obj) else "No"))

if __name__ == '__main__':
    main()

