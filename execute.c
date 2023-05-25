#include "main.h"

/**
 * execute_command - Execute a command entered by the user
 * @command: The command to execute
 * Return: 0 on success, or -1 on failure
 */

int execute_command(char *command)
{
	/* char *path = getenv("PATH"); */
	char *dir, *cmd;
	char *arg[100];
	pid_t pid;
	char *token;
	char *trimmed = trim(command);
	int i = 0;

	arg[0] = trimmed;
	arg[1] = NULL;

	token = strtok(trimmed, " ");
	while (token != NULL && i < 100 - 1)
	{
		arg[i++] = token;
		token = strtok(NULL, " ");
	}
	arg[i] = NULL;

	dir = "/bin"; /* strtok(getenv("PATH"), ":"); */
	while (dir != NULL)
	{
		cmd = malloc(_strlen(dir) + _strlen(arg[0]) + 2);
		if (cmd == NULL)
		{
			perror("malloc");
			free(trimmed);
			return (-1);
		}
		sprintf(cmd, "%s/%s", dir, arg[0]);
		if (access(cmd, X_OK) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				free(trimmed);
				free(cmd);
				return (-1);
			}
			else if (pid == 0)
			{
				if (execve(cmd, arg, environ) == -1)
				{
					perror("execve");
					free(cmd);
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
					free(cmd);
					free(trimmed);
					return (-1);
				}
				free(cmd);
				free(trimmed);
				return(0);
			}
		}
		free(cmd);
		dir = strtok(NULL, ":");
	}
	_printf("%s: command not found\n", arg[0]);
	free(trimmed);
	return (-1);
}
