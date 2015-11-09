#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct
{
    int stack[20];
    int tos;
}STACK;

STACK s1;

void push(int ele)
{
    s1.stack[++(s1.tos)] = ele;
}

int pop()
{
    return s1.stack[(s1.tos)--];
}

int pr(int op2, int op1, char op)
{
  switch(op)
    {
        case '+': return (op1 + op2);
        case '-': return (op2 - op1);
        case '*': return (op1 * op2);
        case '/': return (op2/op1);
    }
    return 0;

}

void rev(char s[20])
{
  int i;
  char temp;

  for(i = 0; i<(strlen(s)/2); i++)
    {
    temp = s[i];
    s[i] = s[strlen(s)-1-i];
    s[strlen(s)-1-i] = temp;
  }

}

int main()
{
    int i, op1, op2, process;
    s1.tos = -1;
    char c;
    char exp[20];
    printf("Enter prefix expresion\n");
    scanf("%s", exp);
    rev(exp);
    for(i = 0; exp[i]!='\0'; i++)
      {
      c = exp[i];
      if(isdigit(c))
	push(c-'0');
      
      else
	{
	op1 = pop();
	op2 = pop();
	push(pr(op1, op2, c));

      }
   
    
    }
    printf("Result : %d\n", pop());

    return 0;
}
