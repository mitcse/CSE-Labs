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

void Insert(int ele, NODE *h)
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

NODE Delete(NODE *h)
{
    NODE *temp = h->next;
    h->next = temp->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
    return *h;
}

void Display(NODE h)
{
    if(h.next == NULL)
    {
        printf("Empty List!\n");
        return;
    }
    NODE *p = h.next;
    while(p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    int ele;
    NODE head;
    head.data = 0;
    head.next = NULL;
    int ch;
    do
    {
        printf("1 to insert, 2 to delete, 3 to display, 4 to exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter element to insert\n");
            	    scanf("%d", &ele);
                    Insert(ele, &head);
                    break;
            case 2: head = Delete(&head);
                    break;
            case 3: Display(head);
                    break;
        }
    }    while(ch!=4);
	return 0;
}
