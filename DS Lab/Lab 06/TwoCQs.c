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

typedef struct CircularQueue {
	int * arr;
	
	int front1;
	int rear1;
	int cap1;
	
	int front2;
	int rear2;
	int cap2;
} CQUEUE_t;

typedef CQUEUE_t * CQUEUE_p_t;

// Queue methods

BOOL isFullQueue (CQUEUE_t queue) {
	if (queue.cap1 + queue.cap2 == SIZE)
		return YES;
	return NO;
}

BOOL isEmptyQueue (CQUEUE_t queue) {
	if (queue.cap1 + queue.cap2 == 0)
		return YES;
	return NO;
}

void insert (CQUEUE_p_t queue, int item, int qno) {
	if (isFullQueue(*queue)) {
		printf("\n\t\tQUEUE OVERFLOW!\n\n");
		return;
	}
	if (qno == 1) {
		if (isEmptyQueue(*queue))
			queue->front1 = queue->rear1 = 0;
		else if (queue->rear1 == queue->rear2 - 1)
			queue->rear1 = 0;
		else
			queue->rear1 += 1;
		*(queue->arr + queue->rear1) = item;
		queue->cap1++;
	}
	if (qno == 2) {
		if (isEmptyQueue(*queue))
			queue->front2 = queue->rear2 = SIZE - 1;
		else if (queue->rear2 == queue->rear1 + 1)
			queue->rear2 = SIZE - 1;
		else
			queue->rear2 -= 1;
		*(queue->arr + queue->rear2) = item;
		queue->cap2++;
	}
}

int delete (CQUEUE_p_t queue, int qno) {
	if (isEmptyQueue(*queue)) {
		printf("\n\t\tQUEUE UNDERFLOW!\n\n");
		return UNDERFLOW_INT;
	}
	int item = 0;
	if (qno == 1) {
		item = *(queue->arr + queue->front1);
		*(queue->arr + queue->front1) = 0;
		if (queue->front1 == queue->rear1)
			queue->front1 = queue->rear1 = -1;
		else if (queue->front1 == queue->rear2 - 1)
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
		else if (queue->front2 == queue->rear1 + 1)
			queue->front2 = SIZE - 1;
		else
			queue->front2 -= 1;
		queue->cap2--;
	}
	return item;
}

void display (CQUEUE_t queue, int qno) {
	if (isEmptyQueue(queue)) {
		printf("\n\t\tEMPTY QUEUE.\n\n");
		return;
	}
	printf("\n\tQUEUE '%d': ", qno);
	int i;
	for (i = 0; i < SIZE; ++i) {
		printf("\t%d", *(queue.arr + i));
	}
	/*
	 if (qno == 1) {
		for (i = queue.front1; i != queue.rear1; i = (i+1)%SIZE)
	 printf("\t%d", *(queue.arr + i));
		printf("\t%d\n", *(queue.arr + i));
	 }
	 if (qno == 2) {
		for (i = queue.front2; i != queue.rear2; i = (i+1)%SIZE)
	 printf("\t%d", *(queue.arr + i));
		printf("\t%d\n", *(queue.arr + i));
	 }
	 */
}


int main(int argc, const char * argv[]) {
	
	CQUEUE_p_t queue = (CQUEUE_p_t)malloc(sizeof(CQUEUE_t));
	queue->arr = (int *)calloc(SIZE, sizeof(int));
	queue->front1 = queue->rear1 = -1;
	queue->front2 = queue->rear2 = SIZE;
	queue->cap1 = queue->cap2 = 0;
	
	int qno;
	do {
		printf("\n\n\t1. Queue 1.\n\t2. Queue 2.\nAnything else for exit.\n\tEnter choice: ");
		scanf("%d", &qno);
		printf("\n\tYou have choosen Queue '%d'.\n", qno);
		char choice;
		do {
			printf("\n\t1. Insert.\n\t2. Delete.\n\t3. Display.\nAnything else to go back.\n\tEnter choice: ");
			scanf(" %c", &choice);
			if (choice == '1') {
				int item;
				printf("\n\tEnter item to insert: ");
				scanf("%d", &item);
				insert(queue, item, qno);
			}
			else if (choice == '2') {
				int item = delete(queue, qno);
				if (item != UNDERFLOW_INT)
					printf("\n\tDeleted Item = %d.\n", item);
			}
			display(*queue, qno);
		} while (choice == '1' || choice == '2' || choice == '3');
	} while (qno == 1 || qno == 2);
}
