#!/usr/bin/python -tt

import os


def main():
    try:
        user_paths = os.environ['HOME'].split(os.pathsep)
    except KeyError:
        user_paths = []

    if user_paths:
        print user_paths


if __name__ == "__main__":
    main()
