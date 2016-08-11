// ...

// Includes

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

typedef char * string;

// Defines

#define MAX_LEN 255