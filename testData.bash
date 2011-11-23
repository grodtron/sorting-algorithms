#!/bin/bash

for n in {100..10000..100}; do python testData.py $n > testData$n.dat; done
