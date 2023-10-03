#ifndef INVERT_H
#define INVERT_H

#define NA "n/a\n"

void allocate_memory(double ***matrix, int n, int m);
int input(double ***matrix, int *n, int *m);
void output(double **matrix, int n, int m);

int invert(double **matrix, int n, int m, double ***matrix_inv);
double det(double **matrix, int m);
void minor(double **matrix, double **M, int i, int j, int m);

void test_invert();

#endif