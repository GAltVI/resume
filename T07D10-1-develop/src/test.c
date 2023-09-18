#include <stdio.h>
#include <stdlib.h>
//#include "matrix.h"
#include "matrix_extended.h"

int main() {
    int mode = 0;
    int m, n;
    if (scanf("%d", &mode) == 1 && mode > 0 && mode <= 4) {
        if (scanf("%d %d", &m, &n) == 2 && n > 0 && n <= N && m > 0 && m <= M) {
            int result = 0;
            switch (mode) {
                case STATIC_ARRAY:
                    result = static_array(m, n);
                    break;
                case POINTERS_TO_SEGMENTS:
                    result = pointer_array_of_segments(m, n);
                    break;
                case POINTERS_WITHIN_ONE_BUFFER:
                    result = pointer_array_within_one_buffer(m, n);
                    break;
                case POINTERS_TO_ARRAYS:
                    result = pointer_array_of_arrays(m, n);
                    break;
                default:
                    printf(NA);
                    break;
            }
            if (result == 1) printf(NA);
        } else
            printf(NA);
    } else
        printf(NA);
    return 0;
}
