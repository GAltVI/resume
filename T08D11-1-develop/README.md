# T08
The russian version of the task can be found in the repository.

## Contents

8. [Modules](#modules) \
 8.1. [electro_snake](#electro_snake) \
 8.2. [det](#det) \
 8.3. [invert](#invert) \
 8.4. [sle](#sle) \
 8.5. [test](#test)


# Modules 

## electro_snake
>**electro_snake.h | electro_snake.c**

>int move_like_snake(); 
<br/>int input(int matrix[M][N], int *m, int *n);
<br/>void output(int matrix[M][N], int m, int n);
<br/>void snake_sort(int matrix[M][N], int m, int n);
<br/>void snake_horizontal(int matrix[M][N], int m, int n);
<br/>void snake_vertical(int matrix[M][N], int m, int n);
<br/>void copy_matrix(int from[M][N], int to[M][N], int m, int n);

***The sorting of the given matrix in a snake-like order vertically and horizontally, and outputs the sorted matrices in the same order, one after another, with an empty line in between. In case of any erros it outputs "n/a".***

| Input | Output |
| ------ | ------ |
| 3 3<br/>1 2 3<br/>4 5 6<br/>7 8 9 | 1 2 3<br/>6 5 4<br/>7 8 9<br/><br/>1 6 7<br/>2 5 8<br/>3 4 9<br/> |
| 2 4<br/>1 2 3 4<br/>5 6 7 8 | 1 2 3 4<br/>8 7 6 5<br/><br/>1 4 5 8<br/>2 3 6 7<br/> |
| 0 0 | n/a |

<br/>


## det

>**det.h | det.c**

>void test_det();
<br/>int input(double ***matrix, int *n, int *m);
<br/>void output(double **matrix, int m, int n);
<br/>double det(double **matrix, int m);
<br/>void minor(double **mas, double **M, int i, int j, int m);

***It calculates and outputs the determinant of the given square matrix with float numbers. If it's impossible to calculate the determinant, it outputs "n/a". Output numbers with an accuracy of 6 decimal places.***

| Input | Output |
| 3 3<br/>1 2 3<br/>4 5 6<br/>7 8 9 | 0.000000 |
| 3 3<br/>1 2 3<br/>4 5 6.00013<br/>7 8 9 | 0.000780 |
| 1 1<br/>4 | 4.000000 |
| 0 0 | n/a |

<br/>


## invert

>**invert.h | invert.c**

>void allocate_memory(double ***matrix, int n, int m);
<br/>int input(double ***matrix, int *n, int *m);
<br/>void output(double **matrix, int n, int m);
<br/>int invert(double **matrix, int n, int m, double ***matrix_inv);
<br/>double det(double **matrix, int m);
<br/>void minor(double **matrix, double **M, int i, int j, int m);
<br/>void test_invert();

***It calculates and outputs the inverse matrix for the given square matrix with float numbers. For errors, it displays "n/a".***

| Input | Output |
| ------ | ------ |
| 3 3<br/>1 0.5 1<br/>4 1 2<br/>3 2 2 | -1.000000 0.500000 0.000000<br/>-1.000000 -0.500000 1.000000<br/>2.500000 -0.250000 -0.500000 |
| 2 2<br/>1 2<br/>3 4 | -2.000000 1.000000<br/>1.500000 -0.500000 |
| 1 1 | n/a |
| 2 3 | n/a |

<br/>


## sle

>void test_sle();
<br/>int input_sle(double ***matrix, int *m, int *n);
<br/>int sle(double **matrix, int m, int n, double **roots);
<br/>int cramer(double **matrix, int m, int n, double **roots);
<br/>int gauss(double **matrix, int m, int n, double **roots);
<br/>void output_roots(double *roots, int n);

***It solves a system of linear equations using either Cramer's rule or Gaussian elimination. Equation coefficients is entered as a matrix via stdin. Errors variations are: <br/> ERROR:  Can't solve SLAE (equations count is not equal variables count).<br/>ERROR: Invalid input.<br/> Numbers should be separated by a space with an accuracy of 6 decimal places.***

| Input | Output |
| ------ | ------ |
| 3 4<br/>1 1 1 2<br/>4 5 3 7<br/>2 7 7 9 | 1.000000 0.000000 1.000000 |
| 2 3<br/>506 66 2315.1<br/>66 11 392.3 | -0.351818 37.774545 |
| 1 2<br/>0.5 4 | 8.000000 |
| 2 4 | n/a |
| 2 3<br/>1 0 3<br/>0 0 2 | n/a | 
| 4 5<br/>2 3 -1 1 1<br/>8 12 -9 8 3<br/>4 6 3 -2 3<br/>2 3 9 -7 3 | -1.000000 1.000000 1.000000 1.000000 |

<br/>


## test

```c
#include <stdio.h>

#include "det.h"
#include "sle.h"

int main() {
    int test_no;
    printf("-----------\nelectro snake test - 1\n");
    printf("determinant test - 2\n");
    printf("invert matrix test - 3\n");
    printf("SLE test - 4\n-----------\n");
    printf("test number > ");
    scanf("%d", &test_no);
    switch (test_no) {
        case 1: printf("~~~test_electro_snake~~~\n");
                move_like_snake();
                break;
        case 2: printf("~~~test_det~~~\n");
                test_det();
                break;
        case 3: printf("~~~test_invert~~~\n");
                test_invert();
                break;
        case 4: printf("~~~test_sle~~~\n");
                test_sle();
                break;
        default: break;
    }
    return 0;
>}
```

***Testing of modules: electro_snake, det, invert, sle.***
<br/>