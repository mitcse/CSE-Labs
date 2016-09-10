//
//  mqpriority.c
//  Simulation of multiple queue priority based scheduling algorithm (non queue implementation, caused too much work in C :p)
//
//  Created by Avikant Saini on 9/10/16.
//


#include <stdio.h>
#include <stdlib.h>

typedef enum { NO, YES } BOOL;

typedef struct data {
	int id;		// process id
	int at;		// arrival time
	int bt;		// burst time
	int wt;		// wait time
	int tat;	// turnaround time
	int pr;		// priority
	int su;	// system process or user process
} DATA_t, *DATA_p_t;

double awt, atat; // Average wait time and average turnaround time
int n;

DATA_p_t *datas;

void inputData () {
	printf("Enter the number of processes: ");
	scanf(" %d", &n);
	int i;
	datas = (DATA_p_t *)calloc(n, sizeof(DATA_p_t));
	for (i = 0; i < n; ++i) {
		*(datas + i) = (DATA_p_t)malloc(sizeof(DATA_t));
		DATA_p_t data = *(datas + i);
		data->id = i;
		printf("Process [%d] Enter arrival time: ", i+1);
		scanf(" %d", &data->at);
		printf("Process [%d]   Enter burst time: ", i+1);
		scanf(" %d", &data->bt);
		printf("Process [%d]     Enter priority: ", i+1);
		scanf(" %d", &data->pr);
		printf("Process [%d]  System/User (0/1): ", i+1);
		scanf(" %d", &data->su);
		data->wt = 0;
		data->tat = 0;
	}
}

// Sort process wrt system and user processes, then priorities (higher is better); clashes resolved using FCFS
void sort () {
	int i;
	for (i = 1; i < n; ++i) {
		int j = i - 1;
		DATA_p_t temp = datas[i];
		while (j >= 0 && datas[j]->pr < temp->pr) { // priority sort first
			datas[j+1] = datas[j];
			j--;
		}
		datas[j+1] = temp;
	}
	for (i = 1; i < n; ++i) {
		int j = i - 1;
		DATA_p_t temp = datas[i];
		while (j >= 0 && datas[j]->su > temp->su) { // system user sort after that
			datas[j+1] = datas[j];
			j--;
		}
		datas[j+1] = temp;
	}
}

// First come first serve based calculation
void calculate () {
	int i;
	(*datas)->wt = 0;
	atat = (*datas)->tat = (*datas)->bt;
	int btt = (*datas)->bt;
	for (i = 1; i < n; ++i) {
		DATA_p_t datai = *(datas + i);
		datai->wt = btt - datai->at;
		btt += datai->bt;
		awt += datai->wt;
		datai->tat = datai->wt + datai->bt;
		atat += datai->tat;
	}
	atat /= n;
	awt /= n;
}

void display () {
	int i;
	printf("\n ID\t| SU\t| PR\t| AT\t| BT\t| WT\t| TAT\n");
	for (i = 0; i < n; ++i) {
		DATA_p_t data = *(datas + i);
		printf(" %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\n", data->id, data->su, data->pr, data->at, data->bt, data->wt, data->tat);
	}
	printf("----------------------------------------\n");
}

int main(int argc, char const *argv[]) {
	// Sample input: 5 0 5 1 0 3 6 0 0 5 6 2 0 3 2 4 1 6 3 1 1
	// Sample output: 8.20
	
	inputData();
	
	printf("\nInitially: \n");
	display();
	
	sort();
	calculate();
	
	printf("\nAfter exeggution: \n");
	display();
	
	printf("Average wait time = %.2lf\n", awt);
	printf("Average turnaround time = %.2lf\n\n", atat);
	
	return 0;
}
