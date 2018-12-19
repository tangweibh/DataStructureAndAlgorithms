#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ARRAY_SIZE(array) sizeof(array)/sizeof(array[0])

void getNextArrayFast(char T[], int length, int *next) {
  next[0] = -1;
  int front_idx=-1, rear_idx=0;
  while (rear_idx < length - 1) {
    if (front_idx == -1 || T[front_idx] == T[rear_idx]) {
      front_idx ++;
      rear_idx ++;
      next[rear_idx] = front_idx;
    } else {
      front_idx = next[front_idx];
    }
  }
}

void getNextArray(char T[], int length, int *next) {
  next[0] = -1;
  if (length > 1) next[1] = 0;
  int i, k, front_idx, rear_idx, match;
  for (i = 2; i < length; i++) {
    for (k = i-1; k > 0; k--) {
      match = 1;
      for (front_idx = 0; front_idx < k; front_idx++) {
        rear_idx = i - k + front_idx;
        if (T[front_idx] != T[rear_idx]) {
          match = 0;
          break;
        }
      }
      if (match == 1) break;
    }
    if (match == 1) next[i] = k;
    else next[i] = 0;
  }
}

int KMP(char S[], char T[], int length_S, int length_T, int *next) {
  int s = 0, t = 0;
  while (s < length_S && t < length_T) {
    if (t == -1 || S[s] == T[t]) {
      t ++;
      s ++;
    } else {
      t = next[t];
    }
  }
  if (t == length_T) return s - length_T;
  else return -1;
}

int main () {
  char S[] = "abcabcabxdfaljflajflajflajfk";
  char T[] = "abcabx";
  int length_S = ARRAY_SIZE(S) - 1;
  int length_T = ARRAY_SIZE(T) - 1;

  // get next array
  int *next = (int*)malloc(sizeof(int)*length_T);
  getNextArrayFast(T, length_T, next);
  int i;
  for (i = 0; i < length_T; i++) {
    printf("%d ", next[i]);
  }
  printf("\n");
  // KMP
  int loc = KMP(S, T, length_S, length_T, next);
  printf("loc: %d\n", loc);
  for (i = 0; i < length_T; i++) {
    printf("%c ", T[i]);
  }
  printf("\n");
  for (i = 0; i < length_T; i++) {
    printf("%c ", S[i+loc]);
  }
  printf("\n");
  return 0;
}

