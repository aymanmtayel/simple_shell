#include "main.h"

/**
 * _fork - fork the proccess
 * @cmd: command to be executed
 * @name: name of the program
 * Return: void
 */

void _fork(char *cmd, char *name)
{
	pid_t pid = fork();

	if (pid == -1)
		exit(EXIT_FAILURE);

	if (pid == 0)
	{
		execute(cmd);
		_error(cmd, name);
		_exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			int e_code = WEXITSTATUS(status);

			exit(e_code);
		}
		else if (WIFSIGNALED(status))
		{
			int sig_num = WTERMSIG(status);

			exit(sig_num);
		}
	}
}
