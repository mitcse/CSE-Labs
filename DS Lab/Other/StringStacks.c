//
//  Stack.c
//  Stack Operations
//
//  Created by Avikant Saini on 8/25/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW NULL

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

void push (char ** stack, char * item, int *tos) {
	if (isStackFull (*tos)) {
		printf("\n\tSTACK OVERFLOW\n");
		return;
	}
	(*tos) += 1;
	*(stack + (*tos)) = item;
}

char * pop (char ** stack, int *tos) {
	if (isStackEmpty (*tos)) {
		printf("\n\tSTACK UNDERFLOW\n");
		return UNDERFLOW;
	}
	return *(stack + ((*tos)--));
}

void display (char ** stack, int tos) {
	printf("\n");
	char ** pi;
	for (pi = stack; pi <= stack + tos; ++pi)
		printf("\n\t%s", *pi);
	printf("\n\n");
}

int main(int argc, const char * argv[]) {
	
	int tos = -1;
	
	char ** stack = (char **)calloc(SIZE, sizeof(char *));
	
	int choice;
	do {
		printf("\n\t1. Push an element.\n\t2. Pop an element.\n\t3. Display current stack.\n\tAnything else for exit.\nEnter your choice: ");
		scanf(" %d", &choice);
		// scanf(" %s", &choice);
		if (choice == 1) {
			char * item = (char *)calloc(SIZE, sizeof(char));
			printf("\n\tEnter element to be pushed: ");
			scanf(" %s", item);
			push(stack, item, &tos);
			if (!isStackFull(tos)) {
				printf("\nCurrent Stack: ");
				display(stack, tos);
			}
		}
		else if (choice == 2) {
			char * item = pop(stack, &tos);
			if (item != UNDERFLOW) {
				printf("\n\tPopped item = %s\n", item);
				printf("\nCurrent Stack: ");
				display(stack, tos);
			}
		}
		else if (choice == 3) {
			printf("\n\tCurrent Stack: ");
			display(stack, tos);
		}
		else
			exit(0);
	} while (choice == 1 || choice == 2 || choice == 3);
	return 0;
}
