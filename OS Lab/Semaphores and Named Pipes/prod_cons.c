/*
 *	Compilation note:
 *	Need to be linked with pthread library
 *	gcc prod_cons_semaphores.c -o prod_cons_semaphores.o -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 16

sem_t fillCount;	// Items produced
sem_t emptyCount;	// Items remaining

pthread_t producerThreads[50], consumerThreads[50];

int buffer[BUFFER_SIZE]; // Works as a stack
int counter; // Acts as a stack top

pthread_mutex_t mutex;

void init () {
	pthread_mutex_init(&mutex, NULL);
	sem_init(&fillCount, 1, 0); // Initially empty
	sem_init(&emptyCount, 1, BUFFER_SIZE); // Initially full
	counter = 0;
}

void write (int item) {
	buffer[counter++] = item;
	// Adds the item to the buffer;
}

int read () {
	return buffer[--counter];
	// pops the last written item from the buffer;
}

void *producer (void *param) {
	
	int item;

	item = rand() % 5;

	sem_wait(&emptyCount);

	pthread_mutex_lock(&mutex);

	printf("Producer produced item = %d\n", item);
	write(item);

	pthread_mutex_unlock(&mutex);

	sem_post(&fillCount);

}

void *consumer (void *param) {

	int item;

	sem_wait(&fillCount);

	pthread_mutex_lock(&mutex);

	item = read();

	printf("Consumer consumed item = %d\n", item);

	pthread_mutex_unlock(&mutex);

	sem_post(&fillCount);

}

int main (int argc, char const * argv []) {
	
	int i;
	int nc, np;

	init();

	printf("Enter number of producers: ");
	scanf(" %d", &np);

	printf("Enter number of consumers: ");
	scanf(" %d", &nc);

	for (i = 0; i < np; ++i) {
		pthread_create(&producerThreads[i], NULL, producer, NULL);
	}

	for (i = 0; i < nc; ++i) {
		pthread_create(&consumerThreads[i], NULL, consumer, NULL);
	}

	for (i = 0; i < np; ++i) {
		pthread_join(producerThreads[i], NULL);
	}

	for (i = 0; i < nc; ++i) {
		pthread_join(consumerThreads[i], NULL);
	}

	exit(0);
	return 0;
}