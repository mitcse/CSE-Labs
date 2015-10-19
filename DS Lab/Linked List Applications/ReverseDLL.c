//
//  ReverseDLL.c
//  Reverse a doubly linked list containing words
//
//  Created by Avikant Saini on 10/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100

typedef enum { NO, YES } BOOL;

typedef struct Node {
	char * data;
	struct Node * next;
	struct Node * prev;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->data = (char *)malloc(SIZE * sizeof(char));
	temp->prev = temp;
	temp->next = temp;
	return temp;
}

void insert (NODE_p_t list, char *val) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->data = val;
	temp->next = list;
	
	list->prev = temp;
	
	if (list->next == list) {
		temp->prev = list;
		list->next = temp;
	}
	
	else {
		p = list->next;
		
		while (p->next != list)
			p = p->next;
		
		temp->prev = p;
		p->next = temp;
	}
}

void inputList (NODE_p_t list) {
	int i, n;
	
	printf("\n\tEnter number of terms in the list: ");
	scanf("%d", &n);
	
	printf("\n\tEnter the list: ");
	for (i = 0; i < n; ++i) {
		//		printf("\tEnter term %d: ", i+1);
		char *item = (char *)malloc(SIZE * sizeof(char));
		scanf(" %s", item);
		insert(list, item);
	}
}

NODE_p_t createAndInputList () {
	NODE_p_t li = createNode();
	inputList(li);
	return li;
}

/*
 NODE_p_t reverseList (NODE_p_t list) {
	NODE_p_t revList = createNode();
	NODE_p_t temp = list->prev;
	while (temp != list) {
 insert(revList, temp->data);
 temp = temp->prev;
	}
	return revList;
 }
 */

void reverseList2 (NODE_p_t list) {
	
	// finding half of the list using slow and fast pointers
	
	NODE_p_t slow = list->next;
	NODE_p_t fast = list->next;
	
	while (fast != list) {
		fast = fast->next;
		if (fast != list) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	NODE_p_t temp1 = list->next;
	NODE_p_t temp2 = list->prev;
	
	while (temp1 != slow) {
		
		char * swap = temp1->data;
		temp1->data = temp2->data;
		temp2->data = swap;
		
		temp1 = temp1->next;
		temp2 = temp2->prev;
	}
	
}

void displayList (NODE_p_t list) {
	NODE_p_t temp = list->next;
	while (temp->next != list) {
		printf("%s -> ", temp->data);
		temp = temp->next;
	}
	printf("%s", temp->data);
}

int main (int argc, const char * argv []) {
	
	NODE_p_t list = createAndInputList();
	
	printf("\n\t     Initially: ");
	displayList(list);
	reverseList2(list);
	printf("\n\tAfter Reversal: ");
	displayList(list);
	
	//	NODE_p_t revList = reverseList(list);
	//	printf("\n\tAfter Reversal (New): ");
	//	displayList(revList);
	
	printf("\n\n");
	return 0;
}

