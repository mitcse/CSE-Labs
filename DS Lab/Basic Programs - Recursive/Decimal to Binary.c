//
//  Decimal to Binary.c
//  Decimal to Binary
//
//  Created by Avikant Saini on 8/15/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

long decToBin (long n) {
	if (n == 0)
		return 0;
	return (n%2 + 10*decToBin(n/2));
}

int main(int argc, const char * argv[]) {
	long n;
	printf("This program will convert a decimal number into binary using recursion.\n\tEnter the decimal number : ");
	scanf("%ld", &n);
	printf("\n\t %ld|d = %ld|b\n\n", n, decToBin(n));
}
