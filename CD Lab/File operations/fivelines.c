// Print five lines of a file at a time

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

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

	int lno = 1;
	int lc;
	char lineBuffer[1024];

	char ch;
	do {
		printf("\n ----- \nc. Print %s5 lines\nq. Quit\nChoice: ", ((lno == 1)?"first ":"next "));
		scanf(" %c", &ch);
		if (ch != 'c') {
			printf("\n-- L8R --\n");
			exit(1);
		}
		lc = 0;
		memset(lineBuffer, '\0', 1023);
		while (lc < 5) {
			if (fscanf(file, "%[^\n]\n", lineBuffer) <= 0) {
				printf("\n-- EOF --\n");
				exit(0);
			}
			printf("%d. %s\n", lno, lineBuffer);
			lno += 1;
			lc += 1;
		}
	} while (ch == 'c');
	
}