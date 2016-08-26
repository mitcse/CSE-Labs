#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> 

int main(int argc, char *argv[] )
{
    char buf;
    int src, dest, n;
    if(argc!=3)
        exit(1);
    else
    {
         src = open(argv[1], O_RDONLY);
         if(src == -1)
         {
            printf("error opening source");
            exit(0);
         }
         else
         {
            dest = open(argv[2], O_WRONLY | O_CREAT , 0641);
            if(dest == -1)
            {
                printf("error opening destination");
                exit(0);
            }
            else
            {
                while((n = read(src, &buf, 1)) != -1)
                    write(dest, &buf, 1);
                close(src);
                close(dest);
            }
        }
    }
    return 0;
}
