//
//  Postfix.c
//  Evaulation of an Expression
//	Converting to Postfix and then evaulate...
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
#define UNDERFLOW_CHAR '\0'

// Boolean type, just for readability

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

#pragma mark - Utility

/// Get the index of a character in a string

int indexOf (char character, char *string) {
	char *ptr = strchr(string, character);
	if (ptr)
		return (int)(ptr - string);
	return -1;
}

/// Checking of the character is an operator

BOOL isOperator (char op) {
	if (indexOf(op, "+-*/%^$") != -1)
		return YES;
	return NO;
}

/// Checking if the character is an operand

BOOL isOperand (char op) {
	if ((op >= 65 && op <= 90) || (op >= 97 && op <= 122) || (op >= 48 && op <= 57))
		return YES;
	return NO;
}

/// Operator Precedence

int operatorPrecedence (char op) {
	if (indexOf(op, "([{") != -1) return 0;
	else if (indexOf(op, "+-") != -1) return 1;
	else if (indexOf(op, "*/%") != -1) return 2;
	else if (indexOf(op, "&^") != -1) return 3;
	else return -1;
}

/// Return the result of an binary operation

double operationResult (char op, double a, double b) {
	switch (op) {
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '%': return (int)a%(int)b;
		case '$':
		case '^': return pow(a, b);
		default : return 0;
	}
}

/// Checking if the character is a number

BOOL isNumber (char op) {
	if (op >= '0' && op <= '9')
		return YES;
	return NO;
}

/// Checking if the character is an alphabet

BOOL isAlphabet (char op) {
	if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z'))
		return YES;
	return NO;
}

/// Get the numeric value of a character (ASCII method)

int numericValue (char character) {
	return (int)(character - 48);
}

#pragma mark - Character Stack

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

#pragma mark - Postfix Conversion

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

#pragma mark - Double stack

// Stack methods for integer stack

void pushi (double *stack, double item, int *tos) {
	if (*tos == SIZE - 1)
		return;
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

double popi (double *stack, int *tos) {
	if (*tos == -1)
		return UNDERFLOW_INT;
	return *(stack + ((*tos)--));
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

#pragma mark - Postfix evaulation

double postfix (char * exp) {
	
	int tos = -1;
	double *stack = (double *)calloc(SIZE, sizeof(double));
	int l = (int)strlen(exp), i;
	
	for (i = 0; i < l; ++i) {
		char z = *(exp + i);
		
		if (isNumber(z))
			pushi(stack, numericValue(z), &tos);
		
		else if (isAlphabet(z)) {
			double numz;
			printf("\n\tEnter the value of '%c': ", z);
			scanf("%lf", &numz);
			pushi(stack, numz, &tos);
		}
		
		else if (isOperator(z)) {
			double b = popi(stack, &tos);
			double a = popi(stack, &tos);
			pushi(stack, operationResult(z, a, b), &tos);
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
	
	printf("\n\tThis program will evaulate an expression.\n\te.g. (4 + 8) * (6 + 5) / ((3 + 2) * (2 + 2))\n\t= 12 * 11 / (5 * 4)\n\t= 132 / 20\n\t= 6.6\n\n\tEnter an valid Infix expression\n\t(Use single character alphabet as variables) : ");
	fgets(string, SIZE, stdin);
	
	char *postfixString = toPostfix(string);
	
	//	printf("\n\n\tInfix: %s\n\tPostfix: %s\n\n", string, postfix);
	
	double result = postfix(postfixString);
	
	if (result == UNDERFLOW_INT) {
		printf("\n\tINVALID EXPRESSION.\n\tUse single character alphabet as varibles to denote non single digit integers and floating point numbers.\n\n");
		exit(6);
	}
	
	printf("\n\t Result = %.4lf\n\n", result);
	
	return 0;
}
