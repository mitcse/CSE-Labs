#include <stdio.h>

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
	return 0;
}
