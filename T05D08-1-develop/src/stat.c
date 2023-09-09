#include <stdio.h>
#define NMAX 10
#define INTMAX 3037000499

int input(long long int *a, int *n);
void output(long long int *a, int n);
long long int max(long long int *a, int n);
long long int min(long long int *a, int n);
long double mean(long long int *a, int n);
long double variance(long long int *a, int n);
void squaring(long long int *asqr, long long int *a, int n);

void output_result(long long int max_v, long long int min_v, long double mean_v, long double variance_v);

int main() {
    int n;
    long long int data[NMAX];
    if (!input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else
        printf("n/a");

    return 0;
}

int input(long long int *a, int *n) {
    int result = 0;
    char ch;
    if (scanf("%d%c", n, &ch) == 2 && ch == '\n' && *n > 0 && *n <= NMAX) {
        long long int *p = a;
        for (; p - a < *n - 1 && !result; p++) {
            if (scanf("%lld%c", p, &ch) != 2 || ch != ' ' || *p > INTMAX || *p < INTMAX * (-1)) result = 1;
        }
        if (scanf("%lld%c", p, &ch) != 2 || ch != '\n' || *p > INTMAX || *p < INTMAX * (-1)) result = 1;
    } else
        result = 1;
    return result;
}

void output(long long int *a, int n) {
    long long int *p = a;
    for (; p - a < n - 1; p++) printf("%lld ", *p);
    printf("%lld\n", *p);
}

long long int max(long long int *a, int n) {
    long long int *p = a;
    long long int max = *p;
    p++;
    for (; p - a < n; p++)
        if (*p > max) max = *p;
    return max;
}

long long int min(long long int *a, int n) {
    long long int *p = a;
    long long int min = *p;
    p++;
    for (; p - a < n; p++)
        if (*p < min) min = *p;
    return min;
}

long double mean(long long int *a, int n) {
    long double mean = 0.;
    if (n > 1) {
        for (long long int *p = a; p - a < n; p++) mean += *p;
        mean /= n;
    } else
        mean = *a;
    return mean;
}

long double variance(long long int *a, int n) {
    long double d = 0.;
    if (n > 1) {
        long long int asqr[NMAX];
        squaring(asqr, a, n);
        long double m = mean(a, n);
        d = mean(asqr, n) - m * m;
    }
    return d;
}

void squaring(long long int *asqr, long long int *a, int n) {
    for (long long int *p = a, *psqrt = asqr; p - a < n; p++, psqrt++) *psqrt = *p * *p;
}

void output_result(long long int max_v, long long int min_v, long double mean_v, long double variance_v) {
    printf("%lld %lld %.6Lf %.6Lf", max_v, min_v, mean_v, variance_v);
}
