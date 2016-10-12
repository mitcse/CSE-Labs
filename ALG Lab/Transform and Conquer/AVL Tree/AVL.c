#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) ((A > B) ? A : B)

typedef enum { NO, YES } BOOL;

typedef struct TNode {
	int data;
	int height;
	struct TNode *left;
	struct TNode *right;
} TNODE_t, *TNODE_p_t;

TNODE_p_t initNode (int data) {
	TNODE_p_t node = (TNODE_p_t)malloc(sizeof(TNODE_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

int height (TNODE_p_t tree) {
	if (tree == NULL)
		return 0;
	return tree->height;
}

#pragma mark - Rotate

TNODE_p_t rotateRight (TNODE_p_t tree) {

	TNODE_p_t left = tree->left;
	TNODE_p_t lr = left->right;

	left->right = tree;
	tree->left = lr;

	tree->height = MAX(height(tree->left), height(tree->right)) + 1;
	left->height = MAX(height(left->left), height(left->right)) + 1;

	return left;

}

TNODE_p_t rotateLeft (TNODE_p_t tree) {

	TNODE_p_t right = tree->right;
	TNODE_p_t rl = right->left;

	right->left = tree;
	tree->right = rl;

	tree->height = MAX(height(tree->left), height(tree->right)) + 1;
	right->height = MAX(height(right->left), height(right->right)) + 1;

	return right;

}

int differenceHeights (TNODE_p_t tree) {
	if (tree == NULL)
		return 0;
	return height(tree->left) - height(tree->right);
}

#pragma mark - Modified insert

TNODE_p_t insertItem (TNODE_p_t tree, int item) {

	if (tree == NULL) {
		return initNode(item);
	}

	if (item < tree->data) {
		tree->left = insertItem(tree->left, item);
	} else {
		tree->right = insertItem(tree->right, item);
	}

	tree->height = MAX(height(tree->left), height(tree->right)) + 1;

	int dh = differenceHeights(tree);

	if (dh > 1) {
		if (item > tree->left->data) {
			tree->left = rotateLeft(tree->left);
		}
		return rotateRight(tree);
	}

	if (dh < -1) {
		if (item < tree->right->data) {
			tree->right = rotateRight(tree->right);
		}
		return rotateLeft(tree);
	} 

	return tree;

}

TNODE_p_t buildTree () {
	
	int data;
	TNODE_p_t root = NULL;
	
	do {
		printf("\tEnter data (-99 for break): ");
		scanf(" %d", &data);
		
		if (data != -99) {
			root = insertItem(root, data);
		}

	} while (data != -99);
	
	return root;
}

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

int heightTree (TNODE_p_t root) {
	if (root == NULL)
		return 0;
	int leftHeight = heightTree(root->left);
	int rightHeight = heightTree(root->right);
	return (leftHeight > rightHeight)?(leftHeight + 1):(rightHeight + 1);
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

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	printf("\n-------------------------AVL TREE-------------------------\n");
	
	TNODE_p_t tree = buildTree();
	
	int choice;
	BOOL displayOptions = YES;
	do {
		// TODO
		printf("\n\n-------------------------------------------------------------");
		if (displayOptions) {
			printf("\n\t 1. Rebuild tree.");
			printf("\n\t 2. Insert an item.");
			printf("\n\t 3. Preorder transversal.");
			printf("\n\t 4. Inorder transversal.");
			printf("\n\t 5. Postorder transversal.");
			printf("\n\t 6. Level order transversal.");
		}
		displayOptions = NO;
		printf("\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1) {
			tree = buildTree();
			printf("\n\tTree is successfully rebuilt.");
		}
		
		else if (choice == 2) {
			int item;
			printf("\n\tEnter item to be inserted: ");
			scanf(" %d", &item);
			if (searchTree(tree, item) != NULL)
				printf("\n\tItem already present!\n\n");
			else {
				tree = insertItem(tree, item);
				printf("\n\t%d is successfully inserted to the tree.", item);
			}
		}
		
		else if (choice == 3) {
			printf("\n\t   Preorder: ");
			preorderTransversal(tree);
		}
		
		else if (choice == 4) {
			printf("\n\t    Inorder: ");
			inorderTransversal(tree);
		}
		
		else if (choice == 5) {
			printf("\n\t  Postorder: ");
			postorderTransversal(tree);
		}
		
		else if (choice == 6) {
			printf("\n\tLevel order: ");
			levelOrder(tree);
		}
		
		
	} while (choice >= 1 && choice <= 6);
	
}




