//
//  ParkingProblem.c
//  Parking problem using circular linked lists queue
//
//  Created by Avikant Saini on 9/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

/*
 Problem goes as follows:
 The k contains a single lane that holds up to 10 cars. Cars arrive at the south end of the garage and leave from the north end. If a customer arrives to pick up a car(X) that is not the northernmost, all cars to the north of X’s car are moved out, X’s car is driven out, and the other cars are restored in the same order that they were in originally. Whenever a car leaves, all cars to the south are moved forward so that at all times all the empty spaces are in the south part of the garage.
                                                  
 Write a program using signally linked list that reads a group of input lines. Each line contains an ‘A’ for arrival and ‘D’ for departure and a license plate number (example: 979WJC). Cars are assumed to arrive and depart in the order specified by the input. The program should print a message each time that a car arrives or departs. When car arrives, the message should specify whether or not there is room in the garage for the car. If there is no room for a car, the car then proceeds to the Knockemdead garage which is similar to the Scratchemup. There is room for 8 cars at the Knockemdead garage. If both garages are full, cars wait in the street near the Scratchemup garage for a space...and of course they are queued up in the street. The size of the street queue is also 8.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int data;
	char * lpNo;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->lpNo = (char *)calloc(SIZE, sizeof(char));
	temp->next = temp;
	temp->data = 0;
	return temp;
}

void addCar (NODE_p_t garage, char * lpNo) {
	NODE_p_t temp = createNode();
	strcpy(temp->lpNo, lpNo);
	
	NODE_p_t p = garage->next;
	
	while (p->next != garage)
		p = p->next;
	
	p->next = temp;
	temp->next = garage;
	
	(garage->data)++;
}

BOOL removeCar (NODE_p_t garage, char * lpNo) {
	NODE_p_t p = garage;
	
	while (p->next != garage) {
		
		NODE_p_t temp = p->next;
		if (strcmp(temp->lpNo, lpNo) == 0) {
			
			p->next = temp->next;
			
			(garage->data)--;
			return YES;
		}
		p = p->next;
	}
	return NO;
}

void display (NODE_p_t queue) {
	NODE_p_t temp = queue->next;
	
	if (temp != queue)  {
		while (temp->next != queue) {
			printf(" %s ->", temp->lpNo);
			temp = temp->next;
		}
		printf(" %s", temp->lpNo);
		temp = temp->next;
	}
	
	printf("\n-------------------------------------------------------------------------\n");
}


int main (int argc, const char * argv []) {
	
	NODE_p_t scratchEmUp = createNode();
	NODE_p_t knockEmDown = createNode();
	NODE_p_t streetThugs = createNode();
	
	char arrDep;
	char *lpNo = (char *)malloc(SIZE * sizeof(char));
	
	do {
		printf("\n\tGIVE INPUT: ");
		scanf(" %c", &arrDep);
		scanf(" %s", lpNo);
		
		if (arrDep == 'A') {
			
			if (scratchEmUp->data < 3) {
				printf("\n\tAdding car '%s' to ScratchEmUp garage.\n", lpNo);
				addCar(scratchEmUp, lpNo);
			}
			
			else if (knockEmDown->data < 2) {
				printf("\n\tAdding car '%s' to KnockEmDown garage.\n", lpNo);
				addCar(knockEmDown, lpNo);
			}
			
			else if (streetThugs->data < 2) {
				printf("\n\tAdding car '%s' to the Street.\n", lpNo);
				addCar(streetThugs, lpNo);
			}
			
			else {
				printf("\n\tParking and Street Full! Only handicap parking space available. Are you actually thinking of parking there?\n\n");
				continue;
			}
		}
		
		else if (arrDep == 'D') {
			
			if (removeCar(scratchEmUp, lpNo))
				printf("\n\tRemoving car '%s' from ScratchEmUp garage.\n", lpNo);
			
			else if (removeCar(knockEmDown, lpNo))
				printf("\n\tRemoving car '%s' from KnockEmDown garage.\n", lpNo);
			
			else if (removeCar(streetThugs, lpNo))
				printf("\n\tRemoving car '%s' from the street.\n", lpNo);
			
			else {
				printf("\n\tCar '%s' not found in both garages or streets. It's probably stolen by aliens. There's nothing you can do now, except weep silently or loudly.\n", lpNo);
				continue;
			}
			
		}
		
		printf("\n\tScratchEmUp: ");
		display(scratchEmUp);
		printf("\n\tKnockEmDown: ");
		display(knockEmDown);
		printf("\n\t The Street: ");
		display(streetThugs);
		
		
	} while (arrDep == 'A' || arrDep == 'D');
	
	return 0;
}

