#include <stdio.h>
#include <stdlib.h>

#define NA "n/a"
#define M 100
#define N 100

void allocate_memory_1(int*** matrix, int m, int n);
int pointer_array_within_one_buffer(int*** matrix, int *m, int *n);

int input_dynamic(int **matrix, int m, int n);
void output_matrix(int **matrix, int m, int n);

int sum(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result);
int transpose(int **matrix, int m, int n);
int mul(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result);

int calculate() {
    int operation = 0;
    int m, n;
    if (scanf("%d", &operation) == 1) {
        int result = 0;
        switch (operation) {
        case 1: //sum
                int **matrix_first, n_first, m_first; 
                int **matrix_second, n_second, m_second;
                int **matrix_result, n_result, m_result;
                int in1 = pointer_array_within_one_buffer(&matrix_first, &n_first, &m_first);
                int in2 = pointer_array_within_one_buffer(&matrix_second, &n_second, &m_second);
                if (!in1 && !in2) result = sum(matrix_first, n_first, m_first, matrix_second, n_second, m_second, matrix_result, &n_result, &m_result);
                
                if (in1 != 2) free(matrix_first);
                if (in2 != 2) free(matrix_second);
                if (!result) free(matrix_result);
                break;
        case 2: //mult
                int **matrix_first, n_first, m_first; 
                int **matrix_second, n_second, m_second;
                int **matrix_result, n_result, m_result;
                int in1 = pointer_array_within_one_buffer(&matrix_first, &n_first, &m_first);
                int in2 = pointer_array_within_one_buffer(&matrix_second, &n_second, &m_second);
                if (!in1 && !in2) result = mul(matrix_first, n_first, m_first, matrix_second, n_second, m_second, matrix_result, &n_result, &m_result);
                
                if (in1 != 2) free(matrix_first);
                if (in2 != 2) free(matrix_second);
                if (!result) free(matrix_result);
                break;
        case 3: //transpose
                int **matrix, m, n; 
                int in = pointer_array_within_one_buffer(&matrix, &m, &n);
                if (!in) result = transpose(matrix, m, n);
                
                if (in != 2) free(matrix);
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

void allocate_memory_1(int*** matrix, int m, int n) {
    *matrix = malloc(m * n * sizeof(int) + m * sizeof(int *));
    if (*matrix != NULL) {
        int *ptr = (int *)(*matrix + m);
        for (int i = 0; i < m; i++) {
            (*matrix)[i] = ptr + (n)*i;
        }
    }
}

int pointer_array_within_one_buffer(int*** matrix, int *m, int *n) {
    int result = 0;
    
    if (scanf("%d %d", m, n) == 2 && *n > 0 && *n <= N && *m > 0 && *m <= M) {
        allocate_memory_1(matrix, *m, *n);
        
        if (*matrix != NULL) {
            result = input_dynamic(*matrix, *m, *n);

            if (result == 0) {
                printf("\n===out===\n");
                output_matrix(*matrix, *m, *n);
            }
        }
    } else result = 2;
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


void output_matrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j != n - 1) printf(" ");
        }
        if (i != m - 1) printf("\n");
    }
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

int transpose(int **matrix, int m, int n) {
    int result = 0;
    int **matrix_tmp;
    allocate_memory_1(&matrix_tmp, m, n);
    if (matrix_tmp != NULL) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix_tmp[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrix_tmp[i][j];
        }
    }
    free(matrix_tmp);
    } else result = 1;
    return result; 
}

int mul(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result) {
    int result = 0;
    if (n_first == m_second) {
        *m_result = m_first;
        *n_result = n_second;
        allocate_memory_1(&matrix_result, *m_result, *n_result);

        for (int i = 0; i < m_result; i++)
            for (int j = 0; j < n_result; j++) {
                matrix_result[i][j] = 0;
                for (int k = 0; k < n_first; k++)
                    matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }

        printf("\n===mul result===\n");
        output_matrix(matrix_result, *m_result, *n_result);
    } else result = 1;
    return result;
}
