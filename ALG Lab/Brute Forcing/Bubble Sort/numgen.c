#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	FILE *output;
	output = fopen("numbers.txt", "w+");
	int i, j;
	for (i = 1; i <= 1000; ++i) {
		fprintf(output, "%d ", i);
		for (j = 0; j < i; ++j) {
			int random = rand();
			fprintf(output, "%d ", random);
		}
		fprintf(output, "\n");
	}
	fclose(output);
	return 0;
}