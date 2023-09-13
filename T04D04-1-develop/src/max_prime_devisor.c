#include <stdio.h>
#include "max_prime_devisor.h"

//максимальный простой делитель числа a
int max_prime_divisor(int a) {
    if (a < 0) a *= -1;
    int pn = a;
    int mpn = a;
    while (pn > 0) {
        int counter = 1;
        for (int i = 2; i <= pn; i++) {
            if (div(pn, i) == 0) {
                counter++;
            }
        }
        if (counter == 2) {
            if (div(a, pn) == 0) {
                mpn = pn;
                break;
            }
        }
        pn--;
    }
    return mpn;
}

//остаток от деления a на b (a % b)
int euclid_div(int a, int b) {
    int res = a;
    while (res >= b) {
        res -= b;
    }
    return res;
}

//проверка на делимость числа a на b
///#in: a - делимое целое
///     b - делитель целое
///#out: b - если делитель
///      0 - иначе
int div(int a, int b) {
    if (b && euclid_div(a, b)) return b;
    return 0;
}
