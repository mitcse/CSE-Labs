//
//  QuickSort.c
//
//  Created by Avikant Saini on 2/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	
	int n, i;
	printf("\n\tEnter number of elements in the array: ");
	scanf(" %d", &n);
	
	int *arr = (int *)calloc(n, sizeof(int));
	
	printf("\n\tEnter %d elements: ", n);
	for (i = 0; i < n; ++i)
		scanf(" %d", (arr + i));
	
	printf("\n\n  Init: ");
	for (int i = 0; i < n; ++i)
		printf("\t%d", arr[i]);
	
	quickSort(arr, 0, n - 1);
	
	printf("\n   Now: ");
	for (int i = 0; i < n; ++i)
		printf("\t%d", arr[i]);
	
}

