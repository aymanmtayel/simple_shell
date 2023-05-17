#include "main.h"

/**
 * execute_command - Execute a command entered by the user
 * @command: The command to execute
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char *command)
{
	char *arg[2];
	pid_t pid;
	char *trimmed = trim(command);

	arg[0] = trimmed;
	arg[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(trimmed);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(trimmed, arg, environ) == -1)
		{
			perror("execve");
			free(trimmed);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			free(trimmed);
			return (-1);
		}
	}
	free(trimmed);
	return (0);
}
