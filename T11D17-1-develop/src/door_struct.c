#include "door_struct.h"

#include <stdio.h>

void output(struct door *doors, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i < n - 1) printf("\n");
    }
}

void sort(struct door *l, struct door *r) {
    if (r - l > 1) {
        struct door m = *(l + (r - l) / 2);
        struct door *ll = l;
        struct door *rr = r - 1;

        while (ll <= rr) {
            while (cmp(*ll, m) == -1) ll++;
            while (cmp(*rr, m) == 1) rr--;
            if (ll <= rr) {
                swap(ll, rr);
                ll++;
                rr--;
            }
        }

        if (l < rr) sort(l, rr + 1);
        if (ll < r) sort(ll, r);
    }
}

int cmp(struct door a, struct door b) {
    int res = 0;
    if (a.id > b.id) res = 1;
    if (a.id < b.id) res = -1;
    return res;
}

void swap(struct door *a, struct door *b) {
    struct door x;
    write_door(*a, &x);
    write_door(*b, a);
    write_door(x, b);
}

void write_door(struct door from, struct door *to) {
    (*to).id = from.id;
    (*to).status = from.status;
}

void set_status(struct door *doors, int n, int new_status) {
    for (int i = 0; i < n; i++) doors[i].status = new_status;
}
