#include "main.h"

/**
 * main - the main shell program
 * @argc: arguments count
 * @argv: array of arguments values
 * Return: 0 on success or error no
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *cmd = NULL, *commands = NULL, **args;
	size_t i = 0;
	ssize_t input_size = 0;
	int exit_c = EXIT_SUCCESS;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		input_size = getline(&commands, &i, stdin);
		if (input_size == -1)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			free(commands);
			exit(127);
		}
		cmd = r_space(commands);
		if (cmd == NULL)
			continue;
		args = split_c(cmd);
		if (args == NULL)
		{
			exit_c = 2;
			continue;
		}
		if (builtins(args) == 0)
			continue;
		else
		{
			if (execute(args) == -1)

