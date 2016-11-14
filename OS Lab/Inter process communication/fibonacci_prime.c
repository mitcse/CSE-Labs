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
	int read_fd;
	int write_fd;
	pipe(fd);

	read_fd = fd[0];
	write_fd = fd[1];

	pid = fork();
	if (pid == 0) {

		close(write_fd);

		// Read from the parent
		read(read_fd, f, sizeof(f));

		// Check if they're prime in the child
		for (i = 0; i < 25; ++i) {
			if (isPrime(f[i]))
				printf(">> %d is prime.\n", f[i]);
		}

		close(read_fd);
		exit(1);

	} else {

		close(read_fd);

		// Generate fibobacci numbers in parent
		for (i = 0; i < 25; ++i) {
			fib[i] = getFibonacci(i);
		}

		// Pass data to the child
		write(write_fd, fib, sizeof(fib));

		// Wait for child to finish
		waitpid(pid, NULL, 0);

		close(write_fd);
	}
	return 0;
}
