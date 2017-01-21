//
//	synchronous_send.cpp
//	Synchronous send with MPI
//
//	Usage: mpiexec -n 2 <file.exe>
// 

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv []) {

	int size, rank;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	char *word = argv[1];

	int i;
	int len = strlen(word);

	if (rank == 0) {
		
		// Send to the process with ID = 1
		MPI_Ssend(word, len, MPI_CHAR, 1, 101, MPI_COMM_WORLD);

		printf("%d. Sent: %s\n", rank, word);

		// Recv from the process with ID = 0
		MPI_Recv(word, len, MPI_CHAR, 1, 102, MPI_COMM_WORLD, &status);

		printf("%d. Recv: %s\n", rank, word);

	} else {
		
		// Revc from the process with ID = 0
		MPI_Recv(word, len, MPI_CHAR, 0, 101, MPI_COMM_WORLD, &status);

		printf("%d. Recv: %s\n", rank, word);

		for (i = 0; i < len; ++i) {
			char z = *(word + i);
			if (z >= 'A' && z <= 'Z')
				*(word + i) += 32;
			else if (z >= 'a' && z <= 'z')
				*(word + i) -= 32;
		}

		// Send to the process with ID = 0
		MPI_Ssend(word, len, MPI_CHAR, 0, 102, MPI_COMM_WORLD);

		printf("%d. Sent: %s\n", rank, word);

	}

	MPI_Finalize();
}