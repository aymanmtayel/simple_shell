#include "main.h"

/**
 * is_valid_executable - Checks if the given path points to a valid executable file.
 * @path: the path to check.
 *
 * Return: 1 if the path points to a valid executable file, 0 otherwise.
 */
int is_valid_executable(const char *path)
{
	return (access(path, X_OK) == 0);
}
