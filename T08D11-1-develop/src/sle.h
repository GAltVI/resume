#ifndef SLE_H
#define SLE_H

#include "det.h"

void test_sle();

int input_sle(double ***matrix, int *m, int *n);

int sle(double **matrix, int m, int n, double **roots);
int cramer(double **matrix, int m, int n, double **roots);
int gauss(double **matrix, int m, int n, double **roots);

void output_roots(double *roots, int n);

#endif