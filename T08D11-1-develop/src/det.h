#ifndef DET_H
#define DET_H

#define NA "n/a"

void test_det();
int input(double ***matrix, int *n, int *m);
void output(double **matrix, int m, int n);
double det(double **matrix, int m);
void minor(double **mas, double **M, int i, int j, int m);

#endif