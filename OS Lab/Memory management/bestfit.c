#include <stdio.h>

int main (int argc, const char * argv []) {
	
	// Sample input: 3 5 2 7 2 1 4
	// Sample output: Process 1 (1) allocated to block of size 2; Process 2 (4) allocated to block of size 5.


	int a[20], p[20], i, j, n, m;
	printf("Enter no of Blocks: ");
	scanf(" %d",&n);
	for (i = 0; i < n; i++) {
		printf("Enter the size of block %d: ", i);
		scanf("%d", &a[i]);
	}
	printf("Enter no of processes: ");
	scanf(" %d", &m);
	for (i = 0; i < m; i++) {
		printf("Enter the size of process %d: ", i+1);
		scanf("%d", &p[i]);
	}
	// Sort the block sizes
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n-1-i; ++j) {
			if (a[j] > a[j+1]) {
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (p[j] <= a[i]) {
				printf("Process %d (%d) allocated to block of size %d.\n", j+1, p[j], a[i]);
				p[j] = 10000;
				break;
			}
		}
	}
	printf("\n");
	for(j = 0;j < m; j++) {
		if(p[j] != 10000) {
			printf("The Process %d is not allocated\n",j);
		}
	}
}