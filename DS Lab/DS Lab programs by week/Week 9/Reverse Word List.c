#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100

typedef struct Node
{
	char *data;
	struct Node * next;
	struct Node * prev;
} NODE;

NODE *createNode ()
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->data = (char *)malloc(SIZE * sizeof(char));
	temp->prev = temp;
	temp->next = temp;
	return temp;
}

void insert (NODE *list, char *val)
{
	NODE *temp = createNode();
	NODE *p;	
	temp->data = val;
	temp->next = list;	
	list->prev = temp;	
	if (list->next == list)
	{
		temp->prev = list;
		list->next = temp;
	}	
	else
	{
		p = list->next;
		
		while (p->next != list)
			p = p->next;	
		temp->prev = p;
		p->next = temp;
	}
}

void inputList (NODE *list)
{
	int i, n;	
	printf("Enter number of terms in the list\n");
	scanf("%d", &n);	
	printf("Enter the list\n");
	for (i = 0; i < n; ++i)
	{
		char *item = (char *)malloc(SIZE * sizeof(char));
		scanf(" %s", item);
		insert(list, item);
	}
}

NODE* createAndInputList ()
{
	NODE *li = createNode();
	inputList(li);
	return li;
}

void reverseList (NODE *list)
{
	NODE *slow = list->next;
	NODE *fast = list->next;	
	while (fast != list)
	{
		fast = fast->next;
		if (fast != list)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}	
	NODE *temp1 = list->next;
	NODE *temp2 = list->prev;	
	while (temp1 != slow)
	{		
		char *swap = temp1->data;
		temp1->data = temp2->data;
		temp2->data = swap;		
		temp1 = temp1->next;
		temp2 = temp2->prev;
	}	
}

void displayList (NODE *list)
{
	NODE *temp = list->next;
	while (temp->next != list)
	{
		printf("%s\n", temp->data);
		temp = temp->next;
	}
	printf("%s\n", temp->data);
}

int main ()
{	
	NODE *list = createAndInputList();	
	printf("Original list is\n");
	displayList(list);
	reverseList(list);
	printf("Reversed list is\n");
	displayList(list);
	return 0;
}

