#!/bin/bash

for n in {100..20000..100}
do
   python testData.py $n > testData$n.dat
done

x=$(ls netbook_result_*dat | wc -l);

for n in {100..20000..100}
do
   echo "$n  $(cat testData$n.dat | ./linked)" >> netbook_result_$x.dat
   echo $n
done

rm testData*.dat
