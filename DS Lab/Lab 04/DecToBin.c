//
//  DecToBin.c
//  Decimal to Binary using 'em Stacks
//
//  Created by Avikant Saini on 8/24/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void push (int *stack, int item, int *tos) {
	if (*tos == SIZE - 1) {
		printf("\n\tSTACK OVERFLOW\n");
		return;
	}
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

void displayReverse (int *stack, int tos) {
	int *pi;
	for (pi = stack + tos; pi >= stack; --pi)
		printf("%d", *pi);
}

int main(int argc, const char * argv[]) {
	
	int tos = -1;
	int *stack = (int *)malloc(sizeof(int *));
	int n;
	
	printf("\n\tEnter a decimal number: ");
	scanf("%d", &n);
	
	int z = n;
	while (z > 0) {
		push(stack, z%2, &tos);
		z /= 2;
	}
	
	printf("\n\t%d|10 = ", n);
	displayReverse(stack, tos);
	printf("|2.\n\n");
	
	return 0;
}