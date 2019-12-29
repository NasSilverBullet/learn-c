#include <stdint.h>

int main() {
  int num;
  intptr_t *pi = (intptr_t *)(void *)&num;
  /* uintptr_t *pu = &num; <- コンパイルエラー */
  // 一度voidポインタ型にキャストしたあとにintptr_tポインタ型にキャストする
  /* intptr_t *pi2 = (intptr_t *)&num; <- これだと
   * 情報の切り捨てが起きる可能性がある*/
}
