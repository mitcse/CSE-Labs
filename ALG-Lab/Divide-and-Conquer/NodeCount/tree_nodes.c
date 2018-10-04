//
//	tree_nodes.c
//	Count of nodes in a tree.
//
//  Created by Avikant Saini on 10/30/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum { NO, YES } BOOL;

typedef struct TNode {
	int data;
	struct TNode *left;
	struct TNode *right;
} TNODE_t;

typedef TNODE_t * TNODE_p_t;

#pragma mark - Tree creation

TNODE_p_t initNode (int data) {
	TNODE_p_t node = (TNODE_p_t)malloc(sizeof(TNODE_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TNODE_p_t insert (TNODE_p_t root, int data) {
	
	if (root == NULL)
		return initNode(data);
	
	if (data < root->data)
		root->left = insert(root->left, data);
	
	else if (data > root->data)
		root->right = insert(root->right, data);
	
	return root;
}

TNODE_p_t buildTree (char * string) {
	int data;
	TNODE_p_t root = NULL;
	char *tmp = (char *)malloc(65536 * sizeof(char));
	strcpy(tmp, string);
	do {
		// printf("\tEnter data (-99 for break): ");
		sscanf(tmp, " %d", &data);
		// printf("Scanned: %d ", data);
		tmp = tmp+3;
		// scanf(" %d", &data);
		if (data != -99) {
			if (root == NULL)
				root = initNode(data);
			else
				insert(root, data);
		}
	} while (data != -99);
	return root;
}

#pragma mark - Node count

int nodeCount (TNODE_p_t root) {
	if (root == NULL)
		return 1;
	int leftCount = nodeCount(root->left);
	int rightCount = nodeCount(root->right);
	return (leftCount + rightCount);
}

int leafCount (TNODE_p_t root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int leftCount = leafCount(root->left);
	int rightCount = leafCount(root->right);
	return (leftCount + rightCount);
}

#pragma mark - Transversals

void preorderTransversal (TNODE_p_t root) {
	if (root != NULL) {
		printf(" %d", root->data);
		preorderTransversal(root->left);
		preorderTransversal(root->right);
	}
}

void inorderTransversal (TNODE_p_t root) {
	if (root != NULL) {
		inorderTransversal(root->left);
		printf(" %d", root->data);
		inorderTransversal(root->right);
	}
}

void postorderTransversal (TNODE_p_t root) {
	if (root != NULL) {
		postorderTransversal(root->left);
		postorderTransversal(root->right);
		printf(" %d", root->data);
	}
}
#pragma mark - Test

int main (int argc, char const * argv []) {
	clock_t start_time, end_time;
	double total_time;

	FILE *input = fopen("trees.txt", "r");
	FILE *output = fopen("number_of_nodes.csv", "w+");
	fprintf(output, "inputsize, time\n");

	int i = 0, c = 0, x;
	char *string = (char *)malloc(65536 * sizeof(char));

	while ((fscanf(input, " %d", &x))) {
		
		sprintf(string, "%s%d ", string, x);
		c++;

		if (x == -99) {

			if (c == 1)
				break;

			// printf("\n%d: %s\n", c, string);

			TNODE_p_t tree = buildTree(string);

			int nn = nodeCount(tree);

			start_time = clock();
		
			for (i = 0; i < 10000; ++i) {
				nodeCount(tree);
			}

			end_time = clock();
			total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

			fprintf(output, "%d, %lf\n", nn, total_time);

			c = 0;
			string = (char *)malloc(1024 * sizeof(char));

		}
	}

	return 0;
}