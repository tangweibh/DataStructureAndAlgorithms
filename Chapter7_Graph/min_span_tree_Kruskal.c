#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
  int begin, end, weight;
} Edge;

typedef struct Graph {
  Edge *edges;
  int vertex_num;
  int edge_num;
} Graph;

void InitializeGraph(Graph *p_G, int vertex_num, int edge_num, 
    int *edge_data) {
  p_G->vertex_num = vertex_num;
  p_G->edge_num = edge_num;
  p_G->edges = (Edge*)malloc(vertex_num*sizeof(Edge));
  int i;
  for (i = 0; i < edge_num; i++) {
    p_G->edges[i].begin = edge_data[i*3];
    p_G->edges[i].end = edge_data[i*3+1];
    p_G->edges[i].weight = edge_data[i*3+2];
  }
}

void MinSpanTree(Graph G) {
  int *cluster_idx = (int*)malloc(G.vertex_num*sizeof(int));
  int i;
  for (i = 0; i < G.vertex_num; i++) {
    cluster_idx[i] = i;
  }
  // find the N-1 edges
  int count = 0;
  int edge_idx = 0;
  while (count < G.vertex_num - 1){
    int begin = G.edges[edge_idx].begin;
    int end = G.edges[edge_idx].end;
    edge_idx ++;
    if (cluster_idx[begin] == cluster_idx[end]) continue;
    if (count == G.vertex_num - 2) {
      int j = count;
    }
    printf("(%d, %d) ", begin, end);
    int src, dst;
    if (cluster_idx[begin] > cluster_idx[end]) {
      src = cluster_idx[begin];
      dst = cluster_idx[end];
    } else {
      src = cluster_idx[end];
      dst = cluster_idx[begin];
    }
    for (i = 0; i < G.vertex_num; i++) {
      if (cluster_idx[i] == src)
        cluster_idx[i] = dst;
    }
    count ++;
  }
}

int main () {
  int graph_edge_data[] = {
    4, 7, 7,
    2, 8, 8,
    0, 1, 10,
    0, 5, 11,
    1, 8, 12,
    3, 7, 16,
    1, 6, 16,
    5, 6, 17,
    1, 2, 18,
    6, 7, 19,
    3, 4, 20,
    3, 8, 21,
    2, 3, 22,
    3, 6, 24,
    4, 5, 26};

  Graph *p_G = (Graph*)malloc(sizeof(Graph));

  InitializeGraph(p_G, 9, 15, graph_edge_data);

  MinSpanTree(*p_G);

  return 0;
}
