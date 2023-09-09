#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#define OK "SUCCESS\n"
#define NO "FAIL\n"
#define EVIL 666

void push_test(Stack *stack);
void pop_test(Stack *stack);

int main() {
    Stack stack;
    init(&stack, 10);

    printf("push test: ");
    push_test(&stack);

    printf("pop test: ");
    pop_test(&stack);

    destroy(&stack);

    return 0;
}

void push_test(Stack *stack) {
    push(stack, EVIL);
    if (stack->data[stack->top] == EVIL)
        printf(OK);
    else
        printf(NO);
}

void pop_test(Stack *stack) {
    if (pop(stack) == EVIL)
        printf(OK);
    else
        printf(NO);
}
