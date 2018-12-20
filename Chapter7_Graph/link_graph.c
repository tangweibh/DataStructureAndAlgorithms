#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
  int vertex_idx;
  struct Edge *next;
} Edge;

typedef struct Vertex {
  char data;
  Edge *first_edge;
} Vertex;

typedef struct Graph {
  int vertex_num;
  Vertex *vertices;
} Graph;

void InitializeGraph(Graph *p_G, int vertex_num, int adj_mat[]) {
  p_G->vertex_num = vertex_num;
  p_G->vertices = (Vertex*)malloc(vertex_num*sizeof(Vertex));

  int i, j;
  // initialize each vertex
  for (i = 0; i < vertex_num; i++) {
    p_G->vertices[i].data = i + 65;
    p_G->vertices[i].first_edge = (Edge*)malloc(sizeof(Edge));
    p_G->vertices[i].first_edge->vertex_idx = -1;
    p_G->vertices[i].first_edge->next = NULL;
    for (j = vertex_num-1; j >= 0; j--) {
      if (adj_mat[i*vertex_num + j]) {
        Edge *new_edge = (Edge*)malloc(sizeof(Edge));
        new_edge->vertex_idx = j;
        new_edge->next = p_G->vertices[i].first_edge->next;
        p_G->vertices[i].first_edge->next = new_edge;
      }
    }
  }
}

void DFS(Graph G, int *visited, int start) {
  visited[start] = 1;
  printf("%c ", G.vertices[start].data);
  Edge *edge = G.vertices[start].first_edge->next;
  while (edge) {
    if (!visited[edge->vertex_idx])
      DFS(G, visited, edge->vertex_idx);
    edge = edge->next;
  }
}

void DFSTraverse(Graph G) {
  int *visited = (int*)malloc(G.vertex_num*sizeof(int));
  int i;
  for (i = 0; i < G.vertex_num; i++) {
    visited[i] = 0;
  }
  DFS(G, visited, 0);
}

int main () {
  int adj_mat[] = {
    0, 1, 0, 0, 0, 1, 0, 0, 0,
    1, 0, 1, 0, 0, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 1, 0, 1, 1, 1,
    0, 0, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 0, 0, 1, 0, 1, 0, 0,
    0, 1, 0, 1, 0, 1, 0, 1, 0,
    0, 0, 0, 1, 1, 0, 1, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0, 0
  };

  int i;
  Graph *p_G = (Graph*)malloc(sizeof(Graph));
  InitializeGraph(p_G, 9, adj_mat);
  for (i = 0; i < p_G->vertex_num; i++) {
    Vertex vertex = p_G->vertices[i];
    printf("%c: ", vertex.data);
    Edge *edge = vertex.first_edge;
    while (edge->next) {
      edge = edge->next;
      printf("%c ", p_G->vertices[edge->vertex_idx].data);
    }
    printf("\n");
  }
  DFSTraverse(*p_G);
  printf("\n");

  return 0;
}
