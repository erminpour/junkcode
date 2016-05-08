#!/usr/bin/python -tt


def mutable():
    print("Mutable list[]:")

    ## declare list
    list_var = []
    print("\tid(list_var) == %s" % id(list_var))

    ## append item to list
    list_var.append("String")
    
    ## Print id, should be the same.
    print("\tlist_var == %s" % list_var)
    print("\tid(list_var) == %s" % id(list_var))


def immutable():
    print("Immutable Integer:")

    ## declare string
    int_var = 42
    print("\tid(int_var) == %s" % id(int_var))

    ## increment by one
    int_var += 1

    ## Print id, should be different.
    print("\tint_var == %s" % int_var)
    print("\tid(int_var) == %s" % id(int_var))


def main():
    mutable()
    immutable()


if __name__ == '__main__':
    main()

