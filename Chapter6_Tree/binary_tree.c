#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node *p_lchild;
  struct Node *p_rchild;
} Node, *Tree;

int CreateTree(Tree *p_T, char data [], int counter) {
  if (data[counter] == 32) return counter+1;
  *p_T = (Tree)malloc(sizeof(Node));
  (*p_T)->data = data[counter];
  (*p_T)->p_lchild = NULL;
  (*p_T)->p_rchild = NULL;
  counter ++;
  counter = CreateTree(&((*p_T)->p_lchild), data, counter);
  counter = CreateTree(&((*p_T)->p_rchild), data, counter);
  return counter;
}

void PreOrderTraverse(Tree T) {
  if (!T) return;
  printf("%c ", T->data);
  PreOrderTraverse(T->p_lchild);
  PreOrderTraverse(T->p_rchild);
}

void MidOrderTraverse(Tree T) {
  if (!T) return;
  MidOrderTraverse(T->p_lchild);
  printf("%c ", T->data);
  MidOrderTraverse(T->p_rchild);
}

void PostOrderTraverse(Tree T) {
  if (!T) return;
  PostOrderTraverse(T->p_lchild);
  PostOrderTraverse(T->p_rchild);
  printf("%c ", T->data);
}

int main () {
  /*        A
   *      /   \
   *     B     C
   *    /     /  \
   *   D     E    F
   *  / \     \
   * G   H     I    */
  char data[] = "ABDG  H   CE I  F  ";
  Tree *p_T = (Tree*)malloc(sizeof(Tree));
  CreateTree(p_T, data, 0);
  // preorder traverse
  PreOrderTraverse(*p_T);
  printf("\n");
  // midorder traverse
  MidOrderTraverse(*p_T);
  printf("\n");
  // postorder traverse
  PostOrderTraverse(*p_T);
  printf("\n");
  return 0;
}
