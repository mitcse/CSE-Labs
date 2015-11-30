//
//  DQStrings.c
//  Double Ended Queue of Strings.
//
//  Created by Avikant Saini on 9/22/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25
#define UNDERFLOW_CHAR '\0'

/// Boolean type, just for readability

typedef enum { NO, YES } BOOL;

typedef struct DoubleEndedQueue {
	char ** arr;
	int front;
	int rear;
	int capacity;
} DQUEUE_t, *DQUEUE_p_t;

// Queue methods

void initQueue (DQUEUE_p_t queue) {
	queue->arr = (char **)calloc(SIZE, sizeof(char *));
	queue->front = queue->rear = -1;
	queue->capacity = 0;
}

BOOL isFullQueue (DQUEUE_t queue) {
	if (queue.capacity == SIZE)
		return YES;
	return NO;
}

BOOL isEmptyQueue (DQUEUE_t queue) {
	if (queue.capacity == 0)
		return YES;
	return NO;
}

void insertRight (DQUEUE_p_t queue, char * item) {
	if (queue->rear == SIZE - 1) {
		printf("\n\tQUEUE RIGHT OVERFLOW\n\n");
		return;
	}
	
	if (isEmptyQueue(*queue))
		queue->front = queue->rear = 0;
	else
		queue->rear += 1;
	
	queue->capacity += 1;
	
	*(queue->arr + queue->rear) = item;
}

void insertLeft (DQUEUE_p_t queue, char * item) {
	if (!isEmptyQueue(*queue) && queue->front == 0) {
		printf("\n\tQUEUE LEFT OVERFLOW!\n\n");
		return;
	}
	
	if (isEmptyQueue(*queue))
		queue->front = queue->rear = 0;
	else
		queue->front -= 1;
	
	queue->capacity += 1;
	
	*(queue->arr + queue->front) = item;
}

char * deleteLeft (DQUEUE_p_t queue) {
	if (isEmptyQueue(*queue)) {
		printf("\n\tQUEUE EMPTY!\n\n");
		return UNDERFLOW_CHAR;
	}
	
	char * item = *(queue->arr + queue->front);
	
	queue->front += 1;
	queue->capacity -= 1;
	
	if (isEmptyQueue(*queue))
		queue->front = queue->rear = -1;
	
	return item;
}

char * deleteRight (DQUEUE_p_t queue) {
	if (isEmptyQueue(*queue)) {
		printf("\n\tQUEUE EMPTY!\n\n");
		return UNDERFLOW_CHAR;
	}
	
	char * item = *(queue->arr + queue->front);
	
	queue->rear -= 1;
	queue->capacity -= 1;
	
	if (isEmptyQueue(*queue))
		queue->front = queue->rear = -1;
	
	return item;
}

void display (DQUEUE_t queue) {
	if (!isEmptyQueue(queue)) {
		printf("\n | Current Queue (f = %d, r = %d, c = %d) : \n", queue.front, queue.rear, queue.capacity);
		int i;
		for (i = queue.front; i <= queue.rear; ++i)
			printf("\t\t%d | %s", i,  *(queue.arr + i));
		printf("\n\n");
	}
}


int main(int argc, const char * argv[]) {
	
	DQUEUE_p_t queue = (DQUEUE_p_t)calloc(SIZE, sizeof(DQUEUE_t));
	initQueue (queue);
	
	char choice;
	
	do {
		printf("\n------------------------------------------------------------\n | 1. Insert Left\n | 2. Insert Right\n | 3. Delete Left\n | 4. Delete Right\n | 5. Display Queue.\n | Q. Quit\n | Enter choice : ");
		choice = getchar();
		getchar();
		
		char * item = (char *)malloc(SIZE * sizeof(char));
		
		if (choice == '1') {
			printf("\n | Enter item to be inserted: ");
			fgets(item, SIZE, stdin);
			insertLeft(queue, item);
		}
		else if (choice == '2') {
			printf("\n | Enter item to be inserted: ");
			fgets(item, SIZE, stdin);
			insertRight(queue, item);
		}
		else if (choice == '3') {
			item = deleteLeft(queue);
			if (item != UNDERFLOW_CHAR)
				printf("\n | Deleted item: %s\n", item);
		}
		else if (choice == '4') {
			item = deleteRight(queue);
			if (item != UNDERFLOW_CHAR)
				printf("\n | Deleted item: %s\n", item);
		}
		
		display(*queue);
		
	} while (choice >= '1' && choice <= '5');
	
	return 0;
}
