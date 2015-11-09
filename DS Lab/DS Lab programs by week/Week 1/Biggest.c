#include<stdio.h>

void biggest (int arr[], int n)
{
	int i, big, pos;
	big = arr[0];
	pos = 0;
	for (i=1; i<n; i++)
	{
		if (big < arr[i])
		{
			big = arr[i];
			pos = i+1;
		}
	}
	printf ("Biggest element is %d and it is at position %d\n", big, pos);
}

void main()
{
	int arr[100], n, i;
	printf("Enter size of array\n");
	scanf("%d", &n);
	printf("Enter array\n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	biggest(arr, n);
}
