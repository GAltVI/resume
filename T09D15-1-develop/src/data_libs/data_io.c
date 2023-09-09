#include "data_io.h"

#include <stdio.h>

int input(double *data, int n) {
    int result = 0;
    for (double *p = data; p - data < n && !result; p++) {
        if (scanf("%lf", p) != 1) {
            result = 1;
        }
    }
    return result;
}

void output(double *data, int n) {
    double *p = data;
    for (; p - data < n - 1; p++) printf("%.2lf ", *p);
    printf("%.2lf", *p);
}
