#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Queue Implementation start

typedef struct node{
  int data;
  struct node* next;
}NODE;

typedef NODE * NODEPTR;

typedef struct queue{
  NODEPTR front, rear;
}QUEUE;

typedef QUEUE * QUEUEPTR;

NODEPTR add_node(int data) {
  NODEPTR new_node = (NODEPTR)malloc(sizeof(NODE));
  new_node -> data = data;
  new_node -> next = NULL;

  return new_node;
}

QUEUEPTR create_queue() {
  QUEUEPTR new_queue = (QUEUEPTR)malloc(sizeof(QUEUE));
  new_queue -> front = NULL;
  new_queue -> rear = NULL;

  return new_queue;
}

QUEUEPTR enqueue(QUEUEPTR queue, int data) {

  NODEPTR temp = add_node(data);
  if(queue -> rear == NULL) {
    queue -> front = temp;
    queue -> rear = queue -> front;
  }
  else {
    queue -> rear -> next = temp;
    queue -> rear = temp;
  }
  return queue;
}

QUEUEPTR dequeue(QUEUEPTR queue) {
  if(queue -> rear != NULL) {
    NODEPTR temp = queue -> front;
    queue -> front = queue -> front -> next;
    free(temp);

    if(queue -> front == NULL) {
      queue -> rear = NULL;
    }
  }
  else {
    printf("Empty queue!\n");
  }

  return queue;
}

int get_front(QUEUEPTR queue) {
  if(queue -> front != NULL) {
    return queue -> front -> data;
  }
  else {
    return -1;
  }
}

int is_queue_empty(QUEUEPTR queue) {
  return (queue -> rear == NULL);
}

// Queue Implementation end

// Breadth First Search

void bfs(int size, int matrix[size][size], int visited[size], int vertex) {

  QUEUEPTR queue = create_queue();
  queue = enqueue(queue, vertex);

  visited[vertex] = 1;
  int front, i;

  while(!is_queue_empty(queue)) {
    front = get_front(queue);
    printf("Vertex %d touched.", front);
    queue = dequeue(queue);

    for(i = 0; i < size; i++) {
      if(matrix[front][i] && !visited[i]) {
        visited[i] = 1;
        queue = enqueue(queue, i);
      }
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

  printf("Breadth First Traversal:\n");
  bfs(number_of_vertex, adjacency, visited, start_vertex);

  return 0;
}
