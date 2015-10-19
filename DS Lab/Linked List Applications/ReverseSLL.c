//
//  ReverseSLL.c
//  Reversing a singly linked list (Circular, with a header node)
//
//  Created by Avikant Saini on 10/18/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 50

typedef enum { NO, YES } BOOL;

typedef struct Node {
	char *data;
	struct Node *next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->data = (char *)malloc(SIZE * sizeof(char));
	temp->next = temp;
	return temp;
}

void insert (NODE_p_t list, char *data) {
	NODE_p_t temp = createNode();
	strcpy(temp->data, data);
	
	NODE_p_t p = list->next;
	
	while (p->next != list)
		p = p->next;
	
	p->next = temp;
	temp->next = list;
	
}

void reverse (NODE_p_t * list) {
	NODE_p_t prev = NULL;
	NODE_p_t curr = (*list)->next;	// *list is header
	NODE_p_t next = NULL;			// next node after the header
	while (curr != *list) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	NODE_p_t newHead = createNode();	// Create new header
	newHead->next = prev;				// Set the new header to last node
	NODE_p_t temp = newHead->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newHead;				// Set the new header to the list's end
	*list = newHead;
}

void display (NODE_p_t list) {
	NODE_p_t temp = list->next;
	
	if (temp != list)  {
		while (temp->next != list) {
			printf(" %s ->", temp->data);
			temp = temp->next;
		}
		printf(" %s", temp->data);
		temp = temp->next;
	}
	
	printf("\n-------------------------------------------------------------------------\n");
}


int main (int argc, const char * argv []) {
	
	NODE_p_t list = createNode();
	
	printf("\n\tEnter list elements one by one. Enter 0 to break: \n");
	
	char *str = (char *)malloc(SIZE * sizeof(char));
	do {
		scanf(" %s", str);
		if (!(strlen(str) == 1 && *str == '0'))
			insert(list, str);
	} while (*str != '0');
	
	printf("\n\tInitially: ");
	display(list);
	
	reverse(&list);
	
	printf("\n\t Reversed: ");
	display(list);
	
}
