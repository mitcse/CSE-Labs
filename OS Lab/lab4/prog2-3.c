#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    int status;
    *argv = "./prog4";
    if (pid == 0)
    {
        printf("Attempting to run exec file of prog4\n");
        if (execvp(*argv, argv) < 0)
            exit(1);
        exit(1);
    }
    else
        while(wait(&status) != pid);
    return 0;
}
