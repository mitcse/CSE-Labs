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
	
	NODE_p_t p = list->next;
	
	temp->value = val;
	temp->next = p;
	temp->prev = list;
	
	list->next = temp;
	p->prev = temp;
	
	(list->value)++;
}

BOOL inputLongInteger (NODE_p_t li) {
	
	int i;
	char * longint = (char *)malloc(SIZE * sizeof(char));
	scanf(" %s", longint);
	
	if (strlen(longint) == 1 && *longint == '0')
		return NO;
	
	for (i = (int)strlen(longint) - 1; i >= 0; --i) {
		char z = *(longint + i);
		if (z < 48 || z > 57) {
			printf("\n\tNot a decimal number... Exiting\n\n");
			exit(69);
		}
		insert(li, z - '0');
	}
	
	return YES;
	
}

NODE_p_t createAndInputLongInteger () {
	NODE_p_t li = createNode();
	if (!inputLongInteger(li))
		return NULL;
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

void displayLongInteger (NODE_p_t longInteger, int maxSize) {
	int size;
	for (size = maxSize; size > longInteger->value; --size)
		printf("  ");
	
	NODE_p_t temp = longInteger->next;
	while (temp != longInteger) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

int maxLength (NODE_p_t * longIntegers) {
	int max = 0, i = 0;
	while (*(longIntegers + i) != NULL) {
		NODE_p_t temp = temp = *(longIntegers + i++);
		if (temp->value > max)
			max = temp->value;
	}
	return max;
}

int main (int argc, const char * argv []) {
	
	int count = 0, i;
	
	printf("\n\nThis program will calculate the sum of multiple 'long integers' using linked lists.\nEnter multiple 'long integers' one by one... Enter 0 to stop:\n\n");
	
	NODE_p_t *longIntegers = (NODE_p_t *)calloc(SIZE, sizeof(NODE_p_t));
	
	while ((*(longIntegers + count++) = createAndInputLongInteger()) != NULL);
	count--;
	
	int max = maxLength(longIntegers);
	
	NODE_p_t sum = createNode();
	
	if (count == 1) {
		sum = *longIntegers;
		printf("\n\tSum = Number entererd = ");
		displayLongInteger(sum, max);
		exit(0);
	}
	
	sum = addLongIntegers(*longIntegers, *(longIntegers + 1));
	
	if (count > 2) {
		for (i = 2; i < count; ++i)
			sum = addLongIntegers(sum, *(longIntegers + i));
	}
	
	if (sum->value > max)
		max = sum->value;
	
	printf("\n\n\t   ");
	displayLongInteger(*longIntegers, max);
	
	i = 1;
	while (*(longIntegers + i) != NULL) {
		printf("\n\t + ");
		displayLongInteger(*(longIntegers + i++), max);
	}
	
	printf("\n\t---");
	for (i = 0; i < max; ++i)
		printf("--");
	
	printf("\n\t = ");
	displayLongInteger(sum, max);
	
	printf("\n\n");
	return 0;
}

