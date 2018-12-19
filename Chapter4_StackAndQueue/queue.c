#include <stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct Queue {
  ElemType data[MAXSIZE];
  int front;
  int rear;
} Queue;

QueueInit(Queue *p_Q) {
  p_Q->front = 0;
  p_Q->rear = 0;
}

void QueuePrint(Queue Q) {
  int front;
  for (front = Q.front; front%MAXSIZE != Q.rear; front++) {
    printf("%d ", Q.data[front]);
  }
  printf("\n");
}

Status EnQueue(Queue *p_Q, ElemType e) {
  if ((p_Q->front - p_Q->rear)%MAXSIZE == 1) return ERROR;  // full
  p_Q->data[p_Q->rear] = e;
  p_Q->rear = (p_Q->rear + 1)%MAXSIZE;
  return OK;
}

Status DeQueue(Queue *p_Q, ElemType *e) {
  if (p_Q->front == p_Q->rear) return ERROR;  // empty
  *e = p_Q->data[p_Q->front];
  p_Q->front = (p_Q->front + 1)%MAXSIZE;
  return OK;
}

int QueueLength(Queue Q) {
  return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

int main() {
  int i, N = 5;
  ElemType e;
  Queue Q;
  QueueInit(&Q);
  for (i = 0; i < N; i++) {
    EnQueue(&Q, i*10);
  }
  QueuePrint(Q);
  while (1) {
    Status s = DeQueue(&Q, &e);
    if (s) printf("%d ", e);
    else break;
  }
  return 0;
}
