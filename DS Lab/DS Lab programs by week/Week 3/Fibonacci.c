#include<stdio.h>

long fibo (int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return (fibo(n-1) + fibo(n-2));
	}
}

int main()
{
	int n;
	printf("Enter number of Fibonacci sequence terms you want\n");
	scanf("%d", &n);
	int i;
	for (i=0; i<n; i++)
	{
		printf("%li\n", fibo(i));
	}
	return 0;
}
