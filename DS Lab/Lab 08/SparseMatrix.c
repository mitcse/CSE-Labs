//
//  SparseMatrix.c
//  Adding two sparse matrices using circular linked lists queue
//
//  Created by Avikant Saini on 9/30/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int row;
	int col;
	int value;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->next = temp;
	temp->row = 0;
	temp->col = 0;
	temp->value = 0;
	return temp;
}

void insert (NODE_p_t list, int r, int c, int v) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->next = list;
	temp->row = r;
	temp->col = c;
	temp->value = v;
	
	if (list->next == list)
		list->next = temp;
	
	else {
		p = list->next;
		while (p->next != list)
			p = p->next;
		p->next = temp;
		
	}
}

/*
 // Checks if the row and column has a value before, if true adds the passed value
 BOOL addToMatrixIfPresent (NODE_p_t list, int r, int c, int v) {
	NODE_p_t temp = list->next;
	while (temp != list) {
 if (temp->row == r && temp->col == c) {
 temp->value += v;
 return YES;
 }
 temp = temp->next;
	}
	return NO;
 }
 
 // Adds two sparse matrices
 NODE_p_t addSparseMatrices (NODE_p_t mat1, NODE_p_t mat2) {
	
	NODE_p_t temp1 = mat1->next;
	NODE_p_t temp2 = mat2->next;
	
	NODE_p_t sum = createNode();
	sum->row = mat1->row;	// Header node contains rows and columns
	sum->col = mat1->col;
	
	while (temp1 != mat1) {
 if (!addToMatrixIfPresent(sum, temp1->row, temp1->col, temp1->value))
 insert(sum, temp1->row, temp1->col, temp1->value);
 temp1 = temp1->next;
	}
	while (temp2 != mat2) {
 if (!addToMatrixIfPresent(sum, temp2->row, temp2->col, temp2->value))
 insert(sum, temp2->row, temp2->col, temp2->value);
 temp2 = temp2->next;
	}
	
	return sum;
 }
 
 // Create a dynamically allocated 2D array from the circular list.
 int ** sparseMatrixFromLinkedList (NODE_p_t list) {
	int ** mat = (int **)calloc(list->row + 1, sizeof(int *));
	int i, j;
	for (i = 0; i < list->row; ++i) {
 *(mat + i) = (int *)calloc(list->col + 1, sizeof(int));
 for (j = 0; j < list->col; ++j)
 *(*(mat + i) + j) = 0;
	}
	
	NODE_p_t temp = list->next;
	while (temp != list) {
 *(*(mat + temp->row) + temp->col) = temp->value;
 temp = temp->next;
	}
	
	return mat;
 }
 */

// Create a dynamically allocated 2D array sparse matrix from linked lists
int ** sparseMatrixFromLinkedLists (NODE_p_t list1, NODE_p_t list2) {
	
	int ** mat = (int **)calloc(list1->row, sizeof(int *));
	int i, j;
	
	// Set every element to zero
	for (i = 0; i < list1->row; ++i) {
		*(mat + i) = (int *)calloc(list1->col, sizeof(int));
		for (j = 0; j < list1->col; ++j)
			*(*(mat + i) + j) = 0;
	}
	
	NODE_p_t temp1 = list1->next;
	NODE_p_t temp2 = list2->next;
	
	// Move throught the linked lists and add the value to that index of the matrix
	while (temp1 != list1) {
		*(*(mat + temp1->row) + temp1->col) += temp1->value;
		temp1 = temp1->next;
	}
	while (temp2 != list2) {
		*(*(mat + temp2->row) + temp2->col) += temp2->value;
		temp2 = temp2->next;
	}
	
	return mat;
}


int main (int argc, const char * argv []) {
	
	NODE_p_t mat1 = createNode();
	NODE_p_t mat2 = createNode();
	
	int i, j, r, c, v;
	
	printf("\n\tEnter dimensions of Matrix 1: ");
	scanf("%d %d", &mat1->row, &mat1->col);		// Header contains rows and columns
	
	printf("\n\tEnter Matrix 1's non zero elements (row, column, value). <? ? 0> i.e. v = 0 for break: ");
	do {
		scanf("%d %d %d", &r, &c, &v);
		if (v != 0)
			insert(mat1, r, c, v);
	} while (v != 0);
	
	printf("\n\tEnter dimensions of Matrix 2: ");
	scanf("%d %d", &mat2->row, &mat2->col);		// Header contains rows and columns
	
	printf("\n\tEnter Matrix 2's non zero elements (row, column, value). <? ? 0> i.e. v = 0 for break: ");
	do {
		scanf("%d %d %d", &r, &c, &v);
		if (v != 0)
			insert(mat2, r, c, v);
	} while (v != 0);
	
	
	if (!((mat1->row == mat2->row) && (mat1->col == mat2->col))) {
		printf("\n\tError: Unequal dimensions.\n\n");
		return 9;
	}
	
	int ** sum = sparseMatrixFromLinkedLists(mat1, mat2);
	
	printf("\n\tMatrix Sum:\n");
	for (i = 0; i < mat1->row; ++i) {
		for (j = 0; j < mat1->col; ++j)
			printf("\t%d", *(*(sum + i) + j));
		printf("\n");
	}
	
	printf("\n\n");
}

