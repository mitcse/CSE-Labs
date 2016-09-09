#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() 
{
  int fd[2];
  pipe(fd);
  if(fork()) 
  {
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);
    execlp("wc", "wc", "-l", NULL);
  } 
  else 
  {
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    execlp("who", "who", "-l", NULL);
  }
  exit(EXIT_FAILURE);
  return 0;
}
