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

typedef struct Stack {
	char *arr;
	int tos;
} STACK_t;

typedef STACK_t * STACK_p_t;

void initStack (STACK_p_t stack) {
	stack->arr = (char *)calloc(SIZE, sizeof(char));
	stack->tos = -1;
}

// Stack methods for character stack

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

void push (STACK_p_t stack, char item) {
	if (stack->tos == SIZE - 1)
		return;
	stack->tos += 1;
	*(stack->arr + stack->tos) = item;
}

char top (STACK_t stack) {
	if (stack.tos == -1)
		return UNDERFLOW_CHAR;
	return *(stack.arr + stack.tos);
}

char pop (STACK_p_t stack) {
	if (stack->tos == -1)
		return UNDERFLOW_CHAR;
	return *(stack->arr + (stack->tos)--);
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
	if (indexOf(op, "+-*/%^$") != -1)
		return YES;
	return NO;
}

// Checking if the character is an operand

BOOL isOperand (char op) {
	if ((op >= 65 && op <= 90) || (op >= 97 && op <= 122) || (op >= 48 && op <= 57))
		return YES;
	return NO;
}

// Operator Precedence

int operatorPrecedence (char op) {
	if (indexOf(op, "([{") != -1) return 0;
	else if (indexOf(op, "+-") != -1) return 1;
	else if (indexOf(op, "*/%^") != -1) return 2;
	else if (op == '$') return 3;
	else return -1;
}

/**
 *	The algorithm goes as follows.
 *
 *	Parse the inputs in the expression one by one.
 *
 *	1. If the input is an operand, then place it in the output buffer.
 *
 *  2. If the input is an operator, push it into the stack.
 *
 *	3. While the stack is not empty and operator in stack has higher or equal precedence than input operator, then pop the operator present in stack and add it to output buffer.
 *
 *	4. Add the input operator to the stack.
 *
 *	5. If the input is an open brace, push it into the stack.
 *
 *	6. If the input is a close brace, pop elements in stack one by one until we encounter close brace. Discard braces while writing to output buffer.
 *
 */

char * toPostfix (char * exp) {
	
	STACK_p_t postfix = (STACK_p_t)calloc(SIZE, sizeof(STACK_t));
	STACK_p_t operator = (STACK_p_t)calloc(SIZE, sizeof(STACK_t));
	initStack(postfix);
	initStack(operator);
	
	int l = (int)strlen(exp);
	int i;
	
	for (i = 0; i < l; ++i) {
		char z = *(exp + i);
		
		if (isOperand(z))
			push(postfix, z);
		
		else if (operatorPrecedence(z) == 0)
			push(operator, z);
		
		else if (isOperator(z)) {
			while (!isStackEmpty(*operator) && operatorPrecedence(z) <= operatorPrecedence(top(*operator))) {
				char op =  pop(operator);
				if (isOperator(op))
					push(postfix, op);
			}
			push(operator, z);
		}
		
		else if ((indexOf(z, ")]}") != -1)) {
			while (operatorPrecedence(top(*operator)) != 0)
				push(postfix, pop(operator));
			pop(operator);
		}
		
		else
			continue;
		
	}
	
	while (!isStackEmpty(*operator))
		push(postfix, pop(operator));
	
	return postfix->arr;
}

int main(int argc, const char * argv[]) {
	
	char *infix = (char *)calloc(SIZE, sizeof(char));
	
	printf("\n\tThis program will convert an Infix expression to Postfix.\n\te.g. (4 + 8) * (6 - 5) / ((3 - 2) * (2 + 2)) = 48+65-*32-22+*/.\n\n\tEnter an valid Infix expression : ");
	fgets(infix, SIZE, stdin);
	
	char *postfix = toPostfix(infix);
	
	printf("\n\n\tInfix: %s\n\tPostfix: %s\n\n", infix, postfix);
	
	return 0;
}
