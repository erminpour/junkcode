#!/usr/bin/env python
"""producer_consumer.py
   Use python thread primitives to implement producer/consumer.
"""
import sys
import threading
import time
import random

__author__ = "Victor Hugo Erminpour"
__license__ = "GPL"
__version__ = "1.0"
__email__ = "victorhugoerminpour@gmail.com"
__status__ = "Prototype"


class Producer (threading.Thread):
    """
    Produces random integers to a list.
    """
    def __init__(self, integerList, condition):
        """
        Producer constructor
        @param integerList
        @param condition
        """
        threading.Thread.__init__(self)
        self.integerList = integerList
        self.condition = condition

    def run(self):
        """
        Producer thread run method.
        Append integers to the integerList
        """
        while True:
            ## generate random integer
            integer = random.randint(0, 512)

            ## get condition variable lock
            self.condition.acquire()
            print "%s: condition acquired" % (self.name)

            ## append integer to integerList
            self.integerList.append(integer)
            print "%s: %d appended to list" % (self.name, integer)

            ## notify the consumer about new data
            print "%s: condition notified" % (self.name)
            self.condition.notify()

            ## release condition variable lock
            print "%s: condition released" % (self.name)
            self.condition.release()

            ## sleep so we can see the messages
            time.sleep(1)


class Consumer (threading.Thread):
    """
    Consumes random integers from a list
    """
    def __init__(self, integerList, condition):
        """
        Consumer constructor
        @param integerList
        @param condition
        """
        threading.Thread.__init__(self)
        self.integerList = integerList
        self.condition = condition

    def run(self):
        """
        Consumer thread run method.
        Remove integers to the integerList
        """
        while True:
            ## get condition variable lock
            self.condition.acquire()
            print "%s: condition acquired" % (self.name)

            while True:
                ## if there's data in the list, remove it
                if self.integerList:
                    integer = self.integerList.pop()
                    print "%s: %d removed from list" % (self.name, integer)
                    break
                else:
                ## if there's no data, block for a notification
                    print "%s: condition wait" % self.name
                    self.condition.wait()

            ## release condition variable lock
            print "%s: condition released" % self.name
            self.condition.release()


def main():
    integerList = []
    conditionVar = threading.Condition()

    thread1 = Producer(integerList, conditionVar)
    thread2 = Consumer(integerList, conditionVar)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

if __name__ == "__main__":
    sys.exit(main())
