#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_FILE "FIFO_FILE"

#define BUFFER_SIZE PIPE_BUF // PIPE_BUF = 64KB
#define PROD_SIZE 16777216 // 16KB
