#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
    int segment_id;
    char *shared_memory;
    const int size = 4096;
    segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
    shared_memory = (char *) shmat(segment_id, NULL, 0);
    sprintf(shared_memory, "Inter process communication demo");
    printf("%s\n", shared_memory);
    shmdt(shared_memory);
    shmctl(segment_id, IPC_RMID, NULL);
    return 0;
}
