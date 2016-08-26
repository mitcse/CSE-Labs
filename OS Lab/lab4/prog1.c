#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
        printf("Child process created\n");
    else
        printf("Parent process\n");
    return 0;
}
