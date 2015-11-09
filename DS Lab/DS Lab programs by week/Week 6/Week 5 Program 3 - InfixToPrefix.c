#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

# define SIZE 1000
# define UNDER '\0'

void push (char *s, char e, int *top)
{
	if (*top == SIZE-1)
		return;
	(*top) += 1;
	*(s+(*top)) = e;
}

char pop (char *s, int *top)
{
	if (*top == -1)
		return UNDER;
	return *(s+((*top)--));
}

void reverse (char *s, int top)
{
	int i;
	for (i=0; i<=top/2; i++)
	{
		char c = *(s + i);
		*(s + i) = *(s + top - i);
		*(s + top - i) = c;
	}
}

int indexOf (char  c, char *s)
{
	char *p = strchr(s, c);
	if (p)
		return (int) (p-s);
	return -1;
}

int isOp (char op)
{
	if (indexOf(op, "+-*/") != -1)
		return 1;
	return 0;
}

int prec (char op)
{
	if (indexOf(op, ")]}") != -1)
		return 0;
	else if (indexOf(op, "+-") != -1)
		return 1;
	else if (indexOf(op, "*/") != -1)
		return 2;
	return -1;
}

char *toPrefixExpn (char *e)
{
	int top1, top2;
	top1 = -1;
	top2 = -1;
	char *pre = (char *) calloc (SIZE, sizeof(char));
	char *op = (char *) calloc (SIZE, sizeof(char));
	int l, i;
	l = strlen(e);
	for (i=l-1; i>=0; --i)
	{
		char z = *(e+i);
		if ((isdigit(z) || isalpha(z)) == 1)
			push (pre, z, &top1);
		else if (prec(z) == 0)
			push (op, z, &top2);
		else if (isOp(z) == 1)
		{
			while ((top2 != -1) && prec(z) < prec(*(op+top2)))
			{
				char o = pop (op, &top2);
				if (isOp(o) == 1)
					push (pre, o, &top1);
			}
			push (op, z, &top2);
		}
		else if (indexOf (z, "([{") != -1)
		{
			while (prec(*(op + top2)) != 0)
				push (pre, pop (op, &top2), &top1);
			pop (op, &top2);
		}
		else
			continue;
	}
	while (top2 != -1)
		push (pre, pop (op, &top2), &top1);
	reverse (pre, top1);
	return pre;
}

int main()
{
	char *expn = (char *) calloc (SIZE, sizeof(char));
	printf ("Enter expression\n");
	scanf ("%s", expn);
	char *p = toPrefixExpn (expn);
	printf ("Result is %s\n", p);
	return 0;
}
