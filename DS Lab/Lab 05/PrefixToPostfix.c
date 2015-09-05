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

// Reversing stack

void reverse (char *stack, int tos) {
	int i;
	for (i = 0; i <= tos/2; ++i) {
		char ch = *(stack + i);
		*(stack + i) = *(stack + tos - i);
		*(stack + tos - i) = ch;
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

/**
 *	The algorithm goes as follows.
 *
 *	Reverse the Expression and parse the inputs in the expression one by one.
 *
 *	1. If the input is an operand, then place it in the output buffer.
 *
 *
 */

char * toPostfix (char * prefix) {
	
	char * postfix = (char *)calloc(SIZE, sizeof(char));
	int toso = -1;
	char * operands = (char *)calloc(SIZE, sizeof(char));
	int l = (int)strlen(prefix), i;
	
	for (i = l - 1; i >= 0; --i) {
		char z = *(prefix + i);
		if (isOperand(z))
			push(operands, z, &toso);
		else if (isOperator(z)) {
			char a = pop(operands, &toso);
			char b = pop(operands, &toso);
			char * string = (char *)calloc(4, sizeof(char));
			int toss = -1;
			push(string, a, &toss);
			push(string, b, &toss);
			push(string, z, &toss);
			strcat(postfix, string);
		}
		else
			continue;
	}
	
	return postfix;
}


int main(int argc, const char * argv[]) {
	
	char * prefix = (char *)calloc(SIZE, sizeof(char));
	
	printf("\n\tThis program will convert an Prefix expression to Postfix.\n\te.g. + * A B / C D = A B * C D / +.\n\n\tEnter an valid Prefix expression : ");
	fgets(prefix, SIZE, stdin);
	
	char * postfix = toPostfix(prefix);
	
	printf("\n\n\tPrefix: %s\n\tPostfix: %s\n\n", prefix, postfix);
	
	return 0;
}
