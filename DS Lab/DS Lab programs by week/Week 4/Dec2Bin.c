#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void push (int *stack, int ele, int *top)
{
	if (*top == SIZE - 1) {
		printf("STACK OVERFLOW\n");
		return;
	}
	(*top) += 1;
	*(stack + (*top)) = ele;
}

void displayReverse (int *stack, int top)
{
	int *p;
	for (p = stack + top; p >= stack; --p)
		printf("%d", *p);
}

int main()
{
	
	int top = -1;
	int *stack = (int *)malloc(sizeof(int *));
	int n;
	
	printf("Enter a decimal number: ");
	scanf("%d", &n);
	
	int x = n;
	while (x > 0) {
		push(stack, x%2, &top);
		x /= 2;
	}
	
	printf("Binary notation of %d is ", n);
	displayReverse(stack, top);
	printf("\n");
	
	return 0;
}
