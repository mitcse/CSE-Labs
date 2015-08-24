// ArrayPrintPointer.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

void printArray(int *arr, int n) {
	int *pi = arr, *pn = arr+n;
	printf("\n\tFORWARD HA!\n\t\t");
	for(; pi < pn; ++pi)
		printf("%d\t", *pi);
	
	printf("\n\n\t!AH DRAWKCAB\n\t\t");
	for(pi = pn - 1; pi >= arr; --pi)
		printf("%d\t", *pi);

	printf("\n\n");
}

int main(int argc, const char *argv[]) {
	int a[100], n, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the array: ");
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printArray(a, n);
}
