#include <stdio.h>

int recursive_fibonacci(int i);

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n >= 0)
        printf("%d", recursive_fibonacci(n));
    else
        printf("n/a");
    return 0;
}

int recursive_fibonacci(int i) {
    if (i == 0)
        return 0;

    if (i == 1)
        return 1;

    return recursive_fibonacci(i - 1) + recursive_fibonacci(i - 2);
}
