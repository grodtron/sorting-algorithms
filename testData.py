#!/usr/bin/python

from random import random
import sys


# This file generates lists of numbers which may be fully ordered,
# partially ordered or totally un-ordered (not necessarily out-of-order)
# just random. Sortedness indicates the percent of the list that is sorted

def main(length, sortedness):
   length = int(length)

   sortedness = float(sortedness)
   if(sortedness > 1.0):
      sortedness = 1.0
   elif(sortedness < 0.0):
      sortedness = 0.0

   for n in range(length):
      # print a random number
      if(random() > sortedness):
         print int(random() * length)
      else:
         print n

   print '\0'

if __name__ == '__main__':
   if(len(sys.argv) == 1):
      print "usage: " + __file__ + " [length of data] [sortedness of data]"
   else:
      main(sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else 1)
