#include<stdio.h>

void main()
{
	int varOne, varTwo, sum;
	int *ptrOne=&varOne;
	int *ptrTwo=&varTwo;
	printf("Enter two numbers\n");
	scanf("%d %d", &varOne, &varTwo);
	sum = *ptrOne + *ptrTwo;
	printf("Sum is %d\n", sum);
}
