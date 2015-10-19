//
//  BinaryTree.c
//  Binary tree building and transversals (Recursive and iterative)
//
//  Created by Avikant Saini on 10/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

/**
 *	Sample tree: A B K # # C H # I # J # # D E # F G # # # # #
 *	Sample tree: F B A # # D C # # E # # G # I H # # #
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

#define initString(size) (char *)malloc(size * sizeof(char))

typedef enum { NO, YES } BOOL;

typedef char * String;

typedef struct TNode {
	String data;
	struct TNode *left;
	struct TNode *right;
} TNODE_t;

typedef TNODE_t * TNODE_p_t;

#pragma mark - Stack declarations

typedef struct Stack {
	TNODE_p_t *arr;
	int capacity;
	int tos;
} STACK_t;

typedef STACK_t * STACK_p_t;

STACK_p_t initStack () {
	STACK_p_t stack = (STACK_p_t)malloc(sizeof(STACK_t));
	stack->capacity = SIZE;
	stack->arr = (TNODE_p_t *)malloc(stack->capacity * sizeof(TNODE_p_t));
	stack->tos = -1;
	return stack;
}

void push (STACK_p_t stack, TNODE_p_t item) {
	if (stack->tos == stack->capacity - 1) {
		stack->capacity *= 2;
		stack->arr = (TNODE_p_t *)realloc(stack->arr, stack->capacity * sizeof(TNODE_p_t));
	}
	*(stack->arr + ++(stack->tos)) = item;
}

TNODE_p_t pop (STACK_p_t stack) {
	if (stack->tos == -1)
		return NULL;
	return *(stack->arr + (stack->tos)--);
}

BOOL isEmpty (STACK_p_t stack) {
	return (stack->tos == -1);
}

#pragma mark - Tree creations

TNODE_p_t initNode (String data) {
	TNODE_p_t node = (TNODE_p_t)malloc(sizeof(TNODE_t));
	node->data = initString(SIZE);
	strcpy(node->data, data);
	node->left = NULL;
	node->right = NULL;
	return node;
}

TNODE_p_t createNode () {
	
	TNODE_p_t root;
	String data = initString(SIZE);
	
	printf("\tEnter data (# for break): ");
	scanf(" %s", data);
	
	if (*data == '#')
		return NULL;
	
	root = initNode(data);
	
	printf("\tLeft of '%s' | ", root->data);
	root->left = createNode();
	
	printf("\tRight of '%s' | ", root->data);
	root->right = createNode();
	
	return root;
}

#pragma mark - Recursive transversals

void preorderRecursive (TNODE_p_t root) {
	if (root != NULL) {
		printf("%s ", root->data);
		preorderRecursive(root->left);
		preorderRecursive(root->right);
	}
}

void inorderRecursive (TNODE_p_t root) {
	if (root != NULL) {
		inorderRecursive(root->left);
		printf("%s ", root->data);
		inorderRecursive(root->right);
	}
}

void postorderRecursive (TNODE_p_t root) {
	if (root != NULL) {
		postorderRecursive(root->left);
		postorderRecursive(root->right);
		printf("%s ", root->data);
	}
}

int height (TNODE_p_t root) {
	if (root == NULL)
		return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return (leftHeight > rightHeight)?(leftHeight + 1):(rightHeight + 1);
}

void printLevel (TNODE_p_t root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		printf("%s ", root->data);
	else {
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

void levelOrder (TNODE_p_t root) {
	int h = height(root), i;
	for (i = 1; i <= h; ++i)
		printLevel(root, i);
}

#pragma mark - Iterative transversals

void preorderIterative (TNODE_p_t root) {
	STACK_p_t stack = initStack();
	TNODE_p_t temp = root;
	while (!isEmpty(stack) || temp != NULL) {
		if (temp != NULL) {
			printf("%s ", temp->data);
			if (temp->right != NULL)
				push(stack, temp->right);
			temp = temp->left;
		}
		else
			temp = pop(stack);
	}
}

void inorderIterative (TNODE_p_t root) {
	STACK_p_t stack = initStack();
	TNODE_p_t temp = root;
	while (!isEmpty(stack) || temp != NULL) {
		if (temp != NULL) {
			push(stack, temp);
			temp = temp->left;
		}
		else {
			temp = pop(stack);
			printf("%s ", temp->data);
			temp = temp->right;
		}
	}
}

void postorderIterative (TNODE_p_t root) {
	STACK_p_t stack = initStack();
	TNODE_p_t temp = root;
	TNODE_p_t last = NULL;
	while (!isEmpty(stack) || temp != NULL) {
		if (temp != NULL) {
			push(stack, temp);
			temp = temp->left;
		}
		else {
			TNODE_p_t peek = *(stack->arr + stack->tos);
			if ((peek->right != NULL) && (last != peek->right))
				temp = peek->right;
			else {
				printf("%s ", peek->data);
				last = pop(stack);
			}
		}
	}
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	TNODE_p_t tree = createNode();
	
	printf("\n\tPreorder (Rec): \n");
	preorderRecursive(tree);
	
	printf("\n\tPreorder (Iter): \n");
	preorderIterative(tree);
	
	printf("\n\n\tInorder (Rec): \n");
	inorderRecursive(tree);
	
	printf("\n\tInorder (Iter): \n");
	inorderIterative(tree);
	
	printf("\n\n\tPostorder (Rec): \n");
	postorderRecursive(tree);
	
	printf("\n\tPostorder (Iter): \n");
	postorderIterative(tree);
	
	printf("\n\n\tLevel Order: \n");
	levelOrder(tree);
	
}

