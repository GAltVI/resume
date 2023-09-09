#include "data_stat.h"

double max(double *data, int n) {
    double *p = data;
    double max = *p;
    p++;
    for (; p - data < n; p++)
        if (*p > max) max = *p;
    return max;
}

double min(double *data, int n) {
    double *p = data;
    double min = *p;
    p++;
    for (; p - data < n; p++)
        if (*p < min) min = *p;
    return min;
}

double mean(double *data, int n) {
    double mean = 0.;
    if (n > 1) {
        for (double *p = data; p - data < n; p++) mean += *p;
        mean /= n;
    } else
        mean = *data;
    return mean;
}

double variance(double *data, int n) {
    double d = 0.;
    if (n > 1) {
        double sqr[n];
        squaring(sqr, data, n);
        double m = mean(data, n);
        d = mean(sqr, n) - m * m;
    }
    return d;
}

void squaring(double *sqr, double *data, int n) {
    for (double *p = data, *psqr = sqr; p - data < n; p++, psqr++) *psqr = *p * *p;
}
