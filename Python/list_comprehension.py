#!/usr/bin/python -tt


myList = [1, 2, 3, 4, 5]

## The syntax for list comprehension is based on
## set builder notation.

#S = [2*x for x in myList if x*2 >3]
S = [(2 * x) for x in myList]
print S
