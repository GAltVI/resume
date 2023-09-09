#include <stdio.h>
#include <stdlib.h>

#define NA "n/a"

int input(double **matrix, int n, int m);
void output(double **matrix, int m, int n);
double det(double **matrix, int m);
void minor(double **mas, double **M, int i, int j, int m);

int main() {
    int m, n;
    if (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0 && m == n) {
        double **matrix = malloc(m * sizeof(double *));
        for (int i = 0; i < m; i++) {
            matrix[i] = malloc(n * sizeof(double));
        }

        if (!input(matrix, n, m)) {
            printf("%.6lf", det(matrix, m));
        } else
            printf(NA);

        for (int i = 0; i < m; i++) free(matrix[i]);
        free(matrix);

    } else
        printf(NA);

    return 0;
}

int input(double **matrix, int n, int m) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (scanf("%lf", &matrix[i][j]) != 1) result = 1;
    }
    return result;
}

void output(double **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        int j = 0;
        for (; j < n - 1; j++) printf("%lf", matrix[i][j]);
        printf("%lf", matrix[i][j]);

        if (i != m - 1) printf("\n");
    }
}

double det(double **matrix, int m) {
    // if (m < 1) printf(NA);
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
