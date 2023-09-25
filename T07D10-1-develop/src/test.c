#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "matrix_extended.h"
#include "matrix_arithmetic.h"

void test_task_0();

int main() {
    test_sort();
    test_matrix_extended();
    test_matrix_arithmetic();

    test_task_0();
}

void test_task_0() {
    int **matrix_first, n_first, m_first; 
    int **matrix_second, n_second, m_second;
    int **matrix_result, n_result, m_result;
    int in1, in2;
    
    in1 = create_matrix(&matrix_first, &m_first, &n_first);
    in2 = create_matrix(&matrix_second, &m_second, &n_second);
    if (!in1 && !in2) {
        in1 = transpose(&matrix_first, &m_first, &n_first);
        printf("\nAFTER after transp\n");
        output_matrix(matrix_first, m_first, n_first);
        printf("\n``````\n");
        if (!in1) {
            printf("\nmul: [%dx%d] * [%dx%d]\n", m_first, n_first, m_second, n_second);
            in2 = mul(matrix_first, m_first, n_first, matrix_second, m_second, n_second, matrix_result, &m_result, &n_result);
            if (!in2) free(matrix_result);
        }
        free(matrix_first);
        free(matrix_second);
    } else printf("\n! ERROR n/a\n");
}
