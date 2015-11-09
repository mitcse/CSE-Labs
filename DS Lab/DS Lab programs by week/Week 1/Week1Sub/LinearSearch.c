#include<stdio.h>

void main()
{
	int arr[100], n, ele, i, pos;
	printf("Enter array size ");
	scanf("%d", &n);
	printf("Enter array ");
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter element to be searched ");
	scanf("%d", &ele);
	for (i=0; i<n; i++)
	{
		if (ele == arr[i])
		{
			pos = i;
			break;
		}
	}
	printf("Element is at %d", pos+1);
}	
