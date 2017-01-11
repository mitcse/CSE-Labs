// Get the size of a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, const char * argv []) {

	printf("Files in the directory: \n");
	system("ls -l");

	char fname[100];
	printf("Enter a filename: ");
	scanf(" %s", fname);

	FILE *file = fopen(fname, "r");
	if (file == NULL) {
		printf("Invalid file name!\n");
		return 9;
	}
	fseek(file, 0, SEEK_END);
	size_t flen = ftell(file);

	printf("Size of '%s' = %liB\n", fname, flen);

}