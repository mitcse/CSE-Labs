//
//	nonvowels.cpp
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
	int count = 0;
	int b[100] = {0};

	int i, n, l;
	
	char str[100], c[100];
	
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0) {

		n = size;

		cout<<"Enter the string: ";
		cin>>str;

		l = strlen(str) / n;
		
	}

	MPI_Bcast(&l, 1, MPI_INT, 0, MPI_COMM_WORLD);

	MPI_Scatter(str, l, MPI_CHAR, c, l, MPI_CHAR, 0, MPI_COMM_WORLD);

	count = 0;
	for (i = 0; i < l; ++i) {
		if (strchr("aeiouAEIOU", c[i]) == NULL)
			count += 1;
	}

	printf("Process [%d] Count = %d\n", rank, count);

	MPI_Gather(&count, 1, MPI_INT, b, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0) {
		
		int tcount = 0;
		for (i = 0; i < n; i++)
			tcount += b[i];
		printf("Total non vowels = %d\n", tcount);

	}

	MPI_Finalize();
}