#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>

typedef enum { NO, YES } BOOL;

int getFibonacci (int n) {
	if (n == 0 || n == 1) return n;
	return getFibonacci(n-1) + getFibonacci(n-2);
}

BOOL isPrime (int n) {
	int i;
	if (n == 0 || n == 1) return NO;
	if (n == 2) return YES;
	for (i = 2; i < n/2; ++i) {
		if (n % i == 0)
			return NO;
	}
	return YES;
}

int main (int argc, const char * argv []) {
	pid_t pid;
	int i;
	int fib[25], f[25];

	int fd[2];
	pipe(fd);


	pid = fork();
	if (pid == 0) {

		close(fd[1]);

		// Read from the parent
		read(fd[0], f, sizeof(f));

		// Check if they're prime in the child
		for (i = 0; i < 25; ++i) {
			if (isPrime(f[i]))
				printf(">> %d is prime.\n", f[i]);
		}

		close(fd[0]);
		exit(1);
	} else {

		close(fd[0]);

		// Generate fibobacci numbers in parent
		for (i = 0; i < 25; ++i) {
			fib[i] = getFibonacci(i);
		}

		// Pass data to the child
		write(fd[1], fib, sizeof(fib));

		// Wait for child to finish
		wait(NULL);

		close(fd[1]);
	}
	return 0;
}
