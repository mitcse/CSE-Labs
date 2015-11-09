#include<stdio.h>

int product(int a, int b)
{
	if (b == 1)
	{
		return a;
	}
	else
	{
		return a + product(a,b-1);
	}
}

int main()
{
	int m, n;
	printf("Enter numbers you want to multiply\n");
	scanf("%d %d", &m, &n);
	printf("Product of %d and %d is %d\n", m, n, product(m,n));
	return 0;
}
