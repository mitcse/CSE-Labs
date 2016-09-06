//
//  topological_sort.c
//	Topological sort in a graph
//
//  Created by Avikant Saini on 9/5/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NO, YES } BOOL;

#pragma mark - Stack utils

typedef struct stack {
	int arr[10];
	int tos;
} STACK_t, *STACK_p_t;

STACK_p_t initStack() {
	STACK_p_t stack = (STACK_p_t)malloc(sizeof(STACK_t));
	stack->tos = -1;
	return stack;
}

BOOL pushStack (STACK_p_t stack, int val) {
	if (stack->tos < 10) {
		stack->arr[++(stack->tos)] = val;
		return YES;
	}
	return NO;
}

BOOL isEmptyStack (STACK_p_t stack) {
	return (stack->tos == -1);
}

int popStack (STACK_p_t stack) {
	if (stack->tos > -1) {
		int val = stack->arr[stack->tos];
		stack->tos--;
		return val;
	}
	return -1;
}

BOOL elementInStack (STACK_p_t stack, int val) {
	if (stack->tos == -1) return NO;
	int i;
	for (i = 0; i <= stack->tos; ++i)
		if (stack->arr[i] == val)
			return YES;
	return NO;
}

#pragma mark - Graph

typedef struct Graph {
	int E; // number of edges
	int V; // number of vertices
	int mat[10][10];
} GRAPH_t, *GRAPH_p_t;

GRAPH_p_t initGraph (int V) {
	GRAPH_p_t graph = (GRAPH_p_t)malloc(sizeof(GRAPH_t));
	graph->E = 0;
	graph->V = V;
	int i, j;
	for (i = 0; i < V; ++i) {
		for (j = 0; j < 10; ++j) {
			graph->mat[i][j] = 0;
		}
	}
	return graph;
}

GRAPH_p_t inputGraph () {
	int V;
	printf("Note that graph vertices ordering starts from '1'.\n");
	printf("\tEnter number of vertices: ");
	scanf(" %d", &V);
	GRAPH_p_t graph = initGraph(V);
	int i, w;
	for (i = 0; i < V; ++i) {
		printf("Enter connected to vertex %d (0 for break): ", i+1);
		do {
			scanf(" %d", &w);
			if (w > 0) {
				graph->mat[i][w-1] = 1;
			}	
		} while (w > 0);
	}
	return graph;
}

void printGraph (GRAPH_p_t graph) {
	int i, j;
	printf("\nGraph G<%d, %d>:\n", graph->V, graph->E);
	for (i = 0; i < graph->V; ++i) {
		for (j = 0; j < graph->V; ++j) {
			printf(" %d", graph->mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

#pragma mark - Topological sort using DFS

void dfsUtil (GRAPH_p_t graph, int v, int visited[], STACK_p_t stack, BOOL *cycle) {
	visited[v] = YES;
	int j;
	for (j = 0; j < graph->V; ++j) {
		if (graph->mat[v][j]) {
			if (!visited[j])
				dfsUtil(graph, j, visited, stack, cycle);
		}
	}
	pushStack(stack, v);
}

void toposortdfs (GRAPH_p_t graph) {
	STACK_p_t stack = initStack();
	int visited[graph->V];
	int i;
	for (i = 0; i < graph->V; ++i)
		visited[i] = NO;
	BOOL cycle = NO;
	for (i = 0; i < graph->V; ++i) {
		if (!visited[i])
			dfsUtil(graph, i, visited, stack, &cycle);
	}
	printf("\nTopological sort (DFS): ");
	while ((i = popStack(stack)) != -1) {
		printf(" %d", i+1);
	}
	printf("\n");
}

#pragma mark - Cycle detection

BOOL isCyclicUtil (GRAPH_p_t graph, int v, int visited[], int restack[]) {
	if (!visited[v]) {
		visited[v] = YES;
		restack[v] = YES;
		int j;
		for (j = 0; j < graph->V; ++j) {
			if (graph->mat[v][j]) {
				if (!visited[j] && isCyclicUtil(graph, j, visited, restack)) {
					return YES;
				} else if (restack[j]) {
					return YES;
				}
			}
		}
	}
	restack[v] = NO;
	return NO;
}

BOOL isCyclic (GRAPH_p_t graph) {
	int V = graph->V;
	int visited[V];
	int restack[V];
	int i;
	for (i = 0; i < V; ++i) {
		visited[i] = NO;
		restack[i] = NO;
	}
	for (i = 0; i < V; ++i) {
		if (isCyclicUtil(graph, i, visited, restack))
			return YES;
	}
	return NO;
}

#pragma mark - Topological sort using source removal

void toposortsource (GRAPH_p_t graph) {
	STACK_p_t stack = initStack();
	int i, j;
	stack = initStack();
	int remaining = graph->V;
	do {

		for (j = 0; j < graph->V; ++j) {
			BOOL noic = YES;
			for (i = 0; i < graph->V; ++i)
				if (graph->mat[i][j])
					noic = NO;
			if (noic) {
				if (!elementInStack(stack, j)) {
					pushStack(stack, j);
					for (i = 0; i < graph->V; ++i)
						graph->mat[j][i] = 0; // Delete row
					remaining--;
				}
			}
		}

	} while (remaining > 0);
	printf("\nTopological sort (SRM): ");
	for (i = 0; i <= stack->tos; ++i)
		printf(" %d", stack->arr[i]+1);
	printf("\n");
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	GRAPH_p_t graph = inputGraph();
	printGraph(graph);

	if (isCyclic(graph)) {
		printf("Graph is Cyclic!\n");
	} else {
		printf("Graph is a DAG!\n");
		toposortsource(graph);
	}
	toposortdfs(graph);

	printf("\n\n");
	return 0;
}
