// 
//	hamilton.c
//	Hamilton circuit in a graph
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef enum { NO, YES } BOOL;

int V;
int g[MAX][MAX];

int path[MAX];
int pi;

BOOL existsInPath (int v) {
	int i;
	for (i = 0; i < V; ++i) {
		if (path[i] == v) return YES;
		if (path[i] == -1) break;
	}
	return NO;
}

BOOL addToPath (int v) {
	if (!existsInPath(v)) {
		path[pi++] = v;
		return YES;
	}
	return NO;
}

BOOL findHamilton () {
	addToPath(0);
	int i, v;
	do {
		int last = path[pi-1];
		BOOL addedany = NO;
		for (v = 0; v < V; ++v) {
			if (g[last][v]) {
				addedany = addedany || addToPath(v);
			}
		}
		if (!addedany)
			return NO;
	} while (pi < V);
	if (pi == V)
		path[pi++] = path[0];
	return YES;
}

int main (int argc, char const * argv []) {
	
	int i, j;
	for (i = 0; i < MAX; ++i) {
		path[i] = -1;
	}
	pi = 0;

	printf("Enter no of vertices: ");
	scanf(" %d", &V);
	
	printf("Enter adj matrix: ");
	for (i = 0; i < V; ++i) {
		for (j = 0; j < V; ++j) {
			scanf(" %d", &g[i][j]);
		}
	}

	if (findHamilton()) {
		printf("Hamilton circuit exists: ");
		for (i = 0; i < pi; ++i)
			printf("%d ", path[i]);
	} else {
		printf("Hamilton circuit does not exist.\n");
	}

	printf("\n");
 
	return 0;
}

/**
*	Sample Input:
*	5
*	0 1 0 1 0 
*	1 0 1 1 1 
*	0 1 0 0 1 
*	1 1 0 0 1 
*	0 1 1 1 0 
*	
*	Sample Output:
*	Hamilton circuit exists: 0 1 2 4 3 0 
*
*	Sample Input:
*	5
*	0 1 0 1 0 
*	1 0 1 1 1 
*	0 1 0 0 1 
*	1 1 0 0 0 
*	0 1 1 0 0 
*	
*	Sample Output:
*	Hamilton circuit does not exist.
*/