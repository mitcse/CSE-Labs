//
//  ppriority.c
//  Simulation of pre-emptive priority based scheduling algorithm
// 	Also prints the gantt chart for the glory of the sontaran empire
//
//  Created by Avikant Saini on 11/18/16.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 127

FILE *gantt;

typedef enum { NO, YES } BOOL;

typedef struct process {
	int id;		// process id
	int pr;		// priority of the process, lower is better
	int at;		// arrival time
	int bt;		// burst time
	int rt;		// remaining time
	int wt;		// wait time
	int tat;	// turnaround time
} process_t, *process_p_t;

double awt, atat; // Average wait time and average turnaround time

int n; // Curent number of process
int k; // Currently being exegguted
process_p_t *pross; // List of processes

int time;

void init () {

	gantt = fopen("gantt.txt", "w+");
	fprintf(gantt, "TIME ||   \n");
	fprintf(gantt, " - - || - - - - - - - - - - -\n");

	int i;
	pross = (process_p_t *)calloc(MAX, sizeof(process_p_t));
	for (i = 0; i < MAX; ++i) {
		*(pross + i) = (process_p_t)malloc(sizeof(process_t));
	}
}

void sort (BOOL pr) {

	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n - 1 - i; ++j) {
			process_p_t a = *(pross + j);
			process_p_t b = *(pross + j + 1);
			BOOL swap = pr ? (a->pr > b->pr) : (a->id > b->id);
			if (swap) {
				process_p_t c = a;
				*(pross + j) = b;
				*(pross + j + 1) = a;
			}
		}
	}

}

void addProcess (int at, int bt, int ppr) {
	process_p_t p = *(pross + n);
	p->id = n;
	p->at = at;
	p->bt = bt;
	p->rt = bt;
	p->pr = ppr;
	p->wt = 0;
	p->tat = 0;
	n += 1;
	sort(YES);
}

void printCurrent () {
	int i;
	printf("\nTime [%d]:\n    ID |   PR |   AT |   RT |   WT |   TAT\n", time);
	for (i = 0; i < n; ++i) {
		process_p_t p = *(pross+i);
		printf("  %3d  |  %3d |  %3d |  %3d |  %3d |  %3d\n", p->id, p->pr, p->at, p->rt, p->wt, p->tat);
	}
	printf("\n");
}

void executeOneTime () {
	
	printCurrent();

	time += 1;
	k = -1;
	int i;

	for (i = 0; i < n; ++i) {
		process_p_t p = *(pross + i);
		if (p->rt > 0) {
			k = i;
			break;
		}
	}
	if (k == -1) {
		printf("-- NO PENDING PROCESSES --\n");
		return;
	}
	
	for (i = 0; i < n; ++i) {
		process_p_t p = *(pross + i);
		if (i == k) {
			printf("Servicing process %d [AT = %d, RT = %d]\n", p->id, p->at, p->rt);
			fprintf(gantt, "%4d ||", time);
			int l;
			for (l = 0; l < n; ++l) {
				if (l == p->id)
					fprintf(gantt, " * |");
				else
					fprintf(gantt, "   |");
			}
			fprintf(gantt, "\n");
			p->rt -= 1;
			p->tat += 1;
		} else {
			if (p->rt > 0) {
				p->wt += 1;
				p->tat += 1;
			}
		}
	}

}


int main (int argc, char const *argv[]) {

	init();

	int ch;
	time = 0;

	do {

		printf("\nTime = [%.2d]; 1. Input new process(es)\n", time);
		if (time > 0)
			printf("             2. Continue exeggution\n");
		printf("             0. Exit\n");
		printf("                Choice: ");
		scanf(" %d", &ch);

		if (ch < 1 || ch > 2) {
			printf("Terminating...\n");
			break;
		}

		if (ch == 1) {

			int bbt;
			int ppr;
			char mander;
			do {
				printf("Enter priority and burst time of process entering at time = %d: ", time);
				scanf(" %d %d", &ppr, &bbt);
				addProcess(time, bbt, ppr);
				printf("Add another (y/n): ");
				scanf(" %c", &mander);
			} while (mander == 'y');

		}

		executeOneTime();

	} while (ch >= 1 && ch <= 2);
	
	awt = 0.0;
	atat = 0.0;

	fprintf(gantt, " - - || - - - - - - - - - - -\n");
	fprintf(gantt, "  ID ||");
	sort(NO);
	int i;
	printf("\nFinally:\n    ID |   PR |   AT |   BT |   WT |   TAT\n");
	for (i = 0; i < n; ++i) {
		process_p_t p = *(pross+i);
		awt += p->wt;
		atat += p->tat;
		fprintf(gantt, "%2d |", p->id);
		printf("  %3d  |  %3d |  %3d |  %3d |  %3d |  %3d\n", p->id, p->pr, p->at, p->bt, p->wt, p->tat);
	}

	printf("\n      Average wait time = %.2lf\n", awt);
	printf("Average turnaround time = %.2lf\n", atat);

	fprintf(gantt, "\n");
	fclose(gantt);
	printf("Gantt chart: \n");
	system("cat gantt.txt");
	system("rm gantt.txt"); // Yeah, it's a jugaad, snprintf wasn't working for some reason :p
	
	return 0;
}

/* 
Sample input:
1 3 5 n 2 1 1 6 n 1 2 3 n 2 2 2 2 2 2 2 2 2 2 2 2 0

Sample final output:

    ID |   PR |   AT |   BT |   WT |   TAT
    0  |    3 |    0 |    5 |    9 |   14
    1  |    1 |    2 |    6 |    0 |    6
    2  |    2 |    3 |    3 |    5 |    8

      Average wait time = 14.00
Average turnaround time = 28.00

TIME ||   
 - - || - - - - - - - - - - -
   1 || * |
   2 || * |
   3 ||   | * |
   4 ||   | * |   |
   5 ||   | * |   |
   6 ||   | * |   |
   7 ||   | * |   |
   8 ||   | * |   |
   9 ||   |   | * |
  10 ||   |   | * |
  11 ||   |   | * |
  12 || * |   |   |
  13 || * |   |   |
  14 || * |   |   |
 - - || - - - - - - - - - - -
  ID || 0 | 1 | 2 |


*/
