#include <stdio.h>

int recursive_fibonacci(int i) {
    if (i == 0)
        return 0;

    if (i == 1)
        return 1;

    return recursive_fibonacci(i - 1) + recursive_fibonacci(i - 2);
}
