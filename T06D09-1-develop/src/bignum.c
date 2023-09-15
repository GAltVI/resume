#include <stdio.h>
#include "bignum.h"
#include "cycle_shift.h"
#include "io_array.h"

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int buffNumber = get_lager_buffer(len1, len2);

    if (buffNumber == 1)
        sum_by_shift(buff1, len1, buff2, len2, result, result_length);
    else
        sum_by_shift(buff2, len2, buff1, len1, result, result_length);
}

void sum_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length) {
    int sum = 0;
    *result_length = 0;
    for (int i = 0; i < lenMAX; i++) {
        cycle_shift(buffMAX, lenMAX, -1);
        sum += *buffMAX;
        if (i < lenMIN) {
            cycle_shift(buffMIN, lenMIN, -1);
            sum += *buffMIN;
        }
        cycle_shift(result, lenMAX, -1);
        *result = sum % TEN;
        (*result_length)++;

        sum /= TEN;
    }

    if (sum > 0) {
        (*result_length)++;
        cycle_shift(result, (*result_length), -1);
        *result = sum;
    }

    delete_unsign_zero(result, result_length);
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int sub = 0;
    int get_high_order_bit = 0;
    *result_length = 0;
    for (int i = 0; i < len1; i++) {
        cycle_shift(buff1, len1, -1);
        sub = *buff1;

        if (get_high_order_bit) {
            sub--;
            get_high_order_bit = 0;
        }

        if (i < len2) {
            cycle_shift(buff2, len2, -1);
            sub -= *buff2;
        }

        if (sub < 0) {
            sub += TEN;
            get_high_order_bit = 1;
        }

        cycle_shift(result, len1, -1);
        *result = sub;
        (*result_length)++;
    }
    delete_unsign_zero(result, result_length);
}

int get_lager_buffer(int len1, int len2) {
    int result = 0;
    if (len1 > len2) result = 1;
    if (len1 < len2) result = 2;
    return result;
}

void delete_unsign_zero(int *buff, int *len) {
    while (*buff == 0 && *len > 0) {
        cycle_shift(buff, (*len), 1);
        (*len)--;
    }
}
