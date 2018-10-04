#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	FILE *output;
	output = fopen("trees.txt", "w+");
	int i, j;
	for (i = 2; i <= 100; i += 2) {
		fprintf(output, "56 ");
		for (j = 0; j < i-2; ++j) {
			int rd;
			if (j % 2 == 0)
				rd = rand() % 50 + 40; 
			else
				rd = rand() % 50 + 10;
			fprintf(output, "%d ", rd);
		}
		fprintf(output, "-99\n");
	}
	fclose(output);
	return 0;
}