#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main() {
  char *string1;
  string1 = (char *)malloc(16);
  strcpy(string1, "0123456789AB");

  char *string2;
  string2 = realloc(string1, 1024);
  printf("string1 Valu: %p [%s]\n", string1, string1);
  printf("string2 Valu: %p [%s]\n", string2, string2);
}
