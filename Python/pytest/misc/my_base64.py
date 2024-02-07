#!/usr/bin/python3

import base64 
  
sample_string = "GeeksForGeeks is the best"
print(sample_string)
print(type(sample_string))

sample_string_bytes = sample_string.encode("ascii") 
print(sample_string_bytes)
print(type(sample_string_bytes))
 
base64_bytes = base64.b64encode(sample_string_bytes) 
print(base64_bytes)
base64_string = base64_bytes.decode("ascii") 
print(base64_string)
  


base64_bytes = base64_string.encode("ascii") 
print(base64_bytes)

sample_string_bytes = base64.b64decode(base64_bytes)
print(sample_string_bytes)
 
sample_string = sample_string_bytes.decode("ascii") 
print(sample_string)



