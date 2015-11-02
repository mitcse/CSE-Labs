//
//  RadixSort.c
//
//  Created by Avikant Saini on 2/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma mark - Radix Sort

// Do this...

void radixSort (int *arr, int start, int end) {
	
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

	radixSort(arr, 0, n - 1);
		
	printf("\n   Now: ");
	for (int i = 0; i < n; ++i)
		printf("\t%d", arr[i]);
	
}

