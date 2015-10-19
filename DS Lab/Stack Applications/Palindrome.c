//
//  Palindrome.c
//  Palindrome
//
//  Created by Avikant Saini on 8/25/15.
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
	if (isStackFull (*tos)) {
		printf("\n\tSTACK OVERFLOW\n");
		return;
	}
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

char pop (char *stack, int *tos) {
	if (isStackEmpty (*tos)) {
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

BOOL isPalindrome (char *string) {
	int tos = -1, i;
	char *stack = (char *)malloc(sizeof(char *));
	
	for (i = 0; i < strlen(string); ++i)
		push(stack, string[i], &tos);
	
	for (i = 0; i < strlen(string)/2; ++i)
		if (pop(stack, &tos) != string[i])
			return NO;
	return YES;
}

int main(int argc, const char * argv[]) {
	
	char *string = (char *)malloc(SIZE * sizeof(char));
	
	printf("\n\tEnter a string: ");
	scanf("%s", string);
	
	if (isPalindrome (string))
		printf("\n\t\"%s\" is Palindrome.\n\n", string);
	else
		printf("\n\t\"%s\" is not Palindrome.\n\n", string);
	
	return 0;
}
