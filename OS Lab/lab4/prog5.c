#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
    printf("Parent process\n");
    int pid = fork();
    if(pid == -1)
        printf("Error\n");
    else if (pid == 0)
    {
        printf("Parent ID:%d\n", getppid);
        printf("Child ID:%d\n", getpid());
        printf("Child process\n");
        printf("Child process completed\n");
        exit(0);
    }
    else
    {
        sleep(5);
        printf("Child created\n");
        while(1);
    }
    return 0;
}
