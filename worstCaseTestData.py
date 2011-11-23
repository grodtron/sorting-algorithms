#!/usr/bin/python

import sys
from random import random

# print an anit-ordered list
def main(length):
   length = int(length)

   section_length, extra = divmod(length, 127 - 33)
   print section_length
   print extra

   n = (127 - 33)
   for n in reversed(range(127 - 33)):
      n = 33 + n
      for s in range(section_length):
         sys.stdout.write(chr(n))
   #for s in range(extra):
    #..  sys.stdout.write(chr(n))

if __name__ == '__main__':
   main(sys.argv[1])
