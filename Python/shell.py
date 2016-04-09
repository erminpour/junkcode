#!/usr/bin/python

import sys

shell_prompt = "$> "

def __help_func():
    print """Commands:
           exit | quit      Exit Shell
           help             Print help message"""

def __exit_func(exit_code=0):
    sys.stdout.write("Goodbye!\n")
    exit(exit_code)

def __shell_loop():
    try:
        sys.stdout.write(shell_prompt)
        line = sys.stdin.readline()
        return line
    except KeyboardInterrupt:
        sys.stdout.write("\n")
        __exit_func(0)

def shell():
    line = __shell_loop()
    while line:
        sys.stdout.write(line)
        if line == "exit\n" or line == "quit\n":
            __exit_func(0)
        if line == "help\n":
            __help_func()
        line = __shell_loop()

if __name__ == '__main__':
    shell()

