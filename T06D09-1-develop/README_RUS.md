# T06

## Contents

6. [Modules](#modules) \
 6.1.  [io_array](#io_array) \
 6.2.  [sort](#sort) \
 6.3.  [several arrays](#several-arrays) \
 6.4.  [сyclic shift](#сyclic-shift) \
 6.5.  [bignum {arbitrary precision arithmetic}](#bignum-{arbitrary-precision-arithmetic})

# Modules

## io_array

>***io_array.h | io_array.c***

>int input(int *buffer, int *length);
><br/>void output(int *buffer, int length);

Ввод и вывод массива целых чисел.

<br/>


## sort

>***sort.h | sort.c***

>void copy_arr(int *a, int *aCopy, int n);

Копирование целочисленного массива из a в aCopy.

>void quick_sort(int *l, int *r);

Быстрая сортировка.

>void pyramid_sort(int *a, int n);
><br/>void heapify(int *a, int n);

Пирамидальная сортировка.

>void swap(int *a, int *b);

Перестановка двух элементов массива.

***Программа сортирует по возрастанию массив из 10 целочисленных элементов двумя разными алгоритмами сортировки: быстрая и пирамидальная сортировки. В stdout в первой строке выводится отсортированный массив первым алгоритмом, во второй соответственно вторым алгоритмом. 
<br/>Передача массива в функцию по указателю. 
<br/>В случае ошибки выводится "n/a".***

| Входные данные | Выходные данные |
| ------ | ------ |
| 4 3 9 0 1 2 100 2 7 -1 | -1 0 1 2 2 3 4 7 9 100<br/>-1 0 1 2 2 3 4 7 9 100 |

<br/>


## several arrays

>***several_arrays.h | several_arrays.c***

>int sum_numbers(int *buffer, int length, int *counter);
><br/>int find_numbers(int *buffer, int length, int number, int *numbers);

***Программа принимает на вход длину массива и массив целых чисел. Выводит в stdout сумму четных элементов массива и новый сформированный массив из элементов старого, на которые делится нацело подсчитанная ранее сумма. 
<br/>Передача массива в функцию по указателю. 
<br/>Максимальный размер входного массива - 10. 
<br/>В случае ошибки или отсутствии четных элементов выводится "n/a".***

Примечание: ноль - нечетное числом.

| Входные данные | Выходные данные |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 0 2 7 -1 | 8<br/>4 1 2 2 -1 |

<br/>


## сyclic shift

>***сyclic_shift.h | сyclic_shift.c***

>int input_shift(int *buffer, int *length, int *c);
><br/>int cycle_shift(int *buffer, int length, int c);
><br/>void reverse(int *buffer, int length);

***Программа ожидает на вход число `n`, массив `A` из `n` целых чисел и число `c`, на которое все элементы массива должны сдвинутся влево циклично. При этом, при отрицательном значении `c` сдвиг происходит вправо по массиву. Выводится измененный массив. 
<br/>Передача массива в функцию по указателю. 
<br/>Максимальный размер входного массива - 10. 
<br/>В случае ошибки выводится "n/a".***

| Входные данные | Выходные данные |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 0 2 7 -1<br/>2 | 9 0 1 2 0 2 7 -1 4 3 |

<br/>


## bignum {arbitrary precision arithmetic}

>***bignum.h | bignum.c***

>int input_bignum(int *buffer, int *length);

>void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
<br/>void sum_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length);

>void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
<br/>void sub_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length);

>int get_lager_buffer(int len1, int len2);
<br/>void delete_unsign_zero(int *buff, int *len);

***Программа вычисляет сумму и разность двух очень больших чисел, переданных программе на вход в виде массивов. Максимальная длина числа - 100 элементов типа int. Вводимые целые числа представляют собой десятичные цифры. В случае если вычитаемое больше уменьшаемого, в разности выводится "n/a". 
<br/>Передача массива в функцию по указателю. 
<br/>В случае ошибки выводится "n/a".***

| Входные данные | Выходные данные |
| ------ | ------ |
| 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1<br/>2 9 | 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0<br/>1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2 |
| 0 1 0<br/>0 0 1 | 1 1<br/>9 |

<br/>
