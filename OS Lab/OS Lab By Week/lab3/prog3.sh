#!bin/bash
echo Enter two non-negative integer values
read a
read b
while [ $b -gt 0 ]
do
    temp=$b
    b=$(( $a % $b ))
    a=$temp
done
echo gcd is $a
