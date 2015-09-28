//
//  Merge Linked List.c
//  Merging two linked lists sorted in ascending order
//
//  Created by Avikant Saini on 9/28/15.
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
	temp->next = NULL;
	temp->data = UNDERFLOW_CHAR;
	return temp;
}

NODE_p_t insert (NODE_p_t list, char item) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->data = item;
	
	if (list->next == NULL) {
		list->next = temp;
		list->data = item;
	}
	
	else {
		p = list->next;
		
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
		
	}
	list->data++;
	return list;
}

void display (NODE_p_t list) {
	NODE_p_t temp = list->next;
	
	if (list->next != NULL)  {
		while (temp != NULL) {
			printf("\t%c", temp->data);
			temp = temp->next;
		}
	}
}


int main (int argc, const char * argv []) {
	
	NODE_p_t list1 = createNode();
	NODE_p_t list2 = createNode();
	NODE_p_t newList = createNode();
	
	int i, n;
	char item;
	
	printf("\n\tList 1: Enter number of elements: ");
	scanf("%d", &n);
	printf("\n\tEnter List 1 elements in ascending order: ");
	for (i = 0; i < n; ++i) {
		scanf(" %c", &item);
		list1 = insert(list1, item);
	}
	
	printf("\n\tList 2: Enter number of elements: ");
	scanf("%d", &n);
	printf("\n\tEnter List 2 elements in ascending order: ");
	for (i = 0; i < n; ++i) {
		scanf(" %c", &item);
		list2 = insert(list2, item);
	}
	
	NODE_p_t temp1 = list1->next;
	NODE_p_t temp2 = list2->next;
	
	while (temp1 != NULL && temp2 != NULL) {
		char c1 = temp1->data;
		char c2 = temp2->data;
		if (c1 > c2) {
			newList = insert(newList, c2);
			temp2 = temp2->next;
		}
		else {
			newList = insert(newList, c1);
			temp1 = temp1->next;
		}
	}
	while (temp1 != NULL) {
		newList = insert(newList, temp1->data);
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		newList = insert(newList, temp2->data);
		temp2 = temp2->next;
	}
	
	printf("\n\tList 1: ");
	display(list1);
	printf("\n\tList 2: ");
	display(list2);
	printf("\n\tMerged List: ");
	display(newList);
}
