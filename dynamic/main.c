#include "stdio.h"
int main() {
  /* char *name = ""; */
  char name;
  printf("Enter a name: ");
  /* scanf("%s", name); */
  scanf("%s", &name);
  printf("%s\n", &name);
}
