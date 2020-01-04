#include "stdio.h"
typedef union _conversion {
  float fNum;
  unsigned int uiNum;
} Conversion;

int isPosition1(float number) {
  Conversion conversion = {.fNum = number};
  return (conversion.uiNum & 0x80000000) == 0;
}

int main() {
  float num = 0.0003f;
  printf("%d\n", isPosition1(num));
}
