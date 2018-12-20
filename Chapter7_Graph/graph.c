#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
  int data;
  struct QueueNode *next;
} QueueNode, *Queue;

void EnQueue(Queue Q, int e) {
  QueueNode *p_node = (QueueNode*)malloc(sizeof(QueueNode));
  p_node->data = e;
  p_node->next = NULL;
  QueueNode *p_rear = Q;
  while (p_rear->next) {
    p_rear = p_rear->next;
  }
  p_rear->next = p_node;
}

int DeQueue(Queue Q, int *e) {
  if (!Q->next) return 0;
  QueueNode *p_node = Q->next;
  *e = p_node->data;
  Q->next = p_node->next;
  free(p_node);
  return 1;
}

typedef struct Graph {
  char *vex;
  int *adj;
  int vex_num;
} Graph;

InitializeGraph(Graph *p_G, int vex_num, int *adj_mat) {
  p_G->vex = (char*)malloc(vex_num*sizeof(char));
  p_G->adj = (int*)malloc(vex_num*vex_num*sizeof(int));
  p_G->vex_num = vex_num;

  int i;
  for (i = 0; i < vex_num; i++) {
    p_G->vex[i] = i + 65;
  }
  for (i = 0; i < vex_num*vex_num; i++) {
    p_G->adj[i] = adj_mat[i];
  }
}

void DFS(Graph G, int* visited, int start) {
  visited[start] = 1;
  printf("%c ", G.vex[start]);
  int i;
  for (i = 0; i < G.vex_num; i++) {
    if (G.adj[start*G.vex_num + i] && !visited[i]) {
      DFS(G, visited, i);
    }
  }
}

void DFSTraverse(Graph G) {
  int *visited = (int*)malloc(G.vex_num * sizeof(int));
  int i;
  for (i = 0; i < G.vex_num; i++) {
    visited[i] = 0;
  }
  DFS(G, visited, 0);
}

void WFS(Graph G, int *visited, Queue Q) {
  int e, i;
  if (!DeQueue(Q, &e) || visited[e]) return;
  visited[e] = 1;
  printf("%c ", G.vex[e]);
  for (i = 0; i < G.vex_num; i++) {
    if (!visited[i] && G.adj[e*G.vex_num + i])
      EnQueue(Q, i);
  }
  while (Q->next) {
    WFS(G, visited, Q);
  }
}

void WFSTraverse(Graph G) {
  Queue Q = (Queue)malloc(sizeof(QueueNode));
  EnQueue(Q, 0);
  int *visited = (int*)malloc(G.vex_num * sizeof(int));
  int i;
  for (i = 0; i < G.vex_num; i++) {
    visited[i] = 0;
  }
  WFS(G, visited, Q);
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
  int i, j;
  Graph *p_G = (Graph*)malloc(sizeof(Graph));
  InitializeGraph(p_G, 9, adj_mat);
  //for (i = 0; i < p_G->vex_num; i++) {
  //  for (j = 0; j < p_G->vex_num; j++) {
  //    printf("%d ", p_G->adj[i*p_G->vex_num + j]);
  //  }
  //  printf("\n");
  //}
  // DFS traverse
  DFSTraverse(*p_G);
  printf("\n");

  // Queue
  //Queue Q = (Queue)malloc(sizeof(QueueNode));
  //for (i = 0; i < 5; i++) {
  //  EnQueue(Q, i*i);
  //}
  //while (1) {
  //  j = DeQueue(Q, &i);
  //  if (j) printf("%d ", i);
  //  else break;
  //}
  // WFS traverse
  WFSTraverse(*p_G);
  return 0;
}
