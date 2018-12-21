#include <stdio.h>
#include <stdlib.h>

#define INF 1000
#define min(a, b) a:b?a,b


typedef struct Graph {
  int vertex_num;
  char *vertex_names;
  int *adj_mat;
} Graph;

void InitializeGraph(Graph *p_G, int vertex_num, int *adj_mat) {
  p_G->vertex_num = vertex_num;
  p_G->vertex_names = (char*)malloc(vertex_num*sizeof(char));
  p_G->adj_mat = (int*)malloc(vertex_num*vertex_num*sizeof(int));
  int i;
  for (i = 0; i < vertex_num; i++)
    p_G->vertex_names[i] = 65 + i;

  for (i = 0; i < vertex_num*vertex_num; i++)
    p_G->adj_mat[i] = adj_mat[i];
}

void MinSpanTree(Graph G) {
  int i, k, next;
  int *low_cost = (int*)malloc(G.vertex_num*sizeof(int));
  int *low_idx = (int*)malloc(G.vertex_num*sizeof(int));
  // assign node 0 as the starting point
  for (i = 0; i < G.vertex_num; i++) {
    low_cost[i] = G.adj_mat[i];
    low_idx[i] = 0;
  }
  // find the N-1 edges
  for (i = 1; i < G.vertex_num; i++) {
    int min_cost = INF;
    for (k = 0; k < G.vertex_num; k++) {
      if (low_cost[k] && low_cost[k] < min_cost) {
        next = k;
        min_cost = low_cost[k];
      }
    }
    printf("(%c, %c) ", G.vertex_names[low_idx[next]],
        G.vertex_names[next]);
    for (k = 0; k < G.vertex_num; k++) {
      if (low_cost[k] > G.adj_mat[k*G.vertex_num + next]) {
        low_cost[k] = G.adj_mat[k*G.vertex_num + next];
        low_idx[k] = next;
      }
    }
  }

}

int main () {
  int adj_mat[] = {
      0,   10,  INF,  INF,  INF,   11,  INF,  INF,  INF,  
     10,    0,   18,  INF,  INF,  INF,   16,  INF,   12,  
    INF,  INF,    0,   22,  INF,  INF,  INF,  INF,    8,  
    INF,  INF,   22,    0,   20,  INF,  INF,   16,   21,  
    INF,  INF,  INF,   20,    0,   26,  INF,    7,  INF,  
     11,  INF,  INF,  INF,   26,    0,   17,  INF,  INF,  
    INF,   16,  INF,  INF,  INF,   17,    0,   19,  INF,  
    INF,  INF,  INF,   16,    7,  INF,   19,    0,  INF,  
    INF,   12,    8,   21,  INF,  INF,  INF,  INF,    0};

  Graph *p_G = (Graph*)malloc(sizeof(Graph));

  InitializeGraph(p_G, 9, adj_mat);

  MinSpanTree(*p_G);
  
  return 0;
}
