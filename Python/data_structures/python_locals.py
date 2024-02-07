#!/usr/bin/python3
''' python_locals.py '''

GLOBAL_TEXT = "Global Text"
print(locals())

def main():
    ''' def main() '''
    print("main()")
    main_text = "main_text"
    print(main_text)
    print(locals())

if __name__ == '__main__':
    main()
