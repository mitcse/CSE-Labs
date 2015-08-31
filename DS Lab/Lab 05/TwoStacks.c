//
//  TwoStacks.c
//  Implementing two stacks in a simgle array.
//
//  Created by Avikant Saini on 8/31/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW '\0'

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

/**
 * Creating a stack structure @param tos1 Holds top of first stack. @param tos2 Holds the top of second stack @param stack The array, filled from front end for first stack, and from end for second stack.
 */

typedef struct Stack {
	int tos1;
	int tos2;
	char *stack;
} STACK_t;

/// There is only one condition for stack full i.e. @code tos1 == tos2 - 1 @endcode

BOOL isStackFull (STACK_t stack) {
	if (stack.tos1 == stack.tos2 - 1)
		return YES;
	return NO;
}

/// Stack 1 is empty if @code tos1 == -1 @endcode

BOOL isStackEmpty1 (STACK_t stack) {
	if (stack.tos1 == -1)
		return YES;
	return NO;
}

/// Stack 2 is empty if @code tos2 == SIZE @endcode

BOOL isStackEmpty2 (STACK_t stack) {
	if (stack.tos2 == SIZE)
		return YES;
	return NO;
}

/// Pushing into stack 1 @param *stack Stack pointer in which we've to push. @param item Item to be pushed.

void push1 (STACK_t *stack, char item) {
	if (isStackFull (*stack)) {
		printf("\n\tSTACK 1 OVERFLOW\n");
		return;
	}
	stack->tos1 += 1;
	*(stack->stack + stack->tos1) = item;
}

/// Pushing into stack 2 @param *stack Stack pointer in which we've to push. @param item Item to be pushed.

void push2 (STACK_t *stack, char item) {
	if (isStackFull(*stack)) {
		printf("\n\tSTACK 2 OVERFLOW\n");
		return;
	}
	stack->tos2 -= 1;
	*(stack->stack + stack->tos2) = item;
}

/// Popping from stack 1. Reduce the top1 after popping.

char pop1 (STACK_t *stack) {
	if (isStackEmpty1 (*stack)) {
		printf("\n\tSTACK 1 UNDERFLOW\n");
		return UNDERFLOW;
	}
	return *(stack->stack + (stack->tos1)--);
}

/// Popping from stack 2. Increase the top2 after popping.

char pop2 (STACK_t *stack) {
	if (isStackEmpty2 (*stack)) {
		printf("\n\tSTACK 2 UNDERFLOW\n");
		return UNDERFLOW;
	}
	return *(stack->stack + (stack->tos2)++);
}

/// Displaying the stack. @param stack The stack (entire structure). @param stackChoice The stack to be printed. @code if (stackChoice == '1') @endcode prints stack 1, and @code if (stackChoice == '2') @endcode prints stack 2.

void display (STACK_t stack, char stackChoice) {
	printf("\n");
	char *pi;
	if (stackChoice == '1')
		for (pi = stack.stack; pi <= stack.stack + stack.tos1; ++pi)
			printf("\t%c", *pi);
	if (stackChoice == '2')
		for (pi = stack.stack + SIZE - 1; pi >= stack.stack + stack.tos2; --pi)
			printf("\t%c", *pi);
	printf("\n");
}

int main(int argc, const char * argv[]) {
	
	STACK_t stack;
	stack.stack = (char *)calloc(SIZE, sizeof(char));
	stack.tos1 = -1;
	stack.tos2 = SIZE;
	
	char stackChoice;
	do {
		printf("\n\n\t1. Stack 1.\n\t2. Stack 2.\n\tAnything else for exit.\nEnter your choice: ");
		scanf(" %c", &stackChoice);
		
		if (!(stackChoice == '1' || stackChoice == '2'))
			exit(6);
		printf("\n\tYou have choosen Stack %c.\n", stackChoice);
		
		char choice;
		do {
			printf("\n\t1. Push an element.\n\t2. Pop an element.\n\t3. Display current stack.\n\tAnything else to return.\nEnter your choice: ");
			scanf(" %c", &choice);
			if (choice == '1') {
				char item;
				printf("\n\tEnter element to be pushed: ");
				scanf(" %c", &item);
				if (stackChoice == '1') push1(&stack, item);
				if (stackChoice == '2') push2(&stack, item);
			}
			else if (choice == '2') {
				char item = '\0';
				if (stackChoice == '1') item = pop1(&stack);
				if (stackChoice == '2') item = pop2(&stack);
				printf("\n\tPopped item: %c\n", item);
			}
			else if (choice == '3') {
				display(stack, stackChoice);
			}
			else
				break;
		} while (choice == '1' || choice == '2' || choice == '3');
		
		
	} while (stackChoice == '1' || stackChoice == '2');
	
	return 0;
}