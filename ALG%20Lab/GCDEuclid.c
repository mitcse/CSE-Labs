#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int gcd(int a, int b) {
	if (b > a)
		gcd(b, a);
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;
	
	int i;
	int a, b;

	// printf("Enter (a, b): ");
	// scanf(" %d, %d ", &a, &b);

	FILE *input;
	input = fopen("inputfib.csv", "r");

	FILE *output;
	output = fopen("GCDEuclid.csv", "w+");
	fprintf(output, "min, time\n");

	while (fscanf(input, " %d, %d ", &a, &b) > 1) {
		start_time = clock();
		for (i = 0; i < 100000; ++i) {
			gcd(a, b);
		}
		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
		fprintf(output, "%d, %lf\n", min(a, b), total_time);
	}

	fclose(input);
	fclose(output);

}