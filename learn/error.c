#include "main.h"

/**
 * _error - outputs the error messages
 * @name: name of the program
 * @cmd: wrong command
 * Return: error code
 */

void _error(char *cmd, char *name)
{
	char *msg = name;

	write(STDERR_FILENO, msg, _strlen(msg));

	msg = ": 1: ";
	write(STDERR_FILENO, msg, _strlen(msg));

	write(STDERR_FILENO, cmd, _strlen(cmd));

	msg = ": not found";
	write(STDERR_FILENO, msg, _strlen(msg));
}
