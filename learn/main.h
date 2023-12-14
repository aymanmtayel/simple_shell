#ifndef M_H
#define M_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define BUFF_MAX 1024

void prompt(void);
void execute(char *cmd);
void _fork(char *cmd, char *name);
size_t _strlen(const char *str);
void _error(char *cmd, char *name);

#endif
