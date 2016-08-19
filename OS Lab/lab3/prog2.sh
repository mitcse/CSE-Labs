#!/bin/bash
# find all possible quadratic roots
echo Enter a, b, c as coefficients of equation
read a
read b
read c
d=$(( ($b)*($b)-4*($a)*($c) ))
if [ $d -gt 0 ]
then
flag=1
elif [ $d -eq 0 ]
then flag=0
else
flag=2
fi
case $flag in
    "1" )
        det=$(echo "sqrt ($d)" | bc -l)
        echo -n "x1 = "
        echo -e "scale=3\n0.5*(-($b)+($det))/($a)" | bc
        echo -n "x2 = "
        echo -e "scale=3\n0.5*(-($b)-($det))/($a)" | bc
        ;;
    "0" )
        echo -n "x = "
        echo -e "scale=3\n-0.5*($b)/($a)" | bc
        ;;
    "2" )
        echo -n "x1 = ("
        echo -e "scale=3\n-0.5*($b)/($a) " | bc
        echo -e "scale=3\n0.5*sqrt(-($d))/($a)" | bc
        echo "i)"
        echo -n "x2 = ("
        echo -e "scale=3\n-0.5*($b)/($a) " | bc
        echo -e "scale=3\n-0.5*sqrt(-($d))/($a)" | bc
        echo "i)"
        ;;
esac
