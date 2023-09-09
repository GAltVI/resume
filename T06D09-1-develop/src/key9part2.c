#include <stdio.h>

#define LEN 100
#define TEN 10

int input(int *buffer, int *length);
void output(int *buffer, int length);

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sum_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length);

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub_by_shift(int *buffMAX, int lenMAX, int *buffMIN, int lenMIN, int *result, int *result_length);

int cycle_shift(int *buffer, int length, int c);
void reverse(int *buffer, int length);

int get_lager_buffer(int len1, int len2);
void delete_unsign_zero(int *buff, int *len);

int main() {
    int len1, buff1[LEN];
    int len2, buff2[LEN];
    int sum_length, result_sum[LEN + 1];
    int sub_length, result_sub[LEN];

    if (!input(buff1, &len1) && !input(buff2, &len2)) {
        delete_unsign_zero(buff1, &len1);
        delete_unsign_zero(buff2, &len2);
        sum(buff1, len1, buff2, len2, result_sum, &sum_length);
        output(result_sum, sum_length);

        if (len1 >= len2) {
            sub(buff1, len1, buff2, len2, result_sub, &sub_length);
            output(result_sub, sub_length);
        } else
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

int input(int *buffer, int *length) {
    int result = 0;
    char ch = 0;
    (*length) = 0;

    for (int *p = buffer; ch != '\n' && !result; p++) {
        if (scanf("%d%c", p, &ch) == 2 && *p >= 0 && *p <= 9 && (ch == ' ' || ch == '\n'))
            (*length)++;
        else {
            result = 1;
            (*length) = 0;
        }
    }
    if (*length < 1 || *length > LEN) result = 1;

    return result;
}

void output(int *buffer, int length) {
    int *p = buffer;
    for (; p - buffer < length - 1; p++) printf("%d ", *p);
    printf("%d\n", *p);
}

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

int cycle_shift(int *buffer, int length, int c) {
    int result = 0;
    if (length != 0) {
        c %= length;
        if (c > 0) {
            reverse(buffer, c);
            reverse(buffer + c, length - c);
            reverse(buffer, length);
        } else {
            c *= -1;
            reverse(buffer, length - c);
            reverse(buffer + length - c, c);
            reverse(buffer, length);
        }
    } else {
        result = 1;
    }
    return result;
}

void reverse(int *buffer, int length) {
    int tmp = 0;
    for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
        tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
    }
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
