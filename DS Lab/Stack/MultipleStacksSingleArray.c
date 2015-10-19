//
//  MultipleStacks.c
//  Implementing multiple stacks in a single array.
//
//  Created by Avikant Saini on 9/13/15.
//  Copyright © 2015 avikantz. All rights reserved.
//
//	Work in progress.
//

#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW_CHAR '\0'

/// Boolean type, just for readability

typedef enum {	NO, YES	 } BOOL;

typedef struct MStacks {
	char *arr;
	int *top;
	char *next;
	
	int size;
	int nstacks;
	int free;
} MSTACKS_t;

typedef MSTACKS_t* MSTACKS_p_t;

void initStack (MSTACKS_p_t stack, int nstacks, int size) {
	
	stack = (MSTACKS_p_t)malloc(sizeof(MSTACKS_t));
	
	stack->size = size;
	stack->nstacks = nstacks;
	
	stack->arr = (char *)calloc(size, sizeof(char));
	stack->top = (int *)calloc(nstacks, sizeof(int));
	stack->next = (char *)calloc(size, sizeof(char));
	
	int i;
	for (i = 0; i < nstacks; ++i)
		*(stack->top + i) = -1;
	
	stack->free = 0;
	
	for (i = 0; i < size - 1; ++i)
		*(stack->next + i) = i + 1;
	*(stack->next + i) = -1;
}

BOOL isStackFull (MSTACKS_p_t stack) {
	if (stack->free == -1)
		return YES;
	return NO;
}

BOOL isStackEmpty (MSTACKS_p_t stack, int sno) {
	if (*(stack->top + sno) == -1)
		return YES;
	return NO;
}

void push (MSTACKS_p_t stack, char item, int sno) {
	if (isStackFull(stack)) {
		printf("\n\tSTACK OVERFLOW!\n\n");
		return;
	}
	
	int i = stack->free;
	
	stack->free = *(stack->next + i);
	
	*(stack->top + sno) = i;
	
	*(stack->arr + i) = item;
}

char pop (MSTACKS_p_t stack, int sno) {
	if (isStackEmpty(stack, sno)) {
		printf("\n\tSTACK %d IS EMPTY!\n\n", sno + 1);
		return UNDERFLOW_CHAR;
	}
	
	int i = *(stack->top + sno);
	
	*(stack->top + sno) = *(stack->next + i);
	
	*(stack->next + i) = stack->free;
	
	stack->free = i;
	
	return *(stack->arr + i);
}

int main(int argc, const char * argv[]) {
	
	MSTACKS_p_t stack;
	initStack(stack, 4, 10);
	
	push(stack, 'A', 0);
	push(stack, 'B', 1);
	push(stack, 'C', 2);
	push(stack, 'D', 3);
	push(stack, 'E', 2);
	push(stack, 'F', 1);
	push(stack, 'G', 2);
	push(stack, 'H', 0);
	push(stack, 'I', 3);
	
	printf("\n\tPopped from stack '%d' = %c.", 0, pop(stack, 0));
	printf("\n\tPopped from stack '%d' = %c.", 1, pop(stack, 1));
	printf("\n\tPopped from stack '%d' = %c.", 2, pop(stack, 2));
	printf("\n\tPopped from stack '%d' = %c.", 3, pop(stack, 3));
	printf("\n\tPopped from stack '%d' = %c.", 2, pop(stack, 2));
	printf("\n\tPopped from stack '%d' = %c.", 1, pop(stack, 1));
}
