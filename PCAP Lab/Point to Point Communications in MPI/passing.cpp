//
//	passing.cpp
//	Incrementing a number and passing it.
//
//	Usage: mpiexec -n K+1 <file.exe> <K> <K integers>
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

	if (rank == 0) {
		
		int k;

		fprintf(stdout, "%d. Enter a number : ", rank);
		scanf_s("%d",&k,1);

		k += 1;

		// Send to ID = 1
		MPI_Send(&k, 1, MPI_INT, rank + 1, rank, MPI_COMM_WORLD);
		fprintf(stdout, "\nNumber sent by process %d is %d.\n", rank, k);

		// Receive from ID = N - 1
		MPI_Recv(&k, 1, MPI_INT, size - 1, size - 1, MPI_COMM_WORLD, &status);
		fprintf(stdout,"Number received by process %d is %d.\n", rank, k);

	} else {
		
		int k;
		// Receive from ID - 1
		MPI_Recv(&k, 1, MPI_INT, rank - 1, rank - 1, MPI_COMM_WORLD, &status);
		fprintf(stdout,"Number received by process %d is %d.\n", rank, k);

		k += 1;
		// Send to (ID + 1) % size
		MPI_Send(&k, 1, MPI_INT, (rank + 1) % size, rank, MPI_COMM_WORLD);
		fprintf(stdout, "Number sent by process %d is %d.\n", rank, k);


	} 

	MPI_Finalize();
}
