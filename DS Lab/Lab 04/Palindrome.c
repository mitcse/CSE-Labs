//
//  Palindrome.c
//  Palindrome
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

int main(int argc, const char * argv[]) {
	
	int tos = -1, i;
	char *stack = (char *)malloc(sizeof(char *));
	char *string = (char *)malloc(sizeof(char *));
	
	printf("\n\tEnter a string: ");
	scanf("%s", string);
	
	for (i = 0; i < strlen(string); ++i) {
		push(stack, string[i], &tos);
	}
	
	BOOL palindrome = YES;
	for (i = 0; i < strlen(string)/2; ++i) {
		if (pop(stack, &tos) != string[i]) {
			palindrome = NO;
			break;
		}
	}
	
	if (palindrome)
		printf("\n\t\"%s\" is Palindrome.\n\n", string);
	else
		printf("\n\t\"%s\" is not Palindrome.\n\n", string);
	
	return 0;
}