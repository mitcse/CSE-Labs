//
//  BinarySearchTree.c
//  Binary search tree - Preorder, inorder, postorder traversal (Recursive).
//	Insertion and search.
//
//  Created by Avikant Saini on 09/08/16.
//  Copyright © 2016 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} NODE_t;

typedef NODE_t *NODE_p_t;

#pragma mark - Tree creation

NODE_p_t initNode (int data) {
	NODE_p_t node = (NODE_p_t)malloc(sizeof(NODE_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

NODE_p_t insertNode (NODE_p_t root, int data) {
	if (root == NULL) {
		return initNode(data);
	}
	if (data < root->data) {
		root->left = insertNode(root->left, data);
	} else if (data > root->data) {
		root->right = insertNode(root->right, data);
	}
	return root;
}

NODE_p_t buildTree () {
	int data;
	NODE_p_t root = NULL;
	printf("\tBinary search tree creation (insert in a level-orderly fashion).\n");
	do {
		printf("\tEnter data (-1 for break): ");
		scanf(" %d", &data);
		if (data != -1) {
			if (root == NULL)
				root = initNode(data);
			else
				insertNode(root, data);
		} 
	} while (data != -1);
	return root;
}


#pragma mark - Operations

void preorderTraversal (NODE_p_t root) {
	if (root != NULL) {
		printf(" %d", root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal (NODE_p_t root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf(" %d", root->data);
		inorderTraversal(root->right);
	}
}

void postorderTraversal(NODE_p_t root) {
	if (root != NULL) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf(" %d", root->data);
	}
}

NODE_p_t searchTree (NODE_p_t root, int item) {
	if (root == NULL)
		return NULL;
	if (item < root->data)
		return searchTree(root->left, item);
	else if (item > root->data)
		return searchTree(root->right, item);
	return root;
}


#pragma mark - Main

int main (int argc, const char * argv []) {
	printf("\n-------------------------BINARY SEARCH TREE-------------------------\n\n");
	NODE_p_t tree = buildTree();
	int choice;
	do {
		printf("\n\n\t1. Rebuild tree.\n");
		printf("\t2. Search for an item.\n");
		printf("\t3. Search for an item (insert if not found).\n");
		printf("\t4. Preorder traversal.\n");
		printf("\t5. Inorder traversal.\n");
		printf("\t6. Postorder traversal.\n");
		printf("\tChoice: ");
		scanf(" %d", &choice);

		if (choice == 1) {
			tree = buildTree();
		} else if (choice == 2 || choice == 3) {
			int item;
			printf("\n\tEnter item to be searched: ");
			scanf(" %d", &item);
			NODE_p_t element = searchTree(tree, item);
			if (element != NULL)
				printf("\n\t%d is present in the tree. (%p)", item, element);
			else {
				if (choice == 2)
					printf("\n\t%d is not present in the tree.", item);
				else {
					insertNode(tree, item);
					printf("\n\t%d was not present in the tree. Now it is.", item);
				}
			}
		} else if (choice == 4) {
			printf("\n\t   Preorder: ");
			preorderTraversal(tree);
		} else if (choice == 5) {
			printf("\n\t    Inorder: ");
			inorderTraversal(tree);
		} else if (choice == 6) {
			printf("\n\t  Postorder: ");
			postorderTraversal(tree);
		}
	} while (choice >= 1 && choice <= 6);
	return 0;
}
