//
//	send_number.cpp
//	Send a random number to each of the child processes.
//
//	Usage: mpiexec -n k <file.exe>
// 

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main (int argc, char *argv []) {

	int size, rank;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int m, n;
	int numbers[MAX][MAX]; // ¯\_(ツ)_/¯
	
	int i, j;

	if (rank == 0) {

		fprintf(stdout, "Enter n, m: ");
		scanf("%d %d", &n, &m);

		fprintf(stdout, "Enter n * m numbers: \n");
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf_s("%d", &numbers[i][j], 1)
			}
		}

		for (i = 1; i < size; ++i) {
			MPI_Send(&n, sizeof(int), MPI_INT, i, i, MPI_COMM_WORLD); // Send m
			MPI_Send(&m, sizeof(int), MPI_INT, i, i, MPI_COMM_WORLD); // Send n
			MPI_Send(*(numbers + i), m * sizeof(int), MPI_INT, i, i, MPI_COMM_WORLD);
		}

	} else {
		MPI_Recv(&n, sizeof(int), MPI_INT, 0, rank, MPI_COMM_WORLD); 
		MPI_Recv(&m, sizeof(int), MPI_INT, 0, rank, MPI_COMM_WORLD); 
		MPI_Recv(*(numbers + i), m * sizeof(int), MPI_INT, 0, rank, MPI_COMM_WORLD);
	}

	// Scatter (Randomize?)

	int *arr = *(numbers + i);
	for (i = 0; i < n - 1; ++i) {
		j = (i + rand () % MAX) % n;
		int c = arr[j];
		arr[j] = arr[i];
		arr[i] = c;
	}

	MPI_Finalize();
}

