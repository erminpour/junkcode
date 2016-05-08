#!/usr/bin/python -tt


def interrogate(obj):
    """Interogate object."""
    if hasattr(obj, '__name__'):
        print("NAME\t=\t%s" % obj.__name__)
    if hasattr(obj, '__class__'):
        print("CLASS\t=\t%s" % obj.__class__.__name__)
    print("ID\t=\t%s" % id(obj))
    print("TYPE\t=\t%s" % type(obj))
    print("VALUE\t=\t%s" % repr(obj))
    print("CALL\t=\t%s" % ("Yes" if callable(obj) else "No"))
    print("")

def main():
    list_var = []
    string_var = "String"

    interrogate(list_var)
    interrogate(string_var)
    interrogate(interrogate)


if __name__ == '__main__':
    main()

