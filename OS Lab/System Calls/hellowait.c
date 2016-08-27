#include <stdio.h>

int main(int argc, char const *argv[]) {
	char *hello = "Hello world!!";
	int i;
	for (i = 0; i < 12; ++i) {
		printf("%c", hello[i]);
		wait(1);
	}
	printf("\n");
	return 0;
}