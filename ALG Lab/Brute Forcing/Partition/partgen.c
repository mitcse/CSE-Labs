#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv []) {
	FILE *output;
	output = fopen("numbers.txt", "w+");
	int size = 10;
	int i, j;
	for (i = 0; i < 100; ++i, size += 10) {
		fprintf(output, "%d ", size);
		int r = rand() % 1000;
		int inc = rand() % 20;
		for (j = 0; j < size; ++j, r += inc) {
			fprintf(output, "%d ", r);
		}
		fprintf(output, "\n");
	}

}