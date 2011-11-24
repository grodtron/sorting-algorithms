from math import *


def f(Q):
   return ((44.0*tan(acos(0.38))) - Q) / (2 * pi * 60 * 115.6 * 115.6)

print 95.074, f(95.074)
print 82.633, f(82.633)
print 57.157, f(57.157)
