//
//  Prefix.c
//  Evaulation of Prefix Operation
//
//  Created by Avikant Saini on 8/30/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define UNDERFLOW_INT -32768

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
	if (op == '+') return a+b;
	else if (op == '-') return a-b;
	else if (op == '*') return a*b;
	else if (op == '/') return (int)a/b;
	else if (op == '$') return (int)pow(a, b);
	return 0;
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

// Checking if the character is a number

BOOL isNumber (char op) {
	if (indexOf(op, "0123456789") != -1)
		return YES;
	return NO;
}

// Get the numeric value of a character (ASCII method)

int numericValue (char character) {
	return (int)(character - 48);
}

/**
 *	The algorithm goes as follows.
 *	Since it's a prefix expression, loop reverse into the expression.
 *	If a number is found, push it into the numberic stack.
 *	If an operator is found, pop two integers from the stack, perform the operation, and push the result back to the stack.
 *	If anything other than an operator and number is found, return the error code.
 *	Finally if at the end, there is only one element in the stack (tos == 0), return that element, else return the error code.
 */

int prefix (char * exp) {
	
	int tos = -1;
	int *stack = (int *)calloc(SIZE, sizeof(int));
	int l = (int)strlen(exp), i;
	
	for (i = l - 1; i >= 0; --i) {
		char z = *(exp + i);
		if (isNumber(z))
			push(stack, numericValue(z), &tos);
		else if (isOperator(z)) {
			int a = pop(stack, &tos);
			int b = pop(stack, &tos);
			int res = operationResult(z, a, b);
			push(stack, res, &tos);
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
	
	printf("\n\tThis program will compute the value of an prefix operation.\n\te.g. *+135 = (1 + 3) * 5 = 20.\n\n\tEnter an valid prefix expression : ");
	scanf("%s", string);
	
	int result = prefix(string);
	
	if (result == UNDERFLOW_INT) {
		printf("\n\tINVALID EXPRESSION.");
		exit(6);
	}
	
	printf("\n\t Result = %d.\n\n", result);
	
	return 0;
}