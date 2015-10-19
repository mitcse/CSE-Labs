//
//  PolynomialOperations.c
//  Polyniomial Operations using Linked Lists
//
//  Created by Avikant Saini on 9/29/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum { NO, YES } BOOL;

typedef struct Node {
	double coeff;
	double pow;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->coeff = 0;
	temp->pow = 0;
	temp->next = NULL;
	return temp;
}

void insert (NODE_p_t list, double coeff, double pow) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->coeff = coeff;
	temp->pow = pow;
	temp->next = NULL;
	
	if (list->next == NULL)
		list->next = temp;
	
	else {
		p = list->next;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
		
	}
}

BOOL addToPolynomialIfPresent (NODE_p_t polyn, double pow, double coeff) {
	NODE_p_t temp = polyn->next;
	while (temp != NULL) {
		if (temp->pow == pow) {
			temp->coeff += coeff;
			return YES;
		}
		temp = temp->next;
	}
	return NO;
}

void inputPolynomial (NODE_p_t polynomial, char * id) {
	
	int i, n;
	double coeff, pow;
	printf("\n\n\tEnter number of terms in the polynomial '%s' : ", id);
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		printf("\tEnter coefficient and power for term %d: ", (i+1));
		scanf("%lf %lf", &coeff, &pow);
		if (!(addToPolynomialIfPresent(polynomial, pow, coeff)))
			insert(polynomial, coeff, pow);
	}
	
}

NODE_p_t createAndInputPolynomial (char * id) {
	NODE_p_t polyn = createNode();
	inputPolynomial(polyn, id);
	return polyn;
}

NODE_p_t addSubstractPolynomials (NODE_p_t polya, NODE_p_t polyb, int choice) {
	NODE_p_t polyc = createNode();
	
	NODE_p_t tempa = polya->next, tempb = polyb->next;
	
	while (tempa != NULL) {
		if (!(addToPolynomialIfPresent(polyc, tempa->pow, tempa->coeff)))
			insert(polyc, tempa->coeff, tempa->pow);
		tempa = tempa->next;
	}
	while (tempb != NULL) {
		if (!(addToPolynomialIfPresent(polyc, tempb->pow, choice*tempb->coeff)))
			insert(polyc, choice*tempb->coeff, tempb->pow);
		tempb = tempb->next;
	}
	
	return polyc;
}

NODE_p_t addPolynomials (NODE_p_t polya, NODE_p_t polyb) {
	NODE_p_t polyc = createNode();
	polyc = addSubstractPolynomials(polya, polyb, 1);
	return polyc;
}

NODE_p_t substractPolynomials (NODE_p_t polya, NODE_p_t polyb) {
	NODE_p_t polyc = createNode();
	polyc = addSubstractPolynomials(polya, polyb, -1);
	return polyc;
}

NODE_p_t multiplyPolynomials (NODE_p_t polya, NODE_p_t polyb) {
	NODE_p_t polyc = createNode();
	
	NODE_p_t tempa = polya->next;
	
	while (tempa != NULL) {
		NODE_p_t tempb = polyb->next;
		while (tempb != NULL) {
			if (!(addToPolynomialIfPresent(polyc, tempa->pow + tempb->pow, tempa->coeff * tempb->coeff)))
				insert(polyc, tempa->coeff * tempb->coeff, tempa->pow + tempb->pow);
			tempb = tempb->next;
		}
		tempa = tempa->next;
	}
	
	return polyc;
}

void displayPolynomial (NODE_p_t polyn) {
	
	NODE_p_t temp = polyn->next;
	
	BOOL isCoeffNonFloatingPoint = ((temp->coeff) == (int)(temp->coeff))?YES:NO;
	BOOL isPowerNonFloatingPoint = ((temp->pow) == (int)(temp->pow))?YES:NO;
	
	printf("\t");
	
	if (temp == NULL) {
		printf("0 ");
		return;
	}
	
	if (temp->coeff == 1) printf("x");
	else if (temp->coeff == 0) printf("0");
	else if (temp->coeff == -1) printf("-x");
	else {
		if (isCoeffNonFloatingPoint)
			printf("%.0lfx", temp->coeff);
		else
			printf("%.3lfx", temp->coeff);
	}
	
	if (temp->pow == 0 || temp->coeff == 0) printf(" ");
	else if (temp->pow != 1) {
		if (isPowerNonFloatingPoint)
			printf("^%.0lf ", temp->pow);
		else
			printf("^(%.3lf) ", temp->pow);
	}
	
	temp = temp->next;
	
	while (temp != NULL) {
		
		isCoeffNonFloatingPoint = ((temp->coeff) == (int)(temp->coeff))?YES:NO;
		isPowerNonFloatingPoint = ((temp->pow) == (int)(temp->pow))?YES:NO;
		
		if (temp->coeff == 0) {
			temp = temp->next;
			continue;
		}
		
		if (temp->coeff == 1) printf("+x");
		else if (temp->coeff == -1) printf("-x");
		else {
			if (isCoeffNonFloatingPoint)
				printf("%s%.0lfx", (temp->coeff > 0)?"+":"", temp->coeff);
			else
				printf("%s%.3lfx", (temp->coeff > 0)?"+":"", temp->coeff);
		}
		
		if (temp->pow == 0) printf(" ");
		else if (temp->pow != 1) {
			if (isPowerNonFloatingPoint)
				printf("^%.0lf ", temp->pow);
			else
				printf("^(%.3lf) ", temp->pow);
		}
		
		temp = temp->next;
	}
}

int main (int argc, const char * argv []) {
	
	char choice;
	
	do {
		printf("\n\n\t1. Add Polynomials.\n\t2. Substract Polynomials.\n\t3. Multiply Polynomials.\n\tEnter choice: ");
		choice = getchar();
		getchar();
		
		if (choice < '1' || choice > '3') {
			printf("\n\tInvalid choice...\n\n");
			return 69;
		}
		
		NODE_p_t a = createAndInputPolynomial("A");
		NODE_p_t b = createAndInputPolynomial("B");
		
		NODE_p_t c;
		char * cid;
		
		if (choice == '1') {
			c = addPolynomials(a, b);
			cid = "+";
		}
		else if (choice == '2') {
			c = substractPolynomials(a, b);
			cid = "-";
		}
		else if (choice == '3') {
			c = multiplyPolynomials(a, b);
			cid = "*";
		}
		
		printf("\n\n\t     A = ");
		displayPolynomial(a);
		printf("\n\n\t     B = ");
		displayPolynomial(b);
		
		printf("\n\n\t A %s B = ", cid);
		displayPolynomial(c);
		
	} while (choice == '1' || choice == '2' || choice == '3');
	
	printf("\n\n");
	
	return 0;
}

