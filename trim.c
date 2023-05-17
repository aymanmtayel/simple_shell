#include "main.h"

/**
 * trim - Trim leading and trailing whitespace from a string
 * @str: The string to trim
 * Return: A pointer to the trimmed string
 */

char *trim(char *str)
{
	size_t i, j, len;
	char *str_trimmed;

	len = _strlen(str);
	for (i = 0; i < len && (str[i] == ' ' || str[i] == '\t'); i++)
		;
	for (j = len - 1; j > i && (str[j] == ' ' || str[j] == '\t'); j--)
		;
	str_trimmed = malloc(j - i + 2);
	if (str_trimmed == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	_strncpy(str_trimmed, str + i, j - i + 1);
	str_trimmed[j - i + 1] = '\0';
	return (str_trimmed);
}
