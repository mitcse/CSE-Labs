// Product.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

long mult (int a, int b) {
	if (b == 1)
		return a;
	return a + mult(a, b-1);
}

int main (int argc, const char *argv []) {
	int a, b;
	printf("This program will calculate the product of 2 numbers.\n\n\tEnter number 1: ");
	scanf("%d", &a);
	printf("\tEnter number 2: ");
	scanf("%d", &b);
	printf("\n\t%d x %d = %ld.\n\n", a, b, mult(a, b));
	return 0;
}