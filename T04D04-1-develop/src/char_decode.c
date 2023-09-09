#include <stdio.h>

int code();
int check_input_in_decod(char ch1, char ch2, char ch3);
int check_hex(char ch);
int upper_case(char ch);
int decode();

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (*argv[1] == '0') {
            if (code()) printf("n/a");
        } else {
            if (*argv[1] == '1') {
                if (decode()) printf("n/a");
            } else
                printf("n/a");
        }
    } else
        printf("n/a");
    return 0;
}

int code() {
    int res = 0;
    char ch1, ch2;
    do {
        scanf("%c%c", &ch1, &ch2);
        if (ch1 != ' ' && ch1 != '\n' && (ch2 == ' ' || ch2 == '\n')) {
            printf("%X", ch1);
            if (ch2 == ' ') printf("%c", ch2);
        } else {
            res = 1;
            break;
        }
    } while (ch2 != '\n');
    return res;
}

int check_input_in_decode(char ch1, char ch2, char ch3) {
    int res = 0;
    if (check_hex(ch1) == 1) res = 1;
    if (check_hex(ch2) == 1) res = 1;
    if (ch3 != ' ' && ch3 != '\n') res = 1;
    return res;
}

int check_hex(char ch) {
    int res = 1;
    if (ch >= '0' && ch <= '9') res = 0;
    if (ch >= 'A' && ch <= 'F') res = 0;
    if (ch >= 'a' && ch <= 'f') res = 0;
    return res;
}

int upper_case(char ch) {
    if (ch >= 'a' && ch <= 'f') ch -= 32;
    return ch;
}

int decode() {
    int res = 0;
    int i = 0;
    char ch1, ch2, ch3;
    do {
        ch1 = getchar();
        ch2 = getchar();
        ch3 = getchar();
        if (check_input_in_decode(ch1, ch2, ch3) == 1) {
            res = 1;
            break;
        }
        ch1 = upper_case(ch1);
        ch2 = upper_case(ch2);
        i = 0;
        if (ch1 >= '0' && ch1 <= '9')
            i += 16 * (ch1 - '0');
        else {
            i += 16 * (ch1 - 55);
        }
        if (ch2 >= '0' && ch2 <= '9')
            i += ch2 - '0';
        else {
            i += ch2 - 55;
        }
        printf("%c", i);
        if (ch3 == ' ') printf(" ");
    } while (ch3 != '\n');
    return res;
}
