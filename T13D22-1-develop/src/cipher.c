#include "cipher.h"

#include <dirent.h>

#ifdef LOG
#include "logger.h"
#endif

#define NA "n/a"
#define EXIT -1
#define OK 0
#define READ_PRINT_FILE 1
#define WRITE_FILE 2
#define ENCRYPT 3
#define ERROR 666
#define NMAX 256
#define ASCII_SIZE 128
#define BUFFER_MAX 1000000

int main() {
    int result = 0;

    if (menu() != OK) printf(NA);

    return result;
}

#ifdef COMMON
int menu() {
    int return_code = OK;
    char file_name[NMAX];

    int mode = 0;
    // char dir_name[NMAX];
    char *files[4] = {"ai_modules/m1.c", "ai_modules/m1.h", "ai_modules/m2.c", "ai_modules/m2.h"};
    int step = 0;
    while (scanf("%d", &mode) == 1 && mode != EXIT) {
        switch (mode) {
            case READ_PRINT_FILE:
                scanf("%255s", file_name);
                return_code = read_print_file(file_name);
                break;
            case WRITE_FILE:
                return_code = write_file(file_name);
                break;
            case ENCRYPT:
                // scanf("%255s", dir_name);
                scanf("%d", &step);
                encrypt(files, step);
                break;
            default:
                break;
        }
    }
    return return_code;
}

int read_print_file(char *file_name) {
    int result = 0;

    FILE *file = fopen(file_name, "r");
    if (file) {
        int ch = 0;
        do {
            ch = getc(file);
            if (ch != EOF) printf("%c", ch);
        } while (ch != EOF);

        printf("\n");
        fclose(file);
    } else {
        result = ERROR;
        printf("n/a\n");
    }

    return result;
}

int write_file(char *file_name) {
    int result = 0;

    FILE *file = fopen(file_name, "a");

    if (file) {
        char str[NMAX];
        scanf("%255s", str);
        putc('\n', file);
        for (int i = 0; str[i] != '\0'; i++) {
            putc(str[i], file);
        }
        fclose(file);
    } else {
        result = ERROR;
        printf("n/a\n");
    }

    return result;
}

int encrypt(char **files, int step) {
    int result = 1;
    for (int i = 0; i < 4; i++) {
        result = code(files[i], step);

        FILE *file = fopen(files[++i], "w");
        if (file != NULL) {
            fclose(file);
        } else {
            result &= 0;
        }
    }

    return result;
}

int code(char *file_name, int step) {
    int result = 1;
    FILE *file = fopen(file_name, "r");

    // printf("file_name = %s\n", file_name);
    int input[BUFFER_MAX];
    input[0] = 0;
    int *p_input = input;
    if (file) {
        while (*p_input != EOF) {
            *p_input = (getc(file) + step) % ASCII_SIZE;
            p_input++;
        }
        *p_input = EOF;
        fclose(file);

        file = fopen(file_name, "w");
        p_input = input;
        if (file) {
            do {
                putc(*p_input, file);
                p_input++;
            } while (*p_input != EOF);

            putc(*p_input, file);
            fclose(file);
        } else {
            result &= 0;
        }
    } else
        result &= 0;

    if (!result) printf("@n/a\n");

    return result;
}
#endif

#ifdef LOG
int menu() {
    FILE *log = log_init("cipher.log");
    int return_code = OK;
    char file_name[NMAX];

    int mode = 0;
    char *files[4] = {"ai_modules/m1.c", "ai_modules/m1.h", "ai_modules/m2.c", "ai_modules/m2.h"};
    int step = 0;
    while (scanf("%d", &mode) == 1 && mode != EXIT) {
        switch (mode) {
            case READ_PRINT_FILE:
                scanf("%255s", file_name);
                return_code = read_print_file(file_name, log);
                break;
            case WRITE_FILE:
                return_code = write_file(file_name, log);
                break;
            case ENCRYPT:
                scanf("%d", &step);
                encrypt(files, step, log);
                break;
            default:
                break;
        }
    }
    if (log_close(log) == 0) return_code = ERROR;
    return return_code;
}

