#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	pid_t pid = fork();
	int status;
	if (pid == 0) {
		printf("In child process...\n");
		printf("Parent pid = %d\n", getppid());
		printf("Child pid = %d\n", getpid());
		sleep(2);
	} else {
		while(wait(&status) != pid);
		printf("Parent process here...\n");
		printf("Parent pid = %d\n", getppid());
		printf("Child pid = %d\n", getpid());
	}
	return 0;
}