#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int static_array(int m, int n) {
    int result = 0;
    int matrix[M][N];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (scanf("%d", &matrix[i][j]) != 1) result = 1;
    }

    if (result == 0) {
        for (int i = 0; i < m; i++) {
            int j = 0;
            for (; j < n - 1; j++) printf("%d ", matrix[i][j]);
            printf("%d", matrix[i][j]);

            if (i != m - 1) printf("\n");
        }
    }

    return result;
}

int pointer_array_within_one_buffer(int m, int n) {
    int result = 0;

    int **matrix = malloc(m * n * sizeof(int) + m * sizeof(int *));

    if (matrix != NULL) {
        int *ptr = (int *)(matrix + m);
        for (int i = 0; i < m; i++) matrix[i] = ptr + (n)*i;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (scanf("%d", &matrix[i][j]) != 1) result = 1;
        }

        if (result == 0) output(matrix, m, n);
    }

    free(matrix);
    return result;
}

int pointer_array_of_arrays(int m, int n) {
    int result = 0;

    int **matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }

    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (scanf("%d", &matrix[i][j]) != 1) result = 1;
        }

        if (result == 0) output(matrix, m, n);
    } else
        result = 1;

    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
    return result;
}

int pointer_array_of_segments(int m, int n) {
    int result = 0;

    int **ptr = malloc(m * sizeof(int *));
    int *val = malloc(m * n * sizeof(int));

    if (ptr != NULL) {
        for (int i = 0; i < m; i++) ptr[i] = val + n * i;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (scanf("%d", &ptr[i][j]) != 1) result = 1;
        }

        if (result == 0) output(ptr, m, n);
    } else
        result = 1;

    free(val);
    free(ptr);
    return result;
}

void output(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        int j = 0;
        for (; j < n - 1; j++) printf("%d ", matrix[i][j]);
        printf("%d", matrix[i][j]);

        if (i != m - 1) printf("\n");
    }
}
