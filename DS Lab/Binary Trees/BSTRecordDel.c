//
//  BSTRecordDel.c
//  BST record manager, search/delete wrt roll number.
//
//  Created by Avikant Saini on 3/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

#define initString(size) (char *)malloc(size * sizeof(char))

typedef char * String;

typedef enum { NO, YES } BOOL;

typedef struct TNode {
	int data;
	String name;
	String section;
	String cgpa;
	String phno;
	struct TNode *left;
	struct TNode *right;
} TNODE_t;

typedef TNODE_t * TNODE_p_t;

#pragma mark - Tree creation

TNODE_p_t initNode (int data) {
	TNODE_p_t node = (TNODE_p_t)malloc(sizeof(TNODE_t));
	node->data = data;
	node->name = initString(SIZE);
	node->section = initString(SIZE);
	node->cgpa = initString(SIZE);
	node->phno = initString(SIZE);
	printf("\n\tRoll number %d, Enter name: ", data);
	scanf(" %s", node->name);
	printf("\tRoll number %d, Enter cgpa: ", data);
	scanf(" %s", node->cgpa);
	printf("\tRoll number %d, Enter section: ", data);
	scanf(" %s", node->section);
	printf("\tRoll number %d, Enter phno: ", data);
	scanf(" %s", node->phno);
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
		printf("\tEnter roll number (0 for break): ");
		scanf(" %d", &data);
		if (data != 0) {
			if (root == NULL)
				root = initNode(data);
			else
				insert(root, data);
		}
	} while (data != 0);
	return root;
}

#pragma mark - Search

TNODE_p_t search (TNODE_p_t root, int item) {
	if (root == NULL)
		return NULL;
	if (item == root->data)
		return root;
	else if (item > root->data)
		return search(root->right, item);
	else
		return search(root->left, item);
}

#pragma mark - Delete

TNODE_p_t minValueNode (TNODE_p_t root) {
	TNODE_p_t temp = root;
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}

TNODE_p_t delete (TNODE_p_t root, int item) {
	if (root == NULL)
		return root;
	
	if (item < root->data)
		root->left = delete(root->left, item);
	else if (item > root->data)
		root->right = delete(root->right, item);
	
	else {
		if (root->left == NULL) {
			TNODE_p_t temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TNODE_p_t temp = root->left;
			free(root);
			return temp;
		}
		
		TNODE_p_t temp = minValueNode(root->right);
		root->data = temp->data;  
		root->right = delete(root->right, temp->data);
	}
	return root;
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	printf("\n-------------------------BINARY SEARCH TREE-------------------------\n");
	
	TNODE_p_t tree = buildTree();
	
	int choice;
	do {
		// TODO
		printf("\n\n-------------------------------------------------------------\n\t 1. Clean and rebuild records.\n\t 2. Insert record.\n\t 3. Search for record.\n\t 4. Delete a record.\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1)
			tree = buildTree();
		
		else if (choice == 2) {
			int item;
			printf("\n\tEnter roll number to be inserted: ");
			scanf(" %d", &item);
			if (search(tree, item) != NULL)
				printf("\n\tRoll number already present!\n\n");
			else
				insert(tree, item);
		}
		
		else if (choice == 3) {
			int item;
			printf("\n\tEnter roll number to be searched: ");
			scanf(" %d", &item);
			TNODE_p_t element = search(tree, item);
			if (element != NULL) {
				printf("\n\t%d is present in the book. (%p)", item, element);
				printf("\n\tRoll number: %d", element->data);
				printf("\n\t       Name: %s", element->name);
				printf("\n\t    Section: %s", element->section);
				printf("\n\t       CGPA: %s", element->cgpa);
				printf("\n\t   Phone no: %s", element->phno);
			}
			else
				printf("\n\t%d is not present in the book.", item);
		}
		
		else if (choice == 4) {
			int item;
			printf("\n\tEnter item to be deleted: ");
			scanf(" %d", &item);
			TNODE_p_t element = search(tree, item);
			if (element != NULL) {
				delete(tree, item);
			}
			else
				printf("\n\t%d is not present in the book.", item);
		}
		
	} while (choice >= 1 && choice <= 4);
	
}

