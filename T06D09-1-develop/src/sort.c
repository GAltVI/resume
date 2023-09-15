#include <stdio.h>
#include "sort.h"

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
