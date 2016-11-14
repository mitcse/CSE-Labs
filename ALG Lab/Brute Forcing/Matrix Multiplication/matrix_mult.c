#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define N 20

int a[N][N];
int b[N][N];
int c[N][N];

int i, j, k;

void multiply (int n) {
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main (int argc, char const * argv[]) {

	clock_t st, et;
	double tt;

	FILE *infile = fopen("matrices.txt", "r");

	FILE *outfile = fopen("matmult.csv", "w+");
	fprintf(outfile, "Size, Time\n");

	int n;

	do {

		fscanf(infile, "%d", &n);

		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				fscanf(infile, "%d ", &a[i][j]);
			}
			for (j = 0; j < n; ++j) {
				fscanf(infile, "%d ", &b[i][j]);
			}
		}

		st = clock();

		int i;
		for (i = 0; i < 1000; ++i) {
			multiply(n);
		}

		et = clock();

		tt = (double)(et - st)/CLOCKS_PER_SEC;

		fprintf(outfile, "%d, %.6lf\n", n, tt);

		if (n == 15) break;

	} while (n < 15);

	return 0;
}