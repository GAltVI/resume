#include <stdio.h>
#include "char_decode.h"

//вывод не печать шестнадцатеричного кода символов
int code() {
    int res = 1;
    char ch1, ch2;
    do {
        scanf("%c%c", &ch1, &ch2);
        if (ch1 != SP && ch1 != NL && (ch2 == SP || ch2 == NL)) {
            printf("%X", ch1);
            if (ch2 == SP) printf("%c", ch2);
        } else {
            res = 0;
            break;
        }
    } while (ch2 != NL);
    return res;
}

//проверка входных данных при декодировании
///ch1, ch2 - должны принадлежать множеству H = {0-9, a-f, A-F} 
///ch3 - пробел или перевод строки
int check_input_in_decode(char ch1, char ch2, char ch3) {
    int res = 1;
    if (!check_hex(ch1) || !check_hex(ch2) || (ch3 != SP && ch3 != NL)) res = 0;
    return res;
}

int check_hex(char ch) {
    int res = 0;
    if (ch >= '0' && ch <= '9') res = 1;
    else if (ch >= 'A' && ch <= 'F') res = 1;
    return res;
}

//перевод в верхний регистр
char upper_case(char ch) {
    if (ch >= 'a' && ch <= 'f') ch -= 32;
    return ch;
}

//декодирование
int decode() {
    int res = 1;
    char ch1, ch2, ch3;
    do {
        scanf("%c%c%c", &ch1, &ch2, &ch3);
        ch1 = upper_case(ch1);
        ch2 = upper_case(ch2);
        if (!check_input_in_decode(ch1, ch2, ch3)) {
            res = 0;
            break;
        }
        int i = 0;
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
        if (ch3 == SP) printf(" ");
    } while (ch3 != NL);
    return res;
}
