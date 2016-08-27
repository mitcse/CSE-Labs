#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	pid_t pid = fork();
	int status;
	if (pid == 0) {
		printf("\tIn child process...\n");
		sleep(10);
		printf("\tchild ps output:\n");
		system("ps");
		sleep(5);
		printf("\tChild quitting.\n");
		exit(0);
		return 0;
	} else {
		printf("Parent process here...\n");
		sleep(5);
		printf("parent ps output:\n");
		system("ps");
		printf("Parent quitting.\n");
	}
	return 0;
}