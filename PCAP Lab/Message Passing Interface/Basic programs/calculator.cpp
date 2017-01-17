// Calculator
// Perform operations in parallel on separate processes.

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv []) {
	
	int rank;

	/*
	printf("argc = %d argv = { ", argc);
	int i;
	for (i = 0; i < argc; ++i) {
		printf("%s, ", argv[i]);
	}
	printf(" }\n\n");
	*/

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	double res;
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	// printf("a = %.3f, b = %.3f\n", a, b);
	if (rank == 0) {
		res = a + b;
		printf("Process %d added: %.3f", rank, res);
	} else if (rank == 1) {
		res = a - b;
		printf("Process %d substracted: %.3f", rank, res);
	} else if (rank == 2) {
		res = a * b;
		printf("Process %d multiplied: %.3f", rank, res);
	} else if (rank == 3) {
		res = a / b;
		printf("Process %d divided : %.3f", rank, res);
	}

	MPI_Finalize();

	return 0;

}