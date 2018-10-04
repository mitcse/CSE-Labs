#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) (A > B) ? A : B

int F[10][10];

int W; // Knapsack capacity
int n; // Number of items

int weights[10];
int values[10];

int i, j, k;

void input () {
	printf("Enter knapsack capacity: ");
	scanf(" %d", &W);
	printf("Enter number of items: ");
	scanf(" %d", &n);
	for (i = 1; i < n + 1; ++i) {
		printf("Item [%d]; Enter weight: ", i);
		scanf(" %d", &weights[i]);
		printf("Item [%d]; Enter value: ", i);
		scanf(" %d", &values[i]);
	}
}

void printshit () {
	printf("\nItem\t|\tWeight\t|\tValue\n");
	for (i = 1; i < n+1; ++i) {
		printf("%d\t|\t%d\t|\t%d\n", i, weights[i], values[i]);
	}
	printf("-------------------------------\n");
	printf("\t\t\t\tCapacity j -> \n");
	printf("\t\t\ti | ");
	for (j = 0; j < W+1; ++j)
		printf("%d\t", j);
	printf("\n");
	for (i = 0; i < n+1; ++i) {
		if (i != 0)
			printf("  w[%d]=%d, v[%d]=%d;\t%d | ", i, weights[i], i, values[i], i);
		else
			printf("\t\t\t%d | ", i);
		for (j = 0; j < W+1; ++j) {
			printf("%d\t", F[i][j]);
		}
		printf("\n");
	}
	printf("\nMaximum value you can fit in knapsack = %d\n", F[n][W]);
}

void exeggute_knapsack () {
	for (j = 0; j < W+1; ++j) {
		F[0][j] = 0;
	}
	for (i = 0; i < n+1; ++i) {
		F[i][0] = 0;
	}
	F[1][1] = 0;
	for (j = 1; j < W+1; ++j) {
		for (i = 1; i < n+1; ++i) {
			if (j - weights[i] >= 0)
				F[i][j] = MAX(F[i-1][j], values[i] + F[i-1][j-weights[i]]);
			else
				F[i][j] = F[i-1][j];
		}
	}
}

int main (int argc, char const * argv []) {
	input();
	exeggute_knapsack();
	printshit();
	return 0;
}

/**
	* Sample Input * (Page 294 of Anany Levitin, 3rd edition)
	5
	4
	2
	12
	1
	10
	3
	20
	2
	15

	* Sample Output *

	Item |	Weight	|	Value
	1	 |	2		|	12
	2	 |	1		|	10
	3	 |	3		|	20
	4	 |	2		|	15

							Capacity j -> 
					i | 0	1	2	3	4	5	
					0 | 0	0	0	0	0	0	
  w[1]=2, v[1]=12;	1 | 0	0	12	12	12	12	
  w[2]=1, v[2]=10;	2 | 0	10	12	22	22	22	
  w[3]=3, v[3]=20;	3 | 0	10	12	22	30	32	
  w[4]=2, v[4]=15;	4 | 0	10	15	25	30	37	


*/