// by arijeet

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include <limits.h>

#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG (1024 * 1024 * 10)

int main()
{
  int pipe_fd;
  int res;
  int open_mode = O_WRONLY;
  int bytes_sent = 0;
  char buffer[BUFFER_SIZE + 1];
  if (access(FIFO_NAME, F_OK) == -1) 
  {
    res = mkfifo(FIFO_NAME, 0777);
    if (res != 0) 
    {
      fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
      exit(EXIT_FAILURE);
    }
  }
  printf("Process %d opening FIFO O_WRONLY\n", getpid());
  pipe_fd = open(FIFO_NAME, open_mode);
  printf("Process %d result %d\n", getpid(), pipe_fd);
  if (pipe_fd != -1) 
  {
    while(bytes_sent < TEN_MEG) 
    {
      res = write(pipe_fd, buffer, BUFFER_SIZE);
      if (res == -1) 
      {
        fprintf(stderr, "Write error on pipe\n");
        exit(EXIT_FAILURE);
      }
      bytes_sent += res;
    }
    (void)close(pipe_fd);
  }
  else 
  {
    exit(EXIT_FAILURE);
  }
  printf("Process %d finished\n", getpid());
  exit(EXIT_SUCCESS);
  return 0;
}
