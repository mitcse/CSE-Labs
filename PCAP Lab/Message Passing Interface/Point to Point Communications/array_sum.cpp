//
//	add_array.cpp
//	Add an array using two processes
//
//	Usage: mpiexec -n 3 <file.exe>
// 

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv []) {

	int size, rank;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int len = atoi(argv[1]);
	int *arr = (int *)calloc(len, sizeof(int));
	int i;
	for (i = 0; i < len; ++i) {
		*(arr + i) = atoi(argv[i+2]);
	}

	int sum1; int sum2;
	double t1, t2;

	if (rank == 0) {
		
		// Send half the array process with ID = 1
		MPI_Ssend(arr, len/2, MPI_INT, 1, 101, MPI_COMM_WORLD);
		MPI_Ssend(arr + len/2, len - len/2, MPI_INT, 2, 102, MPI_COMM_WORLD);

		MPI_Recv(&sum1, sizeof(int), MPI_INT, 1, 103, MPI_COMM_WORLD, &status);
		MPI_Recv(&sum2, sizeof(int), MPI_INT, 2, 104, MPI_COMM_WORLD, &status);

		printf("%d. Sum1 = %d, Sum2 = %d; Sum = %d\n", rank, sum1, sum2, sum1 + sum2);

	} else if (rank == 1) {

		t1 = MPI_Wtime();
		
		MPI_Recv(arr, len/2, MPI_INT, 0, 101, MPI_COMM_WORLD, &status);

		sum1 = 0;
		for (i = 0; i < len/2; ++i) {
			sum1 += *(arr + i);
		}	

		MPI_Ssend(&sum1, sizeof(int), MPI_INT, 0, 103, MPI_COMM_WORLD);

		t2 = MPI_Wtime();

		printf("%d. Sum1: %d (%lf s)\n", rank, sum1, t2 - t1);

	} else if (rank == 2) {

		t1 = MPI_Wtime();

		MPI_Recv(arr + len/2, len - len/2, MPI_INT, 0, 102, MPI_COMM_WORLD, &status);

		sum2 = 0;
		for (i = len/2; i < len; ++i) {
			sum2 += *(arr + i);
		}	

		MPI_Ssend(&sum2, sizeof(int), MPI_INT, 0, 104, MPI_COMM_WORLD);

		t2 = MPI_Wtime();

		printf("%d. Sum2: %d (%lf s)\n", rank, sum2, t2 - t1);

	}

	MPI_Finalize();
}