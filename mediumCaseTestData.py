#!/usr/bin/python

import sys
from random import random

def main(length):
   length = int(length)
   for n in range(length):
      if(n%2):
         sys.stdout.write(chr(int(random() * (127 - 33)) + 33))
      else:
         sys.stdout.write(chr(127))

if __name__ == '__main__':
   main(sys.argv[1])
