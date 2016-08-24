#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a = 0;
	int b = 1;
	int c;

	FILE *output;
	output = fopen("inputfib.csv", "w+");
	
	do {
		c = a + b;
		fprintf(output, "%d, %d\n", a, b);
		a = b;
		b = c;
	} while (c < 100000000);
	
	fclose(output);

	return 0;
}