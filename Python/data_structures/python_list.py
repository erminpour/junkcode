#!/usr/bin/python3

def main():
    print("main()")

    ##
    ## Convert string to list
    text = 'Python'
    text_list = list(text)
    print(text_list)

    ##
    ## Lists store sequences
    li = []
    print(li)
    print(type(li))
    print(len(li))

    ##
    ## Prefilled list
    other_li = [4, 5, 6]

    ##
    ## Append to end of list
    li.append(1)    # li is now [1]
    li.append(2)    # li is now [1, 2]
    li.append(4)    # li is now [1, 2, 4]
    li.append(3)    # li is now [1, 2, 4, 3]
    print(li)

    ##
    ## Remove from the end with pop
    li.pop()        # => 3 and li is now [1, 2, 4]
    print(li)

    ##
    ## Append to list again
    li.append(3)    # li is now [1, 2, 4, 3] again.
    print(li)

    ##
    ## Access a list like an array
    print(li[0])   # => 1

    ##
    ## Look at the last element
    print(li[-1])  # => 3
    print(li[-2])  # => 4

    ##
    ## Looking out of bounds is an IndexError
    try:
        print(li[4])  # Raises an IndexError
    except IndexError:
        print("ERROR: IndexError.")
    except:
        print("ERROR: Generic error message.") 

    # Make a one layer deep copy using slices
    li2 = li[:]

    print(locals())


if __name__ == '__main__':
    main()


