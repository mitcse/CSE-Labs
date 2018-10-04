#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv []) {

	FILE *output;
	output = fopen("strings.txt", "w+");

	int size = 10;
	int i, j;

	for (i = 0; i < 100; ++i, size += 15) {
		fprintf(output, "%d ", size);
		for (j = 0; j < size; ++j) {
			fprintf(output, "A");
		}
		fprintf(output, "\n");
	}

	fclose(output);

}