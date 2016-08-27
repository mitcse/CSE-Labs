#!/bin/bash
# check if input number is odd or even

echo Enter a number
read n
if [ `expr $n % 2` -eq 0 ]
then
echo number is even
else
echo number is odd
fi
