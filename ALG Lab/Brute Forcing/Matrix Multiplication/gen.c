#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv []) {

	FILE *outfile = fopen("matrices.txt", "w+");

	int i, j, k;

	for (k = 2; k < 16; ++k) {

		fprintf(outfile, "%d\n", k);

		for (i = 0; i < k; ++i) {
			for (j = 0; j < k; ++j) {
				fprintf(outfile, "%d ", rand() % 20 + 1);
			}
			fprintf(outfile, "\n");
			for (j = 0; j < k; ++j) {
				fprintf(outfile, "%d ", rand() % 20 + 1);
			}
			fprintf(outfile, "\n");
		}

	}

	fclose(outfile);

}