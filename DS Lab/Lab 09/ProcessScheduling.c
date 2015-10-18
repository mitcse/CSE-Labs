//
//  ProcessScheduling.c
//  Implementing multilevel scheduling of processes with multiple queues using linked list.
//
//  Created by Avikant Saini on 10/18/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int MAX = 50;

typedef enum { NO, YES } BOOL;

typedef struct MQueue {
	int process_id;
	int priority;
	int execution_time;
	struct MQueue *link;
} MQUEUE_t;

typedef MQUEUE_t * MQUEUE_p_t;

MQUEUE_p_t createProcess (int pid, int priority, int exec_time) {
	MQUEUE_p_t process = (MQUEUE_p_t)malloc(sizeof(MQUEUE_t));
	process->process_id = pid;
	process->priority = priority;
	process->execution_time = exec_time;
	process->link = NULL;
	return process;
}

void initQueue (MQUEUE_p_t front[MAX], MQUEUE_p_t rear[MAX]) {
	int i;
	for (i = 0; i < MAX; ++i) {
		*(front + i) = createProcess(0, 0, 0);
		*(rear + i) = createProcess(0, 0, 0);
	}
}

void inputProcess (MQUEUE_p_t front[MAX], MQUEUE_p_t rear[MAX], int pid, int priority, int exec_time) {
	
	if (priority > MAX) {
		int i = MAX;
		MAX *= 2;
		front = (MQUEUE_p_t *)realloc(front, MAX * sizeof(MQUEUE_p_t));
		rear = (MQUEUE_p_t *)realloc(front, MAX * sizeof(MQUEUE_p_t));
		for (; i < MAX; ++i) {
			*(front + i) = createProcess(0, 0, 0);
			*(rear + i) = createProcess(0, 0, 0);
		}
	}
	
	MQUEUE_p_t f = *(front + priority - 1);
	MQUEUE_p_t r = *(rear + priority - 1);
	
	MQUEUE_p_t process = createProcess(pid, priority, exec_time);
	process->link = NULL;
	
	if (f->link == NULL) {
		f->link = process;
		r->link = process;
	}
	
	else {
		MQUEUE_p_t temp = f;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = process;
		r = process;
	}
	return;
}

void scheduleProcess (MQUEUE_p_t front[MAX]) {
	int i;
	int timeStamp = 0;
	for (i = 0; i < MAX; ++i) {
		MQUEUE_p_t f = *(front + i);
		MQUEUE_p_t temp = f->link;
		while (temp != NULL) {
			timeStamp += temp->execution_time;
			printf("Executed pid%d, ending time = %d\n", temp->process_id, timeStamp);
			temp = temp->link;
			f = f->link;
		}
	}
}

int main (int argc, const char * argv []) {
	
	MQUEUE_p_t *front = (MQUEUE_p_t *)malloc(MAX * sizeof(MQUEUE_p_t));
	MQUEUE_p_t *rear = (MQUEUE_p_t *)malloc(MAX * sizeof(MQUEUE_p_t));
	
	initQueue(front, rear);
	
	inputProcess(front, rear, 11, 1, 10);
	inputProcess(front, rear, 12, 1, 10);
	inputProcess(front, rear, 13, 1, 10);
	
	inputProcess(front, rear, 21, 2, 20);
	inputProcess(front, rear, 22, 2, 20);
	inputProcess(front, rear, 23, 2, 20);
	inputProcess(front, rear, 24, 2, 20);
	inputProcess(front, rear, 25, 2, 20);
	
	inputProcess(front, rear, 31, 3, 30);
	inputProcess(front, rear, 32, 3, 30);
	
	scheduleProcess(front);
	
}
