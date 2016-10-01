#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, const char * argv []) {

	int fd[2];
	pipe(fd);

	pid_t pid;
	pid = fork();

	if (pid == 0) {

		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execlp("/usr/bin/wc", "wc", "-l", NULL);

	} else {

		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp("/usr/bin/who", "who", "-l", NULL);

	}

	exit(-1);

}
