#include <stdio.h>
#include <stdlib.h>
#include "matrix_extended.h"

void test_matrix_extended() {
    printf("START > test_matrix_extended >\n");
    int result = menu_matrix_extended();
    if (!result) printf("\nSUCCESS :)\n");
    else printf("\nFAIL :'(\n");
    printf("\n\t>> END\n");
}

int menu_matrix_extended() {
    int mode = 0;
    int m, n;
    if (scanf("%d", &mode) == 1 && mode > 0 && mode <= 4) {
        if (scanf("%d %d", &m, &n) == 2 && n > 0 && n <= N && m > 0 && m <= M) {
            int result = 0;
            switch (mode) {
                case STATIC_ARRAY:
                    result = static_array(m, n);
                    break;
                case POINTERS_WITHIN_ONE_BUFFER:
                    result = pointer_array_within_one_buffer(m, n);
                    break;
                case POINTERS_TO_ARRAYS:
                    result = pointer_array_of_arrays(m, n);
                    break;
                case POINTERS_TO_SEGMENTS:
                    result = pointer_array_of_segments(m, n);
                    break;
                default:
                    printf(NA);
                    break;
            }
            if (result == 1) printf(NA);
        } else
            printf(NA);
    } else printf(NA);
    return 0;
}

//matrix_sort.c
void matrix_sort(int **matrix, int m, int n) {
    printf("\n---sum in rows---\n");
    int sum[M];
    for (int i = 0; i < m; i++) {
        sum[i] = 0;
        for (int j = 0; j < n; j++)
            sum[i] += matrix[i][j];
            
        printf("%d : %d\n", i, sum[i]);
    }
    printf("\n---sort---\n");
    for (int k = 0; k < m; k++) {
        int index = k;
        for (int i = k + 1; i < m; i++) {
            if (sum[i] < sum[k]) {
                int tmp = sum[i];
                sum[i] = sum[k];
                sum[k] = tmp;
                
                for (int j = 0; j < n; j++) {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = tmp;
                }   
            }
        }
    }

    output_matrix(matrix, m, n);
}

void minmax(int **matrix, int m, int n, int *min, int *max) {
    printf("\n---max in rows---\n");
    for (int i = 0; i < m; i++) {
        max[i] = matrix[i][0];
        for (int j = 1; j < n; j++)
            if (matrix[i][j] > max[i]) max[i] = matrix[i][j];
    }
    output_vector(max, m);
    printf("\n---min in columns---\n");
    for (int j = 0; j < n; j++) {
        min[j] = matrix[0][j];
        for (int i = 1; i < m; i++)
            if (matrix[i][j] < min[j]) min[j] = matrix[i][j];
    }
    output_vector(min, n);
}

int static_array(int m, int n) {
    int result = 0;
    int matrix[M][N];
    
    result = input_static(matrix, m, n);

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

int input_static(int matrix[M][N], int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (scanf("%d", &matrix[i][j]) != 1) result = 1;
    }
    return result;
}

void allocate_memory_1(int*** matrix, int m, int n) {
    *matrix = malloc(m * n * sizeof(int) + m * sizeof(int *));
    if (*matrix != NULL) {
        int *ptr = (int *)(*matrix + m);
        for (int i = 0; i < m; i++) {
            (*matrix)[i] = ptr + (n)*i;
        }
    }
}

int pointer_array_within_one_buffer(int m, int n) {
    int result = 0;
    
    int **matrix;
    allocate_memory_1(&matrix, m, n);
    
    if (matrix != NULL) {
        result = input_dynamic(matrix, m, n);

        if (result == 0) {
            printf("\n===out===\n");
            output_matrix(matrix, m, n);

            int min[N], max[M];
            minmax(matrix, m, n, min, max);

            matrix_sort(matrix, m, n);
        }
    }

    free(matrix);
    return result;
}

int input_dynamic(int** matrix, int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) result = 1;
        }
    }
    return result;
}

void allocate_memory_2(int*** matrix, int m, int n) {
    *matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        (*matrix)[i] = malloc(n * sizeof(int));
    }
}

int pointer_array_of_arrays(int m, int n) {
    int result = 0;

    int **matrix;
    allocate_memory_2(&matrix, m, n);

    if (matrix != NULL) {
        result = input_dynamic(matrix, m, n);

        if (result == 0) {
            printf("\n===out===\n");
            output_matrix(matrix, m, n);
            
            int min[N], max[M];
            minmax(matrix, m, n, min, max);

            matrix_sort(matrix, m, n);
        }
    } else
        result = 1;

    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
    return result;
}

void allocate_memory_3(int*** matrix, int **val, int m, int n) {
    *matrix = malloc(m * sizeof(int *));
    *val = malloc(m * n * sizeof(int));
}

int pointer_array_of_segments(int m, int n) {
    int result = 0;

    int **matrix; int *val;
    allocate_memory_3(&matrix, &val, m, n);

    if (matrix != NULL) {
        for (int i = 0; i < m; i++) matrix[i] = val + n * i;
        
        result = input_dynamic(matrix, m, n);

        if (result == 0) {
            printf("\n===out===\n");
            output_matrix(matrix, m, n);
         
            int min[N], max[M];
            minmax(matrix, m, n, min, max);

            matrix_sort(matrix, m, n);
        }
    } else
        result = 1;

    free(val);
    free(matrix);
    return result;
}

void output_matrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j != n - 1) printf(" ");
        }
        //if (i != m - 1) 
        printf("\n");
    }
}

void output_vector(int *vector, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d", vector[i]);
        if (i != m - 1) printf(" ");
    }
}
