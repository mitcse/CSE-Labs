#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node* next;
}NODE;

void Display(NODE *h)
{
  NODE *p = h->next;
  while(p!=h)
    {
    printf("%d\t", p->data);
    p = p->next;
  }
  printf("\n");
}

NODE *getNode()
{
  return ((NODE*)calloc(1, sizeof(NODE)));
}

void insert(NODE *h, int ele)
{
  NODE *p = h;
  while(p->next!=h)
  {
    p = p->next;
  }
  
  NODE *t;
  t = getNode();
  p->next = t;
  t->data = ele;
  t->next = h;

}

int main()
{
  NODE h1, h2;
  h1.data = h2.data = 0;
  h1.next = &h1;
  h2.next = &h2;
  int n, i, ele;
  printf("Enter size of list 1\n");
  scanf("%d", &n);
  printf("Elements?\n");
  for(i = 0; i<n; i++)
  {
    scanf("%d", &ele);
    insert(&h1, ele);
  }
  printf("First list is\n");
  Display(&h1);
  printf("Enter size of list 2\n");
  scanf("%d", &n);
  printf("Elements?\n");
  for(i = 0; i<n; i++)
  {
    scanf("%d", &ele);
    insert(&h2, ele);
  }
  printf("Second list is\n");
  Display(&h2);
  NODE h;
  h.data = 0; 
  h.next = &h;
  NODE *p1, *p2;
  p1 = h1.next;
  while(p1!=&h1)
  {
    insert(&h, p1->data);
    p1 = p1->next;
  }
  int flag = 1;
  p2 = h2.next;
  while(p2!=&h2)
  {
    flag = 1;
    p1 = h1.next;
    while(p1!=&h1)
    {
      if(p1->data == p2->data)
      {
        flag = 0;
		break;
      }
      p1 = p1->next;
    }
    if(flag)
      insert(&h, p2->data); 
    p2 = p2->next;
  }
  printf("Union of both lists is\n");
  Display(&h);
  return 0;
}
