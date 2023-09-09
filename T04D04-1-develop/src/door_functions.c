#include <math.h>
#include <stdio.h>
#define N 42
#define eps 1e-7

double agnesi(double x);
double bernoulli(double x);
double hyperbola(double x);

int main() {
    double x = -1 * M_PI;
    double step = 2. * M_PI / (N - 1);
    double funB, funH;
    for (int i = 0; i < N; i++) {
        printf("%.7f | %.7f | ", x, agnesi(x));
        funB = bernoulli(x);
        if (funB == 0)
            printf("- | ");
        else
            printf("%.7f | ", funB);
        funH = hyperbola(x);
        if (funH == 0)
            printf("-\n");
        else
            printf("%.7f\n", funH);
        x += step;
    }
    return 0;
}

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
