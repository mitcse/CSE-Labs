//
//	fact.cpp
//		
//	
//	
//	Created by @avikantz on 02/02/17
//

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

	int rank, size;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	long fact;
	int i, n;
	long rec;
	int arr[100];

	if (rank == 0) {

		n = size;
		printf("Enter the numbers: ");

		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

	} 

	MPI_Scatter(arr, 1, MPI_INT, &rec, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	printf("Process [%d] received = %d.\n", rank, rec);

	fact = 1;
	for (i = 2; i <= rec; ++i) {
		fact *= i;
	}

	printf("\t%ld! = %ld\n", rec, fact);

	MPI_Finalize();

	return 0;

}