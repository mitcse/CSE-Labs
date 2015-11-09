#include<stdio.h>

int summer (int a[], int n)
{
	int sum = a[n-1];
	if (n == 1)
	{
		return a[n-1];
	}
	else
	{
		return sum + summer (a, n-1);
	}
}

int main()
{
	int a[100], n;
	printf("Enter array size\n");
	scanf("%d", &n);
	printf("Enter array\n");
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Sum of list is %d\n", summer(a,n));
	return 0;
}
