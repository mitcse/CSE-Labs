#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
        printf("Process id of child process is %d\n", getpid());
    printf("Parent process id is %d\n", getppid());
    return 0;
}
