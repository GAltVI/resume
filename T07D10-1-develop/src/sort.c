#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *l, int *r);
void swap(int *a, int *b);

int main() {
    int n = 0;
    int *data = malloc(n);
    if (!input(data, &n)) {
        sort(data, data + n);
        output(data, n);
    } else
        printf("n/a");
    free(data);
    return 0;
}

int input(int *a, int *n) {
    int result = 0;

    if (scanf("%d", n) == 1 && *n > 0 && *n <= NMAX) {
        int *p = a;
        for (; p - a < *n && !result; p++) {
            if (scanf("%d", p) != 1) result = 1;
        }
    } else
        result = 1;

    return result;
}

void output(int *a, int n) {
    int *p = a;
    for (; p - a < n - 1; p++) printf("%d ", *p);
    printf("%d\n", *p);
}

void sort(int *l, int *r) {
    if (r - l <= 1) return;
    int m = *(l + (r - l) / 2);
    int *ll = l;
    int *rr = r - 1;

    while (ll <= rr) {
        while (*ll < m) ll++;
        while (*rr > m) rr--;
        if (ll <= rr) {
            swap(ll, rr);
            ll++;
            rr--;
        }
    }

    if (l < rr) sort(l, rr + 1);
    if (ll < r) sort(ll, r);
}

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}
