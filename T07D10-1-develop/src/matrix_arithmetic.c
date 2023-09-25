#include <stdio.h>
#include <stdlib.h>
#include "matrix_extended.h"
#include "matrix_arithmetic.h"

void test_matrix_arithmetic() {
    printf("START > test_matrix_arithmetic >\n");
    int result = menu_matrix_arithmetic();
    if (!result) printf("\nSUCCESS :)\n");
    else printf("\nFAIL :'(\n");
    printf("\n\t>> END\n");
}

int menu_matrix_arithmetic() {
    int result = 0;
    int operation = 0;
    if (scanf("%d", &operation) == 1) {
        int **matrix_first, n_first, m_first; 
        int **matrix_second, n_second, m_second;
        int **matrix_result, n_result, m_result;
        int **matrix, m, n;
        int in1, in2, in;
        switch (operation) {
        case 1: //sum
                in1 = create_matrix(&matrix_first, &m_first, &n_first);
                in2 = create_matrix(&matrix_second, &m_second, &n_second);
                if (!in1 && !in2) result = sum(matrix_first, m_first, n_first, matrix_second, m_second, n_second, matrix_result, &m_result, &n_result);
                
                if (in1 != 2) free(matrix_first);
                if (in2 != 2) free(matrix_second);
                if (!result) free(matrix_result);
                break;
        case 2: //mult
                in1 = create_matrix(&matrix_first, &m_first, &n_first);
                in2 = create_matrix(&matrix_second, &m_second, &n_second);
                if (!in1 && !in2) result = mul(matrix_first, m_first, n_first, matrix_second, m_second, n_second, matrix_result, &m_result, &n_result);
                
                if (in1 != 2) free(matrix_first);
                if (in2 != 2) free(matrix_second);
                if (!result) free(matrix_result);
                break;
        case 3: //transpose
                in = create_matrix(&matrix, &m, &n);
                if (!in) {
                    result = transpose(&matrix, &m, &n);
                    free(matrix);
                }
                break;
        default:
                printf(NA);
                break;
        }
        if (result == 1) printf(NA);
    } else
        printf(NA);
    return 0;
}

int create_matrix(int*** matrix, int *m, int *n) {
    int result = 0;
    
    if (scanf("%d %d", m, n) == 2 && *n > 0 && *n <= N && *m > 0 && *m <= M) {
        allocate_memory_1(matrix, *m, *n);
        
        if (*matrix != NULL) {
            result = input_dynamic(*matrix, *m, *n);

            if (result == 0) {
                printf("\n---matrix---\n");
                output_matrix(*matrix, *m, *n);
                printf("\n------------\n");
            }
        }
    } else result = 2;
    return result;
}

int sum(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result){
    int result = 0;
    if (m_first == m_second && n_first == n_second) {
        *m_result = m_first;
        *n_result = n_first;
        allocate_memory_1(&matrix_result, *m_result, *n_result);

        for (int i = 0; i < m_first; i++)
            for (int j = 0; j < n_first; j++)
                matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];

        printf("\n===sum result===\n");
        output_matrix(matrix_result, *m_result, *n_result);
    } else result = 1;
    return result;
}

int transpose(int ***matrix, int *m, int *n) {
    int result = 0;
    int tmp;
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            tmp = (*matrix)[j][i];
            (*matrix)[j][i] = (*matrix)[i][j];
            (*matrix)[i][j] = tmp;
        }
    }
    
    tmp = *m;
    *m = *n;
    *n = tmp;
    printf("\n===transpose result===\n");
    output_matrix(*matrix, *m, *n);
    return result; 
}

int mul(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result) {
    int result = 0;
    if (n_first == m_second) {
        *m_result = m_first;
        *n_result = n_second;
        allocate_memory_1(&matrix_result, *m_result, *n_result);

        for (int i = 0; i < *m_result; i++)
            for (int j = 0; j < *n_result; j++) {
                matrix_result[i][j] = 0;
                for (int k = 0; k < n_first; k++)
                    matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }

        printf("\n===mul result===\n");
        output_matrix(matrix_result, *m_result, *n_result);
    } else result = 1;
    return result;
}
