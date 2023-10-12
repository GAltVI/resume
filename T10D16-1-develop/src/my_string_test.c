#include "my_string.h"

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

int my_strlen_test(int i);
int my_strcmp_test(int i);
int my_strcpy_test(int i);
int my_strcat_test(int i);
int my_strchr_test(int i);
int my_strstr_test(int i);
int my_strtok_test(int i);

int main() {
    int i = 1;
// #ifdef QUEST1
    i = my_strlen_test(i);
// #endif

// #ifdef QUEST2
    i = my_strcmp_test(i);
// #endif

// #ifdef QUEST3
    i = my_strcpy_test(i);
// #endif

// #ifdef QUEST4
    i = my_strcat_test(i);
// #endif

// #ifdef QUEST5
    i = my_strchr_test(i);
// #endif

// #ifdef QUEST6
    i = my_strstr_test(i);
// #endif

// #ifdef QUEST7
    i = my_strtok_test(i);
// #endif

    return 0;
}

int my_strlen_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strlen_test  : %d\n", i);
    printf("-----------------------\n");
    test_len_1();
    i++;
    printf("________________________\n\n");
    printf("   my_strlen_test  : %d\n", i);
    printf("-----------------------\n");
    test_len_2();
    i++;
    printf("________________________\n\n");
    printf("   my_strlen_test  : %d\n", i);
    printf("-----------------------\n");
    test_len_3();
    return i++;
}

void test_len_1() {
    char *str = "1234567";
    int len = my_strlen(str);
    printf("input: str=<%s> | output: %d | ", str, len);

    if (len == 7)
        printf(OK);
    else
        printf(NO);
}

void test_len_2() {
    char *str = "12 5";
    int len = my_strlen(str);
    printf("input: str=<%s> | output: %d | ", str, len);

    if (len == 4)
        printf(OK);
    else
        printf(NO);
}

void test_len_3() {
    char *str = "";
    int len = my_strlen(str);
    printf("input: str=<%s> | output: %d | ", str, len);

    if (len == 0)
        printf(OK);
    else
        printf(NO);
}

int my_strcmp_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strcmp_test  : %d\n", i);
    printf("-----------------------\n");
    test_cmp_4();
    i++;
    printf("________________________\n\n");
    printf("   my_strcmp_test  : %d\n", i);
    printf("-----------------------\n");
    test_cmp_5();
    i++;
    printf("________________________\n\n");
    printf("   my_strcmp_test  : %d\n", i);
    printf("-----------------------\n");
    test_cmp_6();
    i++;
    printf("________________________\n\n");
    printf("   my_strcmp_test  : %d\n", i);
    printf("-----------------------\n");
    test_cmp_7();
    return i++;
}

