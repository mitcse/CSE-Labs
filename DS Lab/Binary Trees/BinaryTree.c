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
	
	printf("\t Left of '%s' | ", root->data);
	root->left = createNode();
	
	printf("\tRight of '%s' | ", root->data);
	root->right = createNode();
	
	return root;
}

#pragma mark - Tree insertions

void insertIterative (TNODE_p_t *root, String item) {
	
	int ch;
	TNODE_p_t t = *root;
	TNODE_p_t present = NULL;
	TNODE_p_t newnode;
	
	if (*root == NULL) {
		*root = initNode(item);
		return;
	}
	
	do {
		printf("\tCurrent: '%s' | 1. Left%s; 2. Right%s | Choice: ", t->data, ((t->left == NULL)?"(*)":""), ((t->right == NULL)?"(*)":""));
		scanf(" %d", &ch);
		present = t;
		
		if (ch == 1)
			t = t->left;
		else if (ch == 2)
			t = t->right;
		
		if (t == NULL) {
			newnode = initNode(item);
			(ch == 1)?(present->left = newnode):(present->right = newnode);
			return;
		}
		
	} while (YES);
}

void insertRecursive (TNODE_p_t *root, String item) {
	if (*root == NULL) {
		*root = initNode(item);
		return;
	}
	else {
		int ch;
		TNODE_p_t t = *root;
		printf("\tCurrent: '%s' | 1. Left%s; 2. Right%s | Choice: ", t->data, ((t->left == NULL)?"(*)":""), ((t->right == NULL)?"(*)":""));
		scanf(" %d", &ch);
		
		if (ch == 1)
			insertRecursive(&(t->left), item);
		else if (ch == 2)
			insertRecursive(&(t->right), item);
	}
}

#pragma mark - Search

TNODE_p_t search (TNODE_p_t root, String item) {
	if (root == NULL)
		return NULL;
	if (strcmp(root->data, item) == 0)
		return root;
	TNODE_p_t left = search(root->left, item);
	TNODE_p_t right = search(root->right, item);
	return (left != NULL)?left:((right != NULL)?right:NULL);
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

/**
 *	Initilize an empty stack.
 *	if (stack is empty, or, node is not null)
 *		if (node is not null)
 *			visit node
 *			if (node->right is not null)
 *				push node->right into the stack
 *			node = node->left
 *		else
 *			node = pop stack
 */

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

/**
 *	Initilize an empty stack
 *	if (stack is not empty, or node is not null)
 *		if (node is not null)
 *			push node into the stack
 *			node = node->left
 *		else
 *			node = pop stack
 *			visit node
 *			node = node->right
 */

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

#pragma mark - BST checker

void inorderToStack (TNODE_p_t root, STACK_p_t *stack) {
	if (root != NULL) {
		inorderToStack(root->left, stack);
		push(*stack, root);
		inorderToStack(root->right, stack);
	}
}

BOOL isBST (TNODE_p_t root) {
	
	STACK_p_t stack = initStack();
	inorderToStack(root, &stack);
	
	if (isEmpty(stack))
		return YES;
	
	TNODE_p_t last = pop(stack);
	
	while (!isEmpty(stack)) {
		
		TNODE_p_t slast = pop(stack);
		
		if (strcmp(last->data, slast->data) < 0)
			return NO;
	}
	
	return YES;
}

#pragma mark - Mirror Checker

BOOL isMirror (TNODE_p_t root) {
	
	STACK_p_t stack = initStack();
	inorderToStack(root, &stack);
	
	if (stack->tos < 1)
		return YES;
	
	int i;
	for (i = 0; i <= stack->tos/2; ++i) {
		TNODE_p_t nodei = *(stack->arr + i);
		TNODE_p_t nodeli = *(stack->arr + stack->tos - i);
		if (strcmp(nodei->data, nodeli->data) != 0)
			return NO;
	}
	
	return YES;
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	printf("\n\tStart inserting into the tree...\n");
	TNODE_p_t tree = createNode();
	
	int choice;
	do {
		printf("\n---------------------------------------------------------------------");
		printf("\n\t0. Rebuild tree (recursive)\n\t1. Insert element (iterative)\n\t2. Insert element (recursive)\n\t3. Preorder transversal (recursive)\n\t4. Preorder transversal (iterative)\n\t5. Inorder transversal (recursive)\n\t6. Inorder transversal (iterative)\n\t7. Postorder transversal (recursive)\n\t8. Postorder transversal (iterative)\n\t9. Level order transversal (recursive)\n\t10. Search for an item (recursive)\n\t11. Check if it's BST.\n\t12. Check if it's a Mirror.\n\tEnter choice: ");
		scanf(" %d", &choice);
		
		String item = initString(SIZE);
		
		switch (choice) {
				
			case 0: tree = createNode();
				break;
				
			case 1: printf("\n\tEnter item to be inserted: ");
				scanf(" %s", item);
				insertIterative(&tree, item);
				break;
				
			case 2: printf("\n\tEnter item to be inserted: ");
				scanf(" %s", item);
				insertRecursive(&tree, item);
				break;
				
			case 3: printf("\n\tPreorder (Rec): ");
				preorderRecursive(tree);
				break;
				
			case 4: printf("\n\tPreorder (Iter): ");
				preorderIterative(tree);
				break;
				
			case 5: printf("\n\n\tInorder (Rec): ");
				inorderRecursive(tree);
				break;
				
			case 6: printf("\n\tInorder (Iter): ");
				inorderIterative(tree);
				break;
				
			case 7: printf("\n\n\tPostorder (Rec): ");
				postorderRecursive(tree);
				break;
				
			case 8: printf("\n\tPostorder (Iter): ");
				postorderIterative(tree);
				break;
				
			case 9: printf("\n\n\tLevel Order: ");
				levelOrder(tree);
				break;
				
			case 10: {
				printf("\tEnter item to be searched: ");
				scanf(" %s", item);
				TNODE_p_t loc = search(tree, item);
				if (loc != NULL)
					printf("\n\t'%s' is present in the tree. (%p)\n", item, loc);
				else
					printf("\n\t'%s' is not present in the tree.\n", item);
				break;
			}
				
			case 11: {
				if (isBST(tree)) {
					printf("\n\tTree is BST. Inorder: ");
					inorderRecursive(tree);
				}
				else {
					printf("\n\tTree is not a BST. Inorder: ");
					inorderRecursive(tree);
				}
				break;
			}
				
			case 12: {
				if (isMirror(tree)) {
					printf("\n\tTree is a mirror. Inorder: ");
					inorderRecursive(tree);
				}
				else {
					printf("\n\tTree is not a mirror. Inorder: ");
					inorderRecursive(tree);
				}
				break;
			}
				
			default: break;
				
		}
		
	} while (choice >= 0 && choice <= 12);
	
}

