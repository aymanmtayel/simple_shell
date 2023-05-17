#include "main.h"

#define MAX_ARGS 64

/**
 * splits - split a line into words
 * @line: the line to be split
 * Return: array of words, Null if fail
 */

char **splits(char *line)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *arg = strtok(line, " \t\n");
	int i = 0;

	while (arg != NULL && i < MAX_ARGS -1)
	{
		args[i++] = arg;
		arg = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}
