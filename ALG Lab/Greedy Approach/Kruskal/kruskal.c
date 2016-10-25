#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999

#define MIN(A, B) (A < B) ? A : B

typedef enum { NO, YES } BOOL;

typedef struct Edge {
	int src;
	int dst;
	int wt;
} edge_t, *edge_p_t;

edge_p_t initEdge (int src, int dst, int wt) {
	edge_p_t edge = (edge_p_t)malloc(sizeof(edge_t));
	edge->src = src;
	edge->dst = dst;
	edge->wt = wt;
	return edge;
}

typedef struct Graph {
	int V;
	int E;
	edge_p_t *edges;
} graph_t, *graph_p_t;

graph_p_t G;
int ec;

int i, j;

void initGraph (int V, int E) {
	G = (graph_p_t)malloc(sizeof(graph_t));
	G->V = V;
	G->E = E;
	ec = 0;
	G->edges = (edge_p_t *)calloc(E, sizeof(edge_p_t));
}

void addEdge (int src, int dst, int wt) {
	if (wt == 0) return;
	edge_p_t edge = initEdge(src, dst, wt);
	G->edges[ec++] = edge;
}

void inputGraph () {
	int e, v;
	printf("Enter the number of vertices: ");
	scanf(" %d", &v);
	printf("Enter the number of edges: ");
	scanf(" %d", &e);
	initGraph(v, e);
	int s, d, w, ch = 0;
	do {
		printf("Enter edge details (Src, Dst, Wt): ");
		scanf(" %d %d %d", &s, &d, &w);
		addEdge(s-1, d-1, w);
		ch++;
	} while (ch < e);
}

void printGraph () {
	printf("Graph:\t SRC\t DST\t WT\n");
	for (i = 0; i < G->E; ++i) {
		edge_p_t e = G->edges[i];
		printf("\t%4d\t%4d\t%4d\n", e->src + 1, e->dst + 1, e->wt);
	}
	printf("\n");
}

void sortEdges () {
	for (i = 0; i < G->E; ++i) {
		for (j = 0; j < G->E - 1 - i; ++j) {
			edge_p_t A = G->edges[j];
			edge_p_t B = G->edges[j+1];
			if (A->wt > B->wt) {
				edge_p_t C = A;
				G->edges[j] = B;
				G->edges[j+1] = C;
			}
		} 
	}
}

typedef struct Set {
	
}

int main (int argc, char const * argv[]) {
	inputGraph();
	sortEdges();
	printGraph();
	return 0;
}


/**
6 
10
1 2 3
1 5 6
1 6 5
2 3 1
2 6 4
3 4 6
3 6 4
4 5 8
4 6 5
5 6 2

*/