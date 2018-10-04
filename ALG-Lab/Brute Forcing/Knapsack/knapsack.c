#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <limits.h>

#define MAX 10
#define TWOMAX 1024

int n; // Number of items
int pown; // 2^n
int cap; // Max weight it can hold

float wts[MAX]; // All the weights
float vals[MAX]; // All the values

float mv = -1; // Maximum value

int mvals[MAX]; // Holds the max value combination

void input () {
	printf("Enter the number of items: ");
	scanf(" %d", &n);
	pown = pow(2, n);
	int i;
	for (i = 0; i < n; ++i) {
		printf("Enter weight and value of item %d: ", i+1);
		scanf(" %f %f", &wts[i], &vals[i]);
	}
	printf("Enter knapsack capacity: ");
	scanf(" %d", &cap);
}

float getWeight (int incl[MAX]) {
	int i;
	float wt = 0;
	for (i = 0; i < n; ++i) {
		if (incl[i]) {
			wt += wts[i];
		}
	}
	return wt;
}

float getValue (int incl[MAX]) {
	int i;
	float value = 0.0;
	for (i = 0; i < n; ++i) {
		if (incl[i]) {
			value += vals[i];
		}
	}
	return value;
}

void findMax () {

	int i, j;
	int k;

	int curr[MAX];

	for (i = 0; i < pow(2, n); ++i) {

		for (j = 0; j < n; ++j) {
			curr[j] = (int)(i / (pow(2, j))) % 2;
			// printf("%d", curr[j]);
		}

		float v = getValue(curr);
		float w = getWeight(curr);
		// printf(" | %.2f, %.2f", w, v);

		if (w <= cap && v > mv) {
			mv = v;
			// printf(" | *");
			for (j = 0; j < n; ++j) {
				mvals[j] = curr[j];
			}
		}

		// printf("\n");

	}

}

int main (int argc, char const * argv []) {
	
	int i;

	input();
	findMax();

	printf("\nOptimal solution:\nWeight\t| Value\n");

	for (i = 0; i < n; ++i) {
		if (mvals[i]) {
			printf(" %.2f\t| %.2f\n", wts[i], vals[i]);
		}
	}

	printf("\nMax value: %.2f\n", getValue(mvals));
	printf("Weight fit: %.2f\n", getWeight(mvals));

	return 0;
}

/** 

Sample input:

4
1 15
5 10
3 9
4 5
8

Sample output:



*/
