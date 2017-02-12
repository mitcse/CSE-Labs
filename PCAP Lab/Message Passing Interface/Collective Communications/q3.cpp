#include "mpi.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int fact(int n) {
	if (n<=1)
		return 1;
	else
		return n*fact(n-1);
}
int main(int argc,char* argv[])
{
	int rank, size;
	int i = 0,j;
	int k = 0,fac=1,ans[1000],sum=0;
	int n,a[100][100],b[100];
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (rank == 0) {
		scanf_s("%d",&fac,1);
		//scanf_s("%d",&n,1);
		for (i=0;i<3;i++) 
			for (j=0;j<3;j++)
				scanf_s("%d",&a[i][j],1);
	}
	MPI_Bcast(&fac,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(a,100,MPI_INT,b,100,MPI_INT,0,MPI_COMM_WORLD);
	int count=0;
	for (i=0;i<3;i++) { 
		if (b[i] == fac)
			count++;
	}
		

	MPI_Reduce(&count,&k,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if (rank == 0) {
		fprintf(stdout,"Element Found:%d",k);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}
