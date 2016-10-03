#include "common.h"

int main(int argc, char const * argv []) {
	
	int pipe_fd;
	int res;

	char buffer[BUFFER_SIZE + 1];
	int bytes_read = 0;
	
	memset(buffer, '\0', sizeof(buffer));
	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, O_RDONLY);
	printf("Process %d result %d\n", getpid(), pipe_fd);

	if (pipe_fd != -1)  {
	do {
		res = read(pipe_fd, buffer, BUFFER_SIZE);
		bytes_read += res;
	} while (res > 0);
	(void)close(pipe_fd);
	}
	else 
	{
	exit(EXIT_FAILURE);
	}
	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);


	return 0;
}