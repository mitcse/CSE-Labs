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

int main (int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;
	FILE *input;
	input = fopen("numbers.txt", "r");
	FILE *output;
	output = fopen("partition.csv", "w+");
	fprintf(output, "inputsize, time\n");
	int n, m, i, j;
	while (fscanf(input, " %d", &n)) {
		int *arr = (int *)calloc(n, sizeof(int));
		for (j = 0; j < n; ++j) {
			fscanf(input, " %d", (arr + j));
		}
		start_time = clock();
		findPartition(arr, n);
		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
		fprintf(output, "%d, %lf", n, total_time);
	}
	fclose(input);
	fclose(output);
	return 0;
}