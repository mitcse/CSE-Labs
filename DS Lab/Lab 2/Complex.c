// Complex.c
// Created by @avikantz on 08/11/15

#include <stdio.h>
#include <math.h>

typedef struct Complex {
	float re;
	float im;
} COMPLEX_t;

void input(char id[10], COMPLEX_t *a) {
	printf("\n\tEnter Real(%s): ", id);
	scanf("%f", &a->re);
	printf("\tEnter Imaginary(%s): ", id);
	scanf("%f", &a->im);
	printf("\n");
}

void print(char id[10], COMPLEX_t *a) {
	printf("\t%s = \t%.4f + %.4fi\n", id, a->re, a->im);
}

void add(COMPLEX_t *a, COMPLEX_t *b, COMPLEX_t *s) {
	s->re = a->re + b->re;
	s->im = a->im + b->im;
}

void substract(COMPLEX_t *a, COMPLEX_t *b, COMPLEX_t *d) {
	d->re = a->re - b->re;
	d->im = a->im - b->im;
}

void multiply(COMPLEX_t *a, COMPLEX_t *b, COMPLEX_t *p) {
	p->re = (a->re)*(b->re) - (a->im)*(b->im);
	p->im = (a->re)*(b->im) - (a->im)*(b->re);
}

int main(int argc, const char *argv[]) {
	COMPLEX_t a, b, s, d, p;
	input("A", &a);
	input("B", &b);
	add(&a, &b, &s);
	substract(&a, &b, &d);
	multiply(&a, &b, &p);
	printf("\n");
	print("A", &a);
	print("B", &b);
	print("A+B", &s);
	print("A-B", &d);
	print("A*B", &p);
	return 0;
}

