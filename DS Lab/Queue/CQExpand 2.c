//
//  CircularQueue.c
//  Circular Queue with size expanding option. (Version 2)
//
//  Created by Avikant Saini on 9/08/15.
//  Copyright © 2015 avikantz. All rights reserved.
//
//	Note. While the older version works fine for small values, this one is more efficient and short.
//

#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW_INT -32767

/// Boolean type, just for readability

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

typedef struct CircularQueue {
	int * arr;
	int front, rear, capacity, maxSize;
} CQUEUE_t;

/// CQUEUE_t pointer type @line You might as well use CQUEUE_t *

typedef CQUEUE_t * CQUEUE_p_t;

// Queue methods

void createQueue (CQUEUE_p_t queue) {
	printf("\n\tEnter size of the circular queue: ");
	scanf("%d", &queue->maxSize);
	queue->arr = (int *)calloc(queue->maxSize, sizeof(int));
	queue->capacity = 0;
	queue->rear = queue->front = -1;
}

/**
 *	Check for overflow, if full, prepare to increase the size of the queue.
 *
 *	Increase the size of the queue using realloc.
 *
 *	We need to reset the queue only if the queue is full and front is greater than rear (i.e. the queue is circularly arranged)
 *
 *	Get the current queue elements and put them in 'currentElements' array.
 *
 *	Set front to 0 and rear to capacity - 1
 *
 *	Put elements back in the queue, and increase the max size.
 *
 *	Correction: realloc() is frakking inefficient. Use free() and calloc() instead.
 */

BOOL isFullQueue (CQUEUE_p_t queue) {
	// Check for overflow
	
	if ((queue->front == queue->rear + 1) || (queue->front == 0 && queue->rear == queue->maxSize - 1)) {
		
		// Get all the elements in a temp array/
		
		int i, k;
		int currentElements[queue->capacity + 1];
		
		for (i = queue->front, k = 0; i < queue->capacity; ++i)
			currentElements[k++] = queue->arr[i];
		for (i = 0; i <= queue->rear; ++i)
			currentElements[k++] = queue->arr[i];
			
		// Set front to 0 and rear to capactiy - 1	
			
		queue->front = 0;
		queue->rear = queue->capacity - 1;
		
		// Free the memory of queue->arr, increase the maxSize, use calloc() to increase the size
		
		free(queue->arr);
		queue->maxSize *= 2;
		queue->arr = (int *)calloc(queue->maxSize, sizeof(int));
		
		// Put the elements back into the queue->arr.
		
		for (i = queue->rear; i >= 0; --i)
			queue->arr[i] = currentElements[--k];
		
		return YES;
	}
	return NO;
}

BOOL isEmptyQueue (CQUEUE_t queue) {
	if (queue.front == -1)
		return YES;
	return NO;
}

/**
 *	Insertions are done from the rear end.
 *
 *	If the queue is full, increase size and proceed.
 *
 *	If the queue is empty, set front and rear to 0 and insert at index 0.
 *
 *	If the rear end is at the end of the array, set rear to 0 (circulate) and insert at index 0
 *
 *	Else increment rear end and insert at the position.
 *
 *	Increment the capacity.
 */

void insert (CQUEUE_p_t queue, int item) {
	if (isFullQueue(queue))
		printf("\nQueue overflow... expanding size...");
		
	if (isEmptyQueue(*queue))
		queue->front = queue->rear = 0;
	else
		queue->rear = (queue->rear + 1)%(queue->maxSize);
	
	*(queue->arr + queue->rear) = item;
	
	queue->capacity += 1;
}

/**
 *	Deletions are done from the front end.
 *
 *	Check for underflow, return underflow value if true.
 *
 *	Get the item at the front end.
 *
 *	If front == rear, i.e. there's only one element, set both to -1.
 *
 *	If front is at the end of the array, set front to 0.
 *
 *	Else increment front end.
 *
 *	Decrement the capacity.
 */

int delete (CQUEUE_p_t queue) {
	if (isEmptyQueue(*queue)) {
		printf("\nQueue Underflow!\n\n");
		return UNDERFLOW_INT;
	}
	
	int item = *(queue->arr + queue->front);
	
	if (queue->front == queue->rear)
		queue->front = queue->rear = -1;
	else
		queue->front = (queue->front + 1)%(queue->maxSize);
	
	queue->capacity -= 1;
	
	return item;
}

/**
 *	If the queue is empty, display appropiate message.
 *
 *	If rear end is greater the front end, print from the front end to the rear end.
 *
 *	Else print from front to the end of the queue, then from starting of the queue to the rear end.
 */

void display (CQUEUE_t queue) {
	if (isEmptyQueue(queue))
		printf("\nEmpty Queue.\n");
	else {
		printf("\nCurrent Queue [%d]: ", queue.capacity);
		int i;
		
		for (i = queue.front; i != queue.rear; i = (i+1)%(queue.maxSize))
			printf("\t%d", *(queue.arr + i));
		printf("\t%d\n", *(queue.arr + i));

		printf("\n");
	}
}


int main(int argc, const char * argv[]) {
	
	CQUEUE_t queue;
	
	createQueue(&queue);
	
	char choice;
	int item;
	
	do {
		printf("\n\t1. Insert\n\t2. Delete\n\t3. Display Queue.\n\tQ. Quit\nEnter Choice : ");
		scanf(" %c", &choice);
		
		if (choice == '1') {
			printf("\tEnter item to be inserted: ");
			scanf("%d", &item);
			insert(&queue, item);
		}
		if (choice == '2') {
			item = delete(&queue);
			if (item != UNDERFLOW_INT)
				printf("\tDeleted item: %d\n", item);
		}
		display(queue);
		
	} while (choice == '1' || choice == '2' || choice == '3');
	
	return 0;
}
