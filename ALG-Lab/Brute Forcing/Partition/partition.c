#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { NO, YES } BOOL;

BOOL isSubsetSum (int arr[], int n, int sum) {
	if (sum == 0)
		return YES;
	if (n == 0 && sum != 0)
		return NO;
	if (arr[n-1] > sum)
		return isSubsetSum (arr, n-1, sum);
   	return isSubsetSum (arr, n-1, sum) ||
			isSubsetSum (arr, n-1, sum-arr[n-1]);
}

BOOL findPartition (int arr[], int n) {
	int sum = 0, i;
	for (i = 0; i < n; ++i)
		sum += arr[i];
	if (sum % 2 != 0) 
		return NO;
   return isSubsetSum(arr, n, sum/2);
}

/**
* Source: Wikipedia
INPUT:  A list of integers S
OUTPUT: True if S can be partitioned into two subsets that have equal sum
1 function find_partition(S):
2     n ← |S|
3     K ← sum(S)
4     P ← empty boolean table of size (K/2 + 1) by (n + 1)
5     initialize top row (P(0,x)) of P to True
6     initialize leftmost column (P(x, 0)) of P, except for P(0, 0) to False
7     for i from 1 to k/2:
8         for j from 1 to n:
9             P(i, j) ← P(i, j-1) or P(i-S[j-1], j-1)
10    return P(K/2, n)
*/

BOOL find_partition (int S[], int N) {
	int K = 0;
	int i, j;
	for (i = 0; i < N; ++i)
		K += S[i];
	K /= N;
	BOOL ** P = (BOOL **)calloc(K/2 + 1, sizeof(BOOL *));
	for (i = 0; i < K/2 + 1; ++i) {
		*(P + i) = (BOOL *)calloc(N + 1, sizeof(BOOL));
		*(*(P + i) + 0) = NO;
	}
	for (i = 0; i < N + 1; ++i)
		*(*(P + 0) + i) = YES;

	for (i = 0; i < K/2; ++i) {
		for (j = 0; j < N; ++j) {
			P[i][j] = P[i][j-1] || P[i-S[j-1]][j-1];
		}
	}
	return P[K/2][N];
}

int main (int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;
	FILE *input;
	input = fopen("numbers.txt", "r");
	FILE *output;
	output = fopen("partition.csv", "w+");
	fprintf(output, "inputsize, time\n");
	int n, m, i, j;
	while (fscanf(input, " %d", &n) > 0) {
		int *arr = (int *)calloc(n, sizeof(int));
		for (j = 0; j < n; ++j) {
			fscanf(input, " %d", (arr + j));
		}
		start_time = clock();
		BOOL res = findPartition(arr, n);
		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
		printf("%d, %lf\n", n, total_time);
		fprintf(output, "%d, %lf\n", n, total_time);
	}
	fclose(input);
	fclose(output);
	return 0;
}