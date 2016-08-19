#!/bin/bash
# reverse a number using until

echo Enter number to be reversed
read n
num=0
until [ $n -eq 0 ]
do
    dig=`expr $n % 10`
    n=`expr $n / 10`
    num=`expr $num \* 10 + $dig`
done
echo reverse of number is $num
