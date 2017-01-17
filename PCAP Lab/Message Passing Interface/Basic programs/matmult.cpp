// Multiply two matrices normally, (Only for the lap purposes.)

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char *argv []) {

	int a[10][10];
	int b[10][10];
	int c[10][10];

	int r1, c1, r2, c2;
	int i, j, k;

	// Load from file (needs to be in the to be executed folder)

	FILE *input = fopen("inp.txt", "r");
	fscanf(input, "%d %d", &r1, &c1);\
	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c1; ++j) {
			fscanf(input, "%d ", &a[i][j]);
		}
	}
	fscanf(input, "%d %d", &r2, &c2);
	for (i = 0; i < r2; ++i) {
		for (j = 0; j < c2; ++j) {
			fscanf(input, "%d ", &b[i][j]);
		}
	}

	printf("\nA x B = \n");
	for (i = 0; i < r1; ++i) {
		for (j = 0; j < c2; ++j) {
			c[i][j] = 0;
			for (k = 0; k < c1; ++k) {
				c[i][j] += a[i][k] + b[k][j]; 
			}
			printf("\t%d", c[i][j]);
		}
		printf("\n");
	}

}