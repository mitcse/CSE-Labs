#include <stdio.h>
#include <ctype.h>
#include <math.h>

# define SIZE 20

char stack[SIZE];
int top = -1;

void push (char n)
{
	if (top == SIZE-1)
		printf("Stack Overflow");
	else
	{
		top = top+1;
		stack[top] = n;
	}
}

char pop()
{
	char t;
	if (top == -1)
	{
		printf("Stack Underflow");
		return 0;
	}
	else
	{
		t = stack[top];
		top -= 1;
		return t;
	}
}

int prec (char n)
{
	switch (n)
	{
		case '(' : return 0;
		case '+' : case '-': return 1;
		case '*' : case '/': return 2;
	}
	return 0;
}

void display()
{
	int i;
	if (top != -1)
	{
		for (i=0; i<top; i++)
			printf("%c", stack[i]);
	}
	else
		printf("Empty Stack");
}

int main()
{
	char infix[50], insymb, postfix[40], t;
	int i=0, k=0;
	printf("Enter valid postfix string\n");
	scanf("%s", infix);
	while (infix[i] != '\0')
	{
		insymb = infix[i];
		if (isalpha(insymb) || isdigit(insymb))
			postfix[k++] = insymb;
		else if (insymb == '(')
			push(insymb);
		else if (insymb == ')')
		{
			while (top != -1 && (t = pop()) != '(')
				postfix[k++] = t;
		}
		else
		{
			if (top == -1)
				push(insymb);
			else
			{
				if (prec(insymb) > prec(stack[top]))
					push (insymb);
				else
				{
					while ((top != -1) && (prec(insymb) <= prec(stack[top])))
						postfix[k++] = pop();
					push (insymb);
				}
			}
		}
		printf("%s\n", infix+i);
		postfix[k] = '\0';
		display();
		printf("	%s\n", postfix);
		i++;
	}
	while (top != -1)
	{
		if ((t = pop()) != '(')
			postfix[k++] = t;
	}
	postfix[k] = '\0';
	printf("The postfix expression is : %s\n", postfix);
	return 0;
}
