#!/usr/bin/python3

import pickle

#Here's an example dict
grades = { 'Alice': 89, 'Bob': 72, 'Charles': 87 }

#Use dumps to convert the object to a serialized string
serial_grades = pickle.dumps(grades)
print(serial_grades)

#Use loads to de-serialize an object
received_grades = pickle.loads( serial_grades )
print(received_grades)
