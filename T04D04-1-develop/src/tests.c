#include "max_prime_devisor.h"
#include "char_decode.h"
#include "ABH_functions.h"
#include "fibonacci.h"

int test_max_prime_number() {
    int a = 0;
    if (scanf("%d", &a) == 1 && a != 0)
        printf("%d", max_prime_number(a));
    else
        printf("n/a");
    return 0;
}

int test_char_code_decode(int argc, char *argv[]) {
    int result = 0;
    
    if (argc == 2) {
        switch (*argv[1]) {
            case '0': result = code(); break;
            case '1': result = decode(); break;
            default: result = 0; break;
        }
    } else
        result = 0;
    
    if (!result) printf("n/a");
    return 0;
}

int test_functions() {
    double x = -1 * M_PI;
    double step = 2. * M_PI / (N - 1);
    double funB, funH;
    for (int i = 0; i < N; i++) {
        printf("%.7f | %.7f | ", x, agnesi(x));
        funB = bernoulli(x);
        if (funB == 0)
            printf("- | ");
        else
            printf("%.7f | ", funB);
        funH = hyperbola(x);
        if (funH == 0)
            printf("-\n");
        else
            printf("%.7f\n", funH);
        x += step;
    }
    return 0;
}

int test_fibonacci() {
    int n;
    if (scanf("%d", &n) == 1 && n >= 0)
        printf("%d", recursive_fibonacci(n));
    else
        printf("n/a");
    return 0;
}
