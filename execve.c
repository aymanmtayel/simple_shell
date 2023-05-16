#include "main.h"

/**
 * execute_command - Forks a new process and executes the given command.
 * @path: the path of the command to execute.
 */
void execute_command(const char *path)
{
	char *argv[] = {(char *)path, NULL};
	/* Fork a new process */
	pid_t pid = fork();

	if (pid == -1)
	{
		_printf("error forking");
	}
	else if (pid == 0)
	{
		/* Child process */
		/* Execute the command */

		execve(path, argv, environ);

		/* Handle execve error */
		exit(EXIT_FAILURE);
	}
	else
	{
		handle_child_completion(pid);
	}
}
