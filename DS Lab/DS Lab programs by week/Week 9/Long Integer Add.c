#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 500

typedef struct Node
{
	int value;
	struct Node * next;
	struct Node * prev;
} NODE;

NODE* createNode ()
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->value = 0;
	temp->prev = temp;
	temp->next = temp;
	return temp;
}

void insert (NODE *list, int val)
{
	NODE *temp = createNode();
	NODE *p;	
	temp->value = val;
	temp->prev = list;	
	list->next = temp;	
	if (list->prev == list)
	{
		temp->next = list;
		list->prev = temp;
	}	
	else
	{
		p = list->prev;		
		while (p->prev != list)
			p = p->prev;		
		temp->next = p;
		p->prev = temp;
	}
	(list->value)++;
}

void input (NODE *li)
{	
	int i;
	char *lint = (char *)malloc(SIZE * sizeof(char));
	scanf(" %s", lint);	
	for (i = 0; i < strlen(lint)/2; i++)
	{
		char temp = *(lint + i);
		*(lint + i) = *(lint + strlen(lint) - 1 - i);
		*(lint + strlen(lint) - 1 - i) = temp;
	}	
	for (i = 0; i < strlen(lint); i++)
		insert(li, *(lint + i) - '0');	
}

NODE* create ()
{
	NODE *li = createNode();
	input(li);
	return li;
}

NODE* add (NODE *liA, NODE *liB)
{
	NODE *liC = createNode();	
	int carry = 0, sum = 0;
	NODE *tempA = liA->prev;
	NODE *tempB = liB->prev;	
	while (tempA != liA && tempB != liB)
	{
		sum = tempA->value + tempB->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(liC, sum);
		tempA = tempA->prev;
		tempB = tempB->prev;
	}
	while (tempA != liA)
	{
		sum = tempA->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(liC, sum);
		tempA = tempA->prev;
	}
	while (tempB != liB)
	{
		sum = tempB->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(liC, sum);
		tempB = tempB->prev;
	}
	if (carry != 0)
		insert(liC, carry);	
	return liC;
}

void display (NODE *longInt)
{
	NODE *temp = longInt->next;
	while (temp != longInt)
	{
		printf("%d", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int main ()
{	
	printf("Enter A\n");
	NODE *lia = create();
	printf("Enter B\n");
	NODE *lib = create();
     	NODE *lic = add(lia, lib);	
	printf("A = ");
	display(lia);
	printf("B = ");
	display(lib);	
	printf("A + B = ");
	display(lic);	return 0;
}

