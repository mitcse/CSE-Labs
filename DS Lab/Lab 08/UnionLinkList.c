//
//  UnionLinkedList.c
//  Union operation using singly circular linked list
//
//  Created by Avikant Saini on 9/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW_CHAR '\0'

typedef enum { NO, YES } BOOL;

typedef struct Node {
	char data;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->next = temp;
	temp->data = UNDERFLOW_CHAR;
	return temp;
}

void insert (NODE_p_t list, char item) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->data = item;
	temp->next = list;
	
	if (list->next == list)
		list->next = temp;
	
	else {
		p = list->next;
		
		while (p->next != list)
			p = p->next;
		p->next = temp;
		
	}
}

BOOL listContainsItem (NODE_p_t list, char item) {
	NODE_p_t temp = list->next;
	while (temp != list) {
		if (temp->data == item)
			return YES;
		temp = temp->next;
	}
	return NO;
}

void display (NODE_p_t list) {
	NODE_p_t temp = list->next;
	
	if (temp != list)  {
		while (temp->next != list) {
			printf(" %c ->", temp->data);
			temp = temp->next;
		}
		printf(" %c", temp->data);
		temp = temp->next;
	}
}

int main (int argc, const char * argv []) {
	
	NODE_p_t list1 = createNode();
	NODE_p_t list2 = createNode();
	NODE_p_t unionList = createNode();
	
	int i, n;
	char item;
	
	printf("\n\tList 1: Enter number of elements: ");
	scanf("%d", &n);
	printf("\n\tEnter List 1 elements: ");
	for (i = 0; i < n; ++i) {
		scanf(" %c", &item);
		insert(list1, item);
	}
	
	printf("\n\tList 2: Enter number of elements: ");
	scanf("%d", &n);
	printf("\n\tEnter List 2 elements: ");
	for (i = 0; i < n; ++i) {
		scanf(" %c", &item);
		insert(list2, item);
	}
	
	NODE_p_t temp1 = list1->next;
	NODE_p_t temp2 = list2->next;
	
	while (temp1 != list1) {
		char item = temp1->data;
		if (!listContainsItem(unionList, item))
			insert(unionList, item);
		temp1 = temp1->next;
	}
	while (temp2 != list2) {
		char item = temp2->data;
		if (!listContainsItem(unionList, item))
			insert(unionList, item);
		temp2 = temp2->next;
	}
	
	printf("\n\tList 1: ");
	display(list1);
	printf("\n\tList 2: ");
	display(list2);
	printf("\n\t Union: ");
	display(unionList);
	
	printf("\n\n");
}
