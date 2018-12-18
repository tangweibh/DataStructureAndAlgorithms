#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define OK 1
#define ERROR 0
#define Status int

typedef struct Node {
  ElemType data;
  struct Node *next;
} Node, *LinkList;

void ListPrint(LinkList L) {
  Node *p_node = L->next;
  while (p_node) {
    printf("%d ", p_node->data);
    p_node = p_node->next;
  }
  printf("\n");
}

Status GetElem(LinkList L, int i, ElemType *e) {
  if (i < 1)
    return ERROR;
  Node *p_node = L->next;
  int k = 1;
  while (k < i && p_node) {
    p_node = p_node->next;
    k ++;
  }
  if (p_node) {
    *e = p_node->data;
    return OK;
  } else {
    return ERROR;
  }
}

Status ListInsert(LinkList L, int i, ElemType e) {
  if (i < 1) return ERROR;
  Node *p_node = L;
  int k = 1;
  while (k < i && p_node) {
    p_node = p_node->next;
    k ++;
  }
  if (p_node) {
    Node *p_new_node = (Node*)malloc(sizeof(Node));
    p_new_node->data = e;
    p_new_node->next = p_node->next;
    p_node->next = p_new_node;
    return OK;
  } else {
    return ERROR;
  }
}

Status ListDelete(LinkList L, int i, ElemType *e) {
  if (i < 1) return ERROR;
  Node *p_node = L;
  int k = 1;
  // move p_node to the (i-1)-th node
  while (k < i && p_node) {
    p_node = p_node->next;
    k ++;
  }
  if (!p_node->next) return ERROR;  // the target node not exist
  *e = p_node->next->data;
  free(p_node->next);
  p_node->next = p_node->next->next;
  return OK;
}

// insert a new element to the tail of the list
Status ListCreate(LinkList *p_L, int n) {
  *p_L = (LinkList)malloc(sizeof(Node));
  (*p_L)->next = NULL;
  int i;
  Node *p_node = *p_L;
  for (i=0; i < n; i++) {
    p_node->next = (Node*)malloc(sizeof(Node));
    p_node = p_node->next;
    p_node->data = i*i;
    p_node->next = NULL;
  }
}

// reset a linked list
Status ListClear(LinkList L) {
  Node *p_current_node = L->next;
  while (p_current_node) {
    Node *p_next_node = p_current_node->next;
    free(p_current_node);
    p_current_node = p_next_node;
  }
  L->next = NULL;
  return OK;
}

int main() {
  int N = 5, i;
  // head pointer
  LinkList L;
  ListCreate(&L, N);
  /*
  LinkList L = (LinkList)malloc(sizeof(Node));
  L->next = NULL;
  // current node
  Node *p_node = L;
  for (i = 0; i < N; i++) {
    p_node->next = (Node*)malloc(sizeof(Node));
    p_node = p_node->next;
    p_node->data = i*i;
    p_node->next = NULL;
  } 
  */
  ListPrint(L);
  // get an element
  ElemType e = 0;
  GetElem(L, 5, &e);
  printf("%d \n", e);
  // insert
  ListInsert(L, 1, 100);
  ListPrint(L);
  // delete
  ListDelete(L, 1, &e);
  ListPrint(L);
  printf("%d \n", e);
  // clear
  ListClear(L);
  ListPrint(L);
  return 0;
}
