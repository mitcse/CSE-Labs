//
//  Balanced.c
//  Balanced Expression Test
//
//  Created by Avikant Saini on 8/24/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define UNDERFLOW '\0'

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

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

void push (char *stack, int item, int *tos) {
	if (*tos == SIZE - 1) {
		printf("\n\tSTACK OVERFLOW\n");
		return;
	}
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

char pop (char *stack, int *tos) {
	if (*tos == -1) {
		printf("\n\tSTACK UNDERFLOW\n");
		return UNDERFLOW;
	}
	return *(stack + ((*tos)--));
}

void display (char *stack, int tos) {
	printf("\n");
	char *pi;
	for (pi = stack; pi <= stack + tos; ++pi)
		printf("\t%c", *pi);
	printf("\n");
}

char relatedBracket (char bracket) {
	if (bracket == '(') return ')';
	else if (bracket == '{') return '}';
	else if (bracket == '[') return ']';
	return '\0';
}

BOOL isBalanced (char * exp, char ** message) {
	int tos = -1, i, l = (int)strlen(exp);
	char *stack = (char *)malloc(sizeof(char *));
	
	
	for (i = 0; i < l; ++i) {
		char z = exp[i];
		if (z == '(' || z == '{' || z == '[')
			push(stack, z, &tos);
		if (z == ')' || z == '}' || z == ']') {
			if (isStackEmpty(tos)) {
				*message = "Unbalanced on right.";
				return NO;
			}
			else {
				if (z == relatedBracket(stack[tos]))
					pop(stack, &tos);
				else {
					*message = "Format mismatch.";
					return NO;
				}
			}
		}
	}
	
	if (isStackEmpty(tos))
		return YES;
	
	*message = "Unbalanced on left.";
	return NO;
}

int main(int argc, const char * argv[]) {
	
	char *string = (char *)malloc(SIZE * sizeof(char));
	char **message = (char **)malloc(100 * sizeof(char *));
	
	printf("\n\tEnter an expression: ");
	scanf("%s", string);
	
	if (isBalanced(string, message))
		printf("\n\t\"%s\" is balanced.\n\n", string);
	else
		printf("\n\t\"%s\" is not balanced.\n\tError: %s\n\n", string, *message);
	
	return 0;
}