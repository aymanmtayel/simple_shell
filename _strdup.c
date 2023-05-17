#include "main.h"

/**
 * _strdup - duplicates a string
 * @s: the source string
 * Return: a pointer to the duplicated string, null if failed
 */
char *_strdup(char *s)
{
	int len = _strlen(s);
	char *dup = malloc(len + 1);

	if (!dup)
	{
		perror("_strdup");
		return (NULL);
	}
	_strcpy(dup, s);
	return (dup);
}

