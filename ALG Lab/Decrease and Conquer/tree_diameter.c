//
//	tree_diameter.c
//	Diameter of a tree: longest path between two vertices.
//
//	Created by Avikant Saini on 9/5/16
//  Copyright © 2016 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { NO, YES } BOOL;

#pragma mark - TNode

typedef struct TNode {
	int data;
	struct TNode *left;
	struct TNode *right;
} TNODE_t, *TNODE_p_t;

TNODE_p_t initNode (int data) {
	TNODE_p_t tnode = (TNODE_p_t)malloc(sizeof(TNODE_t));
	tnode->data = data;
	tnode->left = NULL;
	tnode->right = NULL;
	return tnode;
}

#pragma mark - TSNode

typedef struct TSNode {
	TNODE_p_t data;
	struct TSNode *prev;
	struct TSNode *next;
} TSNODE_t, *TSNODE_p_t;

TSNODE_p_t initTSNode (TNODE_p_t data) {
	TSNODE_p_t tsnode = (TSNODE_p_t)malloc(sizeof(TSNODE_t));
	tsnode->data = data;
	tsnode->prev = tsnode;
	tsnode->next = tsnode;
	return tsnode;
}

#pragma mark - Linked list

BOOL insertListRear (TSNODE_p_t *list, TNODE_p_t data) {
	
	TSNODE_p_t temp = initTSNode(data);
	
	if (*list == NULL) {
		*list = temp;
		return YES;
	}
	
	TSNODE_p_t head = *list;
	TSNODE_p_t last = head->prev;
	
	temp->prev = last;
	last->next = temp;
	temp->next = head;
	head->prev = temp;
	
	return YES;
}

BOOL displayList (TSNODE_p_t list) {
	
	if (list == NULL)
		return NO;
	
	TSNODE_p_t temp = list;
	
	while (temp->next != list) {
		printf(" %d ->", temp->data->data);
		temp = temp->next;
	}
	printf(" %d\n", temp->data->data);
	
	return YES;
}

#pragma mark - Tree creation and insertion

TNODE_p_t buildTree () {
	
	int data = 0;
	printf("\tEnter data (0 for break): ");
	scanf(" %d", &data);
	
	if (data == 0)
		return NULL;
	
	TNODE_p_t root = initNode(data);
	
	printf("\t Left of '%d' | ", data);
	root->left = buildTree();
	
	printf("\tRight of '%d' | ", data);
	root->right = buildTree();
	
	return root;
}

BOOL insertTree (TNODE_p_t *root, int data) {
	
	if (*root == NULL) {
		*root = initNode(data);
		return YES;
	}
	
	TNODE_p_t groot = *root;
	
	int choice;
	printf("\n\tCurrent '%d' | 1. Left%s; 2. Right%s | Choice: ", groot->data, ((groot->left == NULL)?"(*)":""), ((groot->right == NULL)?"(*)":""));
	scanf(" %d", &choice);
	
	if (choice == 1)
		return insertTree(&groot->left, data);
	else if (choice == 2)
		return insertTree(&groot->right, data);
	else
		return NO;
	
	return YES;
}

#pragma mark - Traversals

void preorderRecursive (TNODE_p_t root) {
	if (root != NULL) {
		printf(" %d ", root->data);
		preorderRecursive(root->left);
		preorderRecursive(root->right);
	}
}

void inorderRecursive (TNODE_p_t root) {
	if (root != NULL) {
		inorderRecursive(root->left);
		printf(" %d ", root->data);
		inorderRecursive(root->right);
	}
}

void postorderRecursive (TNODE_p_t root) {
	if (root != NULL) {
		postorderRecursive(root->left);
		postorderRecursive(root->right);
		printf(" %d ", root->data);
	}
}

#pragma mark - Search 

TNODE_p_t searchTree (TNODE_p_t root, int item) {
	
	if (root == NULL)
		return NULL;
	
	if (root->data == item)
		return root;
	
	TNODE_p_t left = searchTree(root->left, item);
	TNODE_p_t right = searchTree(root->right, item);
	
	return ((left != NULL)?left:((right != NULL)?right:NULL));
	
	return NULL;
	
}

#pragma mark - Path from node to list

/**
 *	Path is generated from the element to the root.
 *	Follow the search algorithm, if the item is found, insert root in the list, return the root.
 *	Let left be the result from searching in root's left, and right from root's right.
 *	If left is not null, insert root to the list, else if right is not null, insert right to the list.
 */

TNODE_p_t pathFromNode (TNODE_p_t root, int item, TSNODE_p_t *list) {
	
	if (root == NULL)
		return NULL;
	
	if (root->data == item) {
		insertListRear(list, root);
		return root;
	}
	
	TNODE_p_t left = pathFromNode(root->left, item, list);
	TNODE_p_t right = pathFromNode(root->right, item, list);
	
	if (left != NULL) {
		insertListRear(list, root);
		return left;
	}
	else if (right != NULL) {
		insertListRear(list, root);
		return right;
	}
	
	return NULL;
}

#pragma mark - Lowest common ancestor

/**
 *	Path Lists are generated from the element to the root.
 *	To get the lowest common ancestor, traverse both the lists backwards while they have a common element,
 *	The LCA will be the next element from either of the lists.
 */

TNODE_p_t lowestCommonAncestor (TSNODE_p_t lista, TSNODE_p_t listb) {
	
	if (lista == NULL || listb == NULL)
		return NULL;
	
	TSNODE_p_t tempa = lista->prev;
	TSNODE_p_t tempb = listb->prev;
	
	while (tempa->data == tempb->data) {
		tempa = tempa->prev;
		tempb = tempb->prev;
	}
	
	TNODE_p_t lca = tempa->next->data;
	
	return lca;
}

