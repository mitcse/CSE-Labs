#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	
	printf("Files list: \n");
	system("ls -A1");

	char src[64], dst[64];

	printf("Enter source name: ");
	scanf(" %s", src);

	printf("Enter dest name: ");
	scanf(" %s", dst);

	int sfd = open(src, O_RDONLY);
	int dfd = open(dst, O_WRONLY | O_CREAT, 0640);

	char buffer[1];
	while ((read(sfd, buffer, 1)) > 0) {
		write(dfd, buffer, 1);
	}

	return 0;

}