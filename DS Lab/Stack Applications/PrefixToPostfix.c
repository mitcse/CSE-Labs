//
//  PrefixToPostfix.c
//  Convertnig Prefix expression to Postfix
//
//  Created by Avikant Saini on 8/31/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define UNDERFLOW_CHAR '\0'

#define initString(size) (String)malloc(size * sizeof(char));

typedef char * String;

typedef enum { NO, YES } BOOL;

typedef struct Stack {
	String *arr;
	int tos;
} STACK_t;

typedef STACK_t * STACK_p_t;

STACK_p_t initStack () {
	STACK_p_t stack = (STACK_p_t)malloc(sizeof(STACK_t));
	stack->arr = (char **)calloc(SIZE, sizeof(char *));
	stack->tos = -1;
	return stack;
}

BOOL isStackFull (STACK_t stack) {
	if (stack.tos == SIZE - 1)
		return YES;
	return NO;
}

BOOL isStackEmpty (STACK_t stack) {
	if (stack.tos == -1)
		return YES;
	return NO;
}

void push (STACK_p_t stack, String item) {
	if (isStackFull(*stack)) {
		printf("\n\tSTACK OVERFLOW!\n\n");
		return;
	}
	*(stack->arr + ++(stack->tos)) = item;
}

String pop (STACK_p_t stack) {
	if (isStackEmpty(*stack)) {
		printf("\n\tSTACK UNDERFLOW!\n\n");
		return UNDERFLOW_CHAR;
	}
	return *(stack->arr + ((stack->tos)--));
}

// Get the index of a character in a string

int indexOf (char character, String string) {
	char *ptr = strchr(string, character);
	if (ptr)
		return (int)(ptr - string);
	return -1;
}

// Checking of the character is an operator

BOOL isOperator (char op) {
	if (indexOf(op, "+-*/%^$") != -1)
		return YES;
	return NO;
}

// Checking if the character is an operand

BOOL isOperand (char op) {
	if ((op >= 65 && op <= 90) || (op >= 97 && op <= 122))
		return YES;
	if (op >= 48 && op <= 57)
		return YES;
	return NO;
}

/**
 *	The algorithm goes as follows:
 *
 *	Loop through the expression in reverse order.
 *
 *	If input is an operand, convert the character to string, and push it in stack.
 *
 *	If input is an operator, pop two elements from the stack, concatenate them and the operator, and push it back to the stack
 *	@code snprintf(tempString, SIZE, "%s%s%c", pop(stack), pop(stack), z);
 *	@endcode
 *
 *	Push the result in the stack.
 *
 *	Repeat these steps until arr of input prefix string ends.
 *
 *	Return the first element of the stack.
 *
 */

String toPostfix (String prefix) {
	
	STACK_p_t stack = initStack();
	
	int l = (int)strlen(prefix), i;
	
	for (i = l - 1; i >= 0; --i) {
		char z = *(prefix + i);
		
		if (isOperand(z)) {
			String tempString = initString(2);
			snprintf(tempString, 2, "%c", z);
			push(stack, tempString);
		}
		
		else if (isOperator(z)) {
			String tempString = initString(SIZE);
			snprintf(tempString, SIZE, "%s%s%c", pop(stack), pop(stack), z);
			push(stack, tempString);
		}
		
	}
	
	return *(stack->arr);
}


int main(int argc, const char * argv[]) {
	
	String prefix = initString(SIZE);
	
	printf("\n\tThis program will convert an Prefix expression to Postfix.\n\te.g. + * A B / C D = A B * C D / +.\n\n\tEnter an valid Prefix expression : ");
	fgets(prefix, SIZE, stdin);
	
	String postfix = toPostfix(prefix);
	
	printf("\n\n\tPrefix: %s\n\tPostfix: %s\n\n", prefix, postfix);
	
	return 0;
}
