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
    qt = msgget(1271, 0);
    if(qt < 0)
    { 
        perror("Error getting message\n");
    }
    printf("Message init\n");
    printf("Enter a message\n");
    scanf("%s", m.c);
    m.mtype = 1;
    if(msgsnd(qt, &m, sizeof(struct msg),0) < 0)
    {
        perror("Message send error\n");
    }
    printf("Message sent\n");
    return 0;
}
