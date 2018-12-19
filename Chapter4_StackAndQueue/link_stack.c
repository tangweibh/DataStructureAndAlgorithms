#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node, *NodePtr;

typedef struct LinkStack {
  NodePtr top;
  int length;
} LinkStack;

void StackInit(LinkStack *p_S) {
  p_S->length = 0;
  p_S->top = NULL;
}

void StackPush(LinkStack *p_S, ElemType e) {
  NodePtr p_node = (NodePtr)malloc(sizeof(Node));
  p_node->data = e;
  p_node->next = p_S->top;
  p_S->top = p_node;
  p_S->length ++;
}

Status StackPop(LinkStack *p_S, ElemType *e) {
  if (!p_S->top) return ERROR;
  *e = p_S->top->data;
  NodePtr temp = p_S->top;
  p_S->top = p_S->top->next;
  free(temp);
  p_S->length --;
  return OK;
}

int main() {
  int i, N = 5;
  ElemType e;
  LinkStack S;
  StackInit(&S);
  for (i = 0; i < N; i++) {
    StackPush(&S, i*10);
  }
  while (1) {
    Status s = StackPop(&S, &e);
    if (s) printf("%d \n", e);
    else break;
  }

  return 0;
}

