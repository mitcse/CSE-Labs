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

typedef struct thing {
	double a;
	double b;
	double r;
	char op;
} thing_t, *thing_p_t;

// Defines

#define MAX_LEN 255

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define MOD '%'

#define BUFLEN sizeof(thing_t)

#define PORT 19389

#endif