//
//  MergeSort.c
//
//  Created by Avikant Saini on 2/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	
	mergeSort(arr, 0, n - 1);
	
	printf("\n   Now: ");
	for (int i = 0; i < n; ++i)
		printf("\t%d", arr[i]);
	
}

