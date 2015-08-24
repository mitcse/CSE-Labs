//
//  Fibonacci.c
//  Fibonacci
//
//  Created by Avikant Saini on 8/15/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

long fib(long a, long b, long n, long i) {
	if(i == n)
		return a+b;
	return fib(b, a+b, n, ++i);
}

int main(int argc, const char * argv[]) {
	int n, i;
	printf("This program will generate the fibonacci series with the help of a recursive function.\n\tEnter the limit: ");
	scanf("%d", &n);
	printf("\n\t0\t1");
	for(i = 1; i <= n-2; ++i)
		printf("\t%ld", fib(0, 1, i, 1));
	printf("\n\n");
	return 0;
}