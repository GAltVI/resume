#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

#define OK "SUCCESS\n"
#define NO "FAIL\n"

void test_add_1(int test_number);
void test_add_2(int test_number);

void test_remove_1(int test_number);
void test_remove_2(int test_number);
void test_remove_3(int test_number);
void test_remove_4(int test_number);

int main() {
    int test_number = 1;
    test_add_1(test_number);
    test_number++;
    test_add_2(test_number);

    test_remove_1(test_number);
    test_number++;
    test_remove_2(test_number);
    test_number++;
    test_remove_3(test_number);
    test_number++;
    test_remove_4(test_number);

    return 0;
}

void test_add_1(int test_number) {  // add to NOT empty list
    printf("\n-----------\nadd test %d\n-----------\n", test_number);
    struct door door1;
    door1.id = 12;
    door1.status = 1;
    struct door door2;
    door2.id = 10;
    door2.status = 0;

    struct node* list = init(&door1);
    printf("list before:\n");
    print_list(list);

    list = add_door(list, &door2);

    printf("list after:\n");
    print_list(list);

    if (list->next_door != NULL)
        printf(OK);
    else
        printf(NO);

    destroy(list);
}

void test_add_2(int test_number) {  // add to EMPTY list
    printf("\n-----------\nadd test %d\n-----------\n", test_number);
    struct door door;
    door.id = 12;
    door.status = 1;

    struct node* list = NULL;
    printf("list before:\n");
    print_list(list);

    list = add_door(list, &door);

    printf("list after:\n");
    print_list(list);

    if (list != NULL)
        printf(OK);
    else
        printf(NO);

    free(list);
}

void test_remove_1(int test_number) {  // remove FIRST node, nodes count > 1
    printf("\n-----------\nremove test %d\n-----------\n", test_number);
    struct door door1;
    door1.id = 10;
    door1.status = 1;
    struct door door2;
    door2.id = 12;
    door2.status = 0;
    struct door door3;
    door3.id = 14;
    door3.status = 0;

    struct node* list = init(&door1);
    list = add_door(list, &door2);
    list = add_door(list, &door3);
    printf("list before:\n");
    print_list(list);

    list = remove_door(list, list);
    printf("list after:\n");
    print_list(list);

    if (list->door.id != door1.id)
        printf(OK);
    else
        printf(NO);

    destroy(list);
}

void test_remove_2(int test_number) {  // remove any node, nodes count > 1
    printf("\n-----------\nremove test %d\n-----------\n", test_number);
    struct door door;
    door.id = 10;
    door.status = 1;
    struct door door2;
    door2.id = 12;
    door2.status = 0;
    struct door door3;
    door3.id = 14;
    door3.status = 0;

    struct node* list = init(&door);
    list = add_door(list, &door2);
    list = add_door(list, &door3);
    printf("list before:\n");
    print_list(list);

    list = remove_door(list->next_door, list);
    printf("list after:\n");
    print_list(list);

    if (find_door(door2.id, list) == NULL)
        printf(OK);
    else
        printf(NO);

    destroy(list);
}

void test_remove_3(int test_number) {  // remove FIRST node, nodes count = 1
    printf("\n-----------\nremove test %d\n-----------\n", test_number);
    struct door door;
    door.id = 10;
    door.status = 1;

    struct node* list = init(&door);
    printf("list before:\n");
    print_list(list);

    list = remove_door(list, list);
    printf("list after:\n");
    print_list(list);

    if (list == NULL)
        printf(OK);
    else
        printf(NO);

    destroy(list);
}

void test_remove_4(int test_number) {  // remove node from EMPTY list
    printf("\n-----------\nremove test %d\n-----------\n", test_number);
    struct door door;
    door.id = 10;
    door.status = 1;

    struct node* list = NULL;
    struct node* elem = init(&door);
    printf("list before:\n");
    print_list(list);

    struct node* remove_list = remove_door(elem, list);
    printf("list after:\n");
    print_list(remove_list);

    if (remove_list == NULL)
        printf(OK);
    else
        printf(NO);

    destroy(elem);
    destroy(list);
}
