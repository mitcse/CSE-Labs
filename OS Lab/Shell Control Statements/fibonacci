#!/bin/bash

echo Enter number of fibonacci you want
read n
a=0
b=1
echo first $n fibonacci numbers are
echo $a 
echo $b
n=`expr $n - 2`
while [ $n -gt 0 ]
do
    temp=`expr $a + $b`
    echo $temp
    a=$b
    b=$temp
    n=`expr $n - 1`
done
