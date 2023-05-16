#ifndef M_H
#define M_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;

int _printf(const char *format, ...);
int print_string(va_list list);
int print_char(va_list list);
int print_int(va_list list);
unsigned int bin(va_list list);
unsigned int print_unint(va_list list);
int print_octal(va_list list);
int is_valid_executable(const char *path);
void execute_command(const char *path);
void handle_child_completion(pid_t pid);
void print_error(const char *msg);
void exit_with_error(const char *msg);

#endif
