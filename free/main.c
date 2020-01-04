#include "stdlib.h"
int main() {
  int *pi = (int *)malloc(sizeof(int));
  free(pi);
  // メモリを開放したあとにpiはぶら下がりポインタという状態になるのでNULLを代入しておく
  pi = NULL;
}
