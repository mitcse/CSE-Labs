// Question was to create a binary tree iteratively and list all level order traversals (also iteratively).
// Do it recursively, always. This is bullshit.

#include <stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct tnode
{
  int data;
  struct tnode *lchild;
  struct tnode *rchild;
}TNode;

typedef struct queue
{
	struct tnode *ele[SIZE];
	int front, rear;
}Queue;

void insert (Queue *q, TNode *elem)
{
	q->ele[++q->rear] = elem;
}

TNode *delete (Queue *q)
{
	if (q->front == q->rear)
		return NULL;
	else
		return q->ele[++q->front];
}

TNode *getTNode()
{
  TNode *newnode = (TNode *) malloc (sizeof(TNode));
  newnode->rchild = newnode->lchild = NULL;
  return newnode;
}

void insertIterBT (TNode **rt, int item)
{
  int ch;
  TNode *t = *rt;
  TNode *present = NULL;
  TNode *newnode;
  if (*rt == NULL)
    {
      *rt = getTNode();
      (*rt)->data = item;
      return;
    }
  do
    {
      printf("1 to insert to left, 2 to insert to right: ");
      scanf("%d", &ch);
      present = t;
      if (ch == 1)
		t= t->lchild;
      else
		t = t->rchild;
      if (t == NULL)
	{
	  newnode = getTNode();
	  newnode->data = item;
	  (ch == 1)?(present->lchild=newnode):(present->rchild=newnode);
	  return;
	}
    }while (1);
}

void levelOrder (TNode *rt, Queue *q)
{
	TNode *t;
	insert(q, rt);
	
	while (1)
	{
		t = delete(q);
		if (t == NULL)
			break;
		printf(" %d", t->data);
		if (t->lchild)
			insert(q, t->lchild);
		if (t->rchild)
			insert(q, t->rchild);
	}
	printf("\n");
}

int main()
{
  Queue q;
  q.front = q.rear = 0;
  int n, ch, i, el;
  TNode *root;
  root = NULL;
  while (1)
    {
      printf("1 to insert, 2 to list level order traversals, 3 to exit: ");
      scanf(" %d", &ch);
      switch(ch)
	{
	case 1:
	  printf("Enter node: ");
	  scanf(" %d", &el);
	  insertIterBT(&root, el);
	  break;
	case 2:
		levelOrder(root, &q);
		break;
	case 3:
		exit(0);
	}
	}
}
