#include <stdio.h>
#include "sort.h"
#include "bignum.h"
#include "several_arrays.h"
#include "cycle_shift.h"
#include "io_array.h"

void test_sort();
void test_bignum();
void test_several_arrays();
void test_cycle_shift();

int main() {
    test_sort();
    test_bignum();
    test_several_arrays();
    test_cycle_shift();
    return 0;
}

void test_sort() {
    printf("\n===test sort===\n");
    int data[N];
    int dataCopy[N];
    int n;
    if (!input(data, &n)) {
        copy_arr(data, dataCopy, n);

        printf("\n---------------------\nquick sort: ");
        quick_sort(data, data + n);
        output(data, n);

        printf("\n---------------------\npyramid sort: ");
        pyramid_sort(dataCopy, n);
        output(dataCopy, n);
    } else
        printf("n/a");
}

void test_bignum() {
    printf("\n===test bignum===\n");
    int len1, buff1[LEN];
    int len2, buff2[LEN];
    int sum_length, result_sum[LEN + 1];
    int sub_length, result_sub[LEN];

    if (!input_bignum(buff1, &len1) && !input_bignum(buff2, &len2)) {
        delete_unsign_zero(buff1, &len1);
        delete_unsign_zero(buff2, &len2);
        printf("\n---------------------\nsum: ");
        sum(buff1, len1, buff2, len2, result_sum, &sum_length);
        output(result_sum, sum_length);

        if (len1 >= len2) {
            printf("\n---------------------\nsub: ");
            sub(buff1, len1, buff2, len2, result_sub, &sub_length);
            output(result_sub, sub_length);
        } else
            printf("n/a");
    } else
        printf("n/a");
}

void test_several_arrays() {
    printf("\n===test several arrays===\n");
    int data[NMAX];
    int n = 0;
    if (!input(data, &n)) {
        int counter = 0;
        int number = sum_numbers(data, n, &counter);
        if (counter) {
            printf("\n---------------------\nsum of odd elements: %d\n", number);
            int numbers[NMAX];
            int numbersLength = find_numbers(data, n, number, numbers);
            if (numbersLength) {
                printf("new array: ");
                output(numbers, numbersLength);
            }
            else
                printf("n/a");
        } else
            printf("n/a");
    } else
        printf("n/a");
}

void test_cycle_shift() {
    printf("\n===test cycle shift===\n");
    int data[NMAX];
    int n = 0;
    int c = 0;
    if (!input_shift(data, &n, &c)) {
        if (cycle_shift(data, n, c) == 0){
            printf("\n---------------------\nresult: ");
            output(data, n);
        }
        else
            printf("n/a");
    } else
        printf("n/a");
}
