#!/bin/sh
echo "Iveskite skaiciu eilute atskirta tarpais: "
read a b
echo "Skaiciai mazesni uz pirmaji: "
for i in $b
do
if [ $a -gt $i ]
then
echo $i
fi
done
echo "Skaiciai didesni arba lygus pirmajam: "
for i in $b
do
if [ $a -le $i ]
then
echo $i
fi
done
