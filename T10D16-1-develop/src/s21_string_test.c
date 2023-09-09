#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#define OK "SUCCESS\n"
#define NO "FAIL\n"

void test_len_1();
void test_len_2();
void test_len_3();

void test_cmp_4();
void test_cmp_5();
void test_cmp_6();
void test_cmp_7();

void test_cpy_8();
void test_cpy_9();
void test_cpy_10();
void test_cpy_11();

void test_cat_12();
void test_cat_13();
void test_cat_14();

void test_chr_15();
void test_chr_16();
void test_chr_17();

void test_strstr_18();
void test_strstr_19();
void test_strstr_20();

void test_tok_21();
void test_tok_22();
void test_tok_23();

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef QUEST1
    s21_strlen_test();
#endif

#ifdef QUEST2
    s21_strcmp_test();
#endif

#ifdef QUEST3
    s21_strcpy_test();
#endif

#ifdef QUEST4
    s21_strcat_test();
#endif

#ifdef QUEST5
    s21_strchr_test();
#endif

#ifdef QUEST6
    s21_strstr_test();
#endif

#ifdef QUEST7
    s21_strtok_test();
#endif

    return 0;
}

void s21_strlen_test() {
    test_len_1();
    test_len_2();
    test_len_3();
}

void test_len_1() {
    char *str = "1234567";
    int len = s21_strlen(str);
    printf("input: %s | output: %d | ", str, len);

    if (len == 7)
        printf(OK);
    else
        printf(NO);
}

void test_len_2() {
    char *str = "12 5";
    int len = s21_strlen(str);
    printf("input: %s | output: %d | ", str, len);

    if (len == 4)
        printf(OK);
    else
        printf(NO);
}

void test_len_3() {
    char *str = "";
    int len = s21_strlen(str);
    printf("input: %s | output: %d | ", str, len);

    if (len == 0)
        printf(OK);
    else
        printf(NO);
}

void s21_strcmp_test() {
    test_cmp_4();
    test_cmp_5();
    test_cmp_6();
    test_cmp_7();
}

void test_cmp_4() {
    char *str1 = "123";
    char *str2 = "123";

    int res = s21_strcmp(str1, str2);
    printf("input: %s %s | output: %d | ", str1, str2, res);

    if (res == 0)
        printf(OK);
    else
        printf(NO);
}

void test_cmp_5() {
    char *str1 = "123";
    char *str2 = "";

    int res = s21_strcmp(str1, str2);
    printf("input: %s %s | output: %d | ", str1, str2, res);

    if (res == 1)
        printf(OK);
    else
        printf(NO);
}

void test_cmp_6() {
    char *str1 = "1";
    char *str2 = "123";

    int res = s21_strcmp(str1, str2);
    printf("input: %s %s | output: %d | ", str1, str2, res);

    if (res == -1)
        printf(OK);
    else
        printf(NO);
}

void test_cmp_7() {
    char *str1 = "123";
    char *str2 = "124";

    int res = s21_strcmp(str1, str2);
    printf("input: %s %s | output: %d | ", str1, str2, res);

    if (res == -1)
        printf(OK);
    else
        printf(NO);
}

void s21_strcpy_test() {
    test_cpy_8();
    test_cpy_9();
    test_cpy_10();
    test_cpy_11();
}

void test_cpy_8() {
    char *str1 = "123";
    char str2[3] = "";
    printf("input: %s %s | ", str1, str2);

    s21_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (s21_strcmp(str1, str2) == 1)
        printf(OK);
    else
        printf(NO);
}

void test_cpy_9() {
    char *str1 = "123";
    char str2[7] = "456";
    printf("input: %s %s | ", str1, str2);

    s21_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (s21_strcmp(str1, str2) == 0)
        printf(OK);
    else
        printf(NO);
}

void test_cpy_10() {
    char *str1 = "123";
    char *str2 = "12";
    printf("input: %s %s | ", str1, str2);

    s21_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (s21_strcmp(str1, str2) == 1)
        printf(OK);
    else
        printf(NO);
}

