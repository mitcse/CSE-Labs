#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
  int x[2][MAX];
  int f, r;
}Queue;

int isFull(Queue *q)
{
  if(q->r == MAX-1)
    return 1;
  return 0;

}

int isEmpty(Queue *q)
{
  if(q->f == -1 && q->r == -1)
    return 1;
  return 0;
}

void insert(Queue *q, int ele, int pri)
{
  int loc, i;
  loc = 0;
  if(!isFull(q))
    {
    if(q->f == -1)
      {
	q->f = q->r = 0;
	q->x[0][0] = ele;
	q->x[1][0] = pri;
	return;
      }


    else if(pri == 0)
      {
      for(i=(q->r)+1;i>0;i--)
	{
	  q->x[0][i] = q->x[0][i-1];
	  q->x[1][i] = q->x[1][i-1];
	}
      q->x[0][0] = ele;
      q->x[1][0] = pri;  
      (q->r)++;
      return;
      }

    if(q->x[1][q->r] < pri)
      {
	++(q->r);
	q->x[0][q->r] = ele;
	q->x[1][q->r] = pri;
	return;
      }
    
    else
      {
	for(loc = 0; loc < (q->r)+1; loc++)
	  {
	    if(pri<=q->x[1][loc])
	      {
		
		for(i = (q->r); i >= loc; i--)
		  {
		    q->x[0][i+1] = q->x[0][i];
		    q->x[1][i+1] = q->x[1][i];
		  }
	      
		q->x[0][loc] = ele;
		q->x[1][loc] = pri;
		(q->r)++;
		return;
	      }
	  }
      }


    }
  printf("Empty queue\n");
}

int delete(Queue *q)
{
  if(!isEmpty(q))
    {
      int ele;
      ele = q->x[0][(q->f)];
    if (q->f == q->r)
      {
	q->r = -1;
	q->f = -1;
	return ele;
      }
    return q->x[0][(q->f)++];
    }
  printf("Empty queue\n");
  return -32767;
}

void display(Queue *q)
{
  int i;
  printf("\n");
  if (!isEmpty(q))
    {
      for(i = q->f; i<=q->r; i++)
	printf("%d\t", q->x[0][i]);
      printf("\n");
      for(i = q->f; i<=q->r; i++)
	printf("%d\t", q->x[1][i]);
    }
  else
    {
      printf("Empty queue\n");
    }
}

int main()
{
  Queue q;
  q.f = q.r = -1;
  int ch, ele, pri;
  ch = 1;
  while(ch!=4)
    {
    printf("\n1 to insert, 2 to delete, 3 to display, 4 to exit\n");
    scanf("%d", &ch);
    switch(ch)
      {
      case 1:
	printf("Enter element and its priority\n");
	scanf("%d", &ele);
	scanf("%d", &pri);
	insert(&q,ele,pri); 
	break;
      case 2:
	ele = delete(&q);
	if(ele!=-32767)
	  printf("Deleted element %d\n", ele);
	break;
      case 3:
	display(&q);
	break;
      case 4:
	break;
      }

    } 
  return 0;
}
