#include "max_prime_devisor.h"
#include "char_decode.h"
#include "ABH_functions.h"
#include "fibonacci.h"

void test_max_prime_number();
void test_char_code_decode(int argc, char *argv[]);
void test_functions();
void test_fibonacci();

int main(){
    test_max_prime_number();
    test_char_code_decode(int argc, char *argv[]);
    test_functions();
    test_fibonacci();
    return 0;
}

void test_max_prime_number() {
    printf("test_max_prime_number\n=================\n");
    int a = 0;
    if (scanf("%d", &a) == 1 && a != 0)
        printf("%d", max_prime_number(a));
    else
        printf("n/a");
    printf("\n----------------------\n");
}

void test_char_code_decode(int argc, char *argv[]) {
    printf("test_char_code_decode\n=================\n");
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
    printf("\n----------------------\n");
}

void test_functions() {
    printf("test_functions\n=================\n");
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
    printf("\n----------------------\n");
}

void test_fibonacci() {
    printf("test_fibonacci\n=================\n");
    int n;
    if (scanf("%d", &n) == 1 && n >= 0)
        printf("%d", recursive_fibonacci(n));
    else
        printf("n/a");
    printf("\n----------------------\n");
}
