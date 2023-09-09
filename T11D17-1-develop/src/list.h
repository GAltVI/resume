#ifndef LIST_H
#define LIST_H

#include "door_struct.h"
struct node {
    struct door door;
    struct node* next_door;
};

struct node* init(const struct door* door);
struct node* add_door(struct node* elem, const struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
struct node* destroy(struct node* root);

void print_list(struct node* list);

#endif
