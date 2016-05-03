#!/usr/bin/python -tt
## file_line_function.py
## __FILE__, __FUNCTION__, __LINE__

import sys
import inspect

##
## __FILE__

def __FILE__():
    return inspect.currentframe().f_code.co_filename

##
## __LINE__

def __LINE__():
  ## 0 == represents this line
  ## 1 == represents caller line
  callerframerecord = inspect.stack()[1]

  frame = callerframerecord[0]
  info = inspect.getframeinfo(frame)
  return info.lineno
 
##
## __FUNCTION__

def __FUNCTION__():
  callerframerecord = inspect.stack()[1]

  frame = callerframerecord[0]
  info = inspect.getframeinfo(frame)
  return info.function

def foo():
    print("__LINE__ == %s" % (__LINE__()))
    print("__FUNCTION__ == %s" % (__FUNCTION__()))

def main():
    print("__file__ == %s" % (__file__))
    print("__FILE__ == %s" % (__FILE__()))
    print("")
    print("__LINE__ == %s" % (__LINE__()))
    print("__FUNCTION__ == %s" % (__FUNCTION__()))
    print("")
    foo()

if __name__ == '__main__':
    main()


