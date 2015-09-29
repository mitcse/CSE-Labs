//
//  PolynomialLinkedList.c
//  Polynomial evaulation using singly circular linked list
//
//  Created by Avikant Saini on 9/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UNDERFLOW_CHAR '\0'

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int coeff;
	int pow;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->next = temp;
	temp->coeff = 0;
	temp->pow = 0;
	return temp;
}

void insert (NODE_p_t list, int coeff, int pow) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->coeff = coeff;
	temp->pow = pow;
	temp->next = list;
	
	if (list->next == list)
		list->next = temp;
	
	else {
		p = list->next;
		
		while (p->next != list)
			p = p->next;
		p->next = temp;
		
	}
}

double peval (NODE_p_t polyn, double x) {
	double result;
	NODE_p_t temp = polyn->next;
	while (temp != polyn) {
		result += temp->coeff * pow(x, temp->pow);
		temp = temp->next;
	}
	return result;
}

int main (int argc, const char * argv []) {
	
	NODE_p_t a = createNode();
	
	int i, n, coeff, pow;
	printf("\n\tEnter number of terms in the polynomial: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		printf("\n\tEnter coefficient and power for term %d: ", (i+1));
		scanf("%d %d", &coeff, &pow);
		insert(a, coeff, pow);
	}
	
	double x, result;
	printf("\n\tEnter value of 'x': ");
	scanf("%lf", &x);
	
	result = peval(a, x);
	
	printf("\n\tResult = %.3lf\n\n", result);
	
	return 0;
}
