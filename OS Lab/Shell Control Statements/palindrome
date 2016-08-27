#!/bin/bash

echo Enter number to be checked
read n
temp=$n
num=0
until [ $n -eq 0 ]
do
    dig=`expr $n % 10`
    n=`expr $n / 10`
    num=`expr $num \* 10 + $dig`
done
if [ $temp -eq $num ]
then
echo Palindrome
else
echo Not palindrome
fi
