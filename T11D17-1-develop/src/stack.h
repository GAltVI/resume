#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int size;
    int top;
    int *data;
} Stack;

void init(Stack *stack, const int val);
void push(Stack *stack, const int val);
int pop(Stack *stack);
void destroy(Stack *stack);

#endif
