//
//	MultipleQs.c
//	Implementing Multiple Queues of Strings
//
//  Created by Avikant Saini on 8/30/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define UNDERFLOW_CHAR '\0'

typedef enum { NO, YES } BOOL;

typedef struct Queue {
	char ** arr;
	int front;
	int rear;
	int capacity;
} QUEUE_t;

typedef QUEUE_t * QUEUE_p_t;

#pragma mark - Queue Methods

void initQueue (QUEUE_p_t queue) {
	queue->arr = (char **)calloc(SIZE, sizeof(char *));
	queue->front = -1;
	queue->rear = -1;
	queue->capacity = 0;
}

BOOL isQueueFull (QUEUE_t queue) {
	if (queue.capacity == SIZE)
		return YES;
	return NO;
}

BOOL isQueueEmpty (QUEUE_t queue) {
	if (queue.capacity == 0)
		return YES;
	return NO;
}

void insert (QUEUE_p_t queue, char * item) {
	if (isQueueFull(*queue)) {
		printf("\n\tQUEUE FULL!\n\n");
		return;
	}
	
	if (isQueueEmpty(*queue))
		queue->front = queue->rear = 0;
	else
		queue->rear = (queue->rear + 1)%SIZE;
	
	queue->capacity ++;
	
	*(queue->arr + queue->rear) = item;
}

char * delete (QUEUE_p_t queue) {
	if (isQueueEmpty(*queue)) {
		printf("\n\tQUEUE EMPTY\n\n");
		return UNDERFLOW_CHAR;
	}
	
	char * item = *(queue->arr + queue->front);
	
	if (queue->capacity == 1)
		queue->front = queue->rear = -1;
	else
		queue->front = (queue->front + 1)%SIZE;
	
	queue->capacity --;
	
	return item;
}

void display (QUEUE_t queue) {
	int i;
	for (i = queue.front; i != queue.rear; i = (i + 1)%SIZE)
		printf("\t\t%s\n", *(queue.arr + i));
	printf("\t\t%s\n\n", *(queue.arr + i));
}



int main(int argc, const char * argv[]) {
	
	int n, i;
	
	printf("\n\nThis program will implement multiple queues in a single array.\n\tEnter the number of queues you want: ");
	scanf("%d", &n);
	
	QUEUE_p_t * queues = (QUEUE_p_t *)calloc(n, sizeof(QUEUE_p_t));
	
	for (i = 0; i < n; ++i) {
		*(queues + i) = (QUEUE_p_t)malloc(sizeof(QUEUE_t));
		initQueue(*(queues + i));
	}
	
	printf("\n\t%d Queues have been created each of maximum capacity %d.\n", n, SIZE);
	
	int qno;
	do {
		printf("\n\tEnter the queue number you want to perform operations on (1 - %d), 0 to exit.\n\tEnter choice: ", n);
		scanf(" %d", &qno);
		
		if (qno == 0) {
			printf("\n\n");
			exit(8);
		}
		
		if (qno < 1 || qno > n) {
			printf("\n\tInvalid size enetred. Try again.");
			continue;
		}
		
		printf("\n\tYou have selected Queue %d.\n\n", qno);
		
		char choice;
		do {
			printf("\n\tQueue %d\n\t\t1. Insert.\n\t\t2. Delete.\n\t\t3. Display\n\tAnything else to go back.\n\tEnter choice: ", qno);
			scanf(" %c", &choice);
			
			if (choice == '1') {
				char *item = (char *)malloc(SIZE * sizeof(char));
				printf("\n\tEnter item to be inserted in Queue %d: ", qno);
				scanf("%s", item);
				insert(*(queues + qno - 1), item);
			}
			
			if (choice == '2') {
				char *item = delete(*(queues + qno - 1));
				if (item != UNDERFLOW_CHAR)
					printf("\n\tDeleted item from Queue %d: %s.\n\n", qno, item);
			}
			
			printf("\n\tQueue %d: \n", qno);
			display(**(queues + qno - 1));
			
		} while (choice == '1' || choice == '2' || choice == '3');
	} while (qno != 0);
	
	return 0;
}