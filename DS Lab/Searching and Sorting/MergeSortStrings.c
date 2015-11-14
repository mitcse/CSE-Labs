//
//	MergeSortStrings.c
//	Sorting an string array using merge sort
//
//	Created by Avikant Saini on 11/10/15
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define initString(size) (char *)malloc(size * sizeof(char));

typedef enum { NO, YES } BOOL;

typedef char * String;

#pragma mark - Merge sort

void merge (String *arr, int start, int mid, int end) {
	String *temp = (String *)calloc(end + 1, sizeof(String));
	
	int i;
	for (i = start; i <= end; ++i)
		*(temp + i) = initString(SIZE);
	
	i = start;
	int s = start, m = mid + 1;
	
	while ((s <= mid) && (m <= end)) {
		if (strcmp(*(arr + s), *(arr + m)) < 0)
			strcpy(*(temp + (i++)), *(arr + (s++)));
		else
			strcpy(*(temp + (i++)), *(arr + (m++)));
	}
	while (s <= mid) {
		strcpy(*(temp + (i++)), *(arr + (s++)));
	}
	while (m <= end) {
		strcpy(*(temp + (i++)), *(arr + (m++)));
	}
	
	for (i = start; i <= end; ++i) {
		strcpy(*(arr + i), *(temp + i));
	}
}

void mergeSort (String *arr, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void printArray (String *arr, int n) {
	printf("\n\t");
	int i;
	for (i = 0; i < n; ++i)
		printf("%s  ", *(arr + i));
	printf("\n");
}

#pragma mark - Main

int main (int argc, const char * argv[]) {
	
	String *arr = (String *)calloc(5, sizeof(String));
	
	int i;
	for (i = 0; i < 5; ++i)
		*(arr + i) = initString(SIZE);
	
	
	strcpy(*arr, "Merge");
	strcpy(*(arr + 1), "Radix");
	strcpy(*(arr + 2), "Quick");
	strcpy(*(arr + 3), "Heap");
	strcpy(*(arr + 4), "Insertion");
	
	printArray(arr, 5);
	
	mergeSort(arr, 0, 4);
	
	printArray(arr, 5);
}



