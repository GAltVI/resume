#include <stdio.h>
#include "sort.h"

int main() {
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

    return 0;
}
