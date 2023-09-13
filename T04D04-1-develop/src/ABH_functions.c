#include <math.h>
#include <stdio.h>
#define N 42
#define eps 1e-7

double agnesi(double x);
double bernoulli(double x);
double hyperbola(double x);

double agnesi(double x) { return 1.0 / (1.0 + x * x); }

double bernoulli(double x) {
    double y = sqrt(1.0 + 4.0 * x * x) - x * x - 1;
    if (y < 0) y = 0;
    return sqrt(y);
}

double hyperbola(double x) {
    double y = 0;
    if (fabs(x) >= eps) y = 1.0 / (x * x);
    return y;
}
