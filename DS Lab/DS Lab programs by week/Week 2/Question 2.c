#include<stdio.h>

void sum (int *p, int *q)
{
	int s;
	s = *p + *q;
	printf("Sum by passing pointers to function is %d\n", s);
}

int* add (int *p, int *q)
{
	int sum;
	int *s;
	int **ds;
	ds = &s;
	s = &sum;
	sum = *p + *q;
	printf("Sum using double pointer is %d\n", **ds);
	return s;
}

int main()
{
	int a, b;
	printf("Enter two numbers to be added\n");
	scanf("%d %d", &a, &b);
	int *p = &a;
	int *q = &b;
	int *s;
	sum(p,q);
	s = add(p,q);
	printf("Sum using pointer returned from function is %d\n", *s);
	return 0;
}
