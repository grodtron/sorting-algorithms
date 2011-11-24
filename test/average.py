#!/usr/bin/python

import os
import sys

lsdir = sys.argv[1:]

result_dict = {}

for f in lsdir:
   for line in open(f).readlines():
      line = line.split()
      if len(line) < 2:
         continue
      if result_dict.has_key(int(line[0])):
         result_dict[int(line[0])] += float(line[1])
      else:
         result_dict[int(line[0])] = float(line[1])

for k in sorted(result_dict.keys()):
   print k, (result_dict[k] / len(lsdir))
