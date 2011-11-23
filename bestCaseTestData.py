#!/usr/bin/python

import sys

def main(length):
   length = int(length)
   for n in range(length):
      # write out a single character
      sys.stdout.write('a')

if __name__ == '__main__':
   main(sys.argv[1])
