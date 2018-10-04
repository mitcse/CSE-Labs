#include <stdio.h>
#include <stdlib.h>

int g[100][100];

int V;

int visited[100];

void dfsv (int v) {
	printf("Visiting %d\n", v);
	visited[v] = 1;
	int i;
	for (i = 0; i < V; ++i) {
		if (!(visited[i]) && (g[v][i] == 1) && (i != v)) {
			dfsv(i);
		}
	}
}

void dfs () {
	int i;
	for (i = 0; i < V; ++i) {
		if (!visited[i]) {
			dfsv(i);
		}
	}
}

int main (int argc, const char * argv []) {
	printf("Enter no of vertices: ");
	scanf(" %d", &V);
	int i, j;
	printf("Enter adj matrix: ");
	for (i = 0; i < V; ++i) {
		for (j = 0; j < V; ++j) {
			scanf(" %d", &g[i][j]);
		}
	}
	dfs();
	return 0;
}

/**
*	Sample input:
*
*	12
*	0 1 0 0 1 0 0 0 0 0 0 0
*	1 0 1 0 0 1 1 0 0 0 0 0
*	1 0 0 1 0 0 1 0 0 0 0 0
*	0 0 1 0 0 0 0 1 0 0 0 0
*	1 0 0 0 0 1 0 0 1 0 0 0
*	0 1 1 0 1 0 1 0 0 1 0 0
*	0 0 1 0 0 1 0 1 0 0 1 0
*	0 0 0 1 0 0 1 0 0 0 0 1
*	0 0 0 0 1 0 0 0 0 1 0 0
*	0 0 0 0 0 1 0 0 1 0 1 0
*	0 0 0 0 0 0 1 0 0 1 0 1
*	0 0 0 0 0 0 0 1 0 0 1 0
*
*	Sample output:
*
*	Visiting 0
*	Visiting 1
*	Visiting 2
*	Visiting 3
*	Visiting 7
*	Visiting 6
*	Visiting 5
*	Visiting 4
*	Visiting 8
*	Visiting 9
*	Visiting 10
*	Visiting 11
*
*/