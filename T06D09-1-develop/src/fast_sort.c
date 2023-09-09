#include <stdio.h>
#define N 10

int input(int *a);
void output(int *a, int n);
void copy_arr(int *a, int *aCopy, int n);
void quick_sort(int *l, int *r);
void pyramid_sort(int *a, int n);
void heapify(int *a, int n);
void swap(int *a, int *b);

int main() {
    int data[N];
    int dataCopy[N];
    if (!input(data)) {
        copy_arr(data, dataCopy, N);

        quick_sort(data, data + N);
        output(data, N);

        pyramid_sort(dataCopy, N);
        output(dataCopy, N);
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

void copy_arr(int *a, int *aCopy, int n) {
    int *p = a;
    int *pCopy = aCopy;
    for (; p - a < n; p++, pCopy++) *pCopy = *p;
}

void quick_sort(int *l, int *r) {
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
    if (l < rr) quick_sort(l, rr + 1);
    if (ll < r) quick_sort(ll, r);
}

void pyramid_sort(int *a, int n) {
    while (n > 1) {
        heapify(a, n);
        swap(a, a + n - 1);
        n--;
    }
}

void heapify(int *a, int n) {
    int i = n / 2 - 1;
    int largest, leftChild, rightChild;
    do {
        largest = i;
        leftChild = 2 * i;
        rightChild = 2 * i + 1;
        if (*(a + leftChild) > *(a + i)) largest = leftChild;
        if (*(a + rightChild) > *(a + largest)) largest = rightChild;
        swap(a + i, a + largest);
        i--;
    } while (i >= 0);
}

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}
