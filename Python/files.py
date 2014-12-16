#!/usr/bin/python -tt


#def open_file():
#    with open("./files.py", "r") as file:
#        print file.read()

def main():
    file = open("./files.py", "r")
    for line in file:
        print line,     # trailing ',' omits newline
        # print(line, end="")   # Python 3
    file.close()

if __name__ == "__main__":
    main()
    #open_file()
