// Compare two files

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int compareFiles (char *one, char *two) {

	int sfd = open(one, O_RDONLY);
	int dfd = open(two, O_RDONLY);

	char suffer[1], duffer[1];
	while ((read(sfd, suffer, 1) > 0) && (read(dfd, duffer, 1) > 0)) {
		// printf("suffer: %s | %s :reffud\n", suffer, duffer);
		if (*suffer != *duffer) {
			return 0;
		}
	}
	if ((read(sfd, suffer, 1) == -1 || read(dfd, duffer, 1)) == -1)
		return 0;

	return 1;
}
	
int main (int argc, const char * argv []) {

	printf("Files in the directory: \n");
	system("ls -l");

	char one[100], two[100];

	printf("Enter two file names to compare: ");
	scanf(" %s", one);
	scanf(" %s", two);

	if (compareFiles(one, two)) {
		printf("Files are one and the same. Hail Hydra!\n");
	} else {
		printf("Files have some differences. Don't we all.\n");
	}

	return 0;

}