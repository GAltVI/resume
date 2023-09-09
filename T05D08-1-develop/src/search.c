/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>
#define NMAX 30
#define INTMAX 3037000499

int input(long long int *a, int *n);
void output(long long int *a, int n);
long long int max(long long int *a, int n);
long long int min(long long int *a, int n);
long double mean(long long int *a, int n);
long double variance(long long int *a, int n);
void squaring(long long int *asqr, long long int *a, int n);
void search(long long int *a, int n, long double mean_v, long double variance_v);
int even(long long int x);
int sigma_rule(long long int x, long double mean_v, long double variance_v);

int main() {
    int n;
    long long int data[NMAX];
    if (!input(data, &n)) {
        search(data, n, mean(data, n), variance(data, n));
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

void search(long long int *a, int n, long double mean_v, long double variance_v) {
    int result = 0;
    for (long long int *p = a; p - a < n && result == 0; p++) {
        if (*p != 0 && even(*p) == 0 && (long double)*p >= mean_v && sigma_rule(*p, mean_v, variance_v)) {
            printf("%lld", *p);
            result = 1;
            break;
        }
    }
    if (result == 0) printf("0");
}

int even(long long int x) {
    if (x < 0) x *= -1;
    while (x > 1) {
        x -= 2;
    }
    return x;
}

int sigma_rule(long long int x, long double mean_v, long double variance_v) {
    return (long double)x <= mean_v + 3. * sqrt(variance_v) ? 1 : 0;
}
