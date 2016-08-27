#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child process created: %d!\n", pid);
		sleep(2);
	} else {
		printf("Parent process here: %d.\n", pid);
	}
	return 0;
}