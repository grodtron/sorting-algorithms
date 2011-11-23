#!/usr/bin/python

from random import random
import sys

def main(length):
   length = int(length)
   for n in range(length):
      # print a random number
      print int(random() * (2**31)) - 1

   print '\0'

if __name__ == '__main__':
   main(sys.argv[1])
