#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("prog6out.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
    if (write (fd, "Writing contents to file now so check it out\n", 45) != 45)
        printf("Error writing to file\n");
    return 0;
}
