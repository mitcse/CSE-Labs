// helloworld
// Create some threads, even numbered print 'HELLO', odd numbered print 'WORLD'

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv []) {

	int size, rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank % 2 == 0) {
		printf("%.3d. HELLO\n", rank);
	} else {
		printf("%.3d. WORLD\n", rank);	
	}

	MPI_Finalize();
}