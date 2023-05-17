#include "main.h"

/**
 * main - The main entry point of the program
 *
 * Return: 0 on success, or an error code on failure
 */

int main(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t line_len;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			prompt();
		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
			if (interactive)
				_printf("\n");
			break;
		}
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		if (execute_command(line) == -1)
		{
			perror("Error: Unable to execute command");
		}
	}
	free(line);
	return (0);
}
