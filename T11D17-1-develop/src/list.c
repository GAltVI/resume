#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(const struct door* door) {
    struct node* list = (struct node*)malloc(sizeof(struct door));
    list->door = *(door);
    list->next_door = NULL;
    return list;
}

struct node* add_door(struct node* elem, const struct door* door) {
    struct node* tmp = (struct node*)malloc(sizeof(struct door));
    tmp->door = *(door);
    tmp->next_door = elem;
    return tmp;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* p_list = root;
    while (p_list) {
        if (p_list->door.id == door_id) {
            break;
        }
        p_list = p_list->next_door;
    }

    return p_list;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p_list = root;
    if (p_list != NULL) {
        if (p_list->next_door == NULL) {  // remove element from list which contains only one node
            if (p_list == elem) {
                free(p_list);
                p_list = NULL;
            }
        } else if (p_list == elem) {  // remove first element from list, nodes count > 1
            p_list = p_list->next_door;
            free(elem);
            elem = NULL;
        } else {
            while (p_list->next_door) {  // remove any element from list, nodes count > 1
                if ((p_list->next_door) == elem) {
                    break;
                }
                p_list = p_list->next_door;
            }

            p_list->next_door = elem->next_door;
            free(elem);
            // elem = NULL;
        }
        root = p_list;
    } else {
        root = NULL;
    }
    return root;
}

struct node* destroy(struct node* root) {
    while (root) {
        root = remove_door(root, root);
    }
    return root;
}

void print_list(struct node* list) {
    if (list != NULL) {
        struct node* p_list = list;
        while (p_list) {
            printf("%d, %d\n", p_list->door.id, p_list->door.status);
            p_list = p_list->next_door;
        }
    } else
        printf("list empty\n");
}
