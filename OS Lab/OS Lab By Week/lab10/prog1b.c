#include<stdio.h>
#include<stdlib.h>

void main()
{
		int *a,np,pf=0,nf,*frame,*counter,*used;
		int i,j,k,flag=0,temp,index;
		printf("Enter the number of pages:");
		scanf("%d",&np);
		a = (int*)calloc(np,sizeof(int));
		printf("Enter the page number :");
		for(i=0;i<np;i++)
		scanf("%d",&a[i]);
		printf("Enter the Frame size:");
		scanf("%d",&nf);
		frame = (int*)calloc(nf,sizeof(int));
		counter = (int*)calloc(nf,sizeof(int));
		used = (int*)calloc(nf,sizeof(int));
		 for(i=0;i<nf;i++){
            frame[i]= -1;
        }    
        for(i=0;i<np;i++)
 		{
  			flag=0;
		  	for(j=0;j<nf;j++)
  			{	
   				if(frame[j]==a[i])
   				{
    				printf("\n\t");
    				flag=1;break;	
   				}
  			}
  			if(flag==0)
  			{
   				for(j=0;j<nf;j++) used[j]=0;
   				for(j=0,temp=i-1;j<nf-1;j++,temp--)
   				{
    				for(k=0;k<nf;k++)
    				{
     				if(frame[k]==a[temp])
     				used[k]=1;
				    }
   				}
   				for(j=0;j<nf;j++)
    			if(used[j]==0)
    			index=j;
   				frame[index]=a[i];
   				printf("\nFault:  ");
   				pf++;
  			}
  			for(k=0;k<nf;k++)
  			printf("%d\t",frame[k]);
 		}
 printf("\nNumber of page faults is: %d \n",pf);

}