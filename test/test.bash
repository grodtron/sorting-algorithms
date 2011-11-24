if [ ! -e data ] && [ -d data ]
then
   echo "data!"
else
   echo "no data!"
fi

for n in {0..9}
do
   echo 0.$n
done
