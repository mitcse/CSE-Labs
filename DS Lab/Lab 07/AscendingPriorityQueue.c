//
// AscQueue.c
// Ascending priority queue
//
// Created by Avikant Saini on 9/22/15
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW_INT -32767

typedef enum { NO, YES } BOOL;

typedef struct AscQueue {
	int *arr;
	int front, rear;
	int capacity;
} ASC_QUEUE_t;

typedef ASC_QUEUE_t * ASC_QUEUE_p_t;

void initQueue (ASC_QUEUE_p_t queue) {
	queue->arr = (int *)calloc(SIZE, sizeof(int));
	queue->front = queue->rear = -1;
	queue->capacity = 0;
}

BOOL isQueueFull (ASC_QUEUE_t queue) {
	if (queue.capacity == SIZE)
		return YES;
	return NO;
}

BOOL isQueueEmpty (ASC_QUEUE_t queue) {
	if (queue.capacity == 0)
		return YES;
	return NO;
}

void insert (ASC_QUEUE_p_t queue, int item) {
	if (isQueueFull(*queue)) {
		printf("\n\tQUEUE FULL!\n\n");
		return;
	}
	if (isQueueEmpty(*queue)) {
		queue->front = 0;
		queue->rear = 0;
		*(queue->arr) = item;
	}
	else {
		int i, pos = 0;
		for (i = queue->front; i <= queue->rear; ++i)
			if (*(queue->arr + i) > item)
				break;
		pos = i;
		
		queue->rear += 1;
		
		for (i = queue->rear; i > pos; --i)
			*(queue->arr + i) = *(queue->arr + i - 1);
		
		*(queue->arr + pos) = item;
	}
	queue->capacity += 1;
}

int delete (ASC_QUEUE_p_t queue) {
	if (isQueueEmpty(*queue)) {
		printf("\n\tQUEUE EMPTY!");
		return UNDERFLOW_INT;
	}
	queue->capacity -= 1;
	return *(queue->arr + (queue->front)++);
}

void display (ASC_QUEUE_t queue) {
	int i;
	printf("\n\tCURRENT QUEUE:\n");
	for (i = queue.front; i <= queue.rear; ++i)
		printf("\t%d", *(queue.arr + i));
	printf("\n\n");
}

int main (int argc, const char * argv []) {
	ASC_QUEUE_p_t queue = (ASC_QUEUE_p_t)malloc(sizeof(ASC_QUEUE_t));
	initQueue(queue);
	
	char choice;
	
	do {
		printf("\n------------------------------------------------------------\n | 1. Insert\n | 2. Delete\n | 3. Display Queue.\n | Q. Quit\n | Enter choice : ");
		scanf(" %c", &choice);
		
		int item;
		
		if (choice == '1') {
			printf("\n | Enter item to be inserted: ");
			scanf("%d", &item);
			insert(queue, item);
		}
		else if (choice == '2') {
			item = delete(queue);
			if (item != UNDERFLOW_INT)
				printf("\n | Deleted item: '%d'.\n", item);
		}
		
		display(*queue);
		
	} while (choice == '1' || choice == '2' || choice == '3');
	
	return 0;
	
}


