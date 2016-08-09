//
//  GraphRep.c
//  Graph representations in adj list and matrix format.
//
//  Created by Avikant Saini on 09/08/16.
//  Copyright © 2016 avikantz. All rights reserved.
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

ADJ_LIST_NODE_p_t * inputAdjList (int v) {
	
	int i, vertex;

	ADJ_LIST_NODE_p_t *listHeadArr = (ADJ_LIST_NODE_p_t *)calloc(v, sizeof(ADJ_LIST_NODE_p_t));
	
	ADJ_LIST_NODE_p_t temp;
	for (i = 0; i < v; ++i) {
		*(listHeadArr + i) = createAdjListNode();
		temp = *(listHeadArr + i);
		printf("\n\tVertex %d, Enter the connected vertices (1 - %d), 0 to break: ", i+1, v);
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

int ** inputAdjMatrix (int v) {
	int i, j, vertex;
	int ** mat = (int **)calloc(v, sizeof(int *));
	for (i = 0; i < v; ++i) {
		*(mat + i) = (int *)calloc(v, sizeof(int));
		for (j = 0; j < v; ++j) {
			*(*(mat + i) + j) = 0;
		}
	}
	for (i = 0; i < v; ++i) {
		printf("\n\tVertex %d, Enter the connected vertices (1 - %d), 0 to break: ", i+1, v);
		do {
			scanf(" %d", &vertex);
			if (vertex != 0) {
				*(*(mat + i) + vertex) = 1;
			}
		} while (vertex != 0);
	}
	return mat;
}

void printAdjMatrix (int ** mat, int v) {
	int i, j;
	for (i = 0; i < v; ++i) {
		printf("\n\t %d | ", i+1);
		for (j = 0; j < v; ++j) {
			if (*(*(mat + i) + j))
				printf(" %d  ", j);
		}
	}
}

int main (int argc, const char * argv []) {

	int v, e;
	printf("\tEnter number of vertices: ");
	scanf(" %d", &v);
	printf("\t   Enter number of edges: ");
	scanf(" %d", &e);

	if (e > v) {
		printf("\n\tUsing list representation.\n");
		ADJ_LIST_NODE_p_t *list = inputAdjList(v);
		printAdjList(list);
	} else {
		printf("\n\tUsing matrix representation.\n");
		int ** mat = inputAdjMatrix(v);
		printAdjMatrix(mat, v);
	}

	printf("\n\n");

	return 0;
}