#pragma mark - Path finder

/**
 *	Paths are generated from the element to the root.
 *	We take the path from the first element to the lowest common ancestor.
 *	Then from the LCA, we traverse backwards to the second element.
 */

TSNODE_p_t pathBetweenLists (TSNODE_p_t lista, TSNODE_p_t listb, TNODE_p_t lca) {
	
	TSNODE_p_t pathList = NULL;
	
	TSNODE_p_t tempa = lista;
	while (tempa->data != lca) {
		insertListRear(&pathList, tempa->data);
		tempa = tempa->next;
	}
	
	TSNODE_p_t tempb = listb->prev;
	while (tempb->data != lca)
		tempb = tempb->prev;
	while (tempb != listb) {
		insertListRear(&pathList, tempb->data);
		tempb = tempb->prev;
	}
	insertListRear(&pathList, tempb->data);
	
	return pathList;
}

#pragma mark - Diameter (Brute force)

#pragma mark - Diamater (Decrease and conquer)

/**
 *	Diameter of the tree can be defined as:
 *	diameter = max (diameter of the left subtree, diameter of the right subtree, longest path between the two nodes that pass through the root)
 *	Longest path between two nodes which passes through the root = 1 + height of left sub­tree + height of right subtree.
 */

int heightTree (TNODE_p_t root) {
	if (root == NULL)
		return 0;
	int leftHeight = heightTree(root->left);
	int rightHeight = heightTree(root->right);
	return (leftHeight > rightHeight)?(leftHeight + 1):(rightHeight + 1);
}

int diameter (TNODE_p_t tree) {
	if (tree == NULL)
		return 0;
	int ld = diameter(tree->left);
	int rd = diameter(tree->right);
	int dd = (ld > rd) ? ld : rd;
	int lp = 1 + heightTree(tree->left) + heightTree(tree->right);
	return (lp > dd) ? lp : dd;
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	// Sample input: 1 2 4 8 12 0 15 0 0 0 0 5 0 9 0 0 3 6 10 0 13 16 0 0 17 0 0 11 0 14 18 0 0 19 0 0 7 0 0
	// Sample input: 1 2 4 7 0 0 8 10 13 0 0 14 0 0 0 5 0 9 11 0 0 12 0 15 0 0 3 0 6 0 0
	
	TNODE_p_t tree = buildTree();
	
	int choice = 0;
	
	do {
		
		printf("\n-----------------------------------------------------------------------");
		printf("\n\t1. Rebuild tree.\n\t2. Insert element.\n\t3. Preorder traversal.\n\t4. Inorder traversal.\n\t5. Postorder traversal.\n\t6. Search for an element.\n\t7. Path between two elements.\n\t8. Lowest common ancestor.\n\t9. Find diameter of the tree.\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1)
			tree = buildTree();
		
		else if (choice == 2) {
			int item;
			printf("\n\tEnter item to be inserted: ");
			scanf(" %d", &item);
			insertTree(&tree, item);
		}
		
		else if (choice == 3)
			preorderRecursive(tree);
		
		else if (choice == 4)
			inorderRecursive(tree);
		
		else if (choice == 5)
			postorderRecursive(tree);
		
		else if (choice == 6) {
			int item;
			printf("\n\tEnter item to be searched: ");
			scanf(" %d", &item);
			TNODE_p_t search = searchTree(tree, item);
			if (search != NULL)
				printf("\n\t'%d' is present in the tree. (%p).", item, search);
			else
				printf("\n\t'%d' is not present in the tree.", item);
		}
		
		else if (choice == 7) {
			int itema, itemb;
			printf("\n\tEnter elements you want to find the path between: ");
			scanf(" %d", &itema);
			scanf(" %d", &itemb);
			
			TNODE_p_t searcha = searchTree(tree, itema);
			TNODE_p_t searchb = searchTree(tree, itemb);
			
			if (searcha == NULL)
				printf("\n\t'%d' is not present in the tree.", itema);
			if (searchb == NULL)
				printf("\n\t'%d' is not present in the tree.", itemb);
			
			if (searcha != NULL && searchb != NULL) {
				TSNODE_p_t patha = NULL;
				TSNODE_p_t pathb = NULL;
				pathFromNode(tree, itema, &patha);
				pathFromNode(tree, itemb, &pathb);
				TNODE_p_t lca = lowestCommonAncestor(patha, pathb);
				TSNODE_p_t pathAB = pathBetweenLists(patha, pathb, lca);
				printf("\n\tPath between %d and %d: ", itema, itemb);
				displayList(pathAB);
			}
		}
		
		else if (choice == 8) {
			int itema, itemb;
			printf("\n\tEnter elements you want to find the lowest common ancestor of: ");
			scanf(" %d", &itema);
			scanf(" %d", &itemb);
			
			TNODE_p_t searcha = searchTree(tree, itema);
			TNODE_p_t searchb = searchTree(tree, itemb);
			
			if (searcha == NULL)
				printf("\n\t'%d' is not present in the tree.", itema);
			if (searchb == NULL)
				printf("\n\t'%d' is not present in the tree.", itemb);
			
			if (searcha != NULL && searchb != NULL) {
				TSNODE_p_t patha = NULL;
				TSNODE_p_t pathb = NULL;
				pathFromNode(tree, itema, &patha);
				pathFromNode(tree, itemb, &pathb);
				TNODE_p_t lca = lowestCommonAncestor(patha, pathb);
				printf("\n\tLowest common ancestor of %d and %d: %d", itema, itemb, lca->data);
			}
		}
		
		else if (choice == 9) {
			int diam = diameter(tree);
			printf("\n\tDiameter of the tree = %d.", diam);
		}
		
	} while (choice >= 1 && choice <= 9);
	
	printf("\n\n");
	
	return 0;
}

