#include <stdio.h>
#define N 10

int input(int *a);
void output(int *a, int n);
void sort(int *l, int *r);
void swap(int *a, int *b);

int main() {
    int data[N];
    if (!input(data)) {
        sort(data, data + N);
        output(data, N);
    } else
        printf("n/a");

    return 0;
}

int input(int *a) {
    int result = 0;
    char ch;
    int *p = a;
    for (; p - a < N - 1 && !result; p++) {
        if (scanf("%d%c", p, &ch) != 2 || ch != ' ') result = 1;
    }
    if (scanf("%d%c", p, &ch) != 2 || ch != '\n') result = 1;

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
