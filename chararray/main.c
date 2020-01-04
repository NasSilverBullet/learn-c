#include "stdio.h"
int main() {
  char *arr1[] = {"hoge", "huga", "piyopiyo", "sasaki"};
  char **arr2 = arr1;

  int n = sizeof(arr1) / sizeof(arr1[0]);

  for (int i = 0; i < n; i++) {
    printf("&arr1[%d]: %p => arr1[%d]: %s\n", i, &arr1[i], i, arr1[i]);
  }

  printf("----------------\n");

  for (int i = 0; i < n; i++) {
    printf("&arr2[%d]: %p => arr2[%d]: %s\n", i, &arr2[i], i, arr2[i]);
  }

  return 0;
}
