#include <stdio.h>
#include <stdlib.h>
#define NA "n/a"

int input(double ***matrix, int *m, int *n);
void output(double **matrix, int m, int n);
double det(double **matrix, int m);
void minor(double **mas, double **M, int i, int j, int m);

int sle(double **matrix, int m, int n, double *roots);
void output_roots(double *roots, int m);

void main() {
    int result = 0;
    int m, n;
    double **matrix = NULL;
    double *roots = NULL;

    if (input(&matrix, &m, &n)) {
        roots = malloc(n * sizeof(double));
        result = sle(matrix, m, n, roots);
        if (result) {
            output_roots(roots, m);
        } else printf("ERROR: Can't solve SLAE by Cramer's rule (determinant = 0).\n");
    }
    else
        printf(NA);

    free(roots);
    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
}

int input(double ***matrix, int *m, int *n) {
    int result = 1;
    if (scanf("%d %d", m, n) == 2 && *m > 0 && *n > 0) {
        *matrix = malloc(*m * sizeof(double *));
        
        if (*matrix) {
            for (int i = 0; i < *m; i++) {
                (*matrix)[i] = malloc(*n * sizeof(double));
            }
            for (int i = 0; i < *m; i++) {
                for (int j = 0; j < *n; j++)
                    if (scanf("%lf", &(*matrix)[i][j]) != 1) {
                        result = 0;
                    }
            }
        } else result = 0;
    } else result = 0;
    return result;
}

void output(double **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        int j = 0;
        for (; j < n - 1; j++) printf("%lf ", matrix[i][j]);
        printf("%lf", matrix[i][j]);

        if (i != m - 1) printf("\n");
    }
}

double det(double **matrix, int m) {
    double d = 0;
    if (m == 1) {
        return matrix[0][0];
    }

    if (m == 2) {
        d = (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
        return d;
    }

    double **M = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        M[i] = malloc(m * sizeof(double));
    }

    int coeff = 1;

    if (m > 2) {
        for (int i = 0; i < m; i++) {
            minor(matrix, M, i, 0, m);
            d = d + coeff * matrix[i][0] * det(M, (m - 1));
            coeff = -coeff;
        }
    }

    for (int i = 0; i < m; i++) free(M[i]);
    free(M);
    return d;
}

void minor(double **matrix, double **M, int i, int j, int m) {
    int shift_i = 0;
    int shift_j = 0;
    for (int M_i = 0; M_i < (m - 1); M_i++) {
        if (M_i == i) shift_i = 1;

        for (int M_j = 0; M_j < (m - 1); M_j++) {
            if (M_j == j) shift_j = 1;

            M[M_i][M_j] = matrix[M_i + shift_i][M_j + shift_j];
        }
    }
}

int sle(double **matrix, int m, int n, double *roots) {
    int result = 1;
    double **matrix_k = malloc(m * sizeof(double *));
    if (matrix_k) {
        for (int i = 0; i < m; i++) {
            matrix_k[i] = malloc((n - 1) * sizeof(double));
        }
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                    matrix_k[i][j] = matrix[i][j];  
            }
        }
        double d = det(matrix_k, m);
        // printf("\n~~~calc~~~\n");
        // printf("d = %.6lf\n", d);
        if (d != 0) {
            double d_k = 0;
            for (int k = 0; k < n - 1; k++)
            {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n - 1; j++) {
                        if (j == k) {
                            matrix_k[i][j] = matrix[i][n - 1];  
                        } else {
                            matrix_k[i][j] = matrix[i][j];  
                        }
                    }
                }
                // printf("<A%i>\n", k + 1);
                // output(matrix_k, m, n - 1);
                // d_k = det(matrix_k, m);
                // printf("\nd%i = %.6lf\n", k + 1, d_k);
                roots[k] = d_k / d;
            }
        } else result = 0;
        
        for (int i = 0; i < m; i++) free(matrix_k[i]);
    } else result = 0;
    free(matrix_k);
    return result;
}

void output_roots(double *roots, int m) {
    for (int i = 0; i < m; i++) {
        printf("%lf", roots[i]);
        if (i != m - 1) printf("\n");
    }
}