int read_print_file(char *file_name, FILE *log) {
    int result = 0;

    FILE *file = fopen(file_name, "r");
    char msg[100];
    if (file) {
        make_message(file_name, 1, msg);
        logcat(log, msg, info);
        int ch = 0;
        do {
            ch = getc(file);
            if (ch != EOF) printf("%c", ch);
        } while (ch != EOF);
        make_message(file_name, 2, msg);
        logcat(log, msg, info);

        printf("\n");
        fclose(file);
        make_message(file_name, 3, msg);
        logcat(log, msg, info);
    } else {
        result = ERROR;
        printf("n/a\n");
        make_message(file_name, 4, msg);
        logcat(log, msg, error);
    }

    return result;
}

int write_file(char *file_name, FILE *log) {
    int result = 0;

    FILE *file = fopen(file_name, "a");

    char msg[100];
    if (file) {
        make_message(file_name, 1, msg);
        logcat(log, msg, info);

        char str[NMAX];
        scanf("%255s", str);
        putc('\n', file);
        for (int i = 0; str[i] != '\0'; i++) {
            putc(str[i], file);
        }
        make_message(file_name, 5, msg);
        logcat(log, msg, info);

        fclose(file);
        make_message(file_name, 3, msg);
        logcat(log, msg, info);
    } else {
        result = ERROR;
        printf("n/a\n");
        make_message(file_name, 4, msg);
        logcat(log, msg, error);
    }

    return result;
}

int encrypt(char **files, int step, FILE *log) {
    int result = 1;
    for (int i = 0; i < 4; i++) {
        result = code(files[i], step, log);

        FILE *file = fopen(files[++i], "w");
        char msg[100];
        if (file != NULL) {
            make_message(files[i], 1, msg);
            logcat(log, msg, info);

            make_message(files[i], 6, msg);
            logcat(log, msg, info);

            fclose(file);
            make_message(files[i], 3, msg);
            logcat(log, msg, info);
        } else {
            result &= 0;
            make_message(files[i], 4, msg);
            logcat(log, msg, error);
        }
    }

    return result;
}

int code(char *file_name, int step, FILE *log) {
    int result = 1;
    FILE *file = fopen(file_name, "r");

    int input[BUFFER_MAX];
    input[0] = 0;
    int *p_input = input;
    char msg[100];
    if (file) {
        make_message(file_name, 1, msg);
        logcat(log, msg, info);

        while (*p_input != EOF) {
            *p_input = (getc(file) + step) % ASCII_SIZE;
            p_input++;
        }
        make_message(file_name, 2, msg);
        logcat(log, msg, info);

        *p_input = EOF;
        fclose(file);
        make_message(file_name, 3, msg);
        logcat(log, msg, info);

        file = fopen(file_name, "w");
        p_input = input;
        if (file) {
            make_message(file_name, 1, msg);
            logcat(log, msg, info);
            do {
                putc(*p_input, file);
                p_input++;
            } while (*p_input != EOF);
            make_message(file_name, 7, msg);
            logcat(log, msg, info);

            putc(*p_input, file);
            fclose(file);
            make_message(file_name, 3, msg);
            logcat(log, msg, info);
        } else {
            result &= 0;
        }
    } else
        result &= 0;

    if (!result) {
        printf("n/a\n");
        make_message(file_name, 4, msg);
        logcat(log, msg, error);
    }

    return result;
}

void make_message(char *file_name, int type, char *msg) {
    switch (type) {
        case 1:
            strcpy(msg, "file \"");
            strcat(msg, file_name);
            strcat(msg, "\" is opened");
            break;
        case 2:
            strcpy(msg, "file \"");
            strcat(msg, file_name);
            strcat(msg, "\" is read");
            break;
        case 3:
            strcpy(msg, "file \"");
            strcat(msg, file_name);
            strcat(msg, "\" is closed");
            break;
        case 4:
            strcpy(msg, "file \"");
            strcat(msg, file_name);
            strcat(msg, "\" can't be opened");
            break;
        case 5:
            strcpy(msg, "string is wrote in file \"");
            strcat(msg, file_name);
            strcat(msg, "\" ");
            break;
        case 6:
            strcpy(msg, "file \"");
            strcat(msg, file_name);
            strcat(msg, "\" is cleared");
            break;
        case 7:
            strcpy(msg, "file \"");
            strcat(msg, file_name);
            strcat(msg, "\" is encrypt");
            break;
        default:
            break;
    }
}
#endif
