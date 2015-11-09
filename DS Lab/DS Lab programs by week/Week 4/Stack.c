#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW '\0'

void push (char *stack, int ele, int *top)
{
	if (*top == SIZE - 1)
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	(*top) += 1;
	*(stack + (*top)) = ele;
}

char pop (char *stack, int *top)
{
	if (*top == -1)
	{
		printf("STACK UNDERFLOW\n");
		return UNDERFLOW;
	}
	return *(stack + ((*top)--));
}

void display (char *stack, int top)
{
	char *i;
	for (i = stack; i <= stack + top; ++i)
		printf("%c\n", *i);
}

int main()
{
	int top = -1;
	char *stack = (char *)malloc(sizeof(char *));
	int flag;
	
	printf("1 to push, 2 to pop, 3 to display, 0 to exit\n");
	scanf("%d", &flag);
	while (flag == 1 || flag == 2 || flag == 3)
	{
		if (flag == 1)
		{
			char ele;
			printf("Enter element to push \n");
			scanf("%s", &ele);
			push(stack, ele, &top);
			printf("Now stack is \n");
			display(stack, top);
		}
		else if (flag == 2)
		{
			char ele = pop(stack, &top);
			if (ele == UNDERFLOW)
			{
				exit(0);
			}
			printf("Deleted element = %c\n", ele);
			printf("Now stack is \n");
			display(stack, top);
		}
		else if (flag == 3)
		{
			printf("Now stack is \n");
			display(stack, top);
		}
		else
			exit(0);
		printf("1 to push, 2 to pop, 3 to display, 0 to exit\n");
		scanf("%d", &flag);
	}
	return 0;
}
