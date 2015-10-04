//
//  Polynomial.h
//  Polynomial operations using linked list
//
//  Created by Avikant Saini on 10/4/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNDERFLOW_CHAR '\0'

typedef enum { NO, YES } BOOL;

typedef struct Node {
	double coeff;
	double pow;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

/**
 *	Create a linked list node with this function.
 *	Returns a NODE_p_t type defined above.
 */

NODE_p_t createNode ();

void inputPolynomial (NODE_p_t polynomial, char * id);

NODE_p_t createAndInputPolynomial (char * id);

/**
 *	Display the polynomial.
 */

void displayPolynomial (NODE_p_t polyn);

/**
 *	Add/substract two polynomials and returns the result.
 */

NODE_p_t addPolynomials (NODE_p_t polya, NODE_p_t polyb);
NODE_p_t substractPolynomials (NODE_p_t polya, NODE_p_t polyb);

/**
 *	Multiply the polynomials and return the result
 */

NODE_p_t multiplyPolynomials (NODE_p_t polya, NODE_p_t polyb);

/**
 *	Returns the result of evaulation of the passed polynomial.
 *	polyn: the polynomial you want to evaulate at 'x' as a linked list.
 *	x: the value at which you want to evaulate the passed polynomial.
 */

double evaulatePolynomial (NODE_p_t polyn, double x);

#endif /* Polynomial_h */
