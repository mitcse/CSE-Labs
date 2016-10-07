#include<stdio.h>
#include<stdlib.h>

int *block, *file, n, m, *allocated1, *allocated2;

int findmin(int p)
{
  int i, j, min=0, t=999, found=0;
  for(i=0; i<n; i++)
  {
    for(j=0; j<m; j++)
    {
      if(i!=allocated2[j]-1 && block[i]<t)
      {
        t=block[i];
        min=i;
        found++;
        break;
      }
      if(found>0)
        break;
    }
  }
  for(j=0; j<n; j++)
  {
    if(block[j]>=file[p] && block[min]>block[j] && allocated2[j]==0)
    {
      min=j;
      found=1;
    }
  }
  return min;
}

void display(int *a)
{
  printf("File no\t\tfile size\tBlock no\tblock size\t \n");
  int i, j, t=1;
  for(i=0; i<m; i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n", i, file[i], a[i], block[a[i]-1]);
}

void bestFit()
{
  int i, j, k;
  for(i=0; i<m; i++)
  {
    k=findmin(i);
    allocated2[i]=k+1;
  }
  display(allocated2);
}

void firstFit()
{
  int i, j, count;
  for(i=0; i<m; i++)
  {
    for(j=0; j<n; j++)
    {	
      if(block[j] >= file[i] && allocated1[j]==0)
      {
        allocated1[i]=j+1;
        break;
      }
    }
  }
  display(allocated1);
}

int main()
{
  int i;
  printf("Enter the no. of blocks ");
  scanf("%d", &n);
  printf("Enter the no. of files ");
  scanf("%d", &m);
  if(n<m)
  {
    printf("Number of Files are greater than The blocks\n");
    exit(0);
  } 
  block=(int *)calloc(n,sizeof(int));
  allocated1=(int *)calloc(m,sizeof(int));
  allocated2=(int *)calloc(m,sizeof(int));
  file=(int *)calloc(m,sizeof(int));
  printf("Enter block sizes\n");
  for(i=0; i<n; i++)
  {
    printf("Block %d ",i+1);	
    scanf("%d", &block[i]);
  }
  printf("Enter file sizes\n");
  for(i=0; i<m; i++)
  {
    printf("File %d ",i+1);	
    scanf("%d", &file[i]);
  }
  printf("Best Fit\n");
  bestFit();
  printf("First Fit\n");
  firstFit();
  return 0;
}
