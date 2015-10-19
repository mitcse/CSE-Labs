//
//  MultipleStacksSingleArrayAlternate.c
//  Multiple Stacks in a Single Array Using Boundaries
//
//  Created by Avikant Saini on 9/21/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW_INT -32767

typedef enum { NO, YES } BOOL;

typedef struct MultipleStacks {
	int *arr;
	int *top;
	int *boundry;
} STACK_t;

typedef STACK_t * STACK_p_t;

void push (int item, int i, STACK_p_t stack) {
	if (*(stack->top + i) == *(stack->boundry + i)) {
		printf("\n\tSTACK %d OVERFLOW!\n\n", i + 1);
		return;
	}
	*(stack->arr + ++(*(stack->top + i))) = item;
}

int pop (int i, STACK_p_t stack) {
	if (*(stack->top + i) == -1 || *(stack->top + i) == *(stack->boundry + i - 1) + 1) {
		printf("\n\tSTACK %d UNDERFLOW!\n\n", i + 1);
		return UNDERFLOW_INT;
	}
	return *(stack->arr + (*(stack->top + i))--);
}

int main (int argc, const char * argv []) {
	
	int n, i;
	
	printf("\n\tEnter number of stacks you want: ");
	scanf("%d", &n);
	
	STACK_p_t stack = (STACK_p_t)malloc(sizeof(STACK_t));
	
	stack->arr = (int *)calloc(n * SIZE, sizeof(int));
	stack->top = (int *)calloc(n, sizeof(int));
	stack->boundry  =(int *)calloc(n, sizeof(int));
	
	for (i = 0; i < n; ++i) {
		*(stack->top + i) = -1;
		*(stack->boundry + i) = (i + 1) * SIZE;
	}
	
	int stno, ch;
	
	do {
		printf("\n\tEnter the stack no you want to perform operations on (1 - %d): ", n);
		scanf("%d", &stno);
		
		if (stno <= 0 || stno > n) {
			printf("\n\tINVALID CHOICE!\n\n");
			stno = 1;
			continue;
		}
		
		do {
			printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\tCHOICE: ");
			scanf("%d", &ch);
			
			if (ch == 1) {
				int item;
				printf("\n\tEnter item to push into stack %d: ", stno);
				scanf("%d", &item);
				push(item, stno - 1, stack);
			}
			else if (ch == 2) {
				int item = pop(stno - 1, stack);
				if (item != UNDERFLOW_INT)
					printf("\n\tPopped item from stack %d: %d\n", stno, item);
			}
			
		} while (ch > 0 && ch <= 3);
		
	} while (stno > 0 && stno <= n);
	
	return 0;
}
