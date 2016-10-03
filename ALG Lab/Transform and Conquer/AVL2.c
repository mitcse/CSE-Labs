//
//  AVLTree.c
//  AVL tree tree - Preorder, inorder, postorder traversal (Recursive), Level order (Recursive and iterative)
//	Insertion, deletion, search, height, node count, leaf count.
// 
//
//  Created by Avikant Saini on 10/30/15.
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

#pragma mark - Queue utilities

typedef struct Queue {
	TNODE_p_t data;
	struct Queue *next;
} QUEUE_t;

typedef QUEUE_t * QUEUE_p_t;

QUEUE_p_t initQueue (TNODE_p_t data) {
	QUEUE_p_t queue = (QUEUE_p_t)malloc(sizeof(QUEUE_t));
	queue->data = data;
	queue->next = NULL;
	return queue;
}

void insertQueue (QUEUE_p_t *queue, TNODE_p_t data) {
	QUEUE_p_t temp = initQueue(data);
	if (*queue == NULL) {
		*queue = temp;
		return;
	}
	QUEUE_p_t p = *queue;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
}

TNODE_p_t deleteQueue (QUEUE_p_t *queue) {
	if (*queue == NULL)
		return NULL;
	QUEUE_p_t temp = *queue;
	*queue = temp->next;
	return temp->data;
}

BOOL isEmptyQueue (QUEUE_p_t queue) {
	return (queue == NULL);
}

#pragma mark - Array utilities

void insertionSort (int *arr, int l) {
	int i, j, x;
	for (i = 1; i < l - 1; ++i) {
		x = *(arr + i);
		j = i;
		while (j > 0 && *(arr + j - 1) > x) {
			*(arr + j) = *(arr + j - 1);
			--j;
		}
		*(arr + j) = x;
	}
}

int * inputAnArray (int *size) {
	printf("\n\tEnter number of elements in the array: ");
	scanf(" %d", size);
	int n = *size;
	int i;
	int *arr = (int *)calloc(n, sizeof(int));
	printf("\tEnter %d elements: ", n);
	for (i = 0; i < n; ++i)
		scanf(" %d", (arr+i));
	return arr;
}

#pragma mark - Tree creation

