#include <stdio.h>
#include <stdlib.h>

int g[100][100];

int V;

int visited[100];

int queue[100], f = 0, r = 0;

void enqueue (int v) {
	queue[r++] = v;
}

int dequeue () {
	if (f == r) return -1;
	return queue[f++];
}

void bfsv (int v) {
	printf("Visiting %d\n", v);
	visited[v] = 1;
	int i;
	for (i = 0; i < V; ++i) {
		if (!visited[i] && g[v][i] && i != v) {
			enqueue(i);
		}
	}
}

void bfs () {
	int i, x;
	enqueue(0);
	do {
		x = dequeue();
		if (x != -1 && !visited[x]) {
			bfsv(x);
		}
	} while (x != -1);
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
	bfs();
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
*	Visiting 4
*	Visiting 2
*	Visiting 5
*	Visiting 6
*	Visiting 8
*	Visiting 3
*	Visiting 9
*	Visiting 7
*	Visiting 10
*	Visiting 11
*
*/