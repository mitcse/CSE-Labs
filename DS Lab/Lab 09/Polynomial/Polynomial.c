//
//  Polynomial.c
//
//  Created by Avikant Saini on 10/4/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include "Polynomial.h"

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

/*

#pragma mark - Merge sorting nodes

void splitList (NODE_p_t olist, NODE_p_t * lista, NODE_p_t * listb) {
	
	if (olist == NULL || olist->next == NULL) {
		*lista = olist;
		*listb = NULL;
		return;
	}
	
	NODE_p_t slow = olist;
	NODE_p_t fast = olist->next;
	
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*lista = olist;
	*listb = slow;
}

NODE_p_t mergeLists (NODE_p_t lista, NODE_p_t listb) {
	
	if (lista->next == NULL)
		return listb;
	if (listb->next == NULL)
		return lista;
	
	NODE_p_t mergedList = NULL;
	
	if (lista->coeff > listb->coeff) {
		mergedList = lista;
		mergedList->next = mergeLists(lista->next, listb);
	}
	else {
		mergedList = listb;
		mergedList->next = mergeLists(lista, listb->next);
	}
	return mergedList;
}

void mergeSort (NODE_p_t * list) {
	
	NODE_p_t header = *list;
	
	// Base case
	if (header == NULL || header->next == NULL)
		return;
	
	NODE_p_t tempa = NULL;
	NODE_p_t tempb = NULL;
	
	splitList(header, &tempa, &tempb);
	
	mergeSort(&tempa);
	mergeSort(&tempb);
	
	*list = mergeLists(tempa, tempb);
}

*/

#pragma mark - Add to polynomial if present

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


#pragma mark - Input

NODE_p_t createAndInputPolynomial (char * id) {
	NODE_p_t polyn = createNode();
	inputPolynomial(polyn, id);
	return polyn;
}

void inputPolynomial (NODE_p_t polynomial, char * id) {
	
	if (polynomial == NULL) {
		printf("\n\nError: \"Polynomial.h\" : void inputPolynomial (NODE_p_t, char *): Input NODE_p_t should not be NULL. Initialize it using createNode() before passing.\n\n\t");
		exit(1022);
	}
	
	int i, n;
	double coeff, pow;
	printf("\n\tEnter number of terms in the polynomial '%s' : ", id);
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		printf("\n\tEnter coefficient and power for term %d: ", (i+1));
		scanf("%lf %lf", &coeff, &pow);
		insert(polynomial, coeff, pow);
	}
	
}

#pragma mark - Add/Substract

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

#pragma mark - Multiply

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

#pragma mark - Evaulate polynomial

double evaulatePolynomial (NODE_p_t polyn, double x) {
	double result = 0.0;
	NODE_p_t temp = polyn->next;
	while (temp != NULL) {
		result += temp->coeff * powf(x, temp->pow);
		temp = temp->next;
	}
	return result;
}

#pragma mark - Display polynomial

void displayPolynomial (NODE_p_t polyn) {
	
	NODE_p_t temp = polyn->next;
	
	BOOL isCoeffNonFloatingPoint = ((temp->coeff) == (int)(temp->coeff))?YES:NO;
	BOOL isPowerNonFloatingPoint = ((temp->pow) == (int)(temp->pow))?YES:NO;
	
	printf("\n\t");
	
	if (temp == NULL) {
		printf("0 ");
		return;
	}
	
	if (temp->coeff == 1)
		printf("x");
	else if (temp->coeff == 0)
		printf("0");
	else if (temp->coeff == -1)
		printf("-x");
	else {
		if (isCoeffNonFloatingPoint)
			printf("%.0lfx", temp->coeff);
		else
			printf("%.3lfx", temp->coeff);
	}
	
	if (temp->pow == 0 || temp->coeff == 0)
		printf(" ");
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
		
		if (temp->coeff == 1)
			printf("+x");
		else if (temp->coeff == -1)
			printf("-x");
		else {
			if (isCoeffNonFloatingPoint)
				printf("%s%.0lfx", (temp->coeff > 0)?"+":"", temp->coeff);
			else
				printf("%s%.3lfx", (temp->coeff > 0)?"+":"", temp->coeff);
		}
		
		if (temp->pow == 0)
			printf(" ");
		else if (temp->pow != 1) {
			if (isPowerNonFloatingPoint)
				printf("^%.0lf ", temp->pow);
			else
				printf("^(%.3lf) ", temp->pow);
		}
		
		temp = temp->next;
	}
	
}