TNODE_p_t initNode (int data) {
	TNODE_p_t node = (TNODE_p_t)malloc(sizeof(TNODE_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TNODE_p_t rotateL (TNODE_p_t tree) {
	if (tree == NULL || tree->right == NULL)
		return NULL;
	printf(">> rotateL %d\n", tree->data);
	TNODE_p_t b = tree->right;
	tree->right = b->left;
	b->left = tree;
	return b;
}

TNODE_p_t rotateR (TNODE_p_t tree) {
	if (tree == NULL || tree->left == NULL)
		return NULL;
	printf(">> rotateR %d\n", tree->data);
	TNODE_p_t b = tree->left;
	tree->left = b->right;
	b->right = tree;
	return b;
}

int heightTree (TNODE_p_t root) {
	if (root == NULL)
		return 0;
	int leftHeight = heightTree(root->left);
	int rightHeight = heightTree(root->right);
	return (leftHeight > rightHeight)?(leftHeight + 1):(rightHeight + 1);
}

int differenceHeights (TNODE_p_t tree) {
	printf(">> At root %d, lh = %d, rh = %d\n", tree->data, heightTree(tree->left), heightTree(tree->right));
	return (heightTree(tree->left) - heightTree(tree->right));
}

TNODE_p_t balanceTree (TNODE_p_t tree) {
	printf(">> Balancing at root %d\n", tree->data);
	// if (tree == NULL)
	// 	return;
	if (heightTree(tree) < 2) { // Balanced
		printf(">> Height < 2 at %d, returning\n", tree->data); 
		return tree;
	}
	int dh = differenceHeights(tree);
	if (dh >= -1 && dh <= 1) { // Balanced
		printf(">> Diffrence ain't much.\n"); 
		return tree;
	}
	balanceTree(tree->left);
	balanceTree(tree->right);
	if (dh < 0) { // Right heavy;
		printf(">> Right heavy %d\n", tree->data);
		if (differenceHeights(tree->right) > 0) { // Check if you need to do a Right-Left rotation
			tree->right = rotateR(tree->right);
		}
		tree = rotateL(tree);
	} else { // Left heavy
		printf(">> Left heavy %d\n", tree->data);
		if (differenceHeights(tree->left) < 0) {
			tree->left = rotateL(tree->right); // Check if you need to do a Left-Right rotation
		}
		tree = rotateR(tree);
	}
	return tree;
}

TNODE_p_t insert (TNODE_p_t root, int data) {
	
	if (root == NULL)
		return initNode(data);
	
	if (data < root->data) {
		root->left = insert(root->left, data);
		// root = balanceTree(root);
	}
	
	else if (data > root->data) {
		root->right = insert(root->right, data);
		// root = balanceTree(root);
	}
	
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

TNODE_p_t buildTreeFromSortedArray (int *arr, int start, int end) {
	
	if (start > end)
		return NULL;
	
	int mid = (start + end)/2;
	
	TNODE_p_t root = initNode(*(arr + mid));
	
	root->left = buildTreeFromSortedArray(arr, start, mid - 1);
	root->right = buildTreeFromSortedArray(arr, mid + 1, end);
	
	return root;
	
	return NULL;
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
	
	int h = heightTree(root);
	int i;
	
	for (i = 1; i <= h; ++i)
		printLevel(root, i);	// Print a specific level
}

void levelOrderIter (TNODE_p_t root) {
	if (root == NULL)
		return;
	QUEUE_p_t queue = initQueue(root);
	while (!isEmptyQueue(queue)) {
		TNODE_p_t temp = deleteQueue(&queue);
		printf(" %d", temp->data);
		if (temp->left != NULL)
			insertQueue(&queue, temp->left);
		if (temp->right != NULL)
			insertQueue(&queue, temp->right);
	}
}

#pragma mark - Search

TNODE_p_t searchTree (TNODE_p_t root, int item) {
	
	if (root == NULL)
		return NULL;
	
	if (item == root->data)
		return root;
	
	else if (item > root->data)
		return searchTree(root->right, item);
	
	else
		return searchTree(root->left, item);
}

#pragma mark - Delete

/**
 *	Follow the search algorithm to find the element in the tree.
 *
 *	Case 1: If the node to be deleted has no children:
 *		Set the coresponding link from the parent to null, and dispose it.
 *
 *	Case 2: If the node to be delete has one child (L or R):
 *		Link the node's child to the parent, and dispose the node.
 *
 *	Case 3: If the node to be deleted has two children:
 *		Find the minimum value in the right subtree of the node to be deleted (left most in the node's right)
 *		Replace the value of the node to be deleted with the min value found above.
 *		Delete the value from the node's right subtree.
 */

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

#pragma mark - Inorder predecessor and successor

/**
 *	Recursive way
 *	If root is null, return;
 *
 *	If the item is found:
 *
 *		If the left subtree of root is not null,
 *			The predecessor would be the right most child of root's left subtree.
 *
 *		If the right subtree of root is not null,
 *			The successor would be the left most child of root's right subtree.
 *
 *	If the item is lesser than root's data, set the successor to the root, and search in the left subtree.
 *
 *	If the item is greater than root's data, set the predecessor to the root, and search in the right subtree.
 *
 *	Easy way: Store the inorder traversal into a list/arr/string/whatever, find the element and its previous and next elements. 
 *	To get where the element will be present, of not already in the tree, just get it from the list.
 */

void predecessorSuccessor (TNODE_p_t root, int item, TNODE_p_t *predecessor, TNODE_p_t *successor) {
	
	if (root == NULL)
		return;
	
	if (root->data == item) {
		
		if (root->left != NULL) {
			TNODE_p_t temp = root->left;
			while (temp->right != NULL)
				temp = temp->right;
			*predecessor = temp;
		}
		
		if (root->right != NULL) {
			TNODE_p_t temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			*successor = temp;
		}
		
		return;
	}
	else if (item < root->data) {
		*successor = root;
		predecessorSuccessor(root->left, item, predecessor, successor);
	}
	else if (item > root->data) {
		*predecessor = root;
		predecessorSuccessor(root->right, item, predecessor, successor);
	}
	
}

#pragma mark - Lowest common ancestor

/**
 *	Assume both the items are present in the BST.
 *	Use the property of the BST.
 *
 *	If both items are smaller than the root, the LCA lies in the left subtree
 *	If both items are greatrer than the root, the LCA lies in the right subtree
 *	Else LCA is the current root node.
 */

TNODE_p_t lowestCommonAncestor (TNODE_p_t root, int itema, int itemb) {
	
	if (root == NULL)
		return NULL;
	
	if (root->data > itema && root->data > itemb)
		return lowestCommonAncestor(root->left, itema, itemb);
	
	if (root->data < itema && root->data < itema)
		return lowestCommonAncestor(root->right, itema, itemb);
	
	return root;
}

#pragma mark - Merge trees

/**
 *	Merges a tree into another one.
 *	@param tree (TNODE_p_t *) The tree in which otree is to be merged
 *	@param otree (TNODE_p_t) The tree to be merged to tree
 */

void mergeTrees (TNODE_p_t *tree, TNODE_p_t otree) {
	
	if (otree == NULL)
		return;
	
	insert(*tree, otree->data);
	
	mergeTrees(tree, otree->left);
	mergeTrees(tree, otree->right);
}

#pragma mark - Largest and smallest element

void largestAndSmallest (TNODE_p_t root, int *max, int *min) {
	
	TNODE_p_t nodeLeft = root;
	TNODE_p_t nodeRight = root;
	
	while (nodeLeft->left != NULL)
		nodeLeft = nodeLeft->left;
	
	while (nodeRight->right != NULL)
		nodeRight = nodeRight->right;
	
	*min = nodeLeft->data;
	*max = nodeRight->data;
	
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	printf("\n-------------------------BINARY SEARCH TREE-------------------------\n");
	
	TNODE_p_t tree = buildTree();
	
	int choice;
	BOOL displayOptions = YES;
	do {
		// TODO
		printf("\n\n-------------------------------------------------------------");
		if (displayOptions) {
			printf("\n\t 1. Rebuild tree.");
			printf("\n\t 2. Insert an item.");
			printf("\n\t 3. Search for item.");
			printf("\n\t 4. Delete an item.");
			printf("\n\t 5. Calculate height.");
			printf("\n\t 6. Calculate number of nodes.");
			printf("\n\t 7. Calculate number of leaves.");
			printf("\n\t 8. Preorder transversal.");
			printf("\n\t 9. Inorder transversal.");
			printf("\n\t10. Postorder transversal.");
			printf("\n\t11. Level order transversal.");
			printf("\n\t12. Level order transversal (Iterative)");
			printf("\n\t13. Inorder successor and predecessor.");
			printf("\n\t14. Lowest common ancestor.");
			printf("\n\t15. Merge another BST to current Tree.");
			printf("\n\t16. Largest and smallest element.");
			printf("\n\t17. Balance heights (AVL).");
		}
		displayOptions = NO;
		printf("\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1) {
			int bch;
			printf("\n\t1. Rebuild using recursion.\n\t2. Rebuild a balanced BST from an array.\n\tChoice: ");
			scanf(" %d", &bch);
			if (bch == 1) {
				tree = buildTree();
				printf("\n\tTree is successfully rebuilt.");
			}
			else if (bch == 2) {
				int n;
				int *arr = inputAnArray(&n);
				insertionSort(arr, n);
				tree = buildTreeFromSortedArray(arr, 0, n-1);
				printf("\n\tTree is successfully rebuilt.");
			}
		}
		
		else if (choice == 2) {
			int item;
			printf("\n\tEnter item to be inserted: ");
			scanf(" %d", &item);
			if (searchTree(tree, item) != NULL)
				printf("\n\tItem already present!\n\n");
			else {
				insert(tree, item);
				printf("\n\t%d is successfully inserted to the tree.", item);
			}
		}
		
		else if (choice == 3) {
			int item;
			printf("\n\tEnter item to be searched: ");
			scanf(" %d", &item);
			TNODE_p_t element = searchTree(tree, item);
			if (element != NULL)
				printf("\n\t%d is present in the tree. (%p)", item, element);
			else
				printf("\n\t%d is not present in the tree.", item);
		}
		
		else if (choice == 4) {
			int item;
			printf("\n\tEnter item to be deleted: ");
			scanf(" %d", &item);
			TNODE_p_t element = searchTree(tree, item);
			if (element != NULL) {
				delete(tree, item);
				printf("\n\t%d is successfully deleted from the tree.", item);
			}
			else
				printf("\n\t%d is not present in the tree.", item);
		}
		
		else if (choice == 5) {
			printf("\n\tHeight of the tree = %d.\n", heightTree(tree));
		}
		
		else if (choice == 6) {
			printf("\n\tNumber of nodes in the tree = %d.\n", nodeCount(tree) - 1);
		}
		
		else if (choice == 7) {
			printf("\n\tNumber of leaves in the tree = %d.\n", leafCount(tree));
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
		
		else if (choice == 12) {
			printf("\n\tLevel order: ");
			levelOrderIter(tree);
		}
		
		else if (choice == 13) {
			int item;
			printf("\n\tEnter item to get the inorder successor and predessor for: ");
			scanf(" %d", &item);
			TNODE_p_t searchResult = searchTree(tree, item);
			if (searchResult != NULL) {
				TNODE_p_t pred = NULL, succ = NULL;
				predecessorSuccessor(tree, item, &pred, &succ);
				if (pred == NULL)
					pred = searchResult;
				if (succ == NULL)
					succ = searchResult;
				printf("\n\tPredecessor: %d (%p)", pred->data, pred);
				printf("\n\t  Successor: %d (%p)", succ->data, succ);
			}
			else
				printf("\n\t%d is not present in the tree.", item);
		}
		
		else if (choice == 14) {
			int itema, itemb;
			printf("\n\tEnter the two numbers to find the LCA: ");
			scanf(" %d", &itema);
			scanf(" %d", &itemb);
			TNODE_p_t searcha = searchTree(tree, itema);
			TNODE_p_t searchb = searchTree(tree, itemb);
			if (searcha == NULL)
				printf("\n\t'%d' is not present in the tree.", itema);
			if (searchb == NULL)
				printf("\n\t'%d' is not present in the tree.", itemb);
			if (searcha != NULL && searchb != NULL) {
				TNODE_p_t lca = lowestCommonAncestor(tree, itema, itemb);
				printf("\n\tLCA (%d, %d) = %d (%p).", itema, itemb, lca->data, lca);
			}
		}
		
		else if (choice == 15) {
			printf("\n\tStart entering data into the new tree:\n");
			TNODE_p_t tree2 = buildTree();
			mergeTrees(&tree, tree2);
			printf("\n\tMerge successful.");
			printf("\n\t    Inorder: ");
			inorderTransversal(tree);
		}
		
		else if (choice == 16) {
			int max, min;
			largestAndSmallest(tree, &max, &min);
			printf("\n\tLargest = %d, Smallest = %d.", max, min);
		}

		else if (choice == 17) {
			tree = balanceTree(tree); 
			printf("Tree balanced.\n");
		}
		
	} while (choice >= 1 && choice <= 17);
	
}

