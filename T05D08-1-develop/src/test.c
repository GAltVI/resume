#include <stdio.h>
#include "search.h"
//#define NMAX 10

int main() {
    int n;
    int data[NMAX];
    if (!input(data, &n)) {
        int max_v = max(data, n);
        int min_v = min(data, n);
        double mean_v = mean(data, n);
        double variance_v = variance(data, n);
        printf("%d %d %.6f %.6f %d", max_v, min_v, mean_v, variance_v, search(data, n, mean_v, variance_v));
    } else
        printf("n/a");

    return 0;
}
