#ifndef H_CYCLE_SHIFT
#define H_CYCLE_SHIFT

#define NMAX 10

int input(int *buffer, int *length, int *c);
void output(int *buffer, int length);
int cycle_shift(int *buffer, int length, int c);
void reverse(int *buffer, int length);

#endif