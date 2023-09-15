#include <stdio.h>
#include "several_arrays.h"

int sum_numbers(int *buffer, int length, int *counter) {
    int sum = 0;
    *counter = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && buffer[i] % 2 == 0) {
            sum += buffer[i];
            (*counter)++;
        }
    }

    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0)
            if (number % buffer[i] == 0) {
                numbers[j] = buffer[i];
                j++;
            }
    }

    return j;
}
