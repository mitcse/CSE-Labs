#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 4096

int main (int argc, char const * argv []) {

	/**
		int shmget(key_t key, size_t size, int shmflag) -> used to obtain access to a part of shared memory
		key = semaphore ID
		size = size to be allocated
		shmflag = initial access permissions and control creation flags
	*/

	int segment_id = shmget(IPC_PRIVATE, MAX_SIZE, S_IRUSR | S_IWUSR);

	/**
		void * shmat(int shmid, const void *shmaddr, int shmflg);
		Attaches the shared memory segment associated with the shared memory identifier specified 
		by shmid to the address space of the calling process.
	*/

	char *shared_memory = (char *) shmat(segment_id, NULL, 0);

	sprintf(shared_memory, "IPC using shared memory");

	pid_t pid = fork();
	if (pid == 0) {

		// Display shared memory in child
		printf("[CHILD] Shared memory = ");
		puts(shared_memory);

		// Take input into shared memory in child
		printf("Enter some stuff to put in shared memory: \n");
		fgets(shared_memory, MAX_SIZE, stdin);

		/**
			int shmdt(const void *shmaddr);
			Detaches the shared memory segment located at the address specified by shmaddr from
			the address space of the calling process.
		*/
		shmdt(shared_memory);

	} else {

		// Wait till child's done exegguting, then print the shared memory contents.
		wait(&pid);
		printf("[PARENT] Shared memory = ");
		puts(shared_memory);

		shmdt(shared_memory);
	}

	/**
		int shmctl(int shmid, int cmd, struct shmid_ds *buf);
		Used to alter permissions and other properties of the shared memory space defined by shmid
	*/

	shmctl(segment_id, IPC_RMID, NULL);

	return 0;
}
