#!/usr/bin/python3
''' read.py '''

import json
import base64

# Opening JSON file
f = open('test_output.json', 'r')

# returns JSON object as
# a dictionary
data = json.load(f)
#print(data)

# Iterating through the json
# list
#for i in data['cmd_details']:
#    print(i["name"])
#    print(i["args"])
#    print(i["returncode"])
#    print(base64.b64decode(i["stdout"].encode("ascii")).decode("ascii"))
#    print(base64.b64decode(i["stderr"].encode("ascii")).decode("ascii"))

#for cmd in data['cmd_details']:
#    print(cmd)

#print(type(data['cmd_details']))
#print(data['cmd_details'][0])
#print(data['cmd_details'][1])

my_dict = next(item for item in data['cmd_details'] if item["name"] == "mount")
print(my_dict)
print(my_dict['name'])
print(my_dict['returncode'])

test_stdout = base64.b64decode(my_dict["stdout"].encode("ascii")).decode("ascii")
test_stderr = base64.b64decode(my_dict["stderr"].encode("ascii")).decode("ascii")
print(test_stdout)

string_index = test_stdout.find('/dev/mapper/VolGroup-LogVol02')
print(string_index)
print(test_stdout[string_index:].split('\n')[0])

#test_rpm="ostree-libs-2023.1-7.el9_2.x86_64"
#test_rpm="ostree-libs-2022.1-7.el9_2.x86_64"

#if test_rpm in test_stdout:
#    print(f'stdout contains "{test_rpm}"')
#else:
#    print(f'stdout does not contain "{test_rpm}"')

# Closing file
f.close()
