#include <stdio.h>
#include <math.h>

#define DIVBYZERO -99999
#define eps 1e-6

int sum(int a, int b);
int diff(int a, int b);
int mult(int a, int b);
int div(int a, int b);

int max(int a, int b);
void in_curcle(float x, float y);

int main() {
  int a = 0;
  int b = 0;
  printf("input: a, b = ");
  if (scanf("%d %d", &a, &b) == 2) {
      printf("max(a, b) = %d\n", max(a, b));
      int d = div(a, b);
      if (d == DIVBYZERO)
      printf("a + b = %d | a - b = %d | a * b = %d | div by zero\n", sum(a, b), diff(a, b), mult(a, b));
      else
      printf("a + b = %d | a - b = %d | a * b = %d | a / b = %d\n", sum(a, b), diff(a, b), mult(a, b), d);
  } else
    printf("@n/a");

  float x, y;
  printf("input: (x, y) = ");
  if (scanf("%f %f", &x, &y) == 2) {
      printf("Is point (%.2e, %.2e) in the circle x * x + y * y < 25: ", x, y);
      in_curcle(x, y);
  }
  else
    printf("#n/a");
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

int max(int a, int b) { return a > b ? a : b; }

void in_curcle(float x, float y) {
  float f = x * x + y * y;
  if (f < 25)
    printf("GOTCHA");
  else
    printf("MISS");
}
