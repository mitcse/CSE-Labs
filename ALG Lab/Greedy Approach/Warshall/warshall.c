#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16777216

int mat[10][10];
int n;

int i, j, k;

void printmat (int mat[10][10], int n) {
	printf("\n  ");
	for (j = 0; j < n; ++j) {
		printf("\t%d", j+1);
	}
	printf("\n  | ");
	for (j = 0; j < n; ++j) {
		printf(" ⎻⎻⎻⎻⎻⎻⎻");
	}
	printf("\n");
	for (i = 0; i < n; ++i) {
		printf("%d | ", i+1);
		for (j = 0; j < n; ++j) {
			printf("\t%d", mat[i][j]);
		}
		printf("\n");
	}
}

void input () {
	printf("Enter the number of vertices: ");
	scanf(" %d", &n);
	memset(mat, 0, sizeof(int)*n*n);
	for (i = 0; i < n; ++i) {
		printf("Enter connected vertices to Vertex %d [0 to break]: ", i+1);
		do {
			scanf(" %d", &j);
			if (j != 0)
				mat[i][j-1] = 1;
		} while (j != 0);
	}
}

void transistive_closure () {
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
			}
		}
		printf("\nStage %d: ", k);
		printmat(mat, n);
	}
}

int main (int argc, const char * argv []) {
	input();
	printf("Initially: \n");
	printmat(mat, n);
	transistive_closure();
	printf("Transistive closure: \n");
	printmat(mat, n);
}

/**
	* Sample Input * (Page 307 of Anany Levitin, 3rd edition)
	4
	2 0
	4 0
	0
	1 3 0

	* Sample Output * (all stages of this.)
	  		1	2	3	4
	  | ⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻
	1 | 	1	1	1	1
	2 | 	1	1	1	1
	3 | 	0	0	0	0
	4 | 	1	1	1	1


*/