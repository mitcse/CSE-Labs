#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int fibonacci (int n) {
	if (n <= 2) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main (int argc, const char * argv []) {

	clock_t st, et;
	double tt;

	FILE *outfile = fopen("fibonacci.csv", "w+");

	fprintf(outfile, "Number, Time\n");

	int i, k;

	for (k = 0; k < 40; ++k) {

		int x;

		st = clock();

		for (i = 0; i < 50; ++i) {
			x = fibonacci(k);
		}

		et = clock();

		printf("fibonacci(%d) = %d\n", k, x);

		tt = (double)(et - st)/CLOCKS_PER_SEC;

		fprintf(outfile, "%d, %.5lf\n", k, tt);

	}

	fclose(outfile);

}