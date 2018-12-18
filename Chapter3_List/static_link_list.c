#include <stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct Node {
  ElemType data;
  int next;
} Node, LinkList[MAXSIZE];

void ListPrint(LinkList L) {
  int current_idx = MAXSIZE - 1;
  while (L[current_idx].next) {
    current_idx = L[current_idx].next;
    printf("%d ", L[current_idx].data);
  }
  printf("\n");
}

void ListInit(LinkList L) {
  int i;
  for (i = 0; i < MAXSIZE - 1; i++) {
    L[i].next = i+1;
  }
  L[MAXSIZE-1].next = 0;
}

int ListLength(LinkList L) {
  int current = L[MAXSIZE - 1].next;
  int length = 0;
  while (current) {
    length ++;
    current = L[current].next;
  }
  return length;
}

Status ListInsert(LinkList L, int i, ElemType e) {
  int length = ListLength(L);
  if (i < 1 || i > length + 1) return ERROR;  // invalid place
  if (length == MAXSIZE - 2) return ERROR;    // no space
  int current_idx = MAXSIZE - 1;
  // move current to the (i-1)-th 
  int k = 1;
  while (k < i) {
    current_idx = L[current_idx].next;
    k ++;
  }
  // find the next available empty node
  int empty_idx = L[0].next;
  L[0].next = L[empty_idx].next;
  // insert
  L[empty_idx].data = e;
  L[empty_idx].next = L[current_idx].next;
  L[current_idx].next = empty_idx;
  return OK;
}

Status ListDelete(LinkList L, int i, ElemType *e) {
  int length = ListLength(L);
  if (i < 1 || i > length) return ERROR;
  int k = 1;
  int current = MAXSIZE-1;
  // find the (i-1)-th element
  while (k < i) {
    current = L[current].next;
    k ++;
  }
  int target = L[current].next;
  // delete
  *e = L[target].data;
  L[current].next = L[target].next;
  // recycle
  L[target].next = L[0].next;
  L[0].next = target;
  return OK;
}

int main() {
  int i, N = 5;
  LinkList L;
  ListInit(L);
  ListPrint(L);
  for (i = 0; i < N; i++) {
    ListInsert(L, i+1, (i+1)*10);
  }
  ListPrint(L);
  ListInsert(L, 3, 100);
  ListInsert(L, 1, 100);
  ListPrint(L);
  ElemType e = 0;
  ListDelete(L, 2, &e);
  printf("%d \n", e);
  ListPrint(L);
  ListInsert(L, 1, 500);
  ListPrint(L);
  return 0;
}

