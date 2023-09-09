#include <stdio.h>

void in_curcle(float x, float y);

int main() {
  float x, y;
  char ch;
  if (scanf("%f %f%c", &x, &y, &ch) == 3 && ch == '\n')
    in_curcle(x, y);
  else
    printf("n/a");
  return 0;
}

void in_curcle(float x, float y) {
  float f = x * x + y * y;
  if (f < 25)
    printf("GOTCHA");
  else
    printf("MISS");
}
