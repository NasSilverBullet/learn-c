#include "stdio.h"
#include "string.h"

void declaration() {
  /* int *ptr1, ptr2; <-2つ目がポインタになっていない */
  int *prt1, *prt2;

  int num = 10;
  prt1 = &num;
  prt2 = &num;

  printf("%p, %p", prt1, prt2);
}

