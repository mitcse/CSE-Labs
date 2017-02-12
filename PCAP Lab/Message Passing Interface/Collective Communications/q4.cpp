#include<stdio.h>
#include "mpi.h"

int main(int a,char *b[])
{
	int id,ele;
        int a1[3][3];
        int b1[3];
        int count=0;

        int tc=0;
        int error;
	MPI_Init(&a,&b);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
        MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
        if(id==0)
        {
          scanf_s("%d",&ele,1);
          for(int i=0;i<3;i++) 
            for(int j=0;j<3;j++)
             scanf_s("%d",&a1[i][j],1);
        }
        error=MPI_Bcast(&ele,1,MPI_INT,4,MPI_COMM_WORLD); //error code
        if(error!=MPI_SUCCESS)
        {
                  char s[100];
        int len,class1;
          MPI_Error_string(error,s,&len);
          MPI_Error_class(error,&class1);
          fprintf(stderr,"Error description is %s",s);
          fflush(stderr);
          fprintf(stderr,"Error class is %d",class1);
          fflush(stderr);
          
        }
        MPI_Scatter(a1,3,MPI_INT,b1,3,MPI_INT,0,MPI_COMM_WORLD);
        for(int i=0;i<3;i++)
         if(b1[i]==ele)
           count++;
        MPI_Reduce(&count,&tc,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
        if(id==0)
        {
          fprintf(stdout,"Number of occurrences is %d",tc);
          fflush(stdout);
        }
        MPI_Finalize();
        return 0;
}
