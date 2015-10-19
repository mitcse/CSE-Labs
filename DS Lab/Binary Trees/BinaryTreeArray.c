//
//	BinaryTreeArray.c
//	Array representation of a binary tree.
//
//	Created by Avikant Saini on 10/19/15
//

/**
 *	Sample tree input 3 6 4 8 # 5 7 9 # # # # # 2
 *	 Inorder: 4 5 6 7 8 9 2
 *	Preorder: 6 4 5 8 7 9 2
 *
 *	Another sample tree:  3 1 2 3 4 5 6 7 8 9 A B C D E F	(Complete binary tree of height 3)
 *	 Inorder: 8 4 9 2 A 5 B 1 C 6 D 3 E 7 F
 *	Preorder: 1 2 4 8 9 5 A B 3 6 C D 7 E F
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tree {
	char *arr;
	int height;
	int capacity;
} TREE_t;

typedef TREE_t * TREE_p_t;

TREE_p_t initTree (int height) {
	TREE_p_t tree = (TREE_p_t)malloc(sizeof(TREE_t));
	tree->height = height;
	tree->capacity = (int)pow(2, height + 1);
	tree->arr = (char *)calloc(tree->capacity, sizeof(char));
	return tree;
}

#pragma mark - Input iterative

void inputTree (TREE_p_t tree) {
	
	// Get the root node
	printf("\t   Root Node: ");
	scanf(" %c", (tree->arr + 1));
	
	if (*(tree->arr + 1) == '#')
		return;
	
	int i, j;
	
	// For each level
	for (i = 1; i <= tree->height; ++i) {
		
		// Positions in a level 2^(n) to 2^(n+1)-1
		for (j = (int)pow(2, i); j < (int)pow(2, i+1); ++j) {
			
			// Even: left, input if parent is non null
			if (j%2 == 0 && *(tree->arr + j/2) != '#') {
				printf("\t Left of '%c': ", *(tree->arr + j/2));
				scanf(" %c", (tree->arr + j));
			}
			
			// Odd: right, input if parent is non null
			else if (j%2 != 0 && *(tree->arr + j/2) != '#') {
				printf("\tRight of '%c': ", *(tree->arr + j/2));
				scanf(" %c", (tree->arr + j));
			}
		}
	}
}

void preorderTransversal (TREE_p_t tree, int pos) {
	
	if (pos >= tree->capacity || *(tree->arr + pos) == '#')
		return;
	
	printf(" %c", *(tree->arr + pos));
	preorderTransversal(tree, pos * 2);
	preorderTransversal(tree, pos * 2 + 1);
	
}

void inorderTransversal (TREE_p_t tree, int pos) {
	
	if (pos >= tree->capacity || *(tree->arr + pos) == '#')
		return;
	
	inorderTransversal(tree, pos * 2);
	printf(" %c", *(tree->arr + pos));
	inorderTransversal(tree, pos * 2 + 1);
	
}

int main (int argc, const char * argv[]) {
	
	int height;
	printf("\n\tEnter height of the tree: ");
	scanf(" %d", &height);
	TREE_p_t tree = initTree(height);
	printf("\n\tEnter the tree (characters) '#' for null\n: ");
	inputTree(tree);
	
	char choice = '\0';
	do {
		printf("\n\n\t1. Input tree (overwrite)\n\t2. Inorder transversal\n\t3. Preorder transversal\n\tChoice: ");
		scanf(" %c", &choice);
		
		if (choice == '1') {
			printf("\n\tEnter height of the tree: ");
			scanf(" %d", &height);
			tree = initTree(height);
			inputTree(tree);
		}
		
		else if (choice == '2') {
			printf("\n\n\t Inorder: ");
			inorderTransversal(tree, 1);
		}
		
		else if (choice == '3') {
			printf("\n\n\tPreorder: ");
			preorderTransversal(tree, 1);
		}
		
	} while (choice >= '1' && choice <= '3');
	
	printf("\n\n");
	
}
