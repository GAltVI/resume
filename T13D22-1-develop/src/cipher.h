#ifndef CIPHER_H
#define CIPHER_H
#include <stdio.h>
#include <string.h>

#ifdef COMMON
int menu();
int read_print_file(char *file_name);
int write_file(char *file_name);
int encrypt(char **files, int step);
int code(char *file_name, int step);
#endif

#ifdef LOG
int menu();
int read_print_file(char *file_name, FILE *log);
int write_file(char *file_name, FILE *log);
int encrypt(char **files, int step, FILE *log);
int code(char *file_name, int step, FILE *log);
void make_message(char *file_name, int type, char *msg);
#endif

#endif
