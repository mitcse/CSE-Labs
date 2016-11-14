#include <stdio.h>
#include <stdlib.h>

#include <time.h>

void towerOfHanoi (int n, char A, char B, char C) {
	if (n > 0) {
		towerOfHanoi(n-1, A, C, B);
		// printf("Move peg [%d] from \'%c\' to \'%c\'.\n", n, A, C);
		towerOfHanoi(n-1, B, A, C);
	}
}

int main (int argc, const char * argv []) {

	FILE *outfile = fopen("toh.csv", "w+");

	fprintf(outfile, "Pegs, Time\n");

	clock_t st, et;
	double tt;

	int i, k;

	for (k = 1; k < 21; ++k) {

		st = clock();

		for (i = 0; i < 100; ++i) {
			towerOfHanoi(k, 'A', 'B', 'C');
		}

		et = clock();

		tt = (double)(et - st)/CLOCKS_PER_SEC;

		fprintf(outfile, "%d, %.5lf\n", k, tt);

	}

	fclose(outfile);

}