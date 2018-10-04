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

#pragma mark - Merge sort

void merge (int *arr, int start, int mid, int end) {
	int *temp = (int *)calloc(end + 1, sizeof(int));
	int i = start;
	int s = start, m = mid + 1;
	
	while ((s <= mid) && (m <= end)) {
		if (*(arr + s) < *(arr + m))
			*(temp + i++) = *(arr + s++);
		else
			*(temp + i++) = *(arr + m++);
	}
	while (s <= mid)
		*(temp + i++) = *(arr + s++);
	while (m <= end)
		*(temp + i++) = *(arr + m++);
	
	for (i = start; i <= end; ++i)
		*(arr + i) = *(temp + i);
}

void mergeSort (int *arr, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
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
	output = fopen("merge_sort.csv", "w+");
	fprintf(output, "inputsize, time\n");

	while (fscanf(input, " %d", &n)) {

		int *arr = (int *)calloc(n, sizeof(int));
		for (i = 0; i < n; ++i) {
			fscanf(input, " %d", &m);
			*(arr + i) = m;
		}

		start_time = clock();
		
		for (i = 0; i < 50; ++i) {
			mergeSort(arr, 0, n-1);
		}
		printf("Done: %d\n", n);

		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

		fprintf(output, "%d, %lf\n", n, total_time);

		if (n >= 1000)
			break;
	}

	fclose(input);
	fclose(output);
	
}

