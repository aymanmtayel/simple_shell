#include "main.h"

/**
 * r_space - removes the spaces from the command
 * @str: the command to remove the spaces from
 * Return: the command after trimming
 */

char *r_space(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ')
			return (str);
		str++;
	}
	return (NULL);
}
