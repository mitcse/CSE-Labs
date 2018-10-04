#include<stdio.h>
#include<stdlib.h>
int count = 0,cnt=0;
typedef struct NODE
{
	int data;
	struct NODE* lchild,*rchild;
}NODE;

NODE* init(NODE* root,int item)
{
	root = (NODE*)malloc(sizeof(NODE));
	root->data=item;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}
NODE* createTree(NODE* root)
{
	int item;
	if(root==NULL)
	{
		printf("Enter the root of the tree: ");
		scanf("%d",&item); 
		if(item==-1)
			return NULL;
		root=init(root,item);
	}
	printf("Enter the left child of the root (-1 for break): ");
	root->lchild = createTree(root->lchild);
	printf("Enter the right child of the root (-1 for break): ");
	root->rchild = createTree(root->rchild);
}
int countNodes(NODE*root)
{
	if(root==NULL)
	          return 0;
	      count++;
	return (1+countNodes(root->lchild)+countNodes(root->rchild));
	
}
int main()
{
	NODE* root;
	root=NULL;
	root=createTree(root);
	int x;
	x=countNodes(root);
	printf("The total number of nodes is: %d",x);
	printf("\nOpcount: %d",count);
}