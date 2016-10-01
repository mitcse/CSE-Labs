#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

#define SIZE 128

typedef struct message {
    long mtype;
    char c[SIZE];
} MESSAGE_t;