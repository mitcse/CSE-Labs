#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define UNDER -32767

typedef struct
{
	int *arr;
	int front1, rear1, cap1;
	int front2, rear2, cap2;
} CQ;

typedef CQ  *CQ1;

int isFullQueue (CQ q, int qno)
{
	if (qno == 1 && q.cap1 == SIZE/2)
		return 1;
	else if (qno == 2 && q.cap2 == SIZE/2)
		return 1;
	return 0;
}

int isEmptyQueue (CQ q, int qno)
{
	if (qno == 1 && q.cap1 == 0)
		return 1;
	else if (qno == 2 && q.cap2 == 0)
		return 1;
	return 0;
}

void insert (CQ1 q, int ele, int qno)
{
	if (isFullQueue(*q, qno))
    {
		printf("%d OVERFLOW\n", qno);
		return;
	}
	
	if (qno == 1)
    {
	
		if (isEmptyQueue(*q, qno))
			q->front1 = q->rear1 = 0;
			
		else if (q->rear1 == SIZE/2 - 1)
			q->rear1 = 0;
			
		else
			q->rear1 += 1;
			
		*(q->arr + q->rear1) = ele;
		q->cap1++;
	}
	
	if (qno == 2)
    {
	
		if (isEmptyQueue(*q, qno))
			q->front2 = q->rear2 = SIZE - 1;
			
		else if (q->rear2 == SIZE/2)
			q->rear2 = SIZE - 1;
			
		else
			q->rear2 -= 1;
			
		*(q->arr + q->rear2) = ele;
		q->cap2++;
	}
}

int delete (CQ1 q, int qno)
{
	if (isEmptyQueue(*q, qno))
    {
		printf("%d UNDERFLOW\n", qno);
		return UNDER;
	}
	
	int ele = 0;
	if (qno == 1)
    {
	
		ele = *(q->arr + q->front1);
		*(q->arr + q->front1) = 0;
		
		if (q->front1 == q->rear1)
			q->front1 = q->rear1 = -1;
			
		else if (q->front1 == SIZE/2 - 1)
			q->front1 = 0;
			
		else
			q->front1 += 1;
			
		q->cap1--;
	}
	
	if (qno == 2)
    {
	
		ele = *(q->arr + q->front2);
		*(q->arr + q->front2) = 0;
		
		if (q->front2 == q->rear2)
			q->front2 = q->rear2 = SIZE - 1;
			
		else if (q->front2 == SIZE/2)
			q->front2 = SIZE - 1;
			
		else
			q->front2 -= 1;
			
		q->cap2--;
	}
	return ele;
}

void display (CQ q, int qno)
{
	if (isEmptyQueue(q, qno))
    {
		printf("EMPTY QUEUE %d\n", qno);
		return;
	}

	int i;
	
	if (qno == 1)
    {
	    printf("Queue 1 is\n");
		if (q.rear1 >= q.front1)
			for (i = q.front1; i <= q.rear1; ++i)
				printf("%d\n", *(q.arr + i));
				
		else
        {
			for (i = q.front1; i < SIZE/2; ++i)
				printf("%d\n", *(q.arr + i));
			for (i = 0; i <= q.rear1; ++i)
				printf("%d\n", *(q.arr + i));
		}		
	}
	
	else if (qno == 2)
    {
	    	printf("Queue 2 is\n");
		if (q.rear2 <= q.front2)
			for (i = q.front2; i >= q.rear2; --i)
				printf("%d\n", *(q.arr + i));
				
		else
        {
			for (i = q.front2; i >= SIZE/2; --i)
				printf("%d\n", *(q.arr + i));
			for (i = SIZE - 1; i >= q.rear2; --i)
				printf("%d\n", *(q.arr + i));
		}
	}
}


int main()
{
	
	CQ1 queue = (CQ1)malloc(sizeof(CQ));
	queue->arr = (int *)calloc(SIZE, sizeof(int));
	queue->front1 = queue->rear1 = -1;
	queue->front2 = queue->rear2 = SIZE;
	queue->cap1 = queue->cap2 = 0;
	
	int qno;
	do
    {
		printf("1 for queue 1, 2 for queue 2, 3 to display both\n");
		scanf("%d", &qno);
		
		if (qno == 3)
        {
			display(*queue, 1);
			display(*queue, 2);
			continue;
		}
		else if (!(qno == 1 || qno == 2))
			exit(6);
			
		int choice;
		
		do
        {
			printf("1 to insert, 2 to delete, 3 to display\n");
			scanf(" %d", &choice);
			
			if (choice == 1)
            {
				int item;
				printf("Enter element\n");
				scanf("%d", &item);
				insert(queue, item, qno);
			}
			
			else if (choice == '2')
            {
				int item = delete(queue, qno);
				if (item != UNDER)
					printf("Deleted item = %d\n", item);
			}
			else if (choice == 3)
			
				display(*queue, qno);
			else
				break;
		
		} while (choice == 1 || choice == 2 || choice == 3);
	
	} while (qno == 1 || qno == 2 || qno == 3);
	
}
