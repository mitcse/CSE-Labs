#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void bubblesort(int *arr, int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n - 1 - i; ++j) {
			if (*(arr + j) > *(arr + j + 1)) {
				swap(arr + j, arr + j + 1);
			}
		}
	}
}

int main(int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;
	
	int i;
	int n, m;

	FILE *input;
	input = fopen("numbers.txt", "r");

	FILE *output;
	output = fopen("bubblesort.csv", "w+");
	fprintf(output, "inputsize, time\n");

	while (fscanf(input, " %d", &n)) {

		int *arr = (int *)calloc(n, sizeof(int));
		for (i = 0; i < n; ++i) {
			fscanf(input, " %d", &m);
			*(arr + i) = m;
		}

		start_time = clock();
		
		for (i = 0; i < 100; ++i) {
			bubblesort(arr, n);
		}

		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

		fprintf(output, "%d, %lf\n", n, total_time);
	}

	fclose(input);
	fclose(output);

}