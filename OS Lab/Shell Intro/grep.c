#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main (int argc, char const * argv []) {
	FILE *fp;
	char fline[100];
	char *newline;
	int i, count = 0, occ = 0;
	if (argc < 3) {
		printf("Not enough command line parameters given!\n");
		return 3;
	} 
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File could not be opened, found or whatever, errno is %d\n",errno);
		return 3;
	}
	while (fgets(fline, 100, fp) != NULL) {
		count++;
		if (newline = strchr(fline, '\n'))
			*newline = '\0';
		if (strstr(fline, argv[2]) != NULL) {
			printf("%s %d %s\n", argv[1], count, fline);
			occ++;
		}
	}
	printf("\n\tOccurence= %d\n", occ);

	return 1;
}