void test_cmp_4() {
    char *str1 = "123";
    char *str2 = "123";

    int res = my_strcmp(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %d | ", str1, str2, res);

    if (res == 0)
        printf(OK);
    else
        printf(NO);
}

void test_cmp_5() {
    char *str1 = "123";
    char *str2 = "";

    int res = my_strcmp(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %d | ", str1, str2, res);

    if (res == 1)
        printf(OK);
    else
        printf(NO);
}

void test_cmp_6() {
    char *str1 = "1";
    char *str2 = "123";

    int res = my_strcmp(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %d | ", str1, str2, res);

    if (res == -1)
        printf(OK);
    else
        printf(NO);
}

void test_cmp_7() {
    char *str1 = "123";
    char *str2 = "124";

    int res = my_strcmp(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %d | ", str1, str2, res);

    if (res == -1)
        printf(OK);
    else
        printf(NO);
}

int my_strcpy_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strcpy_test  : %d\n", i);
    printf("-----------------------\n");
    test_cpy_8();
    i++;
    printf("________________________\n\n");
    printf("   my_strcpy_test  : %d\n", i);
    printf("-----------------------\n");
    test_cpy_9();
    i++;
    printf("________________________\n\n");
    printf("   my_strcpy_test  : %d\n", i);
    printf("-----------------------\n");
    test_cpy_10();
    i++;
    printf("________________________\n\n");
    printf("   my_strcpy_test  : %d\n", i);
    printf("-----------------------\n");
    test_cpy_11();
    return i++;
}

void test_cpy_8() {
    char *str1 = "123";
    char str2[3] = "";
    printf("input: from=<%s> to=<%s> | ", str1, str2);

    my_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (my_strcmp(str1, str2) == 1)
        printf(OK);
    else
        printf(NO);
}

void test_cpy_9() {
    char *str1 = "123";
    char str2[7] = "456";
    printf("input: from=<%s> to=<%s> | ", str1, str2);

    my_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (my_strcmp(str1, str2) == 0)
        printf(OK);
    else
        printf(NO);
}

void test_cpy_10() {
    char *str1 = "123";
    char *str2 = "12";
    printf("input: from=<%s> to=<%s> | ", str1, str2);

    my_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (my_strcmp(str1, str2) == 1)
        printf(OK);
    else
        printf(NO);
}

void test_cpy_11() {
    char *str1 = "12";
    char *str2 = "123";
    printf("input: from=<%s> to=<%s> | ", str1, str2);

    my_strcpy(str1, str2);
    printf("output: %s | ", str2);

    if (my_strcmp(str1, str2) == -1)
        printf(OK);
    else
        printf(NO);
}

int my_strcat_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strcat_test  : %d\n", i);
    printf("-----------------------\n");
    test_cat_12();
    i++;
    printf("________________________\n\n");
    printf("   my_strcat_test  : %d\n", i);
    printf("-----------------------\n");
    test_cat_13();
    i++;
    printf("________________________\n\n");
    printf("   my_strcat_test  : %d\n", i);
    printf("-----------------------\n");
    test_cat_14();
    return i++;
}

void test_cat_12() {
    char *str1 = "12345";
    char *str2 = "678";

    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    printf("input: str1=<%s> str2=<%s> | ", str1, str2);

    char *str_res = my_strcat(str1, str2);
    printf("output: %s | ", str_res);

    int len_res = my_strlen(str_res);
    if (len_res == len1 + len2)
        printf(OK);
    else
        printf(NO);

    free(str_res);
}

void test_cat_13() {
    char *str1 = "678";
    char *str2 = "12345";

    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    printf("input: str1=<%s> str2=<%s> | ", str1, str2);

    char *str_res = my_strcat(str1, str2);
    printf("output: %s | ", str_res);

    int len_res = my_strlen(str_res);
    if (len_res == len1 + len2)
        printf(OK);
    else
        printf(NO);

    free(str_res);
}

void test_cat_14() {
    char *str1 = "     ";
    char *str2 = "123";

    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    printf("input: str1=<%s> str2=<%s> | ", str1, str2);

    char *str_res = my_strcat(str1, str2);
    printf("output: %s | ", str_res);

    int len_res = my_strlen(str_res);
    if (len_res == len1 + len2)
        printf(OK);
    else
        printf(NO);

    free(str_res);
}

int my_strchr_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strchr_test  : %d\n", i);
    printf("-----------------------\n");
    test_chr_15();
    i++;
    printf("________________________\n\n");
    printf("   my_strchr_test  : %d\n", i);
    printf("-----------------------\n");
    test_chr_16();
    i++;
    printf("________________________\n\n");
    printf("   my_strchr_test  : %d\n", i);
    printf("-----------------------\n");
    test_chr_17();
    return i++;
}

void test_chr_15() {
    char *str = "aB";
    char symb = 'B';

    int chr_index = my_strchr(str, symb);
    printf("input: str=<%s> char=<%c> | output: %d | ", str, symb, chr_index);
    if (chr_index == 1)
        printf(OK);
    else
        printf(NO);
}

void test_chr_16() {
    char *str = "Abc";
    char symb = 'A';

    int chr_index = my_strchr(str, symb);
    printf("input: str=<%s> char=<%c> | output: %d | ", str, symb, chr_index);
    if (chr_index == 0)
        printf(OK);
    else
        printf(NO);
}

void test_chr_17() {
    char *str = "abcd";
    char symb = '1';

    int chr_index = my_strchr(str, symb);
    printf("input: str=<%s> char=<%c> | output: %d | ", str, symb, chr_index);
    if (chr_index == -1)
        printf(OK);
    else
        printf(NO);
}

int my_strstr_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strstr_test  : %d\n", i);
    printf("-----------------------\n");
    test_strstr_18();
    i++;
    printf("________________________\n\n");
    printf("   my_strstr_test  : %d\n", i);
    printf("-----------------------\n");
    test_strstr_19();
    i++;
    printf("________________________\n\n");
    printf("   my_strstr_test  : %d\n", i);
    printf("-----------------------\n");
    test_strstr_20();
    return i++;
}

void test_strstr_18() {
    char *str1 = "str_string";
    char *str2 = "string";

    const char *strstr = my_strstr(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %s | ", str1, str2, strstr);

    if (strstr == str1 + 4)
        printf(OK);
    else
        printf(NO);
}

void test_strstr_19() {
    char *str1 = "str_string";
    char *str2 = "";

    const char *strstr = my_strstr(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %s | ", str1, str2, strstr);

    if (strstr == str1 + my_strlen(str1))
        printf(OK);
    else
        printf(NO);
}

void test_strstr_20() {
    char *str1 = "str_string";
    char *str2 = "123";

    const char *strstr = my_strstr(str1, str2);
    printf("input: str1=<%s> str2=<%s> | output: %s | ", str1, str2, strstr);

    if (strstr == NULL)
        printf(OK);
    else
        printf(NO);
}

int my_strtok_test(int i) {
    printf("\n=======================\n\n");
    printf("   my_strtok_test  : %d\n", i);
    printf("-----------------------\n");
    test_tok_21();
    i++;
    printf("________________________\n");
    printf("   my_strtok_test  : %d\n", i);
    printf("-----------------------\n");
    test_tok_22();
    return i++;
}

void test_tok_21() {
    char *str1 = "test.string";
    char *str2 = ".,";
    char *strtok = my_strtok(str1, str2);
    printf("input: string=<%s> delimeters=<%s> | output: %s | ", str1, str2, strtok);

    if (my_strcmp(strtok, "string") == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    //free(strtok);
}

void test_tok_22() {
    char *str1 = "test.string";
    char *str2 = " ,";
    char *strtok = my_strtok(str1, str2);
    printf("input: string=<%s> delimeters=<%s> | output: %s | ", str1, str2, strtok);

    if (strtok == NULL)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    //free(strtok);
}
