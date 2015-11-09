#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
} NODE;

NODE *createTree (NODE *root, int x)
{
  if (root == NULL)
    {
      root = (NODE *) malloc (sizeof(NODE));
      root->data = x;
      root->lchild = NULL;
      root->rchild = NULL;
    }
  else if (x > root->data)
    root->rchild = createTree (root->rchild, x);
  else if (x < root->data)
    root->lchild = createTree (root->lchild, x);
  else
    {
      printf ("Duplicate entry\n");
      exit(0);
    }
  return root;
}

void inorder (NODE *root)
{
  if (root != NULL)
    {
      inorder (root->lchild);
      printf("%d\n", root->data);
      inorder (root->rchild);
    }
}

void preorder (NODE *root)
{
  if (root != NULL)
    {
      printf("%d\n", root->data);
      preorder (root->lchild);
      preorder (root->rchild);
    }
}

void postorder (NODE *root)
{
  if (root != NULL)
    {
      postorder (root->lchild);
      postorder (root->rchild);
      printf("%d\n", root->data);
    }
}

int recursiveSearch (NODE *root, int ele)
{
  int flag = 0;
  if (root != NULL)
    {
      count++;
      if (root->data == ele)
	return 1;
      else if (root->data < ele)
	flag = recursiveSearch (root->rchild, ele);
      else
	flag = recursiveSearch (root->lchild, ele);
    }
  return flag;
}


int main()
{
  int da, choice, ele, fl;
  NODE *root;
  root = NULL;
  while (1)
    {
      printf("1. Enter new node (No duplicates allowed)\n2. Inorder traversals\n3. Preorder traversals\n4. Postorder traversals\n5. Recursively search for an element\n6. Exit\n");
      scanf (" %d", &choice);
      switch (choice)
	{
	case 1:
	  printf("Enter node\n");
	  scanf(" %d", &da);
	  root = createTree (root, da);
	  break;
	case 2:
	  printf("Inorder traversal is\n");
	  inorder (root);
	  break;
	case 3:
	  printf("Preorder traversal is\n");
	  preorder (root);
	  break;
	case 4:
	  printf("Postorder traversal is\n");
	  postorder (root);
	  break;
	case 5:
	  printf("Enter element to be searched\n");
	  scanf(" %d", &ele);
	  fl = recursiveSearch (root, ele);
	  if (fl == 1)
	    printf("Element found at %dth recursion\n", count);
	  else
	    printf("Element not found\n");
	  break;
	default:
	  exit(0);
	}
    }
}
