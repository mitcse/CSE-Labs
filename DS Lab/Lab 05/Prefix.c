#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct
{
    int stack[20];
    int tos;
}STACK;

STACK s;

void push(int ele)
{
    s.stack[++(s.tos)] = ele;
}

int pop()
{
    return s.stack[(s.tos)--];
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
    s.tos = -1;
    char ch;
    char expn[20];
    printf("Enter the expression in prefix: ");
    scanf("%s", expn);
    rev(expn);
    for(i = 0; expn[i]!='\0'; i++){
      ch = expn[i];
      if(isdigit(ch))
	push(ch-'0');
      
      else
      {
	op1 = pop();
	op2 = pop();
	push(pr(op1, op2, ch));

      }
   
    
    }
    printf("The answer is: %d\n\n", pop());

    return 0;
}
