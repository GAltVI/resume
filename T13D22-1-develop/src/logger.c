#include "logger.h"

#include <time.h>

FILE *log_init(char *filename) {
    FILE *file = fopen(filename, "a");
    return file;
}

int logcat(FILE *log_file, char *message, log_level level) {
    int result = 1;
    if (log_file) {
        switch (level) {
            case debug:
                fprintf(log_file, "DEBUG ");
                break;

            case info:
                fprintf(log_file, "INFO ");
                break;

            case warning:
                fprintf(log_file, "WARNING ");
                break;

            case error:
                fprintf(log_file, "ERROR ");
                break;
            default:
                break;
        }
        const time_t timer = time(NULL);
        struct tm *u = localtime(&timer);
        char time[9];
        strftime(time, 9, "%H:%M:%S", u);
        fprintf(log_file, "%s %s\n", time, message);
    } else
        result = 0;
    return result;
}

int log_close(FILE *log_file) {
    int result = 0;
    if (log_file) {
        fclose(log_file);
        result = 1;
    }
    return result;
}
