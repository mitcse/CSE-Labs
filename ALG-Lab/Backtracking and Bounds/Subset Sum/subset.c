//
//	subset.c
//	Implementing subset sum problem using'backtracking' technique
//
//	created by @avikantz on 11/08/16
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NO, YES } BOOL;

int N;
int arr[100];
int sum;

int sumArray (BOOL incl[N]) {
	int i, s = 0;
	for (i = 0; i < N; ++i) {
		if (incl[i]) {
			s += arr[i];
		}
	}
	return s;
}

void printSubset (BOOL incl[N]) {
	int i;
	printf("{ ");
	for (i = 0; i < N; ++i) {
		if (incl[i]) {
			printf("%d ", arr[i]);
		}
	}
	printf("}\n");
} 

void findSubsets (BOOL incl[N], int i) {
	int xsum = sumArray(incl);
	if (xsum == sum) {
		printSubset(incl);
		return;
	}
	if (i == N || xsum > sum) {
		return;
	}
	BOOL use[N], nouse[N];
	memcpy(use, incl, sizeof(use));
	memcpy(nouse, incl, sizeof(nouse));
	use[i] = YES;
	nouse[i] = NO;
	findSubsets(use, i+1);
	findSubsets(nouse, i+1);
}

int main(int argc, char const * argv[]) {
	printf("Enter number of elements in the subset: ");
	scanf(" %d", &N);
	BOOL incl[N];
	int i;
	printf("Enter subset elements: ");
	for (i = 0; i < N; ++i) {
		scanf(" %d", &arr[i]);
		incl[i] = NO;
	}
	printf("Enter desired sum: ");
	scanf(" %d", &sum);
	findSubsets(incl, 0);
	return 0;
}

/**
	Sample input:
	10
	1 9 3 7 4 6 5 2 8 3
	10

	Sample output:
	{ 1 9 }
	{ 1 3 4 2 }
	{ 1 3 6 }
	{ 1 7 2 }
	{ 1 4 5 }
	{ 1 4 2 3 }
	{ 1 6 3 }
	{ 3 7 }
	{ 3 4 3 }
	{ 3 5 2 }
	{ 7 3 }
	{ 4 6 }
	{ 5 2 3 }
	{ 2 8 }
*/