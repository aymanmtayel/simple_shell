#include "main.h"

/**
 *print_char - a function that prints var char
 *@list: the argument list
 *
 * Return: always 1
*/

int print_char(va_list list)
{
	char s = va_arg(list, int);

	write(1, &s, 1);
	return (1);
}
