#include <stdio.h>
#include "sort.h"

void test_sort();
void test_bignum();
void test_several_arrays();

int main() {
    test_sort();
    test_bignum();
    test_several_arrays();
    return 0;
}

void test_sort() {
    printf("\n===\ntest sort===\n");
    int data[N];
    int dataCopy[N];
    if (!input(data)) {
        copy_arr(data, dataCopy, N);

        printf("\n---------------------\nquick sort: ");
        quick_sort(data, data + N);
        output(data, N);

        printf("\n---------------------\npyramid sort: ");
        pyramid_sort(dataCopy, N);
        output(dataCopy, N);
    } else
        printf("n/a");
}

void test_bignum() {
    printf("\n===\ntest bignum===\n");
    int len1, buff1[LEN];
    int len2, buff2[LEN];
    int sum_length, result_sum[LEN + 1];
    int sub_length, result_sub[LEN];

    if (!input(buff1, &len1) && !input(buff2, &len2)) {
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
    printf("\n===\ntest several arrays===\n");
    int data[NMAX];
    int n = 0;
    if (!input(data, &n)) {
        int counter = 0;
        int number = sum_numbers(data, n, &counter);
        if (counter) {
            printf("%d\n", number);
            int numbers[NMAX];
            int numbersLength = find_numbers(data, n, number, numbers);
            if (numbersLength)
                output(numbers, numbersLength);
            else
                printf("n/a");
        } else
            printf("n/a");
    } else
        printf("n/a");
}

