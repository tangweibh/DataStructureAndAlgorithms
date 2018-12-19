#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;

typedef struct LinkQueue {
  Node *p_front, *p_rear;
} LinkQueue;

void QueueInit(LinkQueue *p_Q) {
  p_Q->p_front = (Node*)malloc(sizeof(Node));
  p_Q->p_rear = p_Q->p_front;
  p_Q->p_front->next = NULL;
}

Status EnQueue(LinkQueue *p_Q, ElemType e) {
  Node *p_node = (Node*)malloc(sizeof(Node));
  p_node->data = e;
  p_node->next = NULL;
  p_Q->p_rear->next = p_node;
  p_Q->p_rear = p_node;
  return OK;
}

Status DeQueue(LinkQueue *p_Q, ElemType *e) {
  if (p_Q->p_front == p_Q->p_rear) return ERROR;
  *e = p_Q->p_front->next->data;
  Node *temp = p_Q->p_front->next;
  p_Q->p_front->next = p_Q->p_front->next->next;
  free(temp);
  if (!p_Q->p_front->next) p_Q->p_rear = p_Q->p_front;
  return OK;
}

int main() {
  int i, N = 5;
  ElemType e;
  LinkQueue Q;
  QueueInit(&Q);
  for (i = 0; i < N; i++) {
    EnQueue(&Q, i*10);
  }
  while (1) {
    Status s = DeQueue(&Q, &e);
    if (s) printf("%d ", e);
    else break;
  }
  return 0;
}
