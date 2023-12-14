#include "main.h"

/**
 * execute - execute a command
 * @cmd: pointer to the command to be executed
 * Return: Void
 */

void execute(char *cmd)
{
	char *args[2];
	
	args[0] = cmd;
	args[1] = NULL;

	if (execve(cmd, args, environ) == -1)
	{
		_exit(EXIT_FAILURE);
	}
}
