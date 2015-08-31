//
//  InfixToPostfix.c
//  Convertnig Infix expression to Postfix
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

// Boolean type, just for readability

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

// Stack methods for character stack

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

void push (char *stack, char item, int *tos) {
	if (*tos == SIZE - 1)
		return;
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

char pop (char *stack, int *tos) {
	if (*tos == -1)
		return UNDERFLOW_CHAR;
	return *(stack + ((*tos)--));
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

// Checking if the character is an operand

BOOL isOperand (char op) {
	if ((op >= 65 && op <= 90) || (op >= 97 && op <= 122))
		return YES;
	if (op >= 48 && op <= 57)
		return YES;
	return NO;
}

// Operator Precedence

int operatorPrecedence (char op) {
	if (indexOf(op, "([{") != -1) return 0;
	else if (indexOf(op, "+-") != -1) return 1;
	else if (indexOf(op, "*/%") != -1) return 2;
	else if (op == '$') return 3;
	else if (indexOf(op, ")]}") != -1) return 4;
	return -1;
}

/**
 *	The algorithm goes as follows.
 *
 *	Reverse the Expression and parse the inputs in the expression one by one.
 *
 *	1. If the input is an operand, then place it in the output buffer.
 *
 *  2. If the input is an operator, push it into the stack.
 *
 *	3. If the operator in stack has lower precedence than input operator, then pop the operator present in stack and add it to output buffer.
 *
 *	4. If the input is an open brace, push it into the stack
 *
 *	5. If the input is a close brace, pop elements in stack one by one until we encounter close brace. Discard braces while writing to output buffer.
 *
 */

char * toPostfix (char * exp) {
	
	int tosp = -1;
	char *postfix = (char *)calloc(SIZE, sizeof(char));
	int toso = -1;
	char *operator = (char *)calloc(SIZE, sizeof(char));
	
	int l = (int)strlen(exp);
	int i;
	
	for (i = 0; i < l -1; ++i) {
		char z = *(exp + i);
		
		if (z == ' ')
			continue;
		
		if (isOperand(z))
			push(postfix, z, &tosp);
		
		if (isOperator(z))
			push(operator, z, &toso);
		
		if (operatorPrecedence(*(operator + toso)) < operatorPrecedence(z)) {
			char op =  pop(operator, &toso);
			if (isOperator(op))
				push(postfix, op, &tosp);
		}
		
		if (operatorPrecedence(z) == 0)
			push(operator, z, &toso);
		
		if (operatorPrecedence(z) == 4) {
			while (operatorPrecedence(*(operator + toso)) != 0)
				push(postfix, pop(operator, &toso), &tosp);
		}
		
	}
	
	while (isStackFull(toso))
		push(postfix, pop(operator, &toso), &tosp);
	
	return postfix;
}

int main(int argc, const char * argv[]) {
	
	char *infix = (char *)calloc(SIZE, sizeof(char));
	
	printf("\n\tThis program will convert an Infix expression to Postfix.\n\te.g. (1 + (4 * 5)) = 145*+.\n\n\tEnter an valid parenthesized Infix expression : ");
	fgets(infix, SIZE, stdin);
	
	char *postfix = toPostfix(infix);
	
	printf("\n\n\tInfix: %s\n\tPostfix: %s\n\n", infix, postfix);
	
	return 0;
}