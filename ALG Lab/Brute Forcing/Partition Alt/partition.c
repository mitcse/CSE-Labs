#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define N 10

typedef enum { NO, YES } BOOL;

int arr[N];

int i, j;

// Generate all the partitions of the set...

void partitons (BOOL curr[N], int k, int n) {

	// Check for emptiness of the partitons...

	int ic = 0, ec = 0;
	for (i = 0; i < n; ++i) {
		if (curr[i]) ic += 1;
		else ec += 1;
	}

	// Only print the last decent
	if (k == n-1) {

		if (ic > 0 && ec > 0) {

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
	BOOL curr[N];
	for (i = 0; i < N; ++i) {
		arr[i] = i + 1;
		curr[i] = NO;
	}
	partitons(curr, 0, 7);
	return 0;
}