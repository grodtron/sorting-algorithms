#!/usr/bin/python

import sys
from random import random

def main(length):
   length = int(length)
   for n in range(length):
      # write out a single non-space ascii character
      sys.stdout.write(chr(int(random() * (127 - 33)) + 33))

if __name__ == '__main__':
   main(sys.argv[1])
