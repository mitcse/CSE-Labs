//
//  SetOperations.c
//  Set operations using linked list (circular with header node).
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

#pragma mark - List definition

typedef struct Node {
	String data;
	struct Node *next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t initNode (String data) {
	NODE_p_t node = (NODE_p_t)malloc(sizeof(NODE_t));
	node->data = initString(SIZE);
	strcpy(node->data, data);
	node->next = node;
	return node;
}

#pragma mark - Insert, input

void insert (NODE_p_t list, String data) {
	NODE_p_t temp = initNode(data);
	temp->next = list;
	
	if (list->next == list) {
		list->next = temp;
		return;
	}
	
	NODE_p_t p = list;
	while (p->next != list && (strcmp(p->next->data, data) < 0))
		p = p->next;
	temp->next = p->next;
	p->next = temp;
}

BOOL containsItem (NODE_p_t list, String item) {
	NODE_p_t temp = list->next;
	while (temp != list) {
		if (strcmp(item, temp->data) == 0)
			return YES;
		temp = temp->next;
	}
	return NO;
}

NODE_p_t createAndInputList (String id) {
	NODE_p_t list = initNode(id);
	String data = initString(SIZE);
	printf("\n\tEnter data of list '%s' (Enter # to break): ", id);
	do {
		scanf(" %s", data);
		if (*data != '#' && !containsItem(list, data))
			insert(list, data);
	} while (*data != '#');
	return list;
}

#pragma mark - Set operations

NODE_p_t unionList (NODE_p_t lista, NODE_p_t listb) {
	NODE_p_t listu = initNode("UNION");
	NODE_p_t tempa = lista->next, tempb = listb->next;
	while (tempa != lista) {
		String data = tempa->data;
		if (!containsItem(listu, data))
			insert(listu, data);
		tempa = tempa->next;
	}
	while (tempb != listb) {
		String data = tempb->data;
		if (!containsItem(listu, data))
			insert(listu, data);
		tempb = tempb->next;
	}
	return listu;
}

NODE_p_t intersectionList (NODE_p_t lista, NODE_p_t listb) {
	NODE_p_t listi = initNode("INTERSECTION");
	NODE_p_t tempa = lista->next;
	while (tempa != lista) {
		if (containsItem(listb, tempa->data))
			insert(listi, tempa->data);
		tempa = tempa->next;
	}
	return listi;
}

NODE_p_t sumLists (NODE_p_t lista, NODE_p_t listb) {
	NODE_p_t lists = initNode("SUM");
	NODE_p_t tempa = lista->next, tempb = listb->next;
	while (tempa != lista && tempb != listb) {
		String sa = tempa->data;
		String sb = tempb->data;
		if (strcmp(sa, sb) < 0) {
			insert(lists, sa);
			tempa = tempa->next;
		}
		else {
			insert(lists, sb);
			tempb = tempb->next;
		}
	}
	while (tempa != lista) {
		insert(lists, tempa->data);
		tempa = tempa->next;
	}
	while (tempb != listb) {
		insert(lists, tempb->data);
		tempb = tempb->next;
	}
	return lists;
}

NODE_p_t differenceLists (NODE_p_t lista, NODE_p_t listb) {
	NODE_p_t listd = initNode("DIFFERENCE");
	NODE_p_t tempa = lista->next;
	while (tempa != lista) {
		if (!containsItem(listb, tempa->data))
			insert(listd, tempa->data);
		tempa = tempa->next;
	}
	return listd;
}

void display (NODE_p_t list) {
	NODE_p_t temp = list->next;
	if (temp != list) {
		while (temp->next != list) {
			printf(" %s ->", temp->data);
			temp = temp->next;
		}
		printf(" %s", temp->data);
	}
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	NODE_p_t lista = createAndInputList("A");
	NODE_p_t listb = createAndInputList("B");
	
	printf("\n\t    A: ");
	display(lista);
	
	printf("\n\t    B: ");
	display(listb);
	
	printf("\n\tA U B: ");
	display(unionList(lista, listb));
	
	printf("\n\tA I B: ");
	display(intersectionList(lista, listb));
	
	printf("\n\tA + B: ");
	display(sumLists(lista, listb));
	
	printf("\n\tA - B: ");
	display(differenceLists(lista, listb));
	
	printf("\n\n");
}

