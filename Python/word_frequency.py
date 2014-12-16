#!/usr/bin/env python
"""word_frequency.py
   Iterate over a list of words and use a dictionary to
   keep track of the frequency(count) of each word.
"""
import sys
from optparse import OptionParser

__author__ = "Victor Hugo Erminpour"
__license__ = "GPL"
__version__ = "1.0"
__email__ = "victorhugoerminpour@gmail.com"
__status__ = "Prototype"

globalWordList = []


def parse_args():
    parser = OptionParser(
        "%prog [options] <word1> <word2> ...]")
    (opts, args) = parser.parse_args()

    global globalWordList
    for argument in args:
        globalWordList.append(argument)


def word_frequency(wordList):
    frequencyDict = {}
    for word in wordList:
        if word in frequencyDict.keys():
            ## get the current count
            count = frequencyDict[word]
            ## replace count
            frequencyDict[word] = count + 1
        else:
            ## first occurence
            frequencyDict[word] = 1
    return frequencyDict


def main():
    # parse cmdline arguments
    parse_args()

    global globalWordList
    wordFrequencyDict = word_frequency(globalWordList)

    if wordFrequencyDict:
        print wordFrequencyDict

if __name__ == "__main__":
    sys.exit(main())
