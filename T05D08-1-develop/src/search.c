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
#include "search.c"

int input(int *a, int *n) {
    int result = 0;
    char ch;
    if (scanf("%d%c", n, &ch) == 2 && ch == '\n' && *n > 0 && *n <= NMAX) {
        int *p = a;
        for (; p - a < *n - 1 && !result; p++) {
            if (scanf("%d%c", p, &ch) != 2 || ch != ' ' || *p > INTMAX || *p < INTMAX * (-1)) result = 1;
        }
        if (scanf("%d%c", p, &ch) != 2 || ch != '\n' || *p > INTMAX || *p < INTMAX * (-1)) result = 1;
    } else
        result = 1;
    return result;
}

void output(int *a, int n) {
    int *p = a;
    for (; p - a < n - 1; p++) printf("%d ", *p);
    printf("%d\n", *p);
}

int max(int *a, int n) {
    int *p = a;
    int max = *p;
    p++;
    for (; p - a < n; p++)
        if (*p > max) max = *p;
    return max;
}

int min(int *a, int n) {
    int *p = a;
    int min = *p;
    p++;
    for (; p - a < n; p++)
        if (*p < min) min = *p;
    return min;
}

long double mean(int *a, int n) {
    long double mean = 0.;
    if (n > 1) {
        for (int *p = a; p - a < n; p++) mean += *p;
        mean /= n;
    } else
        mean = *a;
    return mean;
}

long double variance(int *a, int n) {
    long double d = 0.;
    if (n > 1) {
        int asqr[NMAX];
        squaring(asqr, a, n);
        long double m = mean(a, n);
        d = mean(asqr, n) - m * m;
    }
    return d;
}

void squaring(int *asqr, int *a, int n) {
    for (int *p = a, *psqrt = asqr; p - a < n; p++, psqrt++) *psqrt = *p * *p;
}

void search(int *a, int n, long double mean_v, long double variance_v) {
    int result = 0;
    for (int *p = a; p - a < n && result == 0; p++) {
        if (*p != 0 && even(*p) == 0 && (long double)*p >= mean_v && sigma_rule(*p, mean_v, variance_v)) {
            printf("%d", *p);
            result = 1;
            break;
        }
    }
    if (result == 0) printf("0");
}

int even(int x) {
    if (x < 0) x *= -1;
    while (x > 1) {
        x -= 2;
    }
    return x;
}

int sigma_rule(int x, long double mean_v, long double variance_v) {
    return (long double)x <= mean_v + 3. * sqrt(variance_v) ? 1 : 0;
}
