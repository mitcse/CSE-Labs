#include<stdio.h>
#include<stdlib.h>

int main()
{
  int size, n, waste=0, i=0, t=0, sum=0, n1=0;
  int *p;
  printf("Enter the distribution size ");
  scanf("%d", &size);
  printf("Enter no. of Blocks :");
  scanf("%d", &n);
  p=(int *)calloc(n, sizeof(int));
  while(n1<n)
  {
    printf("Memory for process %d:", i+1);
    scanf("%d", &p[i]);
    i++;
    if(p[i-1]>(size/n))
    {
      printf("Cannot be allocated\n");
      t--;
      continue;
    }
    sum+=p[i-1];
    n1++;
  }
  waste=size-sum;
  printf("Total Memory Allocated %d Internal Fragmentation %d\n", sum, waste);
  return 0;
}


