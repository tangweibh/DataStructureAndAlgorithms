#include <stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;

typedef int ElemType;
typedef struct {
  ElemType data[MAXSIZE];
  int length;
} SqList;

Status GetElem(SqList L, int i, ElemType *e) {
  if (i < 1 || i > L.length) {
    return ERROR;
  }
  *e = L.data[i-1];
  return OK;
}


int main() {
  SqList L;
  int N = 5;
  for (int i = 0; i < N; ++i) {
    L.data[i] = i*i;
  }
  L.length = N;

  for (int i = 0; i < L.length; ++i) {
    ElemType *e;
    GetElem(L, i+1, e);
    //printf(" %d ", i);
  }
  printf("%d", 100);

  return 0;
}
