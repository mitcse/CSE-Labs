#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int gcd(int a, int b) {
	if (a > b)
		gcd(b, a);
	int i;
	for (i = a; i >= 1; --i) {
		if ((b % i == 0) && (a % i == 0)) {
			return i;
		}
	}
}

int main(int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;
	
	int i;
	int a, b;

	// printf("Enter (a, b): ");
	// scanf(" %d, %d ", &a, &b);

	FILE *input;
	input = fopen("inputcoprime.csv", "r");

	FILE *output;
	output = fopen("GCDConseqInteger.csv", "w+");
	fprintf(output, "max, time\n");

	while (fscanf(input, " %d, %d ", &a, &b) > 1) {
		start_time = clock();
		for (i = 0; i < 100000; ++i) {
			gcd(a, b);
		}
		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
		fprintf(output, "%d, %lf\n", max(a, b), total_time);
	}

	fclose(input);
	fclose(output);

}