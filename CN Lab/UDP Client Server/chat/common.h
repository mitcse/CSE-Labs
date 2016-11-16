#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#include <fcntl.h>
#include <unistd.h>

#include <string.h>

typedef enum { NO, YES } BOOL;

typedef struct sockaddr_in sockaddr_in_t;

typedef struct sockaddr sockaddr_t, *sockaddr_p_t;

typedef char* string;

#define BUFLEN 2048

#define SERVER "127.0.0.1"

#define PORT 7871