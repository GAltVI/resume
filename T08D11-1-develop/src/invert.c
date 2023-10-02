#include <stdio.h>
#include <stdlib.h>

#define NA "n/a"

void allocate_memory(double ***matrix, int n, int m);
int input(double ***matrix, int *n, int *m);
void output(double **matrix, int n, int m);

void invert(double **matrix, int n, int m, double ***matrix_inv);
double det(double **matrix, int m);
void minor(double **matrix, double **M, int i, int j, int m);

void main() { 
    int m, n;
    double **matrix = NULL;
    double **matrix_inv = NULL;

    if (input(&matrix, &n, &m)) {
        allocate_memory(&matrix_inv, n, m);
        if (*matrix_inv) {
            invert(matrix, m, n, &matrix_inv);
            printf("\n~~~RESULT~~~\n");
            output(matrix_inv, n, m);
        } else
            printf(NA);
    }
    else
        printf(NA);

    for (int i = 0; i < m; i++) {
        free(matrix[i]); 
        free(matrix_inv[i]);
    }
    free(matrix);
    free(matrix_inv);
}

void allocate_memory(double ***matrix, int n, int m) {
    *matrix = malloc(m * sizeof(double *));
    if (*matrix) {
        for (int i = 0; i < m; i++) {
            (*matrix)[i] = malloc(n * sizeof(double));
        }
    }
}

int input(double ***matrix, int *n, int *m) {
    int result = 1;
    if (scanf("%d %d", n, m) == 2 && *n > 0 && *m > 0 && *m == *n) {
        allocate_memory(matrix, *n, *m);
        if (*matrix) {
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

void invert(double **matrix, int n, int m, double ***matrix_inv) {
    if (m == 1) {
        (*matrix_inv)[0][0] = 1;
        // return;
    } else if (m > 1) {
        double **M = malloc((m-1) * sizeof(double *));
        for (int i = 0; i < (m-1); i++) {
            M[i] = malloc((m-1) * sizeof(double));
        }

        double d = det(matrix, m);
        printf("\nDET = %lf\n\n", d);
        int coeff = 1;
        int iter = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minor(matrix, M, i, j, m);
                printf("\niter %d: i = %d, j = %d\n", iter, i, j);
                output(M, m - 1, n - 1);
                printf("\n");
                iter++;
                (*matrix_inv)[j][i] = det(M, (m - 1)) * coeff * matrix[i][j] / d;
                coeff = -coeff;
            }
        }

        for (int i = 0; i < m; i++) free(M[i]);
        free(M);
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

    double **M = malloc((m-1) * sizeof(double *));
    for (int i = 0; i < (m-1); i++) {
        M[i] = malloc((m-1) * sizeof(double));
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
        shift_j = 0;

        for (int M_j = 0; M_j < (m - 1); M_j++) {
            if (M_j == j) shift_j = 1;

            M[M_i][M_j] = matrix[M_i + shift_i][M_j + shift_j];
        }
    }
}
