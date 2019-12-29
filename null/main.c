#define NULL ((void *)0)

int main() {
  int *pi;
  pi = 0;
  pi = NULL;
  /* pi = 100; <- できない */
  return 0;
}
