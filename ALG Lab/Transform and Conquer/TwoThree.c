#include <stdio.h>
#include <stdlib.h>

#define LESS -32767

#define MIN(A, B) ((A > B)? B : A)
#define MAX(A, B) ((A > B)? A : B)

#define MAX3(A, B, C) MAX(A, MAX(B, C))
#define MIN3(A, B, C) MIN(A, MIN(B, C))
#define MID3(A, B, C) MAX(MIN(A, B), MIN(MAX(A, B), C))

typedef enum { NO, YES } BOOL;

typedef struct TwoThreeNode {
	int k1, k2;
	struct TwoThreeNode *left, *mid, *right;
} TTN_t, *TTN_p_t;

TTN_p_t initNode() {
	TTN_p_t node = (TTN_p_t)malloc(sizeof(TTN_t));
	node->k1 = LESS;
	node->k2 = LESS;
	node->left = NULL;
	node->mid = NULL;
	node->right = NULL;
	return node;
}

#pragma mark - 

TTN_p_t searchTree (TTN_p_t tree, int key) {
	if (tree == NULL)
		return NULL;
	if (key == tree->k1 || key == tree->k2)
		return tree;
	if (key < tree->k1)
		return searchTree(tree->left, key);
	else if (key > tree->k2)
		return searchTree(tree->right, key);
	return searchTree(tree->mid, key);
}

#pragma mark - Insert and delete

TTN_p_t insertItem (TTN_p_t tree, int item) {

	if (tree == NULL) {
		TTN_p_t node = initNode();
		node->k1 = item;
		return node;
	}

	if (tree->k1 == LESS) {
		tree->k1 = item;
		return tree;
	} else if (tree->k2 == LESS) {
		tree->k2 = MAX(item, tree->k1);
		tree->k1 = MIN(item, tree->k1);
		return tree;
	} else {
		if (item < tree->k1) {
			tree->left = insertItem(tree->left, item);
		} else if (item > tree->k2) {
			tree->right = insertItem(tree->right, item);
		} else {
			tree->mid = insertItem(tree->mid, item);
		}
	}

	if (tree->left == NULL && tree->mid == NULL && tree->right == NULL) {
		TTN_p_t leftNode = initNode();
		TTN_p_t rightNode = initNode();
		if (item < tree->k1) {
			// tree->k1 = tree->k1;
			leftNode->k1 = item;
			rightNode->k1 = tree->k2;
		} else if (item > tree->k2) {
			leftNode->k1 = tree->k1;
			tree->k1 = tree->k2;
			rightNode->k1 = item;
		} else {
			leftNode->k1 = tree->k1;
			tree->k1 = item;
			rightNode->k1 = tree->k2;
		}
		tree->k2 = LESS;
		tree->left = leftNode;
		tree->mid = rightNode;
		return tree;
	}

	return tree;

}

#pragma mark - Traversals

void inorderTraversal (TTN_p_t root) {
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	if (root->k1 != LESS)
		printf(" %d", root->k1);
	inorderTraversal(root->mid);
	if (root->k2 != LESS)
		printf(" %d", root->k2);
	inorderTraversal(root->right);
}

#pragma mark - 

int main (int argc, char const * argv []) {

	int x;
	printf("Enter elements one by one, -1 to break: ");

	TTN_p_t tree = NULL;

	do {
		scanf(" %d", &x);
		if (x >= 0)
			tree = insertItem(tree, x);
	} while (x >= 0);

	// TTN_p_t tree = insertItem(NULL, 4);
	// tree = insertItem(tree, 3);
	// tree = insertItem(tree, 2);
	// tree = insertItem(tree, 5);
	// tree = insertItem(tree, 6);
	// tree = insertItem(tree, 1);
	// tree = insertItem(tree, 8);
	// tree = insertItem(tree, 7);

	printf("Inorder: \n");
	inorderTraversal(tree);

	printf("\n\n");

	return 0;

}