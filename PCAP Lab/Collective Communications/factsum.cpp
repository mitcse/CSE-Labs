//
//	factsum.cpp
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
	long i, n;
	long rec;
	long arr[100], facts[100];

	if (rank == 0) {

		n = size;
		printf("Enter the numbers: ");

		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

	} 

	MPI_Scatter(arr, 1, MPI_LONG, &rec, 1, MPI_LONG, 0, MPI_COMM_WORLD);
	
	printf("Process [%d] received = %d.\n", rank, rec);

	fact = 1;
	for (i = 2; i <= rec; ++i) {
		fact *= i;
	}

	MPI_Gather(&fact, 1, MPI_LONG, facts, 1, MPI_LONG, 0, MPI_COMM_WORLD);

	if (rank == 0) {

		printf("Sum of factorials = ");

		long sum = 0;
		for (i = 0; i < n; ++i) {
			sum += facts[i];
			printf("%ld %s", facts[i], (i != n-1)?"+ ":" ");
		}

		printf(" = %ld\n", sum);

	}

	MPI_Finalize();

	return 0;

}