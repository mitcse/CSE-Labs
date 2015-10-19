// PointerDemo.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

int arr[10];

int returnIntegerBySummingPointers(int *a, int *b) {
	int sum = *a + *b;
	return sum;
}

int* returnRandomPointerArray() {
	int i;
	for (i = 0; i < 10; ++i)
		arr[i] = (i+66)*(i+66);
	return arr;
}

int main(int argc, const char *argv[]) {
	int a = 12, b = 54, i;
	printf("Passing pointers to a function.\n\ta = 12, b = 54\n\n\treturnIntegerBySummingPointers(&a, &b) = %d\n\n", returnIntegerBySummingPointers(&a, &b));

	// Returning pointer from function
	printf("Returning random pointer array from a function: \n");
	int *pr = returnRandomPointerArray();
	for (i = 0; i < 10; ++i)
		printf("\tpr[%d] = %d\n", i, *(pr+i));

	// Pointer to pointer
	int *pa = &a, *pb = &b;
	int **ppa = &pa; 	// ppa is pointing to pa
	*ppa = pb; 			// ppa's point i.e. pa is now pointing to b	
	return 0;
} 
