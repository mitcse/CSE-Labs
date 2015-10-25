//
//  StackLinkedList.c
//  Stack using linked list
//
//  Created by Avikant Saini on 10/25/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

#define initString(size) (char *)malloc(size * sizeof(char))
typedef char * String;

typedef enum { NO, YES } BOOL;

typedef struct Node {
	String data;
	struct Node *next;
	struct Node *prev;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t initNode (String data) {
	NODE_p_t node = (NODE_p_t)malloc(sizeof(NODE_t));
	node->data = initString(SIZE);
	strcpy(node->data, data);
	node->next = node;
	node->prev = node;
	return node;
}

#pragma mark - Stack methods

void push (NODE_p_t *stack, String data) {
	
	NODE_p_t temp = initNode(data);
	
	if (*stack == NULL) {
		*stack = temp;
		return;
	}
	
	NODE_p_t first = *stack;
	NODE_p_t last = first->prev;
	
	temp->next = first;
	temp->prev = last;
	last->next = temp;
	first->prev = temp;
	
}

NODE_p_t pop (NODE_p_t *stack) {
	
	if (*stack == NULL)
		return NULL;
	
	NODE_p_t first = *stack;
	NODE_p_t last = first->prev;
	NODE_p_t temp = last;
	
	NODE_p_t secondLast = last->prev;
	secondLast->next = first;
	first->prev = secondLast;
	
	return temp;
}

BOOL isEmpty (NODE_p_t stack) {
	return (stack->next == stack);
}

void display (NODE_p_t list) {
	if (list->next != list) {
		NODE_p_t temp = list->next;
		while (temp->next != list) {
			printf(" %s ->", temp->data);
			temp = temp->next;
		}
		printf(" %s\n", temp->data);
	}
}

void displayWithAddress (NODE_p_t list) {
	NODE_p_t temp = list;
	while (temp->next != list) {
		printf("\n\t%s (%p) ->", temp->data, temp);
		temp = temp->next;
	}
	printf("\n\t%s (%p)\n", temp->data, temp);
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	NODE_p_t stack = initNode("<HEAD>");
	
	int choice;
	do {
		printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Display (with address)\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1) {
			String data = initString(SIZE);
			printf("\n\tEnter item to be pushed: ");
			scanf(" %s", data);
			push(&stack, data);
		}
		
		else if (choice == 2) {
			if (!isEmpty(stack)) {
				NODE_p_t temp = pop(&stack);
				printf("\n\tPopped item: %s (%p)\n", temp->data, temp);
			}
			else
				printf("\n\tSTACK UNDERFLOW!");
		}
		
		else if (choice == 4) {
			if (!isEmpty(stack)) {
				printf("\n\tCurrent Stack: ");
				displayWithAddress(stack);
			}
		}
		
		if (!isEmpty(stack)) {
			printf("\n\tCurrent Stack: ");
			display(stack);
		}
		
	} while (choice >= 1 && choice <= 4);
	
}

