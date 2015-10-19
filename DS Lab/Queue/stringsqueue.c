#include <stdio.h>
#include <string.h>

# define MAX 20

typedef struct
{
	char x[MAX][MAX];
	int front;
	int rear;
} Q;

Q q;

void enqueueRight(char []);
void display();
void dequeueLeft();
void enqueueLeft(char []);

int main()
{
	q.front = -1;
	q.rear = -1;
	int ch, flag = 1;
	char x[MAX];
	while (flag)
	{
	       printf("1. Enqueue Left\n2. Enqueue Right\n3. Dequeue\n4. Display\n5. Exit\n");
	       scanf("%d", &ch);
	       switch (ch)
	       {
		        case 1:
					printf("Enter element\n");
					scanf("%s", x);
					enqueueLeft(x);
					break;
	            case 2:
			    	printf("Enter element\n");
			    	scanf("%s", x);
			    	enqueueRight(x);
					break;
		        case 3:
					dequeueLeft();
					break;
				case 4:
					display();
					break;
				default :
					flag = 0;
					break;
			}
	}
	return 0;
}

void enqueueRight(char x[])
{
	if (q.rear == MAX)
		printf("Full from right\n");
	else
	{
	    strcpy(q.x[++q.rear], x);
		if (q.front == -1)
			q.front = 0;
	}
}

void enqueueLeft(char x[])
{
	if (q.rear == -1 && q.front == -1)
		enqueueRight(x);
	else if (q.front == 0)
		printf("Full from left\n");
	else
	    strcpy(q.x[--q.front], x);
}

void dequeueLeft ()
{
	if (q.rear == -1 && q.front == -1)
	{
		printf("Empty dequeue\n");
		return ;
	}
	else if (q.front == q.rear)
	{
	        printf("Deleted element is %s\n", q.x[q.front]);
		    q.front = q.rear = -1;
	}
	else
	        printf("Deleted element is %s\n", q.x[q.front++]);
}

void display()
{
	int i;
	if (q.front == -1 && q.rear == -1)
		printf("Empty dequeue\n");
	else
	{
		printf("Dequeue is\n");
		for (i=q.front; i<=q.rear; i++)
			printf("%s\n", q.x[i]);
	}
}
