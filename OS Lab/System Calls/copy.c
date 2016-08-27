#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	char sname[100], dname[100];
	printf("Enter file name to copy: ");
	scanf(" %s", sname);
	printf("Enter new file name: ");
	scanf(" %s", dname);

	int src = open(sname, O_RDONLY);
	int dst = open(dname, O_WRONLY | O_CREAT , 0641);
	
	int n;
	char buffer;

	while (n = read(src, &buffer, 1) > 0) {
		write(dst, &buffer, 1);
	}

	close(src);
	close(dst);

	return 0;
}