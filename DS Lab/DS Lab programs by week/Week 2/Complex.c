#include<stdio.h>

typedef struct
{
	int a, b;
} COMPLEX;

void operations (COMPLEX c1, COMPLEX c2)
{
	int sumReal, sumIm, diffReal, diffIm, productReal, productIm;
	sumReal = c1.a + c2.a;
	sumIm = c1.b + c2.b;
    diffReal = c1.a - c2.a;
    diffIm = c1.b - c2.b;
    productReal = ((c1.a*c2.a) - (c1.b*c2.b));
	productIm = ((c1.a*c2.b) + (c1.b*c2.a));
	printf("Sum of %d + %d and %d + %d is %d + %di\n", c1.a, c1.b, c2.a, c2.b, sumReal, sumIm);
	printf("Diff of %d + %d and %d + %d is %d + %di\n", c1.a, c1.b, c2.a, c2.b, diffReal, diffIm);
	printf("Product of %d + %d and %d + %d is %d + %di\n", c1.a, c1.b, c2.a, c2.b, productReal, productIm);
}

int main()
{
	COMPLEX c1, c2;
	printf("Enter a + ib\n");
	scanf("%d %d", &c1.a, &c1.b);
	printf("Enter c + id\n");
	scanf("%d %d", &c2.a, &c2.b);
	operations(c1, c2);
	return 0;
}
