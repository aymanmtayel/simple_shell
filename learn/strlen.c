#include "main.h"

/**
 * _strlen - get the length of a string
 * @str: the string
 * Return: the length of the string
 */

size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
