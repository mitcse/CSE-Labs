//
//  QuickSort.c
//
//  Created by Avikant Saini on 2/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#pragma mark - Utility

void swap (int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

#pragma mark - Quick sort

int partition (int *arr, int start, int end) {
	int pivot = *(arr + end);
	int i = start, j;
	for (j = start; j < end; ++j) {
		if (*(arr + j) <= pivot) {
			swap(arr + i, arr + j);
			i++;
		}
	}
	swap(arr + i, arr + end);
	return i;
}

void quickSort (int *arr, int start, int end) {
	if (start < end) {
		int p = partition(arr, start, end);
		quickSort(arr, start, p - 1);
		quickSort(arr, p + 1, end);
	}
}

#pragma mark - Main

int main (int argc, const char * argv []) {

	clock_t start_time, end_time;
	double total_time;
	
	int i;
	int n, m;

	FILE *input;
	input = fopen("numbers.txt", "r");

	FILE *output;
	output = fopen("quick_sort.csv", "w+");
	fprintf(output, "inputsize, time\n");

	while (fscanf(input, " %d", &n)) {

		int *arr = (int *)calloc(n, sizeof(int));
		for (i = 0; i < n; ++i) {
			fscanf(input, " %d", &m);
			*(arr + i) = m;
		}

		start_time = clock();
		
		for (i = 0; i < 100; ++i) {
			quickSort(arr, 0, n-1);
		}
		printf("Done: %d\n", n);

		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

		fprintf(output, "%d, %lf\n", n, total_time);

		if (n == 1000)
			break;
	}

	fclose(input);
	fclose(output);
	
}

