#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
	int x = 1;
	int i;
	for (i = 0; i < 21; ++i) {
		pid_t pid = fork();
		if (pid == 0) {
			x = 0;
			printf("\n[i = %d, x = %d] Child [%d] Parent [%d]\n", i, x, getpid(), getppid());
			// sleep(1);
			exit(i);
		} else {
			wait(&x);
			printf("Parent [%d] [x = %d, return = %d]\n", getpid(), x, x/256);
		}
	}
	return 0;
}
