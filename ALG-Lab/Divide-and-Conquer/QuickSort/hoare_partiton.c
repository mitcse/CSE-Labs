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
	int k;
	for (j = start; j < end; ++j) {
		if (*(arr + j) <= pivot) {
			swap(arr + i, arr + j);
			for (k = start; k <= end; ++k) {
				printf(" %d", arr[k]);
			}
			printf(" | i = %d, j = %d\n", i, j);
			i++;
		}
	}
	swap(arr + i, arr + end);
	return i;
}

#pragma mark - Main

int main (int argc, const char * argv []) {

	int i;
	int n = 10;
	int arr[10] = {3, 8, 4, 1, 6, 7, 9, 0, 2, 5};

	for (i = 0; i < n; ++i) {
		printf(" %d", arr[i]);
	}
	printf("\n\n");

	partition(arr, 0, n-1);

	printf("\n");
	for (i = 0; i < n; ++i) {
		printf(" %d", arr[i]);
	}
	printf("\n");
	
}

