//
//	AdjList.c
//	Representation of a graph: Adjacency list form
//
//	Created by Avikant Saini on 11/14/15
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
	int vertex;
	struct AdjNode *next;
} ADJ_NODE_t, *ADJ_NODE_p_t;

typedef struct AdjListNode {
	int count;
	ADJ_NODE_p_t head;
} ADJ_LIST_NODE_t, *ADJ_LIST_NODE_p_t;

ADJ_NODE_p_t createAdjNode (int value) {
	ADJ_NODE_p_t adjNode = (ADJ_NODE_p_t)malloc(sizeof(ADJ_NODE_t));
	adjNode->vertex = value;
	adjNode->next = NULL;
	return adjNode;
}

ADJ_LIST_NODE_p_t createAdjListNode () {
	ADJ_LIST_NODE_p_t adjListNode = (ADJ_LIST_NODE_p_t)malloc(sizeof(ADJ_LIST_NODE_t));
	adjListNode->count = 0;
	adjListNode->head = NULL;
	return adjListNode;
}

void insertAdjNode (ADJ_NODE_p_t *head, int value) {
	if (*head == NULL) {
		*head = createAdjNode(value);
		return;
	}
	ADJ_NODE_p_t temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = createAdjNode(value);
}

ADJ_LIST_NODE_p_t * inputAdjList () {
	
	int n, i, vertex;
	printf("\n\tEnter the number of vertices: ");
	scanf(" %d", &n);
	
	ADJ_LIST_NODE_p_t *listHeadArr = (ADJ_LIST_NODE_p_t *)calloc(n, sizeof(ADJ_LIST_NODE_p_t));
	
	ADJ_LIST_NODE_p_t temp;
	for (i = 0; i < n; ++i) {
		*(listHeadArr + i) = createAdjListNode();
		temp = *(listHeadArr + i);
		printf("\n\tVertex %d, Enter the connected vertices (1 - %d), 0 to break: ", i+1, n);
		do {
			scanf(" %d", &vertex);
			if (vertex != 0)
				insertAdjNode(&temp->head, vertex);
		} while (vertex != 0);
	}
	
	return listHeadArr;
}

void printAdjList (ADJ_LIST_NODE_p_t *listHeadArr) {
	int i = 0;
	ADJ_LIST_NODE_p_t temp = *(listHeadArr + i);
	while (temp != NULL) {
		printf("\n\t %d | ", i+1);
		temp = *(listHeadArr + i);
		ADJ_NODE_p_t p = temp->head;
		while (p->next != NULL) {
			printf(" %d ->", p->vertex);
			p = p->next;
		}
		printf(" %d ", p->vertex);
		temp = *(listHeadArr + (++i));
	}
}

#pragma mark - Main

int main (int argc, const char * argv[]) {
	ADJ_LIST_NODE_p_t *listHeadArr = inputAdjList();
	printAdjList(listHeadArr);
}



