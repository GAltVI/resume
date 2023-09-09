#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status;
};

void output(struct door *doors, int n);
void sort(struct door *l, struct door *r);
int cmp(struct door a, struct door b);
void swap(struct door *a, struct door *b);
void write_door(struct door from, struct door *to);
void set_status(struct door *doors, int n, int new_status);

#endif
