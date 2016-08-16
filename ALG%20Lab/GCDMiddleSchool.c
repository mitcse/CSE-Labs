#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int gcd(int a, int b) {
	if (a > b)
		gcd(b, a);
	int fact = 2;
	int gcd = 1;
	int z = a;
	for (fact = 2; fact <= z; fact ++) {
		while (((a % fact) == 0) && ((b % fact) == 0)) {
			gcd = gcd * fact;
			b = b / fact;
			a = a / fact;
			if (a == 0 || b == 0) 
				return gcd;
		}
	}
	return gcd;
}

int main(int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;
	
	int i;
	int a, b;

	// printf("Enter (a, b): ");
	// scanf("%d%d", &a, &b);

	// int g = gcd(a, b);
	// printf("GCD = %d\n", g);

	FILE *input;
	input = fopen("inputcoprime.csv", "r");

	FILE *output;
	output = fopen("GCDMiddleSchool.csv", "w+");
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

	return 0;

}
