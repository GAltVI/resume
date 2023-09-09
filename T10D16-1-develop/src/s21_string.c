#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char *str) { return (str && *str) ? (s21_strlen(str + 1) + 1) : 0; }

int s21_strcmp(char *str1, char *str2) {
    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);
    int res = 0;

    if (len1 > len2) res = 1;

    if (len1 < len2) res = -1;

    if (len1 == len2) {
        for (int i = 0; i < len1; i++) {
            if (str1[i] > str2[i]) {
                res = 1;
                break;
            }
            if (str1[i] < str2[i]) {
                res = -1;
                break;
            }
        }
    }
    return res;
}

int s21_strcpy(char *str1, char *str2) {
    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);
    int res = 0;
    char *p1, *p2;
    if (len1 == len2) {
        for (p1 = str1, p2 = str2; p1 - str1 < len1; p1++, p2++) *p2 = *p1;
    } else
        res = 1;
    return res;
}

char *s21_strcat(char *str1, char *str2) {
    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);

    char *str_res = NULL;
    str_res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    char *p_res = str_res;

    for (char *p1 = str1; p1 - str1 < len1; p1++, p_res++) *p_res = *p1;
    for (char *p2 = str2; p2 - str2 < len2; p2++, p_res++) *p_res = *p2;
    *p_res = '\0';
    return str_res;
}

int s21_strchr(char *str1, char symb) {
    int res = -1;
    int len1 = s21_strlen(str1);

    for (int i = 0; i < len1; i++) {
        if (str1[i] == symb) {
            res = i;
            break;
        }
    }

    return res;
}

const char *s21_strstr(char *str1, char *str2) {
    int len1 = s21_strlen(str1);

    if (*str2 == '\0') return str1 + len1;
    const char *ptr;
    for (int i = 0; i < len1; i++) {
        if (*(str1 + i) == *str2) {
            ptr = s21_strstr(str1 + i + 1, str2 + 1);
            return (ptr) ? ptr - 1 : 0;
        }
    }
    return 0;
}

char *s21_strtok(char *str1, char *str2) {
    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);

    char *str_res = (char *)malloc(sizeof(char) * len1);

    int ind = 0;
    int i = 0;
    if (*str1 != '\0') {
        for (i = 0; i < len1; i++) {
            str_res[i] = str1[i];
            for (int j = 0; j < len2; j++) {
                if (str_res[i] == str2[j]) {
                    str_res[i] = '\0';
                    ind = 1;
                    break;
                }
            }
            if (ind == 1) break;
        }
    } else
        str_res = NULL;
    return str_res + i;
}
