#include<stdio.h>
#include<string.h>

void dfs(int size, int matrix[size][size], int visited[size], int vertex) {
  printf("Vertex %d touched\n", (vertex));
  visited[vertex] = 1;
  int i = 0;

  for(i = 0; i < size; i++) {
    if(matrix[vertex][i] && !visited[i] && i != vertex) {
      dfs(size, matrix, visited, i);
    }
  }
}


int main() {
  int i, j, number_of_vertex, choice = 1, start_vertex;

  printf("Enter the number of vertices:\n>");
  scanf("%d", &number_of_vertex);

  int adjacency[number_of_vertex][number_of_vertex];

  int visited[number_of_vertex];
  memset(visited, 0, sizeof(visited));
  memset(adjacency, 0, sizeof(adjacency[0][0]) * number_of_vertex * number_of_vertex);

  while(choice) {
    i = 0, j = 0;
    printf("Enter connected vertices pair(directed):\n>");
    scanf("%d %d", &i, &j);

    adjacency[i][j] = 1;

    printf("Press 1 to continue, 0 to exit:\n>");
    scanf("%d", &choice);
  }

  printf("Enter the root vertex:\n>");
  scanf("%d", &start_vertex);

  printf("Adjacency matrix:\n");
  for(i = 0; i < number_of_vertex; i++) {
    for(j = 0; j < number_of_vertex; j++) {
      printf("%d ", adjacency[i][j]);
    }
    printf("\n");
  }

  printf("Depth First Traversal:\n");
  dfs(number_of_vertex, adjacency, visited, start_vertex);

  return 0;
}
