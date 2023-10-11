#include <stdio.h>
#include <stdlib.h>

#include "sle.h"

void test_sle() {
    int result = 0;
    int m, n;
    double **matrix = NULL;
    double *roots = NULL;

    if (input_sle(&matrix, &m, &n)) {
        roots = malloc((n - 1) * sizeof(double));
        printf("\n");
        if (sle(matrix, m, n, &roots)) {
            output_roots(roots, n - 1);
        } else printf("ERROR:  Can't solve SLAE (equations count is not equal variables count).");
    } else printf("ERROR: Invalid input.");
    printf("\n");
    free(roots);
    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
}

int sle(double **matrix, int m, int n, double **roots) {
    int result = 1;
    if (cramer(matrix, m, n, roots)) {
    } else if (gauss(matrix, m, n, roots)) {
    } else result = 0;
    return result;
}

int input_sle(double ***matrix, int *m, int *n) {
    int result = 1;
    if (scanf("%d %d", m, n) == 2 && *m > 0 && *n > 1 && *m == *n - 1) {
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

int cramer(double **matrix, int m, int n, double **roots) {
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
                d_k = det(matrix_k, m);
                // printf("\nd%i = %.6lf\n", k + 1, d_k);
                (*roots)[k] = d_k / d;
            }
        } else result = 0;
        
        for (int i = 0; i < m; i++) free(matrix_k[i]);
    } else result = 0;
    free(matrix_k);
    return result;
}

int gauss(double **matrix, int m, int n, double **roots) {
    int result = 1;
    double **matrix_k = malloc(m * sizeof(double *));
    if (matrix_k) {
        for (int i = 0; i < m; i++) {
            matrix_k[i] = malloc(n * sizeof(double));
        }
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                    matrix_k[i][j] = matrix[i][j];  
            }
        }
        
        // printf("\n~~~calc~~~\n");
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < m; i++) {
                if (matrix_k[k][k] != 0) {
                    double coeff_col = matrix_k[i][k];
                    for (int j = k; j < n; j++) {
                        matrix_k[i][j] -= matrix_k[k][j] * coeff_col /  matrix_k[k][k];
                    }
                }
                // printf("\n<A%i>\n", k + 1);
                // output(matrix_k, m, n);
            }
        }
        
        for (int j = n - 2; j >= 0; j--) {
            if (matrix_k[j][j] == 0) {
                (*roots)[j] = 1;
            } else {
                double val = matrix_k[j][n - 1]; //последний стoлбец СЛУ или вектор b в A*x=b
                for (int k = j + 1; k < n - 1; k++) {
                    val -= (*roots)[k] * matrix_k[j][k];
                }
                (*roots)[j] = val / matrix_k[j][j];
            }
        }
        
        for (int i = 0; i < m; i++) free(matrix_k[i]);
    } else result = 0;
    free(matrix_k);
    return result;
}

void output_roots(double *roots, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf", roots[i]);
        if (i != n - 1) printf(" ");
    }
}