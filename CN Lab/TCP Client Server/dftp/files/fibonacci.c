#include <stdio.h>

int main (int argc, const char * argv []) {
	int a = 0;
	int b = 1;
	int c;
	printf("%d %d ", a, b);
	do {
		c = a + b;
		printf("%d ", c);
		a = b;
		b = c;
	} while (c < 1000);
	printf("\n");
}