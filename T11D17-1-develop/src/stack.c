#include "stack.h"

#include <stdlib.h>

void init(Stack *stack, int val) {
    stack->size = 0;
    stack->top = 0;
    stack->data = malloc(sizeof(int));
    stack->data[0] = val;
}

void push(Stack *stack, int val) {
    stack->size++;
    stack->top++;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
    stack->data[stack->top] = val;
}

int pop(Stack *stack) {
    int res = stack->data[stack->top];
    stack->size--;
    stack->top--;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
    return res;
}

void destroy(Stack *stack) { free(stack->data); }
