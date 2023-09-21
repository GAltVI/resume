#ifndef H_MATRIX_EXTENDED
#define H_MATRIX_EXTENDED

#define M 100
#define N 100
#define STATIC_ARRAY 1
#define POINTERS_WITHIN_ONE_BUFFER 2
#define POINTERS_TO_ARRAYS 3
#define POINTERS_TO_SEGMENTS 4
#define NA "n/a"

void matrix_sort(int **matrix, int m, int n);
void minmax(int **matrix, int m, int n, int *min, int *max);
int static_array(int m, int n);

void allocate_memory_1(int*** matrix, int m, int n);
int pointer_array_within_one_buffer(int m, int n);

void allocate_memory_2(int*** matrix, int m, int n);
int pointer_array_of_arrays(int m, int n);

void allocate_memory_3(int*** matrix, int** val, int m, int n);
int pointer_array_of_segments(int m, int n);

int input_static(int matrix[M][N], int m, int n);
int input_dynamic(int** matrix, int m, int n);

void output_matrix(int **matrix, int m, int n);
void output_vector(int *vector, int m);

#endif
