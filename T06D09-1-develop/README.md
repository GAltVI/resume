# T06
The russian version of the task can be found in the repository.

## Contents

1. [Modules](#modules) \
 3.1.  [sort](#sort) \
 3.2.  [several arrays](#several-arrays) \
 3.3.  [сyclic shift](#сyclic-shift) \
 3.4.  [bignum { arbitrary precision arithmetic }](#bignum-{-arbitrary-precision-arithmetic-})

# Modules

## sort

>***sort.h | sort.c***

>int input(int *a);
><br/>void output(int *a, int n);

Input and output an array of integers.

>void copy_arr(int *a, int *aCopy, int n);

Copy an array of integers from a to aCopy.

>void quick_sort(int *l, int *r);

Quick sort algorithm.

>void pyramid_sort(int *a, int n);
><br/>void heapify(int *a, int n);

Heapsort algorithm.

>void swap(int *a, int *b);

Swap two elements of array.

***The program sorts an array of 10 integer elements in ascending order using two different sorting algorithms: quicksort and heapsort. In the first line of stdout, output the array sorted by the first algorithm; in the second line–by the second algorithm. 
<br/>Passing an array to a function by pointer. 
<br/>For errors, display "n/a".***

| Input | Output |
| ------ | ------ |
| 4 3 9 0 1 2 100 2 7 -1 | -1 0 1 2 2 3 4 7 9 100<br/>-1 0 1 2 2 3 4 7 9 100 |

<br/>


## several arrays

>***several_arrays.h | several_arrays.c***

***The program receive the array's length and an array of integers. The program output in stdout the sum of the even elements of the array and the newly formed array from the elements of the old one, by which the previously calculated sum is divided evenly. 
<br/>Passing an array to a function by pointer. 
<br/>The maximum size of the input array is 10. 
<br/>In case of an error or the absence of even elements, display "n/a".***

Note: zero is odd number.

| Input | Output |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 0 2 7 -1 | 8<br/>4 1 2 2 -1 |

<br/>


## сyclic shift

>***сyclic_shift.h | сyclic_shift.c***

***The program receives a number `n`, an array `A` with `n` integers, and a number `c` by which all elements of the array is rotated to the left. If the value of `c` is negative, the shift in the array occur to the right. A modified array is expected as output.
<br/>Passing an array to a function by pointer. 
<br/>The maximum size of the input array is 10. 
<br/>For errors, display "n/a".***

| Input | Output |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 0 2 7 -1<br/>2 | 9 0 1 2 0 2 7 -1 4 3 |

<br/>


## bignum { arbitrary precision arithmetic }

>***bignum.h | bignum.c***

***The program returns the result of addition and subtraction of two very large numbers that were passed to the program as input in the form of arrays. Maximum number length: 100 elements of type int. The entered integers are decimal digits. If the subtrahend is higher than the minuend, "n/a" is displayed instead of the difference. 
<br/>Passing an array to a function by pointer. 
<br/>For errors, display "n/a".***

| Input | Output |
| ------ | ------ |
| 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1<br/>2 9 | 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0<br/>1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2 |
| 0 1 0<br/>0 0 1 | 1 1<br/>9 |

