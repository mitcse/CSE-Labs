#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	FILE *output;
	output = fopen("inputcoprime.csv", "w+");
	int a = 3;
	int b = 1;
	int c;
	int i = 0;
	while ((++i) < 100) {
		fprintf(output, "%d, %d\n", b, a);
		c = a;
		a = 2 * a - b;
		b = c;
	}
	fclose(output);
	return 0;
}