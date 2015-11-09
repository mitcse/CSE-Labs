#include<stdio.h>
#include<stdlib.h>

void main()
{
	int arr[10000], n, freq[201];
  	printf("Enter array size ");
  	scanf("%d", &n);
  	for(int i=; i<n; i++)
  	{
		arr[i] = (float)(((rand(0,RAND_MAX))/RAND_MAX)*200);
  	}
	for (int i=0; i<n; i++)
	{
		printf("%f\n", arr[i]);
	}
}
