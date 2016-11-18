#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, const char * argv []) {

	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0) {

		// Child...

		printf("Child [%d] here, parent [%d] alive\n", getpid(), getppid());

		sleep(5);

		printf("Child [%d] orphan now, adopted by the root process [%d]\n", getpid(), getppid());

		exit(0);

	} else {

		// Parent...

		printf("Parent [%d] here\n", getpid());

		sleep(2);

		printf("Parent dieded\n");

		exit(0);

	}

}