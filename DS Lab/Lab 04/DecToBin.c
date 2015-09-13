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

typedef struct Stack {
	int *arr;
	int tos;
} STACK_t;

typedef STACK_t * STACK_p_t;

void push (STACK_p_t stack, int item) {
	if (stack->tos == SIZE - 1) {
		printf("\n\tSTACK OVERFLOW\n");
		return;
	}
	*(stack->arr + ++(stack->tos)) = item;
}

void displayReverse (STACK_t stack) {
	int *pi;
	for (pi = stack.arr + stack.tos; pi >= stack.arr; --pi)
		printf("%d", *pi);
}

int main(int argc, const char * argv[]) {
	
	STACK_p_t stack = (STACK_p_t)malloc(sizeof(STACK_t));
	stack->arr = (int *)calloc(SIZE, sizeof(int));
	stack->tos = -1;
	long long n;
	
	printf("\n\tEnter a decimal number: ");
	scanf("%lld", &n);
	
	long long z = n;
	while (z > 0) {
		push(stack, z%2);
		z /= 2;
	}
	
	printf("\n\t%lld|10 = ", n);
	displayReverse(*stack);
	printf("|2.\n\n");
	
	return 0;
}