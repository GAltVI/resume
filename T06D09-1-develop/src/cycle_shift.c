#include <stdio.h>
#include "cycle_shift.h"
#include "io_array.h"

int input_shift(int *buffer, int *length, int *c) {
    int result = 0;
    char ch;
    if (!input(buffer, length)) {
        if (scanf("%d%c", c, &ch) != 2 || ch != '\n') result = 1;
    } else
        result = 1;
    return result;
}

int cycle_shift(int *buffer, int length, int c) {
    int return_code = 0;
    if (length > 0) {
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
    } else
        return_code = 1;
    return return_code;
}

void reverse(int *buffer, int length) {
    int tmp = 0;
    for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
        tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
    }
}
