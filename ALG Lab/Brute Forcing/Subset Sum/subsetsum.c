#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX 20

int N;

typedef enum { NO, YES } BOOL;

int arr[MAX];

BOOL checkSum (BOOL curr[N]) {

	int lsum = 0;
	int rsum = 0;

	int i;

	for (i = 0; i < N; ++i) {
		if (curr[i]) {
			lsum += arr[i];
		} else {
			rsum += arr[i];
		}
	}

	return (lsum == rsum);

}

// Generate all the partitions of the set...

void partitons (BOOL curr[N], int k, int n) {

	int i, j;

	int ic = 0, ec = 0;
	for (i = 0; i < n; ++i) {
		if (curr[i]) ic += 1;
		else ec += 1;
	}

	// Only print the last decent
	if (k == n-1) {

		if (ic > 0 && ec > 0) {

			if (checkSum(curr)) {

				for (i = 0; i < n; ++i) {
					if (curr[i])
						printf("%d ", arr[i]);
				}
				printf("  ---------   ");
				for (i = 0; i < n; ++i) {
					if (!curr[i])
						printf("%d ", arr[i]);
				}
				printf("\n");

			}

		}

		return;
	}

	BOOL incl[N];
	BOOL excl[N];
	for (i = 0; i < N; ++i) {
		incl[i] = curr[i];
		excl[i] = curr[i];
	}
	incl[k] = YES;
	excl[k] = NO;

	// Recurse by including current and one by excluding current.
	partitons(incl, k+1, n);
	partitons(excl, k+1, n);
}

int main (int argc, char const * argv []) {
	printf("Enter the number of numbers: ");
	scanf(" %d", &N);
	printf("Enter the numbers: ");
	int i;
	BOOL curr[MAX];
	for (i = 0; i < N; ++i) {
		curr[i] = NO;
		scanf(" %d", &arr[i]);
	}
	printf("\nPartitions with equal sum:\n");
	partitons(curr, 0, N);
	return 0;
}