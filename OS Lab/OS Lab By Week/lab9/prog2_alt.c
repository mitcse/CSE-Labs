#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *intdup(int const * src, size_t len)
{
   int *p = (int *)malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}

int is_possible(int *work, int *need, int n_resources) {
	int i;
	for(i = 0; i<n_resources; i++) {
		if(need[i] > work[i]) {
			return 0;
		}
	}
	return 1;
}

int check_deadlock(int **allocation, int *work, int **need, int n_processes, int n_resources) {
	int finish[n_processes];
	int i, j, k;
	for(i = 0; i<n_processes; i++)
		finish[i] = 0;

	printf("\nNew need matrix - \n");
	for(i = 0; i<n_processes; i++) {
		for(j = 0; j<n_resources; j++) {
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");

	int flag = 1;
	while(flag) {
		flag = 0;
		for(i = 0; i<n_processes; i++) {
			if(finish[i] == 0 && is_possible(work, need[i], n_resources)) {
				printf("Process executed: %d\n", i);
				finish[i] = 1;
				flag = 1;
				printf("New number of resources: ");
				for(j = 0; j<n_resources; j++) {
					work[j] = work[j] + allocation[i][j];
					printf("%d ", work[j]);
				}
				printf("\n");
				break;
			}
		}
	}
	for(i = 0; i<n_processes; i++) {
		if(finish[i] == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n_processes, n_resources;
	printf("Number of processes: ");
	scanf("%d", &n_processes);
	printf("Number of resources: ");
	scanf("%d", &n_resources);
	int **allocation;
	int **max;
	int **need;
	int i, j;
	allocation = (int **)malloc(n_processes * sizeof(int *));
	need = (int **)malloc(n_processes * sizeof(int *));
	max = (int **)malloc(n_processes * sizeof(int *));
	for(i = 0; i<n_processes; i++) {
		allocation[i] = (int *)malloc(sizeof(int) * n_resources);
		need[i] = (int *)malloc(sizeof(int) * n_resources);
		max[i] = (int *)malloc(sizeof(int) * n_resources);
	}
	for(i = 0; i<n_processes; i++) {
		printf("Details for p%d-\n", i);
		printf("Allocation: ");
		for(j = 0; j<n_resources; j++) {
			scanf("%d", &allocation[i][j]);
		}
		printf("Max: ");
		for(j = 0; j<n_resources; j++) {
			scanf("%d", &max[i][j]);
		}
	}
	int available[n_resources];
	printf("Enter available: ");
	for(j = 0; j<n_resources; j++) {
		scanf("%d", &available[j]);
	}


	printf("\nNeed matrix - \n");
	for(i = 0; i<n_processes; i++) {
		for(j = 0; j<n_resources; j++) {
			need[i][j] = max[i][j] - allocation[i][j];
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Enter process id: ");
	int p_id;
	scanf("%d", &p_id);
	int req[n_resources];
	printf("Enter request for %d: ", p_id);
	for(i = 0; i<n_resources; i++) {
		scanf("%d", &req[i]);
	}
	int flag = 0;
	for(i = 0; i<n_resources; i++) {
		if(req[i]>available[i])
			flag = 1;
	}

	if(flag) {
		printf("Requesting more than available.\n");
	}
	else {
		for(i = 0; i<n_resources; i++) {
			available[i] -= req[i];
		}
		for(j = 0; j<n_resources; j++) {
			need[p_id][j] -= req[j];
		}
		int *work = intdup(available, n_resources);
		printf("Resources left: ");
		for(i = 0; i<n_resources; i++) {
			printf("%d ", work[i]);
		}

		int res = check_deadlock(allocation, work, need, n_processes, n_resources);
		if(res == 1) {
			printf("Safe state.");
		}
		else {
			printf("Unsafe state.\n");
		}
	}

}
