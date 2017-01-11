// Count of number of lines and characters in a file

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main (int argc, const char * argv []) {

	printf("Files in the directory: \n");
	system("ls -l");

	char fname[100];
	printf("Enter a filename: ");
	scanf(" %s", fname);

	int fd = open(fname, O_RDONLY);

	int cc = 0;
	int wc = 0;
	int lc = 1;

	char buffer[1];
	while (read(fd, buffer, 1) > 0) {
		char z = *buffer;
		if (z == '\n') {
			lc += 1;
			wc += 1;
		} else if (z == ' ') {
			wc += 1;
			cc += 1;
		} else {
			cc += 1;
		}
	}

	printf("Lines: %d, Words: %d, Characters: %d\n", lc, wc, cc);

	return 0;

}