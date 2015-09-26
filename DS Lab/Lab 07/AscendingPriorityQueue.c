//
//  AscendingPriorityQueue.c
//  Ascending Priority Queue
//
//  Created by Avikant Saini on 9/21/15.
//  Copyright © 2015 avikantz. All rights reserved.
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
	queue->capacity = 0;
	queue->front = queue->rear = -1;
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
		queue->rear += 1;
		
		int pos = 0, i;
		
		for (i = queue->front; i < queue->rear; ++i)
			if (*(queue->arr + i) > item)
				break;
		pos = i;
		
		for (i = queue->rear; i > pos; --i)
			*(queue->arr + i) = *(queue->arr + i - 1);
		
		*(queue->arr + pos) = item;
	}
	queue->capacity += 1;
}

int delete (ASC_QUEUE_p_t queue) {
	if (isQueueEmpty(*queue)) {
		printf("\n\tQUEUE EMPTY!\n\n");
		return UNDERFLOW_INT;
	}
	queue->capacity -= 1;
	return *(queue->arr + (queue->front)++);
}

void display (ASC_QUEUE_t queue) {
	int i;
	printf("\n CURRENT QUEUE\n");
	for (i = queue.front; i <= queue.rear; ++i)
		printf("\t%d", *(queue.arr + i));
	printf("\n\n");
}

int main (int argc, const char * argv []) {
	
	ASC_QUEUE_p_t queue = (ASC_QUEUE_p_t)malloc(sizeof(ASC_QUEUE_t));
	initQueue(queue);
	
	insert(queue, 24);
	insert(queue, 36);
	insert(queue, 21);
	insert(queue, 18);
	insert(queue, 7);
	insert(queue, 11);
	insert(queue, 69);
	insert(queue, 42);
	insert(queue, 88);
	insert(queue, 4);
	
	display(*queue);
	
	
	char choice;
	do {
		
	} while (choice == '1' || choice == '2' || choice == '3');
	
	return 0;
}
