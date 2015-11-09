#include<stdio.h>
#include<stdlib.h>

void main()
{
  int arr[10000], n, freq[199], i, temp;
	i=0;
  	printf("Enter array size ");
  	scanf("%d", &n);
	for (i=0; i<199; i++)
	  {
	    freq[i] = 0;
	  }
  	for(i=0; i<n; i++)
  	{
	  arr[i] = ((rand()/(RAND_MAX/200))-100);
	  freq[arr[i]+99]++;
  	}
	for (i=0; i<n; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("Frequencies are \n");
	for (i=0; i<199; i++)
	  {
	    temp = freq[i];
	    printf("Frequency of %d is %d\n", i-99, temp);
	  }
}
