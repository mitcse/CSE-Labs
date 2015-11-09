#include<stdio.h>

void main()
{
	int arr[100], i, n;
	int sum=0;
	printf("Enter array size\n");
	scanf("%d", &n);
	printf("Enter array\n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i=0; i<n; i++)
	{
		sum = sum + arr[i];
	}
	printf("Array sum is %d \n", sum);
}
