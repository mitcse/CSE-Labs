#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	char *str = (char *)malloc(65536 * sizeof(char));
	printf("Enter stuff to write: \n");
	fgets(str, 65536, stdin);
	int len = strlen(str);
	int fd = open("file.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
	if (write (fd, str, len) != len)
		printf("Error writing to file\n");
	close(fd);
	return 0;
}