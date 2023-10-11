# T08D11

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

***Сортировка заданной целочисленной матрицы змейкой по горизонтали и вертикали. Вывод отсортированных матриц в таком же порядке подряд с пустой строкой между ними. В случае ошибок выводится `n/a`.***

| Входные данные | Выходные данные |
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

***Вычисление определителя заданной квадратной матрицы с вещественными числами. Если определитель подсчитать невозможно, то выводится "n/a".***

| Входные данные | Выходные данные |
| ------ | ------ |
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

***Вычисление и вывод обратной матрицы для заданной квадратной матрицы с вещественными числами. В случае ошибки выводится "n/a". Числа выводятся через пробел с точностью 6 знаков после запятой.***

| Входные данные | Выходные данные |
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

***Решение СЛАУ A*x=b либо методом Крамера, либо методом Гаусса (в случае, если определитель матрицы A равен 0, при этом свободные переменные равны 1). Коэффициенты уравнения вводятся в виде матрицы через stdin. Варианты сообщений об ошибках: <br/> ERROR:  Can't solve SLAE (equations count is not equal variables count).<br/>ERROR: Invalid input.<br/> Решение выводится через пробел с точностью 6 знаков после запятой.***

| Входные данные | Выходные данные |
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

***Тестирование модулей: electro_snake, det, invert, sle.***
<br/>
