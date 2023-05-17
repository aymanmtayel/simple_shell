#ifndef M_H
#define M_H

#define TOKEN_DELIMITERS " \t\r\n\a"

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
#include <signal.h>
#include <errno.h>

extern char **environ;

int _printf(const char *format, ...);
int print_string(va_list list);
int print_char(va_list list);
int print_int(va_list list);
unsigned int bin(va_list list);
unsigned int print_unint(va_list list);
int print_octal(va_list list);

void prompt(void);
int execute_command(char *command);
char *trim(char *str);
char *_strncpy(char *dest, const char *src, size_t n);

char *read_line(void);
char **splits(char *line);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *find_path(char *cmd);
int execute(char **args);
int cd(char **args);
int launch(char **args);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_args(char **args);
char *_strdup(char *s);


#endif
