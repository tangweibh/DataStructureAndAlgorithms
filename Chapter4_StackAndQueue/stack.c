#include <stdio.h>

#define ElemType int
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct Stack {
  ElemType data[MAXSIZE];
  int top;
} Stack;

void StackInit(Stack *S) {
  S->top = -1;
}

Status StackPush(Stack *S, ElemType e) {
  if (S->top == MAXSIZE-1) return ERROR;
  S->top ++;
  S->data[S->top] = e;
  return OK;
}

Status StackPop(Stack *S, ElemType *e) {
  if (S->top == -1) return ERROR;
  *e = S->data[S->top];
  S->top --;
  return OK;
}

int main() {

  int i, N = 10;
  ElemType e;
  Stack S;
  StackInit(&S);
  for (i = 0; i < N; i++) {
    StackPush(&S, i*i);
  } 
  while (1) {
    Status s = StackPop(&S, &e);
    if (s) 
      printf("%d ", e);
    else 
      break;
  }

  return 0;
}
