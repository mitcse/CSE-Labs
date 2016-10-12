#include <stdio.h>
#include <stdlib.h>

typedef enum { NO, YES } BOOL;

int ALLOC[10][10];	// Allocated matrix
int MAX[10][10];	// Max needed
int NEED[10][10];	// Need matrix
int AVAIL[10];		// Availibility matrix
int TOTAL[10];		// Total system resources

BOOL VISITED[10];

int m;	// m = number of resources
int n;	// n = number of processes

int i, j;

void printmat (int mat[10][10], int m, int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		printf("P%d |", i);
		for (j = 0; j < m; ++j) {
			printf("  %d", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void init () {
	printf("Enter the number of processes (< 10): ");
	scanf(" %d", &n);
	printf("Enter the number of resources (< 10): ");
	scanf(" %d", &m);

	printf("Enter available resources: ");
	for (i = 0; i < m; ++i) {
		scanf(" %d", &AVAIL[i]);
		TOTAL[i] = AVAIL[i];
	}

	for (i = 0; i < n; ++i) {
		printf("Enter allocation for process %d: ", i);
		for (j = 0; j < m; ++j) {
			scanf(" %d", &ALLOC[i][j]);
			TOTAL[j] += ALLOC[i][j];
		}
		printf("Enter max for process %d: ", i);
		for (j = 0; j < m; ++j) {
			scanf(" %d", &MAX[i][j]);
			NEED[i][j] = MAX[i][j] - ALLOC[i][j];
		}
	}

	printf("\n\nTOTAL SYSTEM RESOURCES: \n");
	for (i = 0; i < m; ++i)
		printf("  %d", TOTAL[i]);

	printf("\n\nAVAILABLE SYSTEM RESOURCES: \n");
	for (i = 0; i < m; ++i)
		printf("  %d", AVAIL[i]);

	printf("\n\nALLOCATION: \n");
	printmat(ALLOC, m, n);

	printf("MAX: \n");
	printmat(MAX, m, n);

	printf("NEED (MAX - ALLOC): \n");
	printmat(NEED, m, n);

}

BOOL checkAllDone () {
	int i;
	for (i = 0; i < n; ++i) {
		if (VISITED[i] == NO)
			return NO;
	}
	return YES;
}

int findProcessToExeggute () {
	for (i = 0; i < n; ++i) {
		BOOL canDo = YES;
		for (j = 0; j < m; ++j) {
			if ((AVAIL[j] - NEED[i][j]) < 0) {
				canDo = NO;
				break;
			}
		}
		if (canDo) {
			if (!VISITED[i]) {
				return i;
			}
		}
	}
	return -1;
}

void exegguteProcess (int pid) {
	for (i = 0; i < m; ++i) {
		AVAIL[i] += ALLOC[pid][i];
	}
	VISITED[pid] = YES;
}

void exegguteBankers () {

	int exeggcount = 0;
	int pid;

	do {

		if ((pid = findProcessToExeggute()) != -1) {
			exegguteProcess(pid);
			exeggcount += 1;
		}

		if (exeggcount == n) {
			printf("ALL PROCESSES EXEGGUTED! DEADLOCK FREE!");
			break;
		}

	} while (!checkAllDone());

	if (exeggcount != n) {
		printf("NOT ALL PROCESSES EXEGGUTED; DEADLOCKED!\n");
		printf("Deadlocked processes: ");
		for (i = 0; i < n; ++i) {
			if (!VISITED[i])
				printf("P%d ", i);
		}
	}

}


int main (int argc, char const * argv []) {

	/* SAMPLE INPUT
	5
	3
	3 3 2
	0 1 0
	7 5 3
	2 0 0
	3 2 2
	3 0 2
	9 0 2
	2 1 1
	2 2 2
	0 0 2
	4 3 3

	*/

	init();

	exegguteBankers();

	printf("\n\n");

	return 0;
}

