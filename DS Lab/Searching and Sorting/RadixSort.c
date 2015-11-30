//
//  RadixSort.c
//
//  Created by Avikant Saini on 2/11/15.
//  Copyright © 2015 avikantz. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma mark - Radix Sort (LSD)

int maxValue (int *arr, int n) {
	int max = *arr, i;
	for (i = 1; i < n; ++i)
		if (*(arr + i) > max)
			max = *(arr + i);
	return max;
}

int countDigits (int n) {
	int count = 0, z = n;
	while (z != 0) {
		z /= 10;
		++count;
	}
	return count;
}

int digitAtPlace (int num, int place) {
	return (num%((int)pow(10, place)))/(int)(pow(10, place - 1));
}

void digitBySort (int *arr, int n, int digit) {
	int i;
	int *count = (int *)calloc(10, sizeof(int));
	int *narr = (int *)calloc(n, sizeof(int));
	
	for (i = 0; i < n; ++i) {
		int x = digitAtPlace(*(arr + i), digit);
		*(count + x) += 1;
	}
	
	for (i = 1; i < 10; ++i)
		*(count + i) += *(count + i - 1);
	
	for (i = n - 1; i >= 0; --i) {
		int x = digitAtPlace(*(arr + i), digit);
		*(narr + *(count + x) - 1) = *(arr + i);
		*(count + x) -= 1;
	}
	
	for (i = 0; i < n; ++i)
		*(arr + i) = *(narr + i);
}

void radixSortLSD (int *arr, int n) {
	
	int max = maxValue(arr, n), i;
	
	int countMax = countDigits(max);
	
	for (i = 1; i <= countMax; ++i) {
		digitBySort(arr, n, i);
		
		printf("\n\n  Iter %d: ", i);
		for (int i = 0; i < n; ++i)
			printf(" %d ", arr[i]);
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

	radixSortLSD(arr, n);
		
	printf("\n   Now: ");
	for (int i = 0; i < n; ++i)
		printf("\t%d", arr[i]);
	
}

