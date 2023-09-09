#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length, int *counter);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int data[NMAX];
    int n = 0;
    if (!input(data, &n)) {
        int counter = 0;
        int number = sum_numbers(data, n, &counter);
        if (counter) {
            printf("%d\n", number);
            int numbers[NMAX];
            int numbersLength = find_numbers(data, n, number, numbers);
            if (numbersLength)
                output(numbers, numbersLength);
            else
                printf("n/a");
        } else
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

int input(int *buffer, int *length) {
    int result = 0;
    char ch;
    if (scanf("%d%c", length, &ch) == 2 && *length > 0 && *length <= NMAX && ch == '\n') {
        int *p = buffer;
        for (; p - buffer < *length - 1 && !result; p++) {
            if (scanf("%d%c", p, &ch) != 2 || ch != ' ') result = 1;
        }
        if (scanf("%d%c", p, &ch) != 2 || ch != '\n') result = 1;
    } else
        result = 1;
    return result;
}

void output(int *buffer, int length) {
    int *p = buffer;
    for (; p - buffer < length - 1; p++) printf("%d ", *p);
    printf("%d\n", *p);
}

int sum_numbers(int *buffer, int length, int *counter) {
    int sum = 0;
    *counter = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && buffer[i] % 2 == 0) {
            sum += buffer[i];
            (*counter)++;
        }
    }

    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0)
            if (number % buffer[i] == 0) {
                numbers[j] = buffer[i];
                j++;
            }
    }

    return j;
}
