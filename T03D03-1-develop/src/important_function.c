#include <math.h>
#include <stdio.h>

double important_function(float x);

int main() {
  float x;
  char ch;
  if (scanf("%f%c", &x, &ch) == 2 && ch == '\n')
    printf("%.1f", important_function(x));
  else
    printf("n/a");
  return 0;
}

double important_function(float x) {
  return 7e-3 * pow(x, 4) +
         ((22.8 * pow(x, 1. / 3.) - 1e3) * x + 3.) / (x * x / 2.) -
         x * pow(10. + x, 2. / x) - 1.01;
}
