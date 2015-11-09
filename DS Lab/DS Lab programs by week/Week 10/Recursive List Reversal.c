#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;

} NODE;

NODE *getNode()
{
    return ((NODE*)malloc (sizeof(NODE)));
}

void insert(int ele, NODE *h)
{
    if(h ->next == NULL)
    {
        h -> next = getNode();
        (h -> next) -> next = NULL;
        (h -> next) -> data = ele;
        return;
    }
    NODE* p = h;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = getNode();
    (p->next)->next = NULL;
    (p->next)->data = ele;
}

void display(NODE *h)
{
    if(h->next == NULL)
    {
        printf("Empty List!\n");
        return;
    }
    NODE *p = h->next;
    while(p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

NODE * reverse (NODE *t, NODE **h)
{
  NODE *temp;
  if (t->next == NULL)
    {
      (*h)->next = t;
    }
  else
    {
      temp = reverse(t->next, h);
      temp->next = t;
    }
  return t;
}

int main()
{
  NODE *h = getNode();
  NODE *t;
  int i, n, ele;
  printf("Enter number of elements in list\n");
  scanf("%d", &n);
  printf("Enter elements\n");
  for (i=0; i<n; i++)
    {
      scanf("%d", &ele);
      insert(ele, h);
    }
  display(h);
  t = h->next;
  reverse(t, &h);
  t->next = NULL;
  printf("Reversed list is\n");
  display(h);
  return 0;
}
