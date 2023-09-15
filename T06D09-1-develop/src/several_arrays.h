#ifndef H_SEVERAL_ARRAYS
#define H_SEVERAL_ARRAYS

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length, int *counter);
int find_numbers(int *buffer, int length, int number, int *numbers);

#endif
