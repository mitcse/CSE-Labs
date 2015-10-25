//
//  BinarySearchTree.c
//  Binary search tree and shit.
//
//  Created by Avikant Saini on 10/19/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

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

TNODE_p_t buildTree () {
	int data;
	TNODE_p_t root = NULL;
	do {
		printf("\tEnter data (-99 for break): ");
		scanf(" %d", &data);
		if (data != -99) {
			if (root == NULL)
				root = initNode(data);
			else
				insert(root, data);
		}
	} while (data != -99);
	return root;
}

#pragma mark - Height

int height (TNODE_p_t root) {
	if (root == NULL)
		return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return (leftHeight > rightHeight)?(leftHeight + 1):(rightHeight + 1);
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

void printLevel (TNODE_p_t root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		printf(" %d", root->data);
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

#pragma mark - Search

TNODE_p_t search (TNODE_p_t root, int data) {
	if (root == NULL)
		return NULL;
	
	if (data < root->data)
		return search(root->left, data);
	else if (data > root->data)
		return search(root->right, data);
	return root;
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	TNODE_p_t tree = buildTree();
	
	int choice;
	do {
		// TODO
		printf("\n\n-------------------------------------------------------------\n\t 1. Rebuild tree.\n\t 2. Insert an item.\n\t 3. Search for item.\n\t 4. Delete an item.\n\t 5. Calculate height.\n\t 6. Calculate number of nodes.\n\t 7. Calculate number of leaves.\n\t 8. Preorder transversal.\n\t 9. Inorder transversal.\n\t10. Postorder transversal.\n\t11. Level order transversal.\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1)
			tree = buildTree();
		
		else if (choice == 2) {
			int item;
			printf("\n\tEnter item to be inserted: ");
			scanf(" %d", &item);
			if (search(tree, item) != NULL)
				printf("\n\tItem already present!\n\n");
			else
				insert(tree, item);
		}
		
		else if (choice == 3) {
			int item;
			printf("\n\tEnter item to be searched: ");
			scanf(" %d", &item);
			
			if (search(tree, item) != NULL)
				printf("\n\t%d is present in the tree.", item);
			else
				printf("\n\t%d is not present in the tree.", item);
		}
		
		else if (choice == 5) {
			printf("\n\tHeight of the tree = %d.\n", height(tree));
		}
		
		else if (choice == 8) {
			printf("\n\t   Preorder: ");
			preorderTransversal(tree);
		}
		
		else if (choice == 9) {
			printf("\n\t    Inorder: ");
			inorderTransversal(tree);
		}
		
		else if (choice == 10) {
			printf("\n\t  Postorder: ");
			postorderTransversal(tree);
		}
		
		else if (choice == 11) {
			printf("\n\tLevel order: ");
			levelOrder(tree);
		}
		
	} while (choice >= 1 && choice <= 11);
	
}

