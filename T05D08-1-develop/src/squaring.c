#include <stdio.h>
#define NMAX 10
#define INTMAX 3037000499

int input(long long int *a, int *n);
void output(long long int *a, int n);
void squaring(long long int *a, int n);

int main() {
    int n;
    long long int data[NMAX];
    if (!input(data, &n)) {
        squaring(data, n);
        output(data, n);
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
    printf("%lld", *p);
}

void squaring(long long int *a, int n) {
    for (long long int *p = a; p - a < n; p++) *p = *p * *p;
}
