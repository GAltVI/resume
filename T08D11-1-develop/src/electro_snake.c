#include <stdio.h>
#include <stdlib.h>

#include "electro_snake.h"

/*
    1 6 7
    2 5 8
    3 4 9
*/
/*
    1 2 3
    6 5 4
    7 8 9
*/

int move_like_snake() {
    int result = 0;
    int m = 0;
    int n = 0;
    int matrix[M][N];

    if (!input(matrix, &m, &n)) {
        snake_sort(matrix, m, n);
    } else result = 1;
    
    if (result) printf(NA);

    return result;
}

int input(int matrix[M][N], int *m, int *n) {
    int result = 0;
    if (scanf("%d%d", m, n) == 2 && *m > 0 && *n > 0) {
        for (int i = 0; i < *m; i++) {
            for (int j = 0; j < *n; j++)
                if (scanf("%d", &matrix[i][j]) != 1) result = 1;
        }
    } else result = 1;
    return result;
}

void output(int matrix[M][N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j != n - 1) printf(" ");
        }
        if (i != m - 1) printf("\n");
    }
}

void snake_sort(int matrix[M][N], int m, int n) {
    snake_horizontal(matrix, m, n);
    printf("\n\n");
    snake_vertical(matrix, m, n);
}

void snake_horizontal(int matrix[M][N], int m, int n) {
    //printf("\n~~~BEFORE~~~\n");
    //output(matrix, m, n);
    int matrix_h[M][N];
    copy_matrix(matrix, matrix_h, m, n);
    
    //printf("\n~~~snake~~~>horizontal\n");
    int tmp = 0;
    for (int i = 1; i < m; i = i+2) 
    {
        for (int j = n - 1, k = 0; j > k; j--, k++)
        {
            tmp = matrix_h[i][j];
            matrix_h[i][j] = matrix_h[i][k];
            matrix_h[i][k] = tmp;
        }
    }
    //printf("\n~~~AFTER~~~\n");
    output(matrix_h, m, n);
}
void snake_vertical(int matrix[M][N], int m, int n) {
    //printf("\n~~~BEFORE~~~\n");
    //output(matrix, m, n);
    int matrix_v[M][N];
    copy_matrix(matrix, matrix_v, m, n);
    
    //printf("\n~~~snake~~~>vertical\n");
    int k = 0;
    int l = 0;
    int step = 1;
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) {
            matrix_v[k][l] = matrix[i][j];

            k += step;
            if (k == m) {
                l++;
                k = m - 1;
                step *= -1;
            } else if (k == -1) {
                l++;
                k = 0;
                step *= -1;
            }
        }
    }
    //printf("\n~~~AFTER~~~\n");
    output(matrix_v, m, n);
}

void copy_matrix(int from[M][N], int to[M][N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            to[i][j] = from[i][j];
        }
    }
}
