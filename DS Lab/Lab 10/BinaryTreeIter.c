//
//	BinaryTree.c
//
//	Created by Avikant Saini on 10/19/15
//

/**
 Sample input : 1 10 1 8 1 1 3 1 1 1 5 1 2 1 2 2 1 2 2 1 for
 10
	/   \
 8      2
 /  \    /
 3    5  2
 Inorder:  3 8 5 10 2 2
 Preorder:  10 8 3 5 2 2
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef enum { NO, YES } BOOL;

typedef struct tnode {
	int data;
	struct tnode *left;
	struct tnode *right;
} TNODE_t;

typedef TNODE_t * TNODE_p_t;

// Stack crap

typedef struct stack {
	TNODE_p_t arr[SIZE];
	int tos;
} STACK_t;

typedef STACK_t * STACK_p_t;

void push (STACK_p_t stack, TNODE_p_t item) {
	if (stack->tos == SIZE - 1) {
		printf("OVERFLOW!");
		return;
	}
	stack->arr[++(stack->tos)] = item;
}

TNODE_p_t pop (STACK_p_t stack) {
	if (stack->tos == -1)
		return NULL;
	return stack->arr[(stack->tos)--];
}

// Tree creation

TNODE_p_t createLeaf(char data) {
	TNODE_p_t leaf = (TNODE_p_t)malloc(sizeof(TNODE_t));
	leaf->right = NULL;
	leaf->left = NULL;
	leaf->data = data;
	return leaf;
}

void insertIterative (TNODE_p_t *rt, int item) {
	
	int ch;
	TNODE_p_t t = *rt;
	TNODE_p_t present = NULL;
	TNODE_p_t newnode;
	
	if (*rt == NULL) {
		*rt = createLeaf(item);
		return;
	}
	
	do {
		printf("\tCurrent: '%d' | 1. Left%s; 2. Right%s | Choice: ", t->data, ((t->left == NULL)?"(*)":""), ((t->right == NULL)?"(*)":""));
		scanf("%d", &ch);
		present = t;
		
		if (ch == 1)
			t= t->left;
		else if (ch == 2)
			t = t->right;
		
		if (t == NULL) {
			newnode = createLeaf(item);
			(ch == 1)?(present->left=newnode):(present->right=newnode);
			return;
		}
		
	} while (YES);
}

// Transversals

void inOrder (TNODE_p_t root) {
	
	TNODE_p_t current = root;
	
	STACK_t stack;
	stack.tos = -1;
	
	if (current == NULL)
		return;
 
	while (YES) {
		
		if (current !=  NULL) {
			push(&stack, current);
			current = current->left;
		}
		
		else {
			if (stack.tos > -1) {
				current = pop(&stack);
				printf(" %d", current->data);
				current = current->right;
			}
			else
				break;
		}
	}
	
}

void preOrder (TNODE_p_t root) {
	
	TNODE_p_t current = root;
	
	STACK_t stack;
	stack.tos = -1;
	
	if (current == NULL)
		return;
	
	push(&stack, current);
 
	while (stack.tos > -1) {
		
		TNODE_p_t temp = pop(&stack);
		printf(" %d", temp->data);
		
		if (temp->right)
			push(&stack, temp->right);
		if (temp->left)
			push(&stack, temp->left);
		
	}
	
}

int main (int argc, const char * argv[]) {
	
	int ch, el;
	TNODE_p_t root;
	root = NULL;
	
	while (1) {
		printf("\n\t1. Insert\n\t2. Inorder\n\t3. Preorder\n\tChoice: ");
		scanf(" %d", &ch);
		switch(ch) {
			case 1:
				if (root == NULL)
					printf("\tEnter root value: ");
				else
					printf("\tEnter value: ");
				scanf(" %d", &el);
				insertIterative(&root, el);
				break;
			case 2:
				inOrder(root);
				break;
			case 3:
				preOrder(root);
				break;
			default:
				exit(0);
		}
	}
}
