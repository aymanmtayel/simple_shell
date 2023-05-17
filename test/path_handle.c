#include "main.h"

/**
 * find_path - Finds the full path of a command
 * @cmd: The command to find the path of
 * Return: A pointer to the full path of the command, or NULL if not found
 */

char *find_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir;

	if (!path_copy)
	{
		perror("find_path");
		return NULL;
	}
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		char *full_path;
		int cmd_len = _strlen(cmd);
		int dir_len = _strlen(dir);
		
		full_path = malloc(cmd_len + dir_len + 2);
    		if (!full_path)
		{
			perror("find_path");
	    		free(path_copy);
			return NULL;
		}
		_strcpy(full_path, dir);
    		_strcpy(full_path + dir_len, "/");
     		_strcpy(full_path + dir_len + 1, cmd);
     		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
	    		return full_path;
		}
		free(full_path);
    		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
