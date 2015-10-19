// Quadratic.c
// Created by @avikantz on 08/11/15

#include <stdio.h>
#include <math.h>

void getData(float *a, float *b, float *c) {
	printf("\n\tEnter 'a': ");
	scanf("%f", a);
	printf("\tEnter 'b': ");
	scanf("%f", b);
	printf("\tEnter 'c': ");
	scanf("%f", c);
	printf("\n\n");
}

void print_roots(double d, double *x1, double *x2) {
	if (d < 0) {
		printf("\n\tImaginary Roots:\n\t\t%.4f + %.4fi\n\t\t%.4f - %.4fi\n\n", *x1, *x2, *x1, *x2);
	}
	else if (d > 0) {
		printf("\n\tReal and Distinct Roots:\n\t\t%.4f\n\t\t%.4f", *x1, *x2);
	}
	else {
		printf("\n\tReal and Equal Roots:\n\t\t%.4f\n\t\t%.4f", *x1, *x2);
	}
	printf("\n\n");
}

void quadratic(float a, float b, float c, double *x1, double *x2) {
	double d = b*b - 4*a*c;
	if (d < 0) {
		*x1 = -b/(2*a);
		*x2 = sqrt(fabs(d))/(2*a);
		print_roots(d, x1, x2);
	}
	else if (d > 0) {
		*x1 = (-b + sqrt(d))/(2*a);
		*x2 = (-b - sqrt(d))/(2*a);
		print_roots(d, x1, x2);
	}
	else {
		*x1 = *x2 = -b/(2*a);
		print_roots(d, x1, x2);
	}
}

int main(int argc, const char *argv[]) {
	float a, b, c;
	printf("\n\tThis program will calculate roots of a quadratic equation.\n");
	getData(&a, &b, &c);
	double x1, x2;
	quadratic(a, b, c, &x1, &x2);
	return 0;
}
