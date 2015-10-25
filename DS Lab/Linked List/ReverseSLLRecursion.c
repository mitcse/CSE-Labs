//
//  ReverseSLLRecursion.c
//  Reversing a singly linked list using recursion, (No header node in the list).
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
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t initNode (String data) {
	NODE_p_t node = (NODE_p_t)malloc(sizeof(NODE_t));
	node->data = initString(SIZE);
	strcpy(node->data, data);
	node->next = NULL;
	return node;
}

void insert (NODE_p_t * list, String data) {
	
	NODE_p_t temp = initNode(data);
	
	if (*list == NULL) {
		*list = temp;
		return;
	}
	
	NODE_p_t p = *list;
	while (p->next != NULL)
		p = p->next;
	
	p->next = temp;
}

void display (NODE_p_t list) {
	NODE_p_t temp = list;
	while (temp->next != NULL) {
		printf(" %s ->", temp->data);
		temp = temp->next;
	}
	printf(" %s\n", temp->data);
}

void reverseList (NODE_p_t * list) {
	
	// If empty list, return.
	
	if (*list == NULL)
		return;
	
	// Divide the list into two parts, the first node, and the rest of the list.
	
	NODE_p_t first = *list;
	NODE_p_t rest = first->next;
	
	// If rest is null, i.e. only one node, return.
	
	if (rest == NULL)
		return;
	
	// Call recursive reverse for the rest of the list.
	
	reverseList(&rest);
	
	// Set the first node as the last node, i.e. set the next of the second node to first's.
	
	NODE_p_t second = first->next;
	second->next = first;
	
	// Set first's link to null.
	
	first->next = NULL;
	*list = rest;
	
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	NODE_p_t list = NULL;
	
	String data = initString(SIZE);
	
	printf("\n\tEnter elements into the list (Enter # to break):\n");
	do {
		scanf(" %s", data);
		if (*data != '#')
			insert(&list, data);
	} while (*data != '#');
	
	printf("\n\tInitially: ");
	display(list);
	
	reverseList(&list);
	
	printf("\n\t Reversed: ");
	display(list);
	
	printf("\n\n");
	return 0;
	
}