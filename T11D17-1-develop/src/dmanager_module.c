#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

// #define DOORS_COUNT 999
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors, int doors_count);

int main() {
    // struct door doors[DOORS_COUNT];
    int doors_count = 0;
    if (scanf("%d", &doors_count) == 1 && doors_count > 1) {
        struct door * doors = malloc(doors_count * sizeof(struct door));
    
        initialize_doors(doors, doors_count);
        output(doors, doors_count);
        printf("\n\n");
        set_status(doors, doors_count, 0);
        sort(doors, doors + doors_count);
        output(doors, doors_count);
    
        free(doors);
    } else printf("ERROR: invalid input");
    return 0;
}

// Doors initialization function
void initialize_doors(struct door* doors, int doors_count) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < doors_count; i++) {
        doors[i].id = (i + seed) % doors_count;
        doors[i].status = rand() % 2;
    }
}
