#!/usr/bin/python

import sys

def main():
   indata_raw = sys.stdin.readline()
   indata = (int(n) for n in indata_raw.replace('\0', '').split())
   previous = -1
   test_passed = True
   for current in indata:
      if current < previous :
         test_passed = False
         print "Test failed! the value %d was followed by the value %d" % (previous, current)
         f = open("test_failure.dat", 'a')
         f.write(indata_raw)
         f.close()
         break
      else:
         previous = current
   if(test_passed):
      print "Test passed! Hooray!"


if __name__ == '__main__':
   main()
