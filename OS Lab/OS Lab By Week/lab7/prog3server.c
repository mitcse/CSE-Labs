#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

struct msg
{
    long mtype;
    char c[100];
};

int main()
{
    int qt;
    struct msg m;
    qt = msgget(1271, IPC_CREAT | IPC_EXCL | 0600);
    if(qt < 0)
    { 
        perror("Error in getting message\n");
    }
    printf("Message queue created\n");
    if(msgrcv(qt, &m, sizeof(struct msg), 0, 0) < 0)
    {
        perror("Message receive error");
    }   
    printf("Message received\t%s\n", m.c);
    msgctl(qt, IPC_RMID, NULL);
    return 0;
}
