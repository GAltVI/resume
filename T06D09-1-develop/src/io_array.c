#include <stdio.h>
#include "io_array.h"

int input(int *buffer, int *length) {
    int result = 0;
    char ch;
    if (scanf("%d%c", length, &ch) == 2 && *length > 0 && *length <= NMAX && ch == '\n') {
        int *p = buffer;
        for (; p - buffer < *length - 1 && !result; p++) {
            if (scanf("%d%c", p, &ch) != 2 || ch != ' ') result = 1;
        }
        if (scanf("%d%c", p, &ch) != 2 || ch != '\n') result = 1;
    } else
        result = 1;
    return result;
}

void output(int *buffer, int length) {
    int *p = buffer;
    for (; p - buffer < length - 1; p++) printf("%d ", *p);
    printf("%d\n", *p);
}
