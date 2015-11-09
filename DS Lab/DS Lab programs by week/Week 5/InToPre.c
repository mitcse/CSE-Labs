#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define UNDERFLOW_CHAR '\0'

typedef enum
{
	NO = 0,
	YES = 1,
} BOOL;

BOOL isStackFull (int top)
{
	if (top == SIZE - 1)
		return YES;
	return NO;
}

BOOL isStackEmpty (int top)
{
	if (top == -1)
		return YES;
	return NO;
}

void push (char *stack, char ele, int *top)
{
	if (*top == SIZE - 1)
		return;
	(*top) += 1;
	*(stack + (*top)) = ele;
}

char pop (char *stack, int *top)
{
	if (*top == -1)
		return UNDERFLOW_CHAR;
	return *(stack + ((*top)--));
}

void reverse (char *stack, int top)
{
	int i;
	for (i = 0; i <= top/2; ++i)
	  {
		char ch = *(stack + i);
		*(stack + i) = *(stack + top - i);
		*(stack + top - i) = ch;
	}
}


int indexOf (char character, char *str)
{
	char *ptr = strchr(str, character);
	if (ptr)
		return (int)(ptr - str);
	return -1;
}


BOOL isOperator (char op)
{
	if (indexOf(op, "+-*/") != -1)
		return YES;
	return NO;
}

BOOL isOperand (char op)
{
	if ((op >= 65 && op <= 90) || (op >= 97 && op <= 122))
		return YES;
	if (op >= 48 && op <= 57)
		return YES;
	return NO;
}

int operatorPrec (char op)
{
	if (indexOf(op, ")]}") != -1) return 0;
	else if (indexOf(op, "+-") != -1) return 1;
	else if (indexOf(op, "*/") != -1) return 2;
	return -1;
}


char *toPrefix (char *exp)
{
	
	int tos1 = -1;
	char *prefix = (char *)calloc(SIZE, sizeof(char));
	int tos2 = -1;
	char *operator = (char *)calloc(SIZE, sizeof(char));
	
	int l = (int)strlen(exp);
	int i;
	
	for (i = l - 1; i >= 0; --i)
	  {
		char z = *(exp + i);
		
		if (isOperand(z))
			push(prefix, z, &tos1);
		
		else if (operatorPrec(z) == 0)
			push(operator, z, &tos2);
		
		else if (isOperator(z))
		  {
			while (!isStackEmpty(tos2) && operatorPrec(z) < operatorPrec(*(operator + tos2)))
			  {
				char op =  pop(operator, &tos2);
				if (isOperator(op))
					push(prefix, op, &tos1);
			}
			push(operator, z, &tos2);
		}
		
		else if (indexOf(z, "([{") != -1)
		  {
			while (operatorPrec(*(operator + tos2)) != 0)
				push(prefix, pop(operator, &tos2), &tos1);
			pop(operator, &tos2);
		}
		
		else
			continue;
		
	}
	
	while(!isStackEmpty(tos2))
		push(prefix, pop(operator, &tos2), &tos1);
	
	reverse(prefix, tos1);
	return prefix;
}

int main()
{
	
	char *infix = (char *)calloc(SIZE, sizeof(char));
	
	printf("Enter infix expression : ");

	scanf("%s", infix);
	
	char *prefix = toPrefix(infix);
	
	printf("Infix: %s\nPrefix: %s\n", infix, prefix);
	
	return 0;
}
