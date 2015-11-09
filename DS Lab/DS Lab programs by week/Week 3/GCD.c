#include<stdio.h>

int gcd(int x, int y)
{
	while (x != y)
	{
		if (x > y)
		{
			return gcd(x-y, y);
		}
		else
		{
			return gcd(x, y-x);
		}
	}
	return x;
}

int main()
{
	int a, b, result;
	printf("Enter two numbers you want gcd of\n");
	scanf("%d %d", &a, &b);
	result = gcd(a,b);
	printf("GCD of %d and %d is %d\n", a, b, result);
	return 0;
}
