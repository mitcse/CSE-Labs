#include<stdio.h>

long dec2bin(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return (n % 2) + 10 * dec2bin(n/2);
	}
}

int main()
{
	int n;
	printf("Enter decimal number you want converted\n");
	scanf("%d", &n);
	printf("%li\n", dec2bin(n));
	return 0;
}
