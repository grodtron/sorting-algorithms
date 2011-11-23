#!/bin/bash

for n in {100..20000..100}
do
   python bestCaseTestData.py $n > testData$n.dat
done

x=$(ls best_case_result_*dat | wc -l);

for n in {100..20000..100}
do
   echo "$n  $(cat testData$n.dat | ./linked)" >> best_case_result_$x.dat
   echo $n
done

rm testData*.dat
