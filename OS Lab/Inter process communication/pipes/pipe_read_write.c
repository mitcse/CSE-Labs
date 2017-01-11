#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

int main (int argc, char const * argv[]) {

	int pipe_fds[2];
	int read_fd;
	int write_fd;

	pipe(pipe_fds);
	read_fd = pipe_fds[0];
	write_fd = pipe_fds[1];

	pid_t pid;

	if ((pid = fork()) == 0) {

		// Child, read here

		close(write_fd); // Close write

		dup2(read_fd, STDIN_FILENO); // Connect read of pipe to standard input

		execlp("sort", "sort", 0); // Replace current child with 'sort'

	} else {

		// Parent, write here

		close(read_fd); // Close read

		FILE *stream = fdopen(write_fd, "w"); // Get write stream (Convert the write file descriptor to a FILE object, and write to it)

		fprintf(stream, "Explicit is better than implicit.\n");
		fprintf(stream, "Complex is better than complicated.\n");
		fprintf(stream, "Sparse is better than dense.\n");
		fprintf(stream, "Errors should never pass silently.\n");
		fprintf(stream, "Now is better than never.\n");
		fprintf(stream, "Special cases aren't special enough to break the rules.\n");
		fflush(stream);

		close(write_fd); // Close write stream

		waitpid(pid, NULL, 0); // Wait for child

	}

	return 0;
}