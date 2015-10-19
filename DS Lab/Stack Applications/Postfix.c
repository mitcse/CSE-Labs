//
//  Postfix.c
//  Evaulation of Postfix Operation
//
//  Created by Avikant Saini on 8/30/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define UNDERFLOW_INT -32767

// Boolean type, just for readability

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

// Stack methods for integer stack

BOOL isStackFull (int tos) {
	if (tos == SIZE - 1)
		return YES;
	return NO;
}

BOOL isStackEmpty (int tos) {
	if (tos == -1)
		return YES;
	return NO;
}

void push (int *stack, int item, int *tos) {
	if (*tos == SIZE - 1)
		return;
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

int pop (int *stack, int *tos) {
	if (*tos == -1)
		return UNDERFLOW_INT;
	return *(stack + ((*tos)--));
}

// Return the result of an binary operation

int operationResult (char op, int a, int b) {
	switch (op) {
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return (int)(a/b);
		case '$': return (int)pow(a, b);
		default : return 0;
	}
}

// Get the index of a character in a string

int indexOf (char character, char *string) {
	char *ptr = strchr(string, character);
	if (ptr)
		return (int)(ptr - string);
	return -1;
}

// Checking of the character is an operator

BOOL isOperator (char op) {
	if (indexOf(op, "+-*/$") != -1)
		return YES;
	return NO;
}

// Checking if the character is a number or a alphabet

BOOL isNumber (char op) {
	if (op >= '0' && op <= '9')
		return YES;
	return NO;
}

BOOL isAlphabet (char op) {
	if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z'))
		return YES;
	return NO;
}

// Get the numeric value of a character (ASCII method)

int numericValue (char character) {
	return (int)(character - 48);
}

/**
 *	The algorithm goes as follows.
 *	Since it's a postfix expression, loop into the expression.
 *
 *	1. If a number is found, push it into the numberic stack.
 *
 *	2. If a variable (alphabet) is found, input it's value from the user, then push the value into the stack.
 *
 *	3. If an operator is found, pop two integers from the stack, perform the operation, and push the result back to the stack.
 *
 *	4. If anything other than an operator and number is found, return the error code.
 *
 *	5. Finally if at the end, there is only one element in the stack @code(tos == 0)@endcode return that element, else return the error code.
 */

int postfix (char * exp) {
	
	int tos = -1;
	int *stack = (int *)calloc(SIZE, sizeof(int));
	int l = (int)strlen(exp), i;
	
	for (i = 0; i < l; ++i) {
		char z = *(exp + i);
		
		if (isNumber(z))
			push(stack, numericValue(z), &tos);
		
		else if (isAlphabet(z)) {
			int numz;
			printf("\n\tEnter the value of '%c': ", z);
			scanf("%d", &numz);
			push(stack, numz, &tos);
		}
		
		else if (isOperator(z)) {
			int b = pop(stack, &tos);
			int a = pop(stack, &tos);
			push(stack, operationResult(z, a, b), &tos);
		}
		
		else
			return UNDERFLOW_INT;
	}
	if (tos == 0)
		return *stack;
	return UNDERFLOW_INT;
}

int main(int argc, const char * argv[]) {
	
	char *string = (char *)calloc(SIZE, sizeof(char));
	
	printf("\n\tThis program will compute the value of an postfix operation.\n\te.g. 135*+ = 1 + 3 * 5 = 16.\n\n\tEnter an valid postfix expression : ");
	scanf("%s", string);
	
	int result = postfix(string);
	
	if (result == UNDERFLOW_INT) {
		printf("\n\tINVALID EXPRESSION.\n\n\n");
		exit(6);
	}
	
	printf("\n\t Result = %d.\n\n", result);
	
	return 0;
}
