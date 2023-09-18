#ifndef H_MATRIX
#define H_MATRIX

#define M 100
#define N 100
#define STATIC_ARRAY 1
#define POINTERS_WITHIN_ONE_BUFFER 2
#define POINTERS_TO_ARRAYS 3
#define POINTERS_TO_SEGMENTS 4
#define NA "n/a"

void minmax(int **matrix, int m, int n, int *min, int *max);
int static_array(int m, int n);
int pointer_array_within_one_buffer(int m, int n);
int pointer_array_of_arrays(int m, int n);
int pointer_array_of_segments(int m, int n);

void output(int **matrix, int m, int n);

#endif
