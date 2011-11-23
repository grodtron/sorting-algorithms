#!/bin/bash

sorter=./sorting

for sortedness in {1..9}
do


   sortedness=0.$sortedness # get a decimal value for sortedness
   dir=test_$sortedness

   if [ ! -d $dir ]
   then
      echo "making directory $dir"
      mkdir $dir
   fi


   echo "beginning tests for sortedness $sortedness"

   for repetitions in {1..21}
   do


      x=$(ls $dir -1 | wc -l);

      for n in {100..20000..100}
      do
         file=testData$n.dat

         echo -n "making data... "
         python testData.py $n $sortedness > $file
         echo "done"
         
         echo -n "testing $n..."
         echo "$n  $(cat $file | $sorter)" >> $dir/result_$x.dat
         echo "done"

         rm $file
      done

   done

   echo "done tests for sortedness $sortedness"
done

echo "Averaging running results"
for dir in $(ls | grep test_)
do
   if [ -d $dir ]
   then
      echo -ne "\t$dir ... "
      ./average.py $(ls -1 $dir | sed "s/^/$dir\//" | grep -v average) > $dir/average.dat # don't include the average.dat file in the new average
      echo "done"
   fi
done

echo -n "plotting running average result... "
./plot.gpt
echo "done"
