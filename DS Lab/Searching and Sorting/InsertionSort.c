//
//  InsertionSort.c
//
//  Created by Avikant Saini on 2/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma mark - Insertion sort

void insertionSort (int *arr, int l) {
	int i, j, x;
	for (i = 1; i < l - 1; ++i) {
		x = *(arr + i);
		j = i;
		while (j > 0 && *(arr + j - 1) > x) {
			*(arr + j) = *(arr + j - 1);
			--j;
		}
		*(arr + j) = x;
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
	
	insertionSort(arr, n);
	
	printf("\n   Now: ");
	for (int i = 0; i < n; ++i)
		printf("\t%d", arr[i]);
		
	
}

