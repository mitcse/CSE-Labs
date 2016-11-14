/*
 *	Compilation note:
 *	Need to be linked with pthread library
 *	gcc prod_cons_semaphores.c -o prod_cons_semaphores.o -pthread
*/

#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

pthread_t philosophers[10];
pthread_mutex_t chopsticks[10];

int n;

void * thinkEatRepeat (int *ii) {

	int i = *ii;

	printf("[%d] Thinking...\n", i);

	pthread_mutex_lock(&chopsticks[i]);
	pthread_mutex_lock(&chopsticks[(i + 1) % n]);

	printf("[%d] Eating...\n", i);
	sleep(3);

	pthread_mutex_unlock(&chopsticks[i]);
	pthread_mutex_unlock(&chopsticks[(i + 1) % n]);

	printf("[%d] Finished Eating\n", i);

	return NULL;

}

int main (int argc, const char *argv[]) {
	
	printf("Enter number of philosophers (2-10): ");
	scanf(" %d", &n);

	int i;

	for (i = 0; i < n; ++i) {
		pthread_mutex_init(&chopsticks[i], NULL);
	}

	for (i = 0; i < n; ++i) {
		pthread_create(&philosophers[i], NULL, (void *)thinkEatRepeat, &i);
	}

	for (i = 0; i < n; ++i) {
		pthread_join(philosophers[i], NULL);
	}

	for (i = 0; i < n; ++i) {
		pthread_mutex_destroy(&chopsticks[i]);
	}

	return 0;

}