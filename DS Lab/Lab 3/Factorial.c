//
//  Factorial.c
//  Factorial
//
//  Created by Avikant Saini on 8/15/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

long factorial (long n) {
	if (n == 1)
		return 1;
	return n*factorial(n-1);
}

int main(int argc, const char * argv[]) {
	long n;
	printf("This program will calculate the factorial of a number recursively.\n\tEnter a number : ");
	scanf("%ld", &n);
	printf("\n\t%ld! = %ld\n\n", n, factorial(n));
}
