#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left, *right;
} NODE;

typedef NODE* NODEPTR;

NODEPTR newNode(int data)
{
    NODEPTR node = (NODEPTR)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int count = 0;

void createBT (NODEPTR *rt, int item)
{
    int ch;
    NODEPTR t = *rt;
    NODEPTR present = NULL;
    NODEPTR newnode;
    if (*rt == NULL)
    {
        *rt = newNode(item);
         return;
    }
    do
    {
        printf("1 to insert to left, 2 to insert to right\n");
        scanf("%d", &ch);
        present = t;
        if (ch == 1)
            t=t->left;
        else
            t=t->right;
        if (t==NULL)
        {
            newnode = newNode(item);
            (ch == 1)?(present->left=newnode):(present->right=newnode);
            return;
        }
    }while(1);
} 

int counter(NODEPTR root)
{
    count = count + 1;
    if (root == NULL)
        return 1;
    int leftCount = counter(root->left);
    int rightCount = counter(root->right);
    return leftCount + rightCount;
}
 
int main()
{
    NODEPTR root;
    int choice=1;
    while(choice)
    {
        printf("Enter node value\n");
        int ele;
        scanf("%d", &ele);
        createBT(&root, ele);
        printf("1 for more, 0 to exit\n");
        scanf("%d", &choice);
    }
    printf("Number of nodes of tree is %d\n", counter(root)-1);
    printf("Count is %d\n", count);
    return 0;
}
