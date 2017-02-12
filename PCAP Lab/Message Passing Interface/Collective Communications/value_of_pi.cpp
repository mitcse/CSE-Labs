//
//	value_of_pi.cpp
//		
//	
//	
//	Created by Vrushank Upadhayay on 02/08/17
//

#include "mpi.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main (int argc, char *argv[]) {

	int rank, size;
	int i = 0, j;
	int k = 0, fac=1, ans[1000], sum=0;
	int n, a[100][100], b[100];
	float x, y, area, pi1;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	//MPI_Bcast(&size, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	x = (float)(rank+1)/size;
	y = 4.f/(1+x*x);
	area = (1/(float)size)*y;

	MPI_Reduce(&area, &pi1, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0) {
		fprintf(stdout, "%f", pi1);
		fflush(stdout);
	}
	
	MPI_Finalize();

	return 0;
}
