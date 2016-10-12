#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int n) {
	int i;
	printf("\n");
	for (i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void swap (int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void shiftUp (int A[], int start, int end) {
	int c = end;
	while (c > start) {
		int p = c/2;
		if (A[p] < A[c]) {
			swap(A + p, A + c);
			c = p;
		} else {
			return;
		}
	}
}

void heapify (int A[], int count) {
	int end = 1;
	while (end <= count) {
		shiftUp(A, 1, end);
		end += 1;
	}
}

void buildHeap (int A[], int n) {
	int i;
	for (i = 2; i <= n; ++i) {
		heapify(A, i);
	}
}

void heapdeletemin (int A[], int n) {
	int mi = n, i;
	int min = A[i];
	for (i = n-1; i > n/2; --i) {
		if (A[i] < min) {
			min = A[i];
			mi = i;
		}
	}
	swap(A + mi, A + n);
	heapify(A, n-1);
}

void heapdeletemax (int A[], int n) {
	swap(A + 1, A + n);
	heapify(A, n-1);
}

int * inputAHeap (int *size) {
	printf("\n\tEnter number of elements in the heap: ");
	scanf(" %d", size);
	int n = *size;
	int i;
	int *arr = (int *)calloc(n+1, sizeof(int));
	printf("\tEnter %d elements: ", n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", (arr+i));
		if (i > 1)
			heapify(arr, i);
	}
	return arr;
}

#pragma mark - main

int main (int argc, char const * argv []) {

	// int n;
	// int *arr = inputAHeap(&n);

	// printArray(arr, n);

	// heapdeletemax(arr, n);

	// printArray(arr, n-1);

	clock_t start_time, end_time;
	double total_time;
	
	int i;
	int n, m;

	FILE *input;
	input = fopen("numbers.txt", "r");

	FILE *output;
	output = fopen("heapdelete.csv", "w+");
	fprintf(output, "inputsize, time\n");

	while (fscanf(input, " %d", &n)) {

		int *arr = (int *)calloc(n, sizeof(int));
		for (i = 0; i < n; ++i) {
			fscanf(input, " %d", &m);
			*(arr + i) = m;
		}

		buildHeap(arr, n);

		start_time = clock();

		int z = n;
		for (i = 0; i < 20; ++i, --z) {
			heapdeletemax(arr, n);
		}

		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

		fprintf(output, "%d, %lf\n", n, total_time);
		printf("%d, %lf\n", n, total_time);

		if (n == 2000)
			break;
	}

	fclose(input);
	fclose(output);

	return 0;
}