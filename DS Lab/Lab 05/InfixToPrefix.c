//
//  InfixToPrefix.c
//  Convertnig Infix expression to Prefix
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

// Reversing stack

void reverse (STACK_p_t stack) {
	int i;
	for (i = 0; i <= stack->tos/2; ++i) {
		char ch = *(stack->arr + i);
		*(stack->arr + i) = *(stack->arr + stack->tos - i);
		*(stack->arr + stack->tos - i) = ch;
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
	if (indexOf(op, "+-*/%$") != -1)
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
	if (indexOf(op, ")]}") != -1) return 0;
	else if (indexOf(op, "+-") != -1) return 1;
	else if (indexOf(op, "*/%") != -1) return 2;
	else if (op == '$') return 3;
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
 *	3. While the stack is not empty and operator in stack has higher precedence than input operator, then pop the operator present in stack and add it to output buffer.
 *
 *	4. Push the input operator into the output stack.
 *
 *	5. If the input is an close brace, push it into the stack.
 *
 *	6. If the input is a open brace, pop elements in stack one by one until we encounter open brace. Discard braces while writing to output buffer.
 *
 *	7. Display the output buffer in reverse order.
 */

char * toPrefix (char * exp) {
	
	STACK_p_t prefix = (STACK_p_t)malloc(sizeof(STACK_t));
	STACK_p_t operator = (STACK_p_t)malloc(sizeof(STACK_t));
	initStack(prefix);
	initStack(operator);
	
	int l = (int)strlen(exp);
	int i;
	
	for (i = l - 1; i >= 0; --i) {
		char z = *(exp + i);
		
		if (isOperand(z))
			push(prefix, z);
		
		else if (operatorPrecedence(z) == 0)
			push(operator, z);
		
		else if (isOperator(z)) {
			while (!isStackEmpty(*operator) && operatorPrecedence(z) < operatorPrecedence(top(*operator))) {
				char op =  pop(operator);
				if (isOperator(op))
					push(prefix, op);
			}
			push(operator, z);
		}
		
		else if (indexOf(z, "([{") != -1) {
			while (operatorPrecedence(top(*operator)) != 0)
				push(prefix, pop(operator));
			pop(operator);
		}
		
		else
			continue;
		
	}
	
	while(!isStackEmpty(*operator))
		push(prefix, pop(operator));
	
	reverse(prefix);
	return prefix->arr;
}

int main(int argc, const char * argv[]) {
	
	char *infix = (char *)calloc(SIZE, sizeof(char));
	
	printf("\n\tThis program will convert an Infix expression to Prefix.\n\te.g. (1 + (4 * 5)) = +*145.\n\n\tEnter an valid Infix expression : ");
	fgets(infix, SIZE, stdin);
	
	char *prefix = toPrefix(infix);
	
	printf("\n\n\tInfix: %s\n\tPrefix: %s\n\n", infix, prefix);
	
	return 0;
}