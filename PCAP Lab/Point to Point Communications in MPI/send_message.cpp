//
//	send_number.cpp
//	Send a random number to each of the child processes.
//
//	Usage: mpiexec -n k <file.exe>
// 

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE sizeof(int)

int main (int argc, char *argv []) {

	int size, rank;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	char message[128];
	int len;

	int i;

	if (rank == 0) {

		message = "SEND HELP!";
		len = strlen(message);

		for (i = 1; i < size; ++i) {
			MPI_Send(&len, 1, MPI_INT, i, i, MPI_COMM_WORLD);
			MPI_Send(message, strlen(message), MPI_CHAR, i, size + i, MPI_COMM_WORLD);
		}

	} else {
		
		MPI_Recv(&len, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		MPI_Recv(message, len, MPI_CHAR, 0, size + rank, MPI_COMM_WORLD, &status);

		MPI_Send(message, len, MPI_CHAR, 0, 2 * size + rank, MPI_COMM_WORLD, &status);		

	}

	MPI_Finalize();
}