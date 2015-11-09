#include<stdio.h>

long fact (int n)
{
	long fac = 1;
	if (n==1)
	{
		return 1;
	}
	else
	{
		return n*fact(n-1);
	}
}

int main()
{
	int n;
	long fac;
	printf("Enter number you want factorial of (till 25)\n");
	scanf("%d", &n);
	fac = fact(n);
	printf("Factorial of %d is %li\n", n, fac);
	return 0;
}
