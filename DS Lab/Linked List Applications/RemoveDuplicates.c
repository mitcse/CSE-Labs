//
//  RemoveDuplicates.c
//  Remove duplicates from a singly linked list, non circular, non header node
//	Inclusive of freeing memory
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
	int data;
	struct Node *next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->data = 0;
	temp->next = NULL;
	return temp;
}

void insert (NODE_p_t * list, int data) {
	
	if (*list == NULL) {
		*list = createNode();
		(*list)->data = data;
		return;
	}
	
	NODE_p_t temp = createNode();
	temp->data = data;
	
	NODE_p_t p = *list;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
}

void removeDuplicates (NODE_p_t list) {
	NODE_p_t p = list;
	while (p != NULL) {
		NODE_p_t temp = p;
		while (temp != NULL && temp->data == p->data) {
			p->next = temp->next;
			temp = temp->next;
		}
		p = p->next;
	}
}

void freeMemory (NODE_p_t list) {
	NODE_p_t p = list;
	while (p != list) {
		NODE_p_t temp = p;
		p = p->next;
		free(temp);
	}
	list = NULL;
}

void display (NODE_p_t list) {
	NODE_p_t temp = list;
	if (temp != NULL)  {
		while (temp->next != NULL) {
			printf(" %d ->", temp->data);
			temp = temp->next;
		}
		printf(" %d", temp->data);
		temp = temp->next;
	}
	
	printf("\n-------------------------------------------------------------------------\n");
}


int main (int argc, const char * argv []) {
	
	NODE_p_t list = NULL;
	
	printf("\n\tEnter sorted list, -99 to break: \n");
	
	int data;
	do {
		scanf(" %d", &data);
		if (data != -99)
			insert(&list, data);
	} while (data != -99);
	
	printf("\n\tInitially: ");
	display(list);
	
	removeDuplicates(list);
	
	printf("\n\t  No Dups: ");
	display(list);
	
	freeMemory(list);
	
}
