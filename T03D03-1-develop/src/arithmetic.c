#include <stdio.h>
#define DIVBYZERO -99999

int sum(int a, int b);
int diff(int a, int b);
int mult(int a, int b);
int div(int a, int b);

int main() {
  int a = 0;
  int b = 0;
  char ch;
  if (scanf("%d %d%c", &a, &b, &ch) == 3 && ch == '\n') {
    int d = div(a, b);
    if (d == DIVBYZERO)
      printf("%d %d %d n/a", sum(a, b), diff(a, b), mult(a, b));
    else
      printf("%d %d %d %d", sum(a, b), diff(a, b), mult(a, b), d);
  } else
    printf("n/a");
  return 0;
}
int sum(int a, int b) { return a + b; }
int diff(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int div(int a, int b) {
  if (b == 0) {
    return DIVBYZERO;
  }
  return a / b;
}
