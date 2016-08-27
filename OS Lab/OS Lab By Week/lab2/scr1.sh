echo This shell script answers questions 1 to 7 of OS lab 2
echo 
# list all files
ls
echo
# list all files starting with a or A
ls [aA]*
echo
# count number of logged in users
who -q
echo
# count number of files in current directory
ls | wc -l
echo
# echo date with string
echo The date today is Fri Aug 12 21:24:05 IST 2016
echo
# run date ls pwd
date; ls; pwd
echo
# display output ofa compiled program
./prog1
echo
# run exec file in bg with i/o redirect
./prog2 < prog2input.txt > prog2output.txt &
echo question 8 done check prog2output text file
echo
# simulate grep
# ./a.out inputfile pattern
./prog9 prog2output.txt Enter
echo
