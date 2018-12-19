#include <stdio.h>

int func(int i) {
  if (i > 2) return func(i-1) + func(i-2);
  else return 1;
}

int main() {
  int i, N = 12;
  for (i = 1; i < N; i++) {
    printf("%d ", func(i));
  }
  printf("\n");
  return 0;
}
