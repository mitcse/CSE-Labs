//
//  TwoCQs.c
//  Two Circular Queues in a single Array.
//
//  Created by Avikant Saini on 9/07/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define UNDERFLOW_INT -32767

/// Boolean type, just for readability

typedef enum {
	NO = 0,
	YES = 1,
} BOOL;

/**
*	Divide the queue into two parts.
*	
*	Set front and rear of queue 1 to -1. Insert in ascending order.
*
*	Set front and reat of queue 2 to SIZE. Insert in descending order.
*
*	Capacity gives the current size of queue. Overflow for a queue if it's capacity == SIZE/2.
*/

typedef struct CircularQueue {
	int * arr;
	int front1, rear1, cap1;
	int front2, rear2, cap2;
} CQUEUE_t;

typedef CQUEUE_t * CQUEUE_p_t;

// Queue methods

BOOL isFullQueue (CQUEUE_t queue, int qno) {
	if (qno == 1 && queue.cap1 == SIZE/2)
		return YES;
	else if (qno == 2 && queue.cap2 == SIZE/2)
		return YES;
	return NO;
}

BOOL isEmptyQueue (CQUEUE_t queue, int qno) {
	if (qno == 1 && queue.cap1 == 0)
		return YES;
	else if (qno == 2 && queue.cap2 == 0)
		return YES;
	return NO;
}

void insert (CQUEUE_p_t queue, int item, int qno) {
	if (isFullQueue(*queue, qno)) {
		printf("\n\t\tQUEUE '%d' OVERFLOW!\n\n", qno);
		return;
	}
	
	if (qno == 1) {
	
		if (isEmptyQueue(*queue, qno))
			queue->front1 = queue->rear1 = 0;
			
		else if (queue->rear1 == SIZE/2 - 1)
			queue->rear1 = 0;
			
		else
			queue->rear1 += 1;
			
		*(queue->arr + queue->rear1) = item;
		queue->cap1++;
	}
	
	if (qno == 2) {
	
		if (isEmptyQueue(*queue, qno))
			queue->front2 = queue->rear2 = SIZE - 1;
			
		else if (queue->rear2 == SIZE/2)
			queue->rear2 = SIZE - 1;
			
		else
			queue->rear2 -= 1;
			
		*(queue->arr + queue->rear2) = item;
		queue->cap2++;
	}
}

int delete (CQUEUE_p_t queue, int qno) {
	if (isEmptyQueue(*queue, qno)) {
		printf("\n\t\tQUEUE '%d' UNDERFLOW!\n\n", qno);
		return UNDERFLOW_INT;
	}
	
	int item = 0;
	if (qno == 1) {
	
		item = *(queue->arr + queue->front1);
		*(queue->arr + queue->front1) = 0;
		
		if (queue->front1 == queue->rear1)
			queue->front1 = queue->rear1 = -1;
			
		else if (queue->front1 == SIZE/2 - 1)
			queue->front1 = 0;
			
		else
			queue->front1 += 1;
			
		queue->cap1--;
	}
	
	if (qno == 2) {
	
		item = *(queue->arr + queue->front2);
		*(queue->arr + queue->front2) = 0;
		
		if (queue->front2 == queue->rear2)
			queue->front2 = queue->rear2 = SIZE - 1;
			
		else if (queue->front2 == SIZE/2)
			queue->front2 = SIZE - 1;
			
		else
			queue->front2 -= 1;
			
		queue->cap2--;
	}
	return item;
}

void display (CQUEUE_t queue, int qno) {
	if (isEmptyQueue(queue, qno)) {
		printf("\n\t\tEMPTY QUEUE %d.\n\n", qno);
		return;
	}
	
	printf("\n\tQUEUE '%d': ", qno);
	int i;
	
	if (qno == 1) {
		if (queue.rear1 >= queue.front1)
			for (i = queue.front1; i <= queue.rear1; ++i)
				printf("\t%d", *(queue.arr + i));
				
		else {
			for (i = queue.front1; i < SIZE/2; ++i)
				printf("\t%d", *(queue.arr + i));
			for (i = 0; i <= queue.rear1; ++i)
				printf("\t%d", *(queue.arr + i));
		}		
	}
	
	else if (qno == 2) {
		if (queue.rear2 <= queue.front2)
			for (i = queue.front2; i >= queue.rear2; --i)
				printf("\t%d", *(queue.arr + i));
				
		else {
			for (i = queue.front2; i >= SIZE/2; --i)
				printf("\t%d", *(queue.arr + i));
			for (i = SIZE - 1; i >= queue.rear2; --i)
				printf("\t%d", *(queue.arr + i));
		}
	}
	
	printf ("\n\n");
}


int main(int argc, const char * argv[]) {
	
	printf("\n\n  This program implements two circular queues in a single array.\n  The initial SIZE is set to 10, and is equally distributed among the queues.\n  Initially, for queue 1, front and rear are set to -1, and for queue 2 to SIZE.\n\n");
	
	CQUEUE_p_t queue = (CQUEUE_p_t)malloc(sizeof(CQUEUE_t));
	queue->arr = (int *)calloc(SIZE, sizeof(int));
	queue->front1 = queue->rear1 = -1;
	queue->front2 = queue->rear2 = SIZE;
	queue->cap1 = queue->cap2 = 0;
	
	int qno;
	do {
		printf("\n\n----------------------MAIN MENU----------------------\n  1. Queue 1.\n  2. Queue 2.\n  3. Display Both.\n  Anything else for exit.\n\n  Enter choice: ");
		scanf("%d", &qno);
		
		if (qno == 3) {
			display(*queue, 1);
			display(*queue, 2);
			continue;
		}
		else if (!(qno == 1 || qno == 2))
			exit(6);
			
		printf("\n\t| You have choosen Queue '%d'.\n", qno);
		char choice;
		
		do {
			printf("\n\t| 1. Insert.\n\t| 2. Delete.\n\t| 3. Display.\n\t| Anything else to go back.\n\t| Enter choice: ");
			scanf(" %c", &choice);
			
			if (choice == '1') {
				int item;
				printf("\n\t| Enter item to insert: ");
				scanf("%d", &item);
				insert(queue, item, qno);
			}
			
			else if (choice == '2') {
				int item = delete(queue, qno);
				if (item != UNDERFLOW_INT)
					printf("\n\t| Deleted Item = %d.\n", item);
			}
			
			display(*queue, qno);
		
		} while (choice == '1' || choice == '2' || choice == '3');
	
	} while (qno == 1 || qno == 2 || qno == 3);
	
}
