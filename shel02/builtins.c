#include "main.h"

/**
 * builtins - is a function that check for built in calls
 * @args: the command to check against available in env
 * Return: 0 if success or 1 if not found
 */

int builtins(char **args)
{
	char *str = args[0];
	int exit_c = 0;

	if (stringcompare(str, "env") == 0)
	{
		execute_env();
		free(args);
		return (0);
	} else if (stringcompare(str, "exit") == 0)
	{
		if (args[1] != NULL)
		{
			exit_c = atoi(args[1]);
			if ((status == 0 && stringcompare(args[1], "0") != 0) ||(status < 0))
					{
					char *error = ": 1: exit: Illegal number: ";

					_perror(concatenate(getenv("_"), error, args[1]), args, cmd);}
					free(args);
					free(cmd);
					exit(status);
					} else {
					free(args);
					free(cmd);
					exit(0);}
	} else if (stringcompare(str, "setenv") == 0)
	{
		if (args[1] && args[2])

