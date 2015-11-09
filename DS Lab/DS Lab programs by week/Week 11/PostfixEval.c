#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct tnode
{
  char data;
  struct tnode *lchild, *rchild;
} TNode;

typedef struct stack
{
  TNode* st[100];
  int top;
}STACK;

void push(STACK *s, TNode *t)
{
  s->st[++(s->top)] = t;
}

TNode *pop(STACK *s)
{
  return (s->st[(s->top)--]);
}

TNode *getNode()
{
  TNode *temp = (TNode *)malloc(sizeof(TNode));
  temp->rchild = temp->lchild = NULL;
  return temp;
}

TNode *buildTree(char post[])
{
  STACK st;
  st.top = -1;
  char s;
  int i = 0;
  TNode* t;
  while(post[i]!='\0')
  {
    s = post[i++];
    t = getNode();
    t->data = s;
    if(isalpha(s)||isdigit(s))
    {
      push(&st, t);
    }
    else
    {
      t->rchild = pop(&st);
      t->lchild = pop(&st);
      push(&st, t);
    }
  }
  return st.st[0];
}

float operation(float a, float b, char op)
{
  switch(op)
    {
    	case '+': return a+b;
    	case '-': return a-b;
   	 	case '*': return a*b;
    	case '/': return a/b;
    }
  return -1;
}

float evaluate(TNode *root)
{
  float val, t1, t2;
  if(root == NULL)
    return 0;
  else
  {
    if(isdigit(root->data))
      return (float)((root->data) - '0');
    else if(isalpha(root->data))
    {
      printf("Enter %c\n", root->data);
      scanf("%f", &val);
      return(val);
    }
    else
    {
      t1 = evaluate(root->lchild);
      t2 = evaluate(root->rchild);
      return operation(t1, t2, root->data);
    }
  }
}

int main()
{
  char postfix[100];
  printf("Enter postfix expression\n");
  scanf("%s", postfix);
  TNode *root = buildTree(postfix);
  float answer;
  answer = evaluate(root);
  printf("%.2f\n", answer);
  return 0;
}
