#ifndef ELECTRO_SNAKE_H
#define ELECTRO_SNAKE_H

#define N 10
#define M 10
#define NA "n/a"

int move_like_snake(); 

int input(int matrix[M][N], int *m, int *n);
void output(int matrix[M][N], int m, int n);

void snake_sort(int matrix[M][N], int m, int n);
void snake_horizontal(int matrix[M][N], int m, int n);
void snake_vertical(int matrix[M][N], int m, int n);
void copy_matrix(int from[M][N], int to[M][N], int m, int n);

#endif