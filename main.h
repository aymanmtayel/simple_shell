#ifndef M_H
#define M_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

#define MAX_BUFF 1024

void prompt(void);
char *r_space(char *str);
char **split_c(char *cmd);
char *stringtok(char *str, char *del);
int builtins(char **args);
int stringcompare(const char *str1, const char *str2);

#endif
