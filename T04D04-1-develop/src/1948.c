#include <stdio.h>

int max_prime_number(int a);
int euclid_div(int a, int b);
int div(int a, int b);

int main() {
    int a = 0;
    if (scanf("%d", &a) == 1 && a != 0)
        printf("%d", max_prime_number(a));
    else
        printf("n/a");
    return 0;
}

int max_prime_number(int a) {
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

int euclid_div(int a, int b) {
    int res = a;
    while (res >= b) {
        res -= b;
    }
    return res;
}

int div(int a, int b) {
    if (euclid_div(a, b)) return b;
    return 0;
}
