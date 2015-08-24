//
//  Stack.c
//  Stack
//
//  Created by Avikant Saini on 8/24/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW '\0'

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
	
	int tos = -1;
	char *stack = (char *)malloc(sizeof(char *));
	char choice;
	
	printf("\n\t1. Push an element.\n\t2. Pop an element.\n\t3. Display current stack.\n\tAnything else for exit.\nEnter your choice: ");
	scanf("%s", &choice);
	while (choice == '1' || choice == '2' || choice == '3') {
		if (choice == '1') {
			char item;
			printf("\n\tEnter element to be pushed: ");
			scanf("%s", &item);
			push(stack, item, &tos);
			printf("\nCurrent Stack: ");
			display(stack, tos);
		}
		else if (choice == '2') {
			char item = pop(stack, &tos);
			printf("\n\tPopped item = %c\n", item);
			printf("\nCurrent Stack: ");
			display(stack, tos);
		}
		else if (choice == '3') {
			printf("\nCurrent Stack: ");
			display(stack, tos);
		}
		else
			exit(0);
		printf("\n\t1. Push an element.\n\t2. Pop an element.\n\t3. Display current stack.\n\tAnything else for exit.\nEnter your choice: ");
		scanf("%s", &choice);
	}
	return 0;
}