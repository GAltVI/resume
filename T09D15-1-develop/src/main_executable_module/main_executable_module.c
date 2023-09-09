#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_sort.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data;
    int n;

    printf("LOAD DATA...\n");
    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));

        if (input(data, n) == 0 && data != NULL) {
            printf("RAW DATA:\n\t");
            output(data, n);

            printf("\nNORMALIZED DATA:\n\t");
            int is_normalized = normalization(data, n);
            if (is_normalized)
                output(data, n);
            else
                printf("ERROR");

            printf("\nSORTED NORMALIZED DATA:\n\t");
            if (is_normalized) {
                sort(data, data + n);
                output(data, n);
            } else
                printf("ERROR");

            printf("\nFINAL DECISION:\n\t");
            if (make_decision(data, n))
                printf("YES");
            else
                printf("NO");
        } else
            printf("ERROR");
        free(data);
    } else
        printf("ERROR");

    return 0;
}
