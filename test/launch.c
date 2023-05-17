#include "main.h"

/**
 *
 *
 *
 *
 */

int launch(char **args)
{
	if (args[0] == NULL)
	{
		return 1;
	}
	if (_strcmp(args[0], "cd") == 0)
	{
 		return cd(args);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		return execute(args);
	}
}
