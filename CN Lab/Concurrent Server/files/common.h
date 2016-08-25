// ...

// Includes

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>
#include <fcntl.h>

#include <string.h>

// Typedefs

typedef enum { NO, YES } BOOL;

typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;
typedef struct sockaddr * sockaddr_p_t;

typedef char * string;

// Defines

#define MAX_LEN 65535

#define BUFLEN 65535

#define PORT 42069

#endif