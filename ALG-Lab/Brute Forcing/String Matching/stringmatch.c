#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int bfmatch(char *str, int n) {
	const char *sub = "AAAAB"; // 5
	int i = 0, j = 0;
	while (i < n) {
		while (j < 5 && *(str + i + j) == *(sub + j)) {
			j++;
		}
		if (j == 5)
			return i;
		else
			j = 0;
		i++;
	}
	return -1;
}

int main(int argc, const char * argv []) {
	clock_t start_time, end_time;
	double total_time;\

	int i, j;

	FILE *output;
	output = fopen("stringmatch.csv", "w+");
	fprintf(output, "inputsize, time\n");


	for (j = 10; j <= 1000; j += 10) {

		char *str = (char *)malloc(j * sizeof(char));
		for (i = 0; i < j; ++i) {
			*(str + i) = 'A';
		}

		start_time = clock();

		for (i = 0; i < 1000; ++i) {
			bfmatch(str, j);
		}

		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

		fprintf(output, "%d, %lf\n", j, total_time);
	}

}