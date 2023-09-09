#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

#define ERR "ERROR"

int main() {
    double *data;
    int n = 0;

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));

        if (input(data, n) == 0 && data != NULL) {
            if (normalization(data, n))
                output(data, n);
            else
                printf(ERR);
        } else
            printf(ERR);

        free(data);
    } else
        printf(ERR);

    return 0;
}
