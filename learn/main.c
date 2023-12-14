#include "main.h"

/**
 * main - main shell code
 * @argc: arguments count
 * @argv: array of arguments values
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	char *cmd = NULL;
	size_t c_size = 0;
	ssize_t get_cmd;
	int i = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			prompt();
			get_cmd = getline(&cmd, &c_size, stdin);

			if (get_cmd == -1)
			{
				if (feof(stdin))
				{
					break;
				}
				else
				{
					_error(cmd, argv[0]);
					break;
				}
			}
			if (*cmd != '\n')
				_fork(cmd, argv[0]);
		}
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			cmd = argv[i];
			_fork(cmd, argv[0]);
		}
	}
	free(cmd);
	return (0);
}
