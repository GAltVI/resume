#ifndef H_MATRIX_ARITHMETIC
#define H_MATRIX_ARITHMETIC

void test_matrix_arithmetic();

int menu_matrix_arithmetic();
int create_matrix(int*** matrix, int *m, int *n);

int sum(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result);
int transpose(int ***matrix, int *m, int *n);
int mul(int **matrix_first, int m_first, int n_first, int **matrix_second, int m_second, int n_second, int **matrix_result, int *m_result, int *n_result);

#endif