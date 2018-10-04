#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999

#define MIN(A, B) (A < B) ? A : B

int mat[10][10];
int n;

int dist[10][10];

int i, j, k;

void printmat (int mat[10][10], int n) {
	printf("\n  ");
	for (j = 0; j < n; ++j) {
		printf("\t%3d", j+1);
	}
	printf("\n  | ");
	for (j = 0; j < n; ++j) {
		printf(" ⎻⎻⎻⎻⎻⎻⎻");
	}
	printf("\n");
	for (i = 0; i < n; ++i) {
		printf("%d | ", i+1);
		for (j = 0; j < n; ++j) {
			if (mat[i][j] == INF)
				printf("\t  ∞");
			else
				printf("\t%3d", mat[i][j]);
		}
		printf("\n");
	}
}

void input () {
	printf("Enter the number of vertices: ");
	scanf(" %d", &n);
	memset(mat, 0, sizeof(int)*n*n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			dist[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (i = 0; i < n; ++i) {
		printf("Enter connected vertices to Vertex %d [0 to break]: ", i+1);
		do {
			scanf(" %d", &j);
			if (j != 0) {
				mat[i][j-1] = 1;
			}
		} while (j != 0);
		for (j = 0; j < n; ++j) {
			if (mat[i][j] != 0) {
				printf("Enter weight of edge (%d, %d): ", i+1, j+1);
				scanf(" %d", &dist[i][j]);
			}
		}
	}
}

void shortest_path () {
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				int nd = dist[i][k] + dist[k][j];
				dist[i][j] = MIN(dist[i][j], nd);
			}
		}
		printf("\nStage %d: ", k);
		printmat(dist, n);
	}
}

void transistive_closure () {
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
			}
		}
		// printf("\nStage %d: ", k);
		// printmat(mat, n);
	}
}

int main (int argc, const char * argv []) {
	input();
	printf("Initially: \n");
	printmat(mat, n);
	// transistive_closure();
	// printf("Transistive closure: \n");
	// printmat(mat, n);
	printf("Initially, distance:\n");
	printmat(dist, n);
	shortest_path();
	printf("Shortest paths:\n");
	printmat(dist, n);
}

/**
	* Sample Input * (Page 311 of Anany Levitin, 3rd edition)
	4
	3 0
	3
	1 0
	2
	2 4 0
	7
	1
	1 0
	6

	* Sample Output *

	Initially, distance:
	  	  1   2	  3	  4
	  |  ------------------
	1 |   0	  ∞	  3	  ∞
	2 |   2	  0	  ∞	  ∞
	3 |   ∞	  7	  0	  1
	4 |   6	  ∞	  ∞	  0

	Shortest paths:

	  	  1	  2	  3	  4
	  |  ------------------
	1 |   0	 10	  3	  4
	2 |   2	  0	  5	  6
	3 |   7	  7	  0	  1
	4 |   6	 16	  9	  0


*/