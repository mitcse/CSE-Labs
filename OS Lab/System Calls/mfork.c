#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t pids[10];
int count = 0;

void forkThatProcess (int i) {

	if (i == 10)
		return;

	if ((pids[count++] = fork()) == 0) {

		printf("Child [%d], Parent [%d]\n", getpid(), getppid());

		// sleep(1);

		forkThatProcess(i+1);

		exit(i);

	} else {

		int x;
		wait(&x);
		x = x >> 8;

		printf("Parent [%d], return status = %d\n", getpid(), x);

	}

}

int main (int argc, const char * argv []) {

	forkThatProcess(0);

}