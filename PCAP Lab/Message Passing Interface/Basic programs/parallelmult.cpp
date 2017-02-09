// Parallel matrix multiplication using MPI

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv []) {

	int a[10][10];
	int b[10][10];
	int c[10][10];

	int r1, c1, r2, c2;
	int i, j;

	// Load from file (needs to be in the to be executed folder)

	FILE *input = fopen("inp.txt", "r");
	fscanf(input, "%d %d", &r1, &c1);\
	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c1; ++j) {
			fscanf(input, "%d ", &a[i][j]);
		}
	}
	fscanf(input, "%d %d", &r2, &c2);
	for (i = 0; i < r2; ++i) {
		for (j = 0; j < c2; ++j) {
			fscanf(input, "%d ", &b[i][j]);
		}
	}

	// Initialize matrix C

	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c2; ++j) {
			c[i][j] = 0; 
		}
	}

	int id;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	// Parallel multiplication

	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c2; ++j) {
			c[i][j] += a[i][id] + b[id][j]; 
		}
	}

	// Print it

	if (id == 2) {
		printf("\nA x B = \n");
		for (i = 0; i < r1; ++i) {
			for (j = 0; j < c2; ++j) {
				printf("%4d", c[i][j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();

}