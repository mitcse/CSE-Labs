// Copy contents of one file into another

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, const char * argv []) {

	printf("Files in the directory: \n");
	system("ls -l");

	char src[100], dst[100];

	printf("Enter source name: ");
	scanf(" %s", src);

	printf("Enter dest name: ");
	scanf(" %s", dst);

	int sfd = open(src, O_RDONLY);
	int dfd = open(dst, O_WRONLY | O_CREAT, 0640);

	char buffer[1];
	while (read(sfd, buffer, 1) > 0) {
		write(dfd, buffer, 1);
	}

	return 0;

}