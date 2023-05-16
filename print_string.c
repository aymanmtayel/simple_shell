#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * print_string - prints a given string
 * @list: string to be printed
 *
 * Return: the length of the string printed
 */

int print_string(va_list list)
{
	char *s;
	unsigned int len;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = 6;
		write(1, s, 6);
		return (len);
	}

	len = 0;
	while (s[len] != '\0')
		++len;
	write(1, s, len);
	return (len);
}
