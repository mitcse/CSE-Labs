//
//  GCD.c
//  GCD
//
//  Created by Avikant Saini on 8/15/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

long gcd(long a, long b){
	if (b > a)
		return gcd(b, a);
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
	long a, b;
	printf("This program will calculate the GCD of two numbers recursively.\n\tEnter two numbers : ");
	scanf("%ld %ld", &a, &b);
	printf("\n\tGCD(%ld, %ld) = %ld\n\n", a, b, gcd(a, b));
}