void test_cpy_11() {
    char *str1 = "12";
    char *str2 = "123";
    printf("input: %s %s | ", str1, str2);

    s21_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (s21_strcmp(str1, str2) == -1)
        printf(OK);
    else
        printf(NO);
}

void s21_strcat_test() {
    test_cat_12();
    test_cat_13();
    test_cat_14();
}

void test_cat_12() {
    char *str1 = "12345";
    char *str2 = "678";

    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);

    printf("input: %s %s | ", str1, str2);

    char *str_res = s21_strcat(str1, str2);
    printf("output: %s | ", str_res);

    int len_res = s21_strlen(str_res);
    if (len_res == len1 + len2)
        printf(OK);
    else
        printf(NO);

    free(str_res);
}

void test_cat_13() {
    char *str1 = "678";
    char *str2 = "12345";

    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);

    printf("input: %s %s | ", str1, str2);

    char *str_res = s21_strcat(str1, str2);
    printf("output: %s | ", str_res);

    int len_res = s21_strlen(str_res);
    if (len_res == len1 + len2)
        printf(OK);
    else
        printf(NO);

    free(str_res);
}

void test_cat_14() {
    char *str1 = "     ";
    char *str2 = "123";

    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);

    printf("input: %s %s | ", str1, str2);

    char *str_res = s21_strcat(str1, str2);
    printf("output: %s | ", str_res);

    int len_res = s21_strlen(str_res);
    if (len_res == len1 + len2)
        printf(OK);
    else
        printf(NO);

    free(str_res);
}

void s21_strchr_test() {
    test_chr_15();
    test_chr_16();
    test_chr_17();
}

void test_chr_15() {
    char *str = "aB";
    char symb = 'B';

    int chr_index = s21_strchr(str, symb);
    printf("input: %s %c | output: %d | ", str, symb, chr_index);
    if (chr_index == 1)
        printf(OK);
    else
        printf(NO);
}

void test_chr_16() {
    char *str = "Abc";
    char symb = 'A';

    int chr_index = s21_strchr(str, symb);
    printf("input: %s %c | output: %d | ", str, symb, chr_index);
    if (chr_index == 0)
        printf(OK);
    else
        printf(NO);
}

void test_chr_17() {
    char *str = "abcd";
    char symb = '1';

    int chr_index = s21_strchr(str, symb);
    printf("input: %s %c | output: %d | ", str, symb, chr_index);
    if (chr_index == -1)
        printf(OK);
    else
        printf(NO);
}

void s21_strstr_test() {
    test_strstr_18();
    test_strstr_19();
    test_strstr_20();
}

void test_strstr_18() {
    char *str1 = "str_string";
    char *str2 = "string";

    const char *strstr = s21_strstr(str1, str2);
    printf("input: %s %s | output: %s | ", str1, str2, strstr);

    if (strstr == str1 + 4)
        printf(OK);
    else
        printf(NO);
}

void test_strstr_19() {
    char *str1 = "str_string";
    char *str2 = "";

    const char *strstr = s21_strstr(str1, str2);
    printf("input: %s %s | output: %s | ", str1, str2, strstr);

    if (strstr == str1 + s21_strlen(str1))
        printf(OK);
    else
        printf(NO);
}

void test_strstr_20() {
    char *str1 = "str_string";
    char *str2 = "123";

    const char *strstr = s21_strstr(str1, str2);
    printf("input: %s %s | output: %s | ", str1, str2, strstr);

    if (strstr == NULL)
        printf(OK);
    else
        printf(NO);
}

void s21_strtok_test() {
    test_tok_21();
    test_tok_22();
    test_tok_23();
}

void test_tok_21() {
    char *str1 = "test.string";
    char *str2 = "., ";
    printf("%s %s ", str1, str2);
    char *strtok = s21_strtok(str1, str2);
    do {
        printf("%s\n", strtok);
        strtok = s21_strtok(NULL, str2);
    } while (strtok != NULL);

    if (strtok != 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(strtok);
}

void test_tok_22() {}

void test_tok_23() {}
