#include<stdio.h>
#include<stdlib.h>

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
  int n;
  n = 2;
  char **stacks = (char**) calloc(n, SIZE);
  int **top = (int**) calloc(n, sizeof(int));
  int i;
  for (i=0; i<n; i++)
    {
      stacks[i] = (char*) calloc(1, SIZE);
      top[i] = (int*) calloc(1, sizeof(int));
    }
  for (i=0; i<n; i++)
    *top[i] = -1;
  char loopOn;
  loopOn = 'y';
  while (loopOn == 'y')
    {
      printf("Enter 1 for operations on stack 1, 2 for operations on stack 2\n");
      int stackNo;
      scanf("%d", &stackNo);
      printf("Enter 1 to add, 2 to delete, 3 to display\n");
      int x;
      scanf("%d", &x);
      if (x == 1)
	{
	  // push to stack stackNo
	  char ele;
	  printf("Enter element to push \n");
	  scanf("%s", &ele);
	  push(stacks[stackNo-1], ele, top[stackNo-1]);
	  printf("Now stack %d is \n", stackNo);
	  display(stacks[stackNo-1], *top[stackNo-1]);
	}
      else if (x == 2)
	{
	  // pop from stack stackNo
	  char ele = pop(stacks[stackNo-1], top[stackNo-1]);
	  if (ele == UNDERFLOW)
	    {
	      exit(0);
	    }
	  printf("Deleted element = %c\n", ele);
	  printf("Now stack %d is \n", stackNo);
	  display(stacks[stackNo-1], *top[stackNo-1]);
	}
      else if (x == 3)
	{
	  // display stack stackNo
	  printf("Now stack %d is \n", stackNo);
	  display(stacks[stackNo-1], *top[stackNo-1]);
	}
      else
	exit(0);
      printf("Want to go again? y/n\n");
      scanf(" %c", &loopOn);
    }
  return 0;
}
