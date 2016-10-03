#include "common.h"

int main(int argc, char const * argv []) {
	
	int pipe_fd;
	int res;

	long bytes_sent;
	char buffer[BUFFER_SIZE + 1];

	if (access(FIFO_NAME, F_OK) == -1) {
		if ((res = mkfifo(FIFO_NAME, 777)) != 0) {
			printf("Error in creating FIFO\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("Process %d created FIFO\n", getpid());

	pipe_fd = open(FIFO_NAME, O_WRONLY);

	printf("Process %d result = %d\n", getpid(), pipe_fd);

	if (pipe_fd != -1) {

		while (bytes_sent < PROD_SIZE) {
			if ((res = write(pipe_fd, buffer, BUFFER_SIZE)) == -1) {
				printf("Error while writing on buffer [currently sent = %ld].\n", bytes_sent);
				exit(EXIT_FAILURE);
			}
			bytes_sent += res;
		}

		close(pipe_fd);

	} else {
		exit(EXIT_FAILURE);
	}

	printf("Process %d finished.\n", getpid());
	exit(EXIT_SUCCESS);

	return 0;
}