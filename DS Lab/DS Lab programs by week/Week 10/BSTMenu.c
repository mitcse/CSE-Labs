#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
  int data;
  struct node *left, *right;
} Node;

typedef struct Queue
{
	Node *queue[100];
	int front, back;
}Q;

Q q;

Node *getNode()
{
  Node *newnode = (Node *) malloc(sizeof(Node));
  newnode->left = newnode->right = NULL;
  return newnode;
}

void inQueue(Node *p)
{
  if(q.front == -1)
  {
    q.front = q.back =0;
    q.queue[q.front] = p;
    return;
  }
  q.queue[++(q.back)] = p;

}

Node *delQueue()
{
  if(q.front == -1)
    return NULL;
  if(q.front == q.back)
  {
    Node *ptr = q.queue[q.front];
    q.front = q.back = -1;
    return ptr;
  }
  return q.queue[(q.front)++];
}

void LevelOrder(Node *r)
{
  inQueue(r);
  Node *t;
  while(1){
    t = delQueue();
    if(t == NULL)
      break;
    printf("%d -> ", t->data);

    if(t->left)
    {
      inQueue(t->left);
    }

    if(t->right){
      inQueue(t->right);
    }
  }
  printf("\n");
  
}

void TreeSearch(Node *root, int key)
{

  if(root == NULL)
  {
    printf("Not found");
    return;
  }

  if(key<root->data)
    TreeSearch(root->left, key);

  if(key>root->data)
    TreeSearch(root->right, key);

  if(key == root->data)
    printf("Element found");
  

} 

void BTinsert(int ele, Node **root)
{
  Node *trav = *root;
  Node *newnode = getNode();
  newnode->data = ele;

  if(trav == NULL)
  {
    (*root) = newnode;
    return;
  }

  while(1){
    if(ele<trav->data)
    {
      if(trav->left == NULL)
      {
		trav->left = newnode;
		return;
      }
      trav = trav->left;
    }

    if(ele>trav->data)
    {
      if(trav->right == NULL)
      {
		trav->right = newnode;
		return;
      }
      trav = trav->right;
    }
    if(ele == trav->data)
    {
      printf("Duplicate");
      return;
    }
  }
}

int main()
{

  q.front = q.back = -1;
  int key, ch, ch1, ele;
  Node *root = NULL;
  while(1)
  {
    printf("1. Insertion\n2. Level order\n3. Search\n4. exit\n");
    scanf("%d", &ch);
    if(ch == 4)
      break;
    else if(ch == 1)
    {
      printf("Enter element\n");
      scanf("%d", &ele);
      BTinsert(ele, &root);
    }
    else if(ch == 2)
      LevelOrder(root);
    
    else if(ch ==3)
    {
      printf("Enter element\n");
      scanf("%d", &key);
      TreeSearch(root, key);
    }
 }
  return 0;
}
