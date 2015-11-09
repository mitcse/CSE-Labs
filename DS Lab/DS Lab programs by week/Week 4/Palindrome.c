#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
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
	int top;
	top = -1;
	int i;
	char *stack = (char *)malloc(sizeof(char *));
	char *string = (char *)malloc(sizeof(char *));
	
	printf("Enter a string: ");
	scanf("%s", string);
	
	for (i = 0; i < strlen(string); ++i) {
		push(stack, string[i], &top);
	}
	
	int flag;
	flag = 1;
	for (i = 0; i < strlen(string)/2; ++i) {
		if (pop(stack, &top) != string[i]) {
			flag = 0;
			break;
		}
	}
	
	if (flag == 1)
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");
	
	return 0;
}
