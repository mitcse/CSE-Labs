#!/bin/bash

# initial sum and array init
n_sum=0
declare -a is_prime
is_prime[0]=0
is_prime[1]=0
for (( i = 2; i <= 100; i++ )); do
	is_prime[i]=1
done

for (( i = 2; i <=50 ; i++ )); do
	j=$(($i * 2))
	while [[ $j -le 100 ]]; do
		if [[ ${is_prime[$j]} -eq 1 ]]; then
			is_prime[$j]=0
		fi
		j=$(($j + $i))
	done
done

for (( i = 2; i <=100; i++ )); do
	if [[ ${is_prime[$i]} -eq 1 ]]; then
		n_sum=$(( $n_sum + $i ))
	fi
done

echo Sum of required numbers is $n_sum
