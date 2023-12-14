#include "main.h"

/**
 * split_c - split the command
 * @cmd: the input from the user
 * Return: the command after split
 */

char **split_c(char *cmd)
{
	char *token;
	char **args;
	int c1 = 0;
	int c2 = 0;

	while (cmd[c1])
	{
		if (cmd[c1] == '#')
		{
			if (c1 == 0)
				return (NULL);
			cmd[c1] = '\0';
			break;
		}
		c1++;
	}
	args = malloc(MAX_BUFFER * sizeof(char *));
	if (args == NULL)
	{
		perror(getenv("_"));
		free(args);
		exit(EXIT_FAILURE);
	}
	token = stringtok(cmd, " ");
	while (token != NULL && c2 < MAX_BUFFER - 1)
	{
		if (strcompare(token, " ") != 0)
			args[c2++] = token;
		token = stringtok(NULL, " ");
	}
	args[c2] = NULL;
	return (args);
}
