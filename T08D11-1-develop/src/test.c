#include <stdio.h>

#include "det.h"
#include "sle.h"

int main() {
    int test_no;
    printf("-----------\nelectro snake test - 1\n");
    printf("determinant test - 2\n");
    printf("invert matrix test - 3\n");
    printf("SLE test - 4\n-----------\n");
    printf("test number > ");
    scanf("%d", &test_no);
    switch (test_no) {
        case 1: printf("~~~test_electro_snake~~~\n");
                move_like_snake();
                break;
        case 2: printf("~~~test_det~~~\n");
                test_det();
                break;
        case 3: printf("~~~test_invert~~~\n");
                test_invert();
                break;
        case 4: printf("~~~test_sle~~~\n");
                test_sle();
                break;
        default: break;
    }
    return 0;
}