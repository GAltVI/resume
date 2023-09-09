#include "data_sort.h"

void sort(double *l, double *r) {
    if (r - l <= 1) return;
    double m = *(l + (r - l) / 2);
    double *ll = l;
    double *rr = r - 1;

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

void swap(double *a, double *b) {
    double x = *a;
    *a = *b;
    *b = x;
}
