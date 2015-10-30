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

TNODE_p_t search (TNODE_p_t root, int item) {
	if (root == NULL)
		return NULL;
	if (root->data == item)
		return root;
	TNODE_p_t left = search(root->left, item);
	TNODE_p_t right = search(root->right, item);
	return (left != NULL)?left:((right != NULL)?right:NULL);
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
		
		TNODE_p_t temp = minValueNode(root->right); // node with two children: Get the inorder successor (smallest in the right subtree)
		root->data = temp->data;  // Copy the inorder successor's content to this node
		root->right = delete(root->right, temp->data);  // Delete the inorder successor
	}
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
			TNODE_p_t element = search(tree, item);
			if (element != NULL)
				printf("\n\t%d is present in the tree. (%p)", item, element);
			else
				printf("\n\t%d is not present in the tree.", item);
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

