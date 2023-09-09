#include "print_module.h"

#include <stdio.h>
#include <time.h>

void print_log(char (*print)(char), char *message) {
    const time_t timer = time(NULL);
    struct tm *u = localtime(&timer);
    char time[TIME_FORMAT_SIZE];
    strftime(time, TIME_FORMAT_SIZE, "%H:%M:%S", u);

    char *ptr = Log_prefix;
    for (; *ptr != ']'; ptr++) print(*ptr);
    print(*ptr);
    print(' ');

    for (ptr = time; ptr - time < TIME_FORMAT_SIZE; ptr++) print(*ptr);
    print(' ');

    for (ptr = message; *ptr != '\0'; ptr++) print(*ptr);
    print(*ptr);
}

char print_char(char ch) { return putchar(ch); }
