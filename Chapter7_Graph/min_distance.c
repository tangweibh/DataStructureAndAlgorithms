#include <stdio.h>
#include <stdlib.h>

#define INF 1000

int min(int a, int b) {
  if (a > b) return b;
  else return a;
}

typedef struct Graph {
  int vertex_num;
  int *adj_mat;
} Graph;

void InitializeGraph(Graph *p_G, int vertex_num, int *adj_mat) {
  int i;
  p_G->vertex_num = vertex_num;
  p_G->adj_mat = (int*)malloc(vertex_num*vertex_num*sizeof(int));
  for (i = 0; i < vertex_num*vertex_num; i++) {
    p_G->adj_mat[i] = adj_mat[i];
  }
}

int Dijkstra(Graph G) {
  int *D = (int*)malloc(G.vertex_num*sizeof(int));
  int *P = (int*)malloc(G.vertex_num*sizeof(int));
  int *isfinal = (int*)malloc(G.vertex_num*sizeof(int));
  int i, j, k;
  for (i = 0; i < G.vertex_num; i++) {
    D[i] = G.adj_mat[i];
    isfinal[i] = 0;
  }
  isfinal[0] = 1;
  for (i = 1; i < G.vertex_num; i++) {
    int min_distance = INF;
    for (j = 0; j < G.vertex_num; j++) {
      if (!isfinal[j] && D[j] < min_distance) {
        k = j;
        min_distance = D[j];
      }
    }
    isfinal[k] = 1;
    for (j = 0; j < G.vertex_num; j++) {
      int temp = min_distance + G.adj_mat[k*G.vertex_num + j];
      if (!isfinal[j] && D[j] > temp) {
        D[j] = temp;
        P[j] = k;
      }
    }
  }
  for (i = 0; i < G.vertex_num; i++) {
    printf("%d ", D[i]);
  }
  for (i = 0; i < G.vertex_num; i++) {
    printf("%d ", P[i]);
  }
}

int main () {
  int adj_mat[] = {
      0,   1,   5, INF, INF, INF, INF, INF, INF, 
      1,   0,   3,   7,   5, INF, INF, INF, INF, 
      5,   3,   0, INF,   1,   7, INF, INF, INF, 
    INF,   7, INF,   0,   2, INF,   3, INF, INF, 
    INF,   5,   1,   2,   0,   3,   6,   9, INF, 
    INF, INF,   7, INF,   3,   0, INF,   5, INF, 
    INF, INF, INF,   3,   6, INF,   0,   2,   7, 
    INF, INF, INF, INF,   9,   5,   2,   0,   4, 
    INF, INF, INF, INF, INF, INF,   7,   4,   0};

  Graph *p_G = (Graph*)malloc(sizeof(Graph));

  InitializeGraph(p_G, 9, adj_mat);

  Dijkstra(*p_G);
  return 0;
}
