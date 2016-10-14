#include<stdio.h>
#include<stdlib.h>

void main()
{
		int *a,n,count=0,frn,*frame;
		int i,j,k,avail;
		printf("Enter the number of pages:");
		scanf("%d",&n);
		a = (int*)calloc(n,sizeof(int));
		printf("Enter the page number :");
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		printf("Enter the Frame size:");
		scanf("%d",&frn);
		frame = (int*)calloc(frn,sizeof(int));
		 for(i=0;i<frn;i++)
            frame[i]= -1;

            j=0;
            printf("\tref string\t page frames\n");
			for(i=0;i<n;i++)
            {
               printf("%d\t\t",a[i]);
               avail=0;
               for(k=0;k<frn;k++)
				if(frame[k]==a[i])
                    avail=1;
                if (avail==0)
                {
                   frame[j]=a[i];
                   j=(j+1)%frn;
                   count++;
                   for(k=0;k<frn;k++)
                   printf("%d\t",frame[k]);
				}
                printf("\n");
			}
 printf("Page Fault Is %d\n",count);
                        
}

