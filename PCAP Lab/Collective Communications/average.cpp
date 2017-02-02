//
//	average.cpp
//		
//	
//	
//	Created by @avikantz on 02/02/17
//

#include "mpi.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {

	int rank,size;
	float avg = 0;
	float b[100];

	int i, n, m;
	
	int arr[100],c[100];
	
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0) {
		n = size;
		cout<<"Enter 'm': ";
		cin>>m;

		printf("Enter %d x %d = %d elements: ", n, m, n*m);
		for (i = 0; i < n * m; ++i) {
			cin>>arr[i];
		}
		
	}

	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(arr, m, MPI_INT, c, m, MPI_INT, 0, MPI_COMM_WORLD);

	for (i = 0; i < m; ++i) { 
		avg += c[i];
	}

	avg /= m;
	printf("Process [%d] Average = %.2f\n", rank, avg);

	MPI_Gather(&avg,1,MPI_FLOAT,b,1,MPI_FLOAT,0,MPI_COMM_WORLD);

	if (rank == 0) {
		
		float tavg = 0;
		for (i = 0; i < n; i++)
			tavg += b[i];
		tavg /= n;
		printf("Total average = %.2f\n", tavg);

	}

	MPI_Finalize();
}