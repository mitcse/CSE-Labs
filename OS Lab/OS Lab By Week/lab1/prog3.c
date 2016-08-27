#include <stdio.h>

void sorting(int a[], int n);
int main()
{
	printf("Enter n\n");
	int n;
	scanf("%d", &n);
	int *a;
	printf("Enter numbers\n");
	for (int i=0; i<n; i++)
	{
		scanf("%d ", (a+i));
	}
	printf("printing now\n");
	for (int i=0; i<n; i++)
	{
		printf("%d\n", *(a+i));
	}
	printf("Sorting\n");
	sorting(a, n);
	return 0;
}

void sorting (int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	printf("Sorted\n");
	for (int i=0; i<n; i++)
	{
		printf("%d\n", a[i]);
	}
}

