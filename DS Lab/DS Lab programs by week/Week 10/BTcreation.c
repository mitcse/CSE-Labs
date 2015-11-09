#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int info;
  struct node *left, *right;
}NODE;

NODE *create (NODE *bnode, int x)
{
  NODE *root;
  if (bnode == NULL)
    {
      bnode = (NODE *) malloc(sizeof(NODE));
      bnode->info = x;
      bnode->left = bnode->right = NULL;
    }
  else if (x > bnode->info)
    bnode->right = create (bnode->right, x);
  else if (x < bnode->info)
    bnode->left = create (bnode->left, x);
  else
    {
      printf("Duplicate node\n");
      exit(0);
    }
  return (bnode);
}

void inorder (NODE *ptr)
{
  if (ptr != NULL)
    {
      inorder (ptr->left);
      printf("%5d", ptr->info);
      inorder (ptr->right);
    }
  printf("\n");
}

void postorder (NODE *ptr)
{
  if (ptr != NULL)
    {
      postorder (ptr->left);
      postorder(ptr->right);
      printf("%5d", ptr->info);
    }
  printf("\n");
}

void preorder (NODE *ptr)
{
  if (ptr != NULL)
    {
      printf("%5d", ptr->info);
      preorder (ptr->left);
      preorder (ptr->right);
    }
  printf("\n");
}

void main()
{
  int n, x, ch, i;
  NODE *root;
  root = NULL;
  while (1)
    {
      printf("1 to insert, 2 to list traversals, 3 to exit\n");
      scanf("%d", &ch);
      switch (ch)
	{
	case 1:
	  printf("Enter node\n");
	  scanf("%d", &x);
	  root = create(root, x);
	  break;
	case 2:
	  printf("Inorder movements\n");
	  inorder(root);
	  printf("Preorder movements\n");
	  preorder(root);
	  printf("Postorder movements\n");
	  postorder(root);
	  break;
	case 3:
	  exit(0);
	}
    }
}
