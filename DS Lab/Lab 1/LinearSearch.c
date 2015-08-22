//
//  LinearSearch.c
//  LinearSearch
//
//  Created by Avikant Saini on 8/4/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

int list[100], n, tbs, ind;

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void sort(int a[], int n) {
	int i, j, min;
	for (i = 0; i < n; ++i) {
		min = i;
		for (j = i; j < n; ++j)
			if (a[j] < a[min])
				min = j;
		swap(&a[i], &a[min]);
	}
}

void printArray(int a[], int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int linearSearch(int a[], int n, int x) {
	int i;
	for (i = 0; i < n; ++i)
		if (a[i] == x)
			return i;
	return -1;
}

int main(int argc, const char * argv[]) {
	printf("Enter number of integers: ");
	scanf("%d", &n);
	printf("\n\nEnter %d integers: ", n);
	int i;
	for (i = 0; i < n; ++i)
		scanf("%d", &list[i]);
	
	printf("Original List: ");
	printArray(list, n);
	
//	sort(list, n);
//	
//	printf("Sorted List: ");
//	printArray(list, n);
	
	printf("\nEnter element to be searched: ");
	scanf("%d", &tbs);
	
	ind = linearSearch(list, n, tbs);
	
	if (ind == -1)
		printf("\n404: %d NOT FOUND", tbs);
	else
		printf("\n'%d' found at position %d.\n\n", tbs, ind+1);
	
    return 0;
}