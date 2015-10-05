//
//  LongInteger.c
//  Long Integer Addition using Linked Lists
//
//  Created by Avikant Saini on 10/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 250

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int value;
	struct Node * next;
	struct Node * prev;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->value = 0;
	temp->prev = temp;
	temp->next = temp;
	return temp;
}

void insert (NODE_p_t list, int val) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->value = val;
	temp->prev = list;
	
	list->next = temp;
	
	if (list->prev == list) {
		temp->next = list;
		list->prev = temp;
	}
	
	else {
		p = list->prev;
		
		while (p->prev != list)
			p = p->prev;
		
		temp->next = p;
		p->prev = temp;
	}
	(list->value)++;
}

void inputLongInteger (NODE_p_t li) {
	
	int i;
	char * longint = (char *)malloc(SIZE * sizeof(char));
	scanf(" %s", longint);
	
	for (i = 0; i <= strlen(longint)/2; ++i) {
		char temp = *(longint + i);
		*(longint + i) = *(longint + strlen(longint) - 1 - i);
		*(longint + strlen(longint) - 1 - i) = temp;
	}
	
	for (i = 0; i < strlen(longint); ++i)
		insert(li, *(longint + i) - '0');
	
}

NODE_p_t createAndInputLongInteger () {
	NODE_p_t li = createNode();
	inputLongInteger(li);
	return li;
}

NODE_p_t addLongIntegers (NODE_p_t lia, NODE_p_t lib) {
	NODE_p_t lic = createNode();
	
	int carry = 0, sum = 0;
	NODE_p_t tempa = lia->prev;
	NODE_p_t tempb = lib->prev;
	
	while (tempa != lia && tempb != lib) {
		sum = tempa->value + tempb->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(lic, sum);
		tempa = tempa->prev;
		tempb = tempb->prev;
	}
	while (tempa != lia) {
		sum = tempa->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(lic, sum);
		tempa = tempa->prev;
	}
	while (tempb != lib) {
		sum = tempb->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(lic, sum);
		tempb = tempb->prev;
	}
	if (carry != 0)
		insert(lic, carry);
	
	return lic;
}

void displayLongInteger (NODE_p_t longInteger) {
	NODE_p_t temp = longInteger->next;
	while (temp != longInteger) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

int main (int argc, const char * argv []) {
	
	printf("\n\tEnter A: ");
	NODE_p_t lia = createAndInputLongInteger();
	printf("\n\tEnter B: ");
	NODE_p_t lib = createAndInputLongInteger();
	
	NODE_p_t lic = addLongIntegers(lia, lib);
	
	printf("\n\t    A = ");
	displayLongInteger(lia);
	printf("\n\t    B = ");
	displayLongInteger(lib);
	
	printf("\n\tA + B = ");
	displayLongInteger(lic);
	
	printf("\n\n");
	return 0;
}

