#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main() {
  printf("size int: %lu\n", sizeof(int));

  // 値はゼロ埋めされる
  int *pi = calloc(5, sizeof(int));
  printf("pi value: %d\n", *pi);

  // 値にゴミが入っている
  int *pi2 = (int *)malloc(5 * sizeof(int));
  printf("pi2 value: %d\n", *pi2);

  // calloc と等価
  int *pi3 = malloc(5 * sizeof(int));
  memset(pi3, 0, 5 * sizeof(int));
}

// calloc のほうがmallocより時間がかかる
