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

void PrintList(SqList L) {
  int i;
  for (i = 0; i < L.length; i++)
    printf("%d ", L.data[i]);
  printf("\n");
}

Status GetElem(SqList L, int i, ElemType *e) {
  if (i < 1 || i > L.length)
    return ERROR;
  *e = L.data[i-1];
  return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
  if (i < 1 || i > L->length + 1)
    return ERROR;
  if (L->length == MAXSIZE)
    return ERROR;
  if (i < L->length + 1) {
    int k;
    for (k = L->length+1; k > i; k--) {
      L->data[k-1] = L->data[k-2];
    }
  }
  L->data[i-1] = e;
  L->length += 1;
  return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
  if (L->length == 0)
    return ERROR;
  if (i < 1 || i > L->length)
    return ERROR;
  *e = L->data[i-1];
  int k;
  for (k=i-1; k < L->length-1; k++)
    L->data[k] = L->data[k+1];
  L->length -= 1;
  return OK;
}


int main() {
  // construct an exmaple list
  SqList L;
  int N = 5, i;
  for (i = 0; i < N; ++i)
    L.data[i] = i*i;
  L.length = N;

  // list functions
  PrintList(L);

  // insert
  ListInsert(&L, 3, 100);
  PrintList(L);

  // delete
  ElemType *e;
  ListDelete(&L, 3, e);
  PrintList(L);
  printf("%d\n", *e);

  return 0;
}
