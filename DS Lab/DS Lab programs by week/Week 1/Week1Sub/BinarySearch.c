#include<stdio.h>

void main()
{
	int arr[100], n, ele, pos, i, low, mid, high;
	printf("Enter size of array\n");
	scanf("%d", &n);
	printf("Enter sorted array\n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter element to be searched\n");
	scanf("%d", &ele);
	low = 0;
	high = n-1;
	i=0;
	while (3<4)
	{
		mid = (high+low)/2;
		if (ele == arr[mid])
		{
			pos = mid+1;
			break;
		}
		else if (ele > arr[mid])
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	printf("Element is at %d position\n", pos);
}
