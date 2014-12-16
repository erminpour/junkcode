#!/usr/bin/python -tt


def main():
    myList = [1, 2, 3, 4, 5]

    print myList[4]

    myList.append(31337)
    print myList
    myList.remove(31337)
    print myList

if __name__ == '__main__':
    main()
