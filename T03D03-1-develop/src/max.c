#include <stdio.h>

int max(int a, int b);

int main() {
  int a = 0;
  int b = 0;
  char ch;
  if (scanf("%d %d%c", &a, &b, &ch) == 3 && ch == '\n')
    printf("%d", max(a, b));
  else
    printf("n/a");
  return 0;
}

int max(int a, int b) { return a > b ? a : b; }
