#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
	int src, dest, weight;
} edge_t, *edge_p_t;
 
typedef struct Graph {
	int V, E;
	edge_p_t edge;
} graph_t, *graph_p_t;
 
graph_p_t initGraph(int V, int E) {
	graph_p_t graph = (graph_p_t) malloc( sizeof(graph_t));
	graph->V = V;
	graph->E = E;
	graph->edge = (edge_p_t)calloc(E, sizeof(edge_t));
	return graph;
}

graph_p_t inputGraph () {
	int e, v;
	printf("Enter the number of vertices: ");
	scanf(" %d", &v);
	printf("Enter the number of edges: ");
	scanf(" %d", &e);
	graph_p_t graph = initGraph(v, e);
	int s, d, w, ch = 0;
	do {
		printf("Enter edge details (Src, Dst, Wt): ");
		scanf(" %d %d %d", &s, &d, &w);
		graph->edge[ch].src = s-1;
		graph->edge[ch].dest = d-1;
		graph->edge[ch].weight = w;
		ch++;
	} while (ch < e);
	return graph;
}

typedef struct subset {
	int parent;
	int rank;
} subset_t;

int find(subset_t subsets[], int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union (subset_t subsets[], int x, int y) {
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp (const void* a, const void* b) {
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST (graph_p_t graph) {
	int V = graph->V;
	struct Edge result[V];
	int e = 0;
	int i = 0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	subset_t *subsets =
		(subset_t*) malloc( V * sizeof(subset_t) );

 	int v;
	for (v = 0; v < V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1) {
		struct Edge next_edge = graph->edge[i++];
 
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
 
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}

	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i) {
		printf("%d - %d | %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
	}
}
 
int main() {

	graph_p_t graph = inputGraph();
 
	KruskalMST(graph);
 
	return 0;
}

/*
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