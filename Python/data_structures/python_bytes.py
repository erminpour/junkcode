#!/usr/bin/python3
''' python_bytes.py '''

B_STRING = b'Bytes String'

print(B_STRING)
print(type(B_STRING))

print(B_STRING.decode())
print(type(B_STRING.decode()))

print(B_STRING.decode().encode())
print(type(B_STRING.decode().encode()))
