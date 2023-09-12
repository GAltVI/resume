#include <stdio.h>
#include <math.h>

#define DIVBYZERO -99999
#define eps 1e-6

int sum(int a, int b);
int diff(int a, int b);
int mult(int a, int b);
int div(int a, int b);

int max(int a, int b);
double important_function(float x);
double fun();
void in_curcle(float x, float y);

int main() {
  int a = 0;
  int b = 0;
  if (scanf("%d %d", &a, &b) == 2) {
    int d = div(a, b);
    if (d == DIVBYZERO)
      printf("%d %d %d n/a", sum(a, b), diff(a, b), mult(a, b));
    else
      printf("%d %d %d %d", sum(a, b), diff(a, b), mult(a, b), d);
  } else
    printf("n/a");

  
  double res = fun();
  if (res <= eps)
    printf("OK!");

  
  float x, y;
  if (scanf("%f %f", &x, &y) == 2)
    in_curcle(x, y);
  else
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

int max(int a, int b) { return a > b ? a : b; }

double important_function(float x) {
  return 7e-3 * pow(x, 4) +
         ((22.8 * pow(x, 1. / 3.) - 1e3) * x + 3.) / (x * x / 2.) -
         x * pow(10. + x, 2. / x) - 1.01;
}

double fun() { return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20)); }

void in_curcle(float x, float y) {
  float f = x * x + y * y;
  if (f < 25)
    printf("GOTCHA");
  else
    printf("MISS");
}
