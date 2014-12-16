#!/usr/bin/python -tt


words = 'Out of all the things I have lost, I miss my mind the most.'.split()
F = map(lambda x: [x.upper(), x.lower(), len(x)], words)

for line in F:
    print line

